# C_Calculator

This is a standard calculator program built in C using the GUI library gtk 4.

## Running the source code
To run the source code for this project, you have to install the [gtk 4.0](https://www.gtk.org/) library on your machine and configure your IDE appropriately.
## Editing the GUI Layout
To edit the GUI layout, you can use the gladeui software. A ui.glade file, which can be edited using the software, is provided in the repository. The gladeui software may generate an xml file that can only be run on gtk 3 and not gtk 4. In that case, you have to convert the xml file to the gtk version by using the following command
````
gtk4-builder-tool simplify --3to4 calculator.ui
````
This command requires installing the [gtk4 builder tool](https://www.gtk.org/docs/installations/windows/).
