# PageShot (Webpage Screenshot Taker)


This program captures a screenshot of a web page and saves it as a PNG file on the user's desktop. It uses the GTK library to create a window, the WebKit library to load the webpage,
and the GLib library for utility functions. Then the program prompts the user to enter a valid URL, which will loads the page, and waits for it to finish loading.
When the page has finished loading, the program will capture a screenshot of the window and then saves it as a PNG file on the user's desktop under the name
'screenshot.png' and exits the program. 

Please compile the code on your Ubuntu Desktop. Do not put the file in any other location before compilation.



# Installation
This program might ask you to install some librarires so if it does just run the following command:
```
sudo apt-get install libgtk-3-dev libwebkit2gtk-4.0-dev
```

To see if it's installed:
```
pkg-config --modversion gtk+-3.0
pkg-config --modversion webkit2gtk-4.0
```


# Compilation
Make sure you are running it on a working version of ubuntu. To compile it run this command on terminal:
```
gcc -o pageshot pageshot.c `pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0`
```

If everything is done correctly then it will compile and you can run the program using: ```./pageshot```


