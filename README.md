# koch_snowflake
###This is my official github repo created for the 6th semester graphics project.
* graph.out : It is the binary file that is a result of the code in ready to execute format in unix mode.
* koch.cpp : Source code to create Koch snowflake.
* graph.h : It is a custom header file. Include this in the GL directory of the system you use.
* printw.h : It is a custom header file with <br/>
		printw function written by Ali BaderEddin (modified under GNU GPL) and <br/>
		_vscprintf written by ismail of stack overflow. <br/>

Version 1.0 : Koch curve function <br/>
Version 1.1 : Adding animation to simulate the progress of the function <br/>
Version 1.2 : Successfully added succession counter using custom library files. <br/>
Version 1.3 : Portability to windows and linux setup by updating the preprocessor header to check OS type.<br/>
Version 1.4 : Developed interface to work with in Linux environment using gtkdialog. <br/>
Version 1.5 : Added scalability of center zoom to the previous version successfully. <br/>
Version 1.6 : Fixed the problem with reshape function to scale properly. <br/>
Version 1.7 : Added support to interface in linux systems lacking gtkdialog by altering the route of interface through zenity.<br/>
Version 1.8 : Added zoom implementation as a separate program to view the enhancement of the koch curve.<br/>
Version 1.9 : Created installer using DCP and PackJacket for cross-platform installation. <br/>
Version 2.0 : Added color settings to koch.cpp<br/>
Version 2.1 : 3D Rendering of koch curve in koch3d.cpp, cubing tetrahedron in 3dkoch.cpp, basic game scene rendering in game.cpp <br/>
Version 2.2 : Conversion of the procedural programming into semi-object oriented programming with <br/> background improvement and code organisation<br/>
Version 2.3 : Some more conversion to OOP and shooter from villain released as 2D Koch curve.<br/>
Version 2.4 : Using OOPs, I managed to make an AI that locates the defender and attacks him if he ever stopped. <br/>
Version 2.5 : Collision detection enabled. Technically now, it's a dodge game. Some code for offensive mode exists in comments. <br/>
Version 2.6 : Offensive mode activated. There is a glitch when game ends which has to be eliminated. <br/>
Version 2.7 : Glitch removed. Interface created. Activated through rfdlin. Taking this to windows is left <br/>
