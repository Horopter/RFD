/* Define printw with other headers in RFD.
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

#ifndef PRINTW_H_INCLUDED
#define PRINTW_H_INCLUDED
//Enable string functions
#include<string.h>
// Creates counter objects on final Opengl/glut window
class printer
{
	public:
	GLvoid *font_styles;
	printer()
	{
		font_styles = GLUT_BITMAP_HELVETICA_18;
	}
	void printw(float x, float y, int num, const char *st)
	{
		int len,i;
		char cmdbuf[500];
		glRasterPos2f(x,y);//Initial position to start with.
		snprintf(cmdbuf, sizeof(cmdbuf), "%s :: %d",st, num);
		len=strlen(cmdbuf);
		for(i=0;i<len;i++)
		{
			glutBitmapCharacter(font_styles,cmdbuf[i]); //printing each character.
		}
	}
};
#endif // PRINTW_H_INCLUDED
