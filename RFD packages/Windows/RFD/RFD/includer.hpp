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
#include"graph.hpp"
#include"printw.hpp"
#include"koch3d.hpp"
#include"defender.hpp"
#include"kocht.hpp"
#include"shooter.hpp"
using namespace std;


#endif // INCLUDER_H_INCLUDED
