/* Define defender with other headers in RFD.
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

#ifndef DEFENDER_H_INCLUDED
#define DEFENDER_H_INCLUDED
/*
It is defined to store values in triplets. Saves time and improves understanding of object.
In case of coordinates, it stores three values (x,y,z) and in case of colors it stores three values (R,G,B)
*/
typedef float point[3]; 
// Creates object defender in the game. 
class defense
{
	public:
	point def[4];
	defense()
	{
		// Coordinates of defender are initialised.
		def[0][0]=-1.5;
		def[0][1]=-4;
		def[0][2]=0;
		def[1][0]=-0.5;
		def[1][1]=-4.0;
		def[1][2]=0.0;
		def[2][0]=0;
		def[2][1]=-3.5;
		def[2][2]=0;
		def[3][0]=0.5;
		def[3][1]=-4;
		def[3][2]=0;
		def[4][0]=1.5;
		def[4][1]=-4;
		def[4][2]=0;
		def[5][0]=0;
		def[5][1]=-4.5;
		def[5][2]=0;
	}
	void defender()
	{
		//drawing the defender in the new position defined by def.
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
			glVertex3fv(def[1]);
			glVertex3fv(def[2]);
			glVertex3fv(def[3]);
		glEnd();
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
			glVertex3fv(def[0]);
			glVertex3fv(def[4]);
			glVertex3fv(def[5]);
		glEnd();
	}
	//This function was never used in the program but, it helps a lot in debugging game in general.
	//The x-coordinate of defender is the sole center of action.
	float getXPos()
	{
		return (def[1][0]+def[4][0])/2;
	}
};
#endif // DEFENDER_H_INCLUDED
