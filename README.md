<div style="float: left; padding: 16px">
<svg width="196" height="196" viewBox="0 0 196 196" fill="none" xmlns="http://www.w3.org/2000/svg">
<path d="M49 0C21.938 0 0 21.938 0 49V147C0 174.062 21.938 196 49 196H147C174.062 196 196 174.062 196 147V49C196 21.938 174.062 0 147 0H49Z" fill="#546EF3"/>
<path d="M32.6821 98C68.7574 98.0083 98.0001 127.256 98.0001 163.333C61.9178 163.333 32.6667 134.082 32.6667 98H32.6821Z" fill="#1E1E1E"/>
<path d="M32.6667 98.1276C68.8195 98.1276 98.1277 127.436 98.1277 163.589C98.1277 127.436 127.436 98.1276 163.589 98.1276C127.436 98.1276 98.1277 68.8194 98.1277 32.6667C98.1277 68.8194 68.8195 98.1276 32.6667 98.1276Z" fill="#EDE3C9"/>
<path d="M98.0193 32.6667C134.093 32.6771 163.333 61.9241 163.333 98C127.251 98 98 68.749 98 32.6667C98.0064 32.6667 98.0128 32.6667 98.0193 32.6667Z" fill="#1E1E1E"/>
</svg>

</div>
<div>
<h2>modulAR - augmented reality home automation</h2>
<p>This project will allow you to add IoT capabilities to existing devices, using an ESP8266 module and a Unity based AR application. Communication will happen over MQTT, allowing you to control your devices from anywhere in the world.</p>
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
- Vuforia ([Vuforia](https://developer.vuforia.com/downloads/sdk#downloadModal))
- Figma To Unity Importer  ([source](https://github.com/ManakhovN/FigmaToUnityImporter))
- Unity-UI-Rounded-Corners - ([source](https://github.com/kirevdokimov/Unity-UI-Rounded-Corners.git))