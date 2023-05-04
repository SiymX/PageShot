# PageShot (Webpage Screenshot Taker)


This program captures a screenshot of a web page and saves it as a PNG file on the user's desktop. It uses the GTK library to create a window, the WebKit library to load the webpage,
and the GLib library for utility functions. Then the program prompts the user to enter a valid URL, which will loads the page, and waits for it to finish loading.
When the page has finished loading, the program will capture a screenshot of the window and then saves it as a PNG file on the user's desktop under the name
'screenshot.png' and exits the program. 



# Install the following if required
```
sudo apt-get install libgtk-3-dev libwebkit2gtk-4.0-dev
```
