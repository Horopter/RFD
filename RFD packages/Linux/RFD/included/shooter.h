/* Define shooter with other headers in RFD.
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

#ifndef SHOOTER_H_INCLUDED
#define SHOOTER_H_INCLUDED
// Enable mathematical functions.
#include<cmath>
/*
It is defined to store values in triplets. Saves time and improves understanding of object.
In case of coordinates, it stores three values (x,y,z) and in case of colors it stores three values (R,G,B)
*/
typedef float point[3];
//Creates bullets for the defender.
class shooter
{
	private:
		point init;
	public:
	int c;
	point color[9];
	point shape[4];
	shooter(point a)
	{
		c=rand()%7;//arbitrary color assignment.
		init[0]=a[0];//Initial position decided by argument.
		init[1]=a[1];
		init[2]=a[2];
		//Color pallettes
		color[0][0]=1;
		color[0][1]=0;
		color[0][2]=0;
		color[1][0]=0;
		color[1][1]=1;
		color[1][2]=0;
		color[2][0]=0;
		color[2][1]=0;
		color[2][2]=1;
		color[3][0]=1;
		color[3][1]=1;
		color[3][2]=0;
		color[4][0]=0;
		color[4][1]=1;
		color[4][2]=1;
		color[5][0]=1;
		color[5][1]=0;
		color[5][2]=1;
		color[6][0]=0.5;
		color[6][1]=0.5;
		color[6][2]=1;
		color[7][0]=0;
		color[7][1]=0.5;
		color[7][2]=0.5;
		color[8][0]=0.8;
		color[8][1]=0;
		color[8][2]=0.7;
		drawshooter();
		shoot();
	}
	//Rendering the shooting bullets based off on arbitrary color assigned at creation.
	void drawshooter()
	{
		glBegin(GL_POLYGON);
			glColor3fv(color[c]);
			glVertex3f(init[0]-0.05,init[1],0);
			glVertex3f(init[0]+0.05,init[1],0);
			glVertex3f(init[0],init[1]+0.1,0);
		glEnd();
	}
	//Increment postion in Y axis by specified unit.
	void shoot()
	{
		init[1]+=0.1;
	}
	//Position access.
	float getinitx()
	{
		return this->init[0];
	}
	float getinity()
	{
		return this->init[1];
	}
	//Position update.
	void putx(float x, float y)
	{
		init[0]=x;
		init[1]=y;
	}

};

#endif // SHOOTER_H_INCLUDED
