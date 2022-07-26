/*
                      _       _          _____
                     | |     | |   /\   |  __ \
  _ __ ___   ___   __| |_   _| |  /  \  | |__) |
 | '_ ` _ \ / _ \ / _` | | | | | / /\ \ |  _  /
 | | | | | | (_) | (_| | |_| | |/ ____ \| | \ \  Arduino sketch
 |_| |_| |_|\___/ \__,_|\__,_|_/_/    \_\_|  \_\ V26.07.22

 the following file can:
 ✓ use arduino_secrets.h to store credentials
 ✓ connect to the WiFi
 ✓ connect to the MQTT broker
 ✓ retain the connection
 ✓ subscribe to the MQTT topic
 ✓ toggle the LED ON and OFF through the messages
 ✓ turn the arm by x° send through the messages
 */

#include "arduino_secrets.h"    // passwords
#include <ESP8266WiFi.h>        // WiFi
#include <PubSubClient.h>       // MQTT
#include <AccelStepper.h>       // stepper

// serial port baud
const int baud = 9600;
// LED state
int ledState = LOW;
// notify about the state of the spin
bool notifyStop = true;
// stepper motor
const int stepsPerRevolution = 4096;
const int oneDegree = stepsPerRevolution / 360;
const int onePercent = stepsPerRevolution / 100;
const int motorSpeed = 500;
const int motorAcceleration = 100;
// ULN2003 motor driver pins
#define IN1 4
#define IN2 3
#define IN3 2
#define IN4 1
// WiFi Network
const char *ssid = WIFI_SSID;
const char *password = WIFI_PASSWORD;
// MQTT Server
const char *mqtt_server = MQTT_URL;
const int mqtt_port = MQTT_PORT;
const char *mqtt_username = MQTT_USERNAME;
const char *mqtt_password = MQTT_PASSWORD;
// MQTT Topic
const char *topic_status = "IoT/vpp/module/id1/status";
const char *topic_led = "IoT/vpp/module/id1/led";
const char *topic_motor = "IoT/vpp/module/id1/motor";

// connection basics
WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE    (50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

// stepper basics
AccelStepper stepper(AccelStepper::HALF4WIRE, IN1, IN3, IN2, IN4);

// WiFi connection
void setup_wifi() {
    Serial.println();
    delay(500);
    Serial.println();

    Serial.print("Connecting to WiFi");
    Serial.println();
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(400);
        Serial.print("⏝");
        digitalWrite(BUILTIN_LED, LOW);
        delay(1028);
        Serial.print("⏜");
        digitalWrite(BUILTIN_LED, HIGH);
    }

    randomSeed(micros());
    digitalWrite(BUILTIN_LED, HIGH);
    Serial.println();
    Serial.print("Connected to: ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

// controls over MQTT
void callback(char *topic, byte *payload, unsigned int length) {
    Serial.println();
    Serial.print("Message arrived in topic: ");
    Serial.print(topic);
    Serial.println();
    Serial.print("Message: ");
    String message;
    for (int i = 0; i < length; i++) {
        message = message + (char) payload[i];  //Convert *byte to String
    }
    Serial.print(message);

    // LED
    if (strcmp(topic, topic_led) == 0) {
        // toggle the LED on and off
        if (message == "toggle") {
            digitalWrite(BUILTIN_LED, !digitalRead(BUILTIN_LED));
            client.publish(topic_status, "module 1 - LED toggled");
        }
            // turn the LED on
        else if (message == "on") {
            digitalWrite(BUILTIN_LED, LOW);
            client.publish(topic_status, "module 1 - LED on");
        }
            // turn the LED off
        else if (message == "off") {
            digitalWrite(BUILTIN_LED, HIGH);
            client.publish(topic_status, "module 1 - LED off");
        }
    }

    // motor
    if (strcmp(topic, topic_motor) == 0) {
        // general spin
        if (message == "spin") {
            stepper.move(-stepsPerRevolution);
            client.publish(topic_status, "module 1 - motor spinning");
            notifyStop = true;
        }
            // half spin
        else if (message == "half spin" or message == "half" or message == "halfspin") {
            stepper.move(stepsPerRevolution / 2);
            client.publish(topic_status, "module 1 - motor is doing half a spin");
            notifyStop = true;
        }
            // spin by a degree
        else if (message != "spin") {
            const int angle = message.toInt();
            if (angle >= -360 && angle <= 360 && angle != 0) {
                stepper.move(angle * oneDegree);
                client.publish(topic_status, "module 1 - motor spinning by X°");
                notifyStop = true;
            } else if (angle == 0) {
                stepper.moveTo(angle);
                client.publish(topic_status, "module 1 - motor has not been moved");
                notifyStop = false;
            } else if (angle < -360 || angle > 360) {
                int quotient = angle / 360;
                stepper.moveTo(quotient * stepsPerRevolution);
                client.publish(topic_status, "module 1 - motor spinning by X°");
                notifyStop = false;
            }
        } else {
            stepper.move(0);
            client.publish(topic_status, "module 1 - unknown command");
            notifyStop = false;
        }
    }

    // line spacer
    Serial.print("");
    Serial.println();
    Serial.print(". . . . . . . . . . . .");
    Serial.println();
}

void reconnect() {
    // Loop until reconnected
    while (!client.connected()) {
        Serial.println();
        Serial.print("Connecting to MQTT broker");

        // Create a random client ID
        String clientId = "vppModule-";
        clientId += String(random(0xffff), HEX);

        // Attempt to connect
        if (client.connect(clientId.c_str(), mqtt_username, mqtt_password)) {
            Serial.println();
            Serial.print("Connected to: ");
            Serial.print(mqtt_server);

            // connected? send confirmation
            client.publish(topic_status, "module 1 is connected");

            // flash the LED
            digitalWrite(BUILTIN_LED, LOW);
            delay(100);
            digitalWrite(BUILTIN_LED, HIGH);
            delay(100);

            // subscribe
            client.subscribe(topic_led);
            client.subscribe(topic_motor);
            client.subscribe(topic_motor_degree);
            client.subscribe(topic_motor_percent);
            client.subscribe(topic_status);

            // set the led off
            digitalWrite(BUILTIN_LED, HIGH);

        } else {
            // reconnect countdown
            Serial.println();
            Serial.print("failed to connect to MQTT broker");
            Serial.println();
            Serial.print(" trying again in ");
            for (int i = 4; i >= 0; i--) {
                Serial.print(i + 1);
                Serial.print(", ");
                delay(1000);
            }
            delay(500);
            Serial.print("0");
            delay(1000);
        }
    }
}

void motor() {
    stepper.setMaxSpeed(motorSpeed);
    stepper.setAcceleration(motorAcceleration);
}

// main
void setup() {
    Serial.begin(baud);
    setup_wifi();
    pinMode(BUILTIN_LED, OUTPUT);
    client.setServer(mqtt_server, mqtt_port);
    motor();
    client.setCallback(callback);
}


// reconnect to the WiFi
void loop() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();
    if (stepper.distanceToGo() == 0 && notifyStop == true) {
        client.publish(topic_status, "module 1 - spin completed");
        notifyStop = false;
    }
    stepper.run();
}