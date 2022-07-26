<img src="https://user-images.githubusercontent.com/3185243/181126881-33ef77f5-9b48-443d-9fbf-0738a6d74d8e.png" width="196" align="left" style="padding: 16px">

<div>
<h2>modulAR - augmented reality home automation</h2>
<p>Add IoT capabilities to existing devices, using an ESP8266 module and a Unity based AR application. Communication will happen over MQTT, allowing you to control your devices from anywhere in the world.</p>
</div>

  <br>
  <br> 

## TOC
- [List of parts](#list-of-parts)
- [Circuit Diagram](#circuit-diagram)
- [Casing design](#casing-design)
- [App Prototype](#app-prototype)
- [Contributing](#contributing)
- [Packages used](#packages-used)
  <br>
  <br> 

### List of parts
| quantity | name                   |
|----------|------------------------|
| 1        | ESP8266                |
| 1        | Stepper motor 28byj-48 |
| 2        | Battery                |
<br>
<br>

### Circuit Diagram
<img src="https://user-images.githubusercontent.com/3185243/181097852-c3fe0e63-619b-417d-9925-6258d9180513.png" width="100%" style="max-width: 600px;">
<br>
<br>

### Casing design
<img src="none">
<br>
<br>

### App Prototype
<img src="none">
<br>
<br>

### Contributing
Feel free to report a bug, or suggest an improvement. Both of these can be added under `issues` tab.
You can also `fork` this repository and submit a pull request, if you would like to share your improvements.

#### Development setup:
1. download repository
2. update `arduino_secrets.h.example` with your secrets and change the file extension to `arduino_secrets.h`
3. add vuforia license key in `VuforiaConfiguration.asset.example` and change the file extension to `VuforiaConfiguration.asset`
4. In Unity editor, install missing [packages](#packages-used)
5. In Arduino IDE,
   1. install necessary libraries
   2. go to `Preferences` ≫ `Additional boards manager URLs:` and add: <br>
   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```

### Packages used
- Vuforia ([source](https://developer.vuforia.com/downloads/sdk#downloadModal))
- Figma To Unity Importer  ([source](https://github.com/ManakhovN/FigmaToUnityImporter))
- Unity-UI-Rounded-Corners - ([source](https://github.com/kirevdokimov/Unity-UI-Rounded-Corners.git))