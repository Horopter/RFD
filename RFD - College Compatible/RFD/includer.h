#ifndef INCLUDER_H_INCLUDED
#define INCLUDER_H_INCLUDED

#include<iostream>
#include<cmath>
#if defined(__gnu_linux__)||defined(__linux__)
	#include<unistd.h>
#endif
#if defined(_WIN32)||defined(__WINDOWS__)||defined(_WIN64)
	#include<windows.h>
#endif
#include<cstdlib>
#include<ctime>
#include<cstdio>
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#if defined(__gnu_linux__)||defined(__linux__)
	#include"GL/freeglut.h"
	#include"GL/freeglut_std.h"
	#include"GL/gl.h"
	#include"GL/glu.h"
	#include"GL/glut.h"
	#include"GL/glx.h"
#endif
#if defined(_WIN32)||defined(__WINDOWS__)||defined(_WIN64)
	//#include"GL/gl.h"
	//#include"GL/glu.h"
	//#include"GL/glut.h"
	#include<GL/glut.h>
#endif


#endif // GRAPH_H_INCLUDED

//#include"graph.h"
#include"printw.h"
#include"koch3d.h"
#include"defender.h"
#include"kocht.h"
#include"shooter.h"
using namespace std;


#endif // INCLUDER_H_INCLUDED
