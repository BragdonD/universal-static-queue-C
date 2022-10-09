### Static-Queue in C

This is a static queue implementation in C. It is able to store any kind of data since it is written with a `void*` array to store the data. Note that if you pass pointer as type for the queue, you will need to handle the dealocation of the element each time you dequeue one.

## Folder-organisation

In the inc folder you will find the header for each files In the src folder you will find the implementation of all the function.
Here the `main` and the `ui` files are just mean as an utilization example.

## How to use it

First you will need to build the project, the makefile is provided with the program, so you just need to enter the following command at the racine of the workspace folder: mingw32-make. Ok so now, you have build the project, (the makefile is setup to compile the program for debug mode) you can now run the program by running the following once again at the racine of the workspace folder : .\bin\main.

In the program, you will be able to use multiple commands. They will be presented to you by a menu when the program is running.

## Warning

Please do not create the bin and obj folder. They will be created by the makefile. Plus do not touch to the created files inside those two folders.
