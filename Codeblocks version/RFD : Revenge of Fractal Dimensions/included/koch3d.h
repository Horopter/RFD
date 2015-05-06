/* Define koch3d with other headers in RFD.
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

#ifndef KOCH3D_H_INCLUDED
#define KOCH3D_H_INCLUDED
/*
It is defined to store values in triplets. Saves time and improves understanding of object.
In case of coordinates, it stores three values (x,y,z) and in case of colors it stores three values (R,G,B)
*/
typedef float point[3];
// default initial size. This wasn't modified in the program but can help in customizability.
float init_size=1;
/*
Creates the object Kochus in the game. It is a 3D homologue of Koch's curve.
Instead of taking triangles, we have considered tetrahedrons. The base of new tetrahedron is concentric
with the face it rests on and is symmetrically positioned.
*/
class koch_devil
{
	public :
	point init_tetr[4]; // initial values of coordinates of tetrahedron.
	static GLfloat theta; // angle of spin, in Y-axis.
	GLint axis; // axis number. Gives customizability in case it be needed. The code should be modified accordingly.
	point color[9]; // Color customization, which has been utilized.
	int g,choice; // Glitter variable (also successions in fractal) g and color variable choice.  
	koch_devil()
	{
		//Initialisation of starting positions
		init_tetr[0][0]=1;
		init_tetr[0][1]=3.5;
		init_tetr[0][2]=1;
		init_tetr[1][0]=1;
		init_tetr[1][1]=1.5;
		init_tetr[1][2]=-1;
		init_tetr[2][0]=-1;
		init_tetr[2][1]=3.5;
		init_tetr[2][2]=-1;
		init_tetr[3][0]=-1;
		init_tetr[3][1]=1.5;
		init_tetr[3][2]=1;
		//Color pallette initialsisation.
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
		axis=1; // Y axis as axis #1
	}
	//initial value of tetrahedron base size.
	void init_tetra(float size)
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				init_tetr[i][j]*=init_size;
	}
	//Each face of tetrahedron is rendered.
	void triangle(point a, point b, point c, int m)
	{
		glBegin(GL_TRIANGLES);
			glColor3fv(color[(choice+g-m)%9]);
			glVertex3fv(a);
			glColor3fv(color[(choice+g-m+1)%9]);
			glVertex3fv(b);
			glColor3fv(color[(choice+g-m+2)%9]);
			glVertex3fv(c);
		glEnd();
	}
	// Render of tetrahedron.
	void tetra(point a, point b, point c, point d, int m)
	{
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_LINES); // Borders
			glVertex3fv(a);
			glVertex3fv(b);
			glVertex3fv(b);
			glVertex3fv(c);
			glVertex3fv(c);
			glVertex3fv(d);
			glVertex3fv(d);
			glVertex3fv(a);
			glVertex3fv(a);
			glVertex3fv(c);
			glVertex3fv(b);
			glVertex3fv(d);
		glEnd();
		triangle(a,b,c,m);
		triangle(a,b,d,m);
		triangle(b,c,d,m);
		triangle(c,a,d,m);
	}
	// Finding peak vertex of new tetrahedron. 
	void findvertex(point a, point b, point c, int m)
	{
		point u,v,w,centroid,normal,p,q,peak;
		float scale,size2,size;
		for(int i=0;i<3;i++)
		{
			u[i]=(a[i]+b[i])/2;
			v[i]=(b[i]+c[i])/2;
			w[i]=(c[i]+a[i])/2;
		}
		for(int i=0;i<3;i++)
		{
			centroid[i]=(a[i]+b[i]+c[i])/3;
			p[i]=c[i]-a[i];
			q[i]=b[i]-a[i];
		}
		for(int i=0;i<3;i++)
		{
			u[i]=(a[i]+centroid[i])/2;
			v[i]=(b[i]+centroid[i])/2;
			w[i]=(c[i]+centroid[i])/2;
		}
		normal[0]=p[1]*q[2]-p[2]*q[1];
		normal[1]=p[2]*q[0]-p[0]*q[2];
		normal[2]=p[0]*q[1]-p[1]*q[0];
		scale = sqrt(pow(normal[0],2)+pow(normal[1],2)+pow(normal[2],2));
		size2 = pow((u[0]-v[0]),2)+pow((u[1]-v[1]),2)+pow((u[2]-v[2]),2);
		size = sqrt(size2);
		for(int i=0;i<3;i++)
		{
			normal[i]=normal[i]*0.816496;
			normal[i]=normal[i]*size;
			normal[i]/=scale;
			peak[i]=centroid[i]-normal[i];
		}
		spread(u,v,w,peak,m-1);
	}
	// Calling for successions.
	void spread(point a, point b, point c, point d, int m)
	{
		tetra(a,b,c,d,m);
		if(m>0)
		{
			findvertex(a,b,d,m-1);
			findvertex(b,c,d,m-1);
			findvertex(c,a,d,m-1);
		}
		else
			return;
	}
	// spin the structure.
	static void spintetra()
	{
		theta+=2;
		if(theta>360)
			theta-=360;
		glutPostRedisplay();
	}
	// Object rendering with delay induced according to system.
	void koch(int m,int c)
	{
		g=m;
		choice=c;
		tetra(init_tetr[0],init_tetr[1],init_tetr[2],init_tetr[3],m);
		glFlush();
		if(m>0)
		{
			findvertex(init_tetr[1],init_tetr[0],init_tetr[3],m);
			findvertex(init_tetr[2],init_tetr[1],init_tetr[3],m);
			findvertex(init_tetr[0],init_tetr[2],init_tetr[3],m);
			findvertex(init_tetr[0],init_tetr[1],init_tetr[2],m);
		}
		else
		{
			unsigned long i=5000000;
			while(i)
			{
				i-=1;
			}
		}
	}

};
// static variable initialization
float koch_devil::theta=0;

#endif // KOCH3D_H_INCLUDED
