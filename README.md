<img src="https://user-images.githubusercontent.com/3185243/188761469-24204cc4-f75a-4975-a3b5-6369ee1d6a12.png" width="196" align="left" style="padding: 16px">

<div>
<h2>modulAR - augmented reality home automation</h2>
<p>Add IoT capabilities to existing devices, using an ESP8266 module and a Unity based AR application. Communication will happen over MQTT, allowing you to control your devices from anywhere in the world.</p>
<p>Credits: <a href="https://claudia.mazzuca.com/">Claudia Mazzuca</a>, <a href="https://www.linkedin.com/in/giulia-daleo/">Giulia D’Aleo</a>, <a href="https://github.com/JanOstrowka">Jan Ostrówka</a></p>
<p>*inspired by an amazing <a href="https://www.frolicstudio.com/portfolio/smartians/" target="_blank">Smartians</a> project form <a href="https://www.frolicstudio.com/" target="_blank">FROLIC studio</a></p>
</div>

  <br>
  <br> 

## TOC
- [List of parts](#list-of-parts)
- [Circuit Diagram](#circuit-diagram)
- [Casing design](#casing-design)
- [App Prototype](#app-prototype)
- [Contributing](#contributing)
  <br>
  <br> 
### The video
<a href="url">
<img style="display: block; margin-right: auto; width: 100%; max-width: 600px; border-radius: 16px;" src="https://media.giphy.com/media/TwPYTOvWlrlj2YOjbP/giphy.gif">
<p>▶️ click here to play the video</p>
</a>
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
<img style="display: block; margin-right: auto; width: 100%; max-width: 600px" src="https://user-images.githubusercontent.com/3185243/188761839-d1a27435-4fdc-4f5e-afe4-74f4e8287b7e.png">
<br>
<br>

### Casing design
<img style="display: block; margin-right: auto; width: 100%; max-width: 600px" src="https://user-images.githubusercontent.com/3185243/188761962-6837f404-8dfc-4d1d-9698-b898735ffdb9.png">

design files of the 3D models are available in the [models folder](./models)
<br>
<br>

### App Prototype
<img style="display: block; margin-right: auto; width: 100%; max-width: 600px" src="https://user-images.githubusercontent.com/3185243/188765238-c4579408-bdcb-4f12-be6a-9f17a9111f36.png">

download the latest version of the app from [here](.builds/modulAR.apk)
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

#### Unity packages
- Vuforia ([source](https://developer.vuforia.com/downloads/sdk#downloadModal))
- Figma To Unity Importer  ([source](https://github.com/ManakhovN/FigmaToUnityImporter))
- Unity-UI-Rounded-Corners - ([source](https://github.com/kirevdokimov/Unity-UI-Rounded-Corners.git))