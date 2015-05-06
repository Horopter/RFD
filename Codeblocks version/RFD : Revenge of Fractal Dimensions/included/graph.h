/* Define graph with other headers in RFD.
   Or use includer.h
   Copyright (C) 2015 Horopter Inc.
   This file is part of the Horopter 'included' Library.

   The Horopter 'included' Library is part of free software RFD;
   you can redistribute it and/or modify it under the terms of the
   GNU Lesser General Public License as published by the Free Software Foundation;

   Like GNU libraries, the Horopter 'included' Library is distributed in the hope that 
   it will be useful, knowledgeable but WITHOUT ANY WARRANTY;
   without even the implied warranty of  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
   See the GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the Horopter 'included' Library; if not, see
   <http://www.gnu.org/licenses/>. 
 */

#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
/*
	Headers for linux compatibility.
	This works with freeglut installed in the system.
	We recommend the headers be available to compile in GL directory;
	under the RFD source files.
*/
#if defined(__gnu_linux__)||defined(__linux__)
	#include"GL/freeglut.h"
	#include"GL/freeglut_std.h"
	#include"GL/gl.h"
	#include"GL/glu.h"
	#include"GL/glut.h"
	#include"GL/glx.h"
	#include<unistd.h>
#endif
/*
	Headers for windows compatibility.
	This works with standard glut files supported by Visual Studio 2012 and later.
	We recommend the headers be available to compile in GL directory;
	under the RFD source files.
*/
#if defined(_WIN32)||defined(__WINDOWS__)||defined(_WIN64)
	#include"GL/gl.h"
	#include"GL/glu.h"
	#include"GL/glut.h"
	#include<windows.h>
#endif


#endif // GRAPH_H_INCLUDED
