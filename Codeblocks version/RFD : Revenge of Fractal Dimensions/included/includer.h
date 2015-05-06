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
#include"graph.h"
#include"printw.h"
#include"koch3d.h"
#include"defender.h"
#include"kocht.h"
#include"shooter.h"
using namespace std;


#endif // INCLUDER_H_INCLUDED
