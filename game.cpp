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
using namespace std;
int s,choice=1,g;
float init_size=1;
int cx, cy;
static GLfloat  scaling = 1.0f;
static int lasty = 0;
typedef float point[3];
point init_tetr[]={{1,3.5,1},{1,1.5,-1},{-1,3.5,-1},{-1,1.5,1}};
point starloc[] = {{-5,3,0}};
point def[] ={{-1,-3,0},{-1,-2.95,0},{1,-2.95,0},{1,-3,0}};
static GLfloat theta[]={0.0};
static GLint axis=1;
point color[] = {{1,0,0},{0,1,0},{0,0,1},{1,1,0},{0,1,1},{1,0,1},{0.5,0.5,1},{0,0.5,0.5},{0.8,0,0.7}};
void spread(point a, point b, point c,point d, int m);
void glTranslatefv(point v)
{
	glTranslatef(v[0],v[1],v[2]);
}
void triangle(point a, point b, point c, int m)
{
	glColor3fv(color[(choice+g-m)%9]);
	glBegin(GL_TRIANGLES);
		glVertex3fv(a);
		glVertex3fv(b);
		glVertex3fv(c);
	glEnd();
	
}
void tetra(point a, point b, point c, point d, int m)
{
	glColor3f(0.0,0.0,0.0);	
	glBegin(GL_LINES);
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
void spread(point a, point b, point c, point d, int m)
{
	tetra(a,b,c,d,m);
	int j;
	if(m>0)
	{
		findvertex(a,b,d,m-1);
		findvertex(b,c,d,m-1);
		findvertex(c,a,d,m-1);		
	}
	else
		return;
}
void spintetra()
{
	theta[0]+=2;
	if(theta[0]>360)
		theta[0]-=360;
	glutPostRedisplay();
}
void koch(int m)
{
	tetra(init_tetr[0],init_tetr[1],init_tetr[2],init_tetr[3],g);
	glFlush();
	if(m>0)
	{
		findvertex(init_tetr[1],init_tetr[0],init_tetr[3],m);
		findvertex(init_tetr[2],init_tetr[1],init_tetr[3],m);
		findvertex(init_tetr[0],init_tetr[2],init_tetr[3],m);
		findvertex(init_tetr[0],init_tetr[1],init_tetr[2],m);
	}
}
void defender()
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);
		glVertex3fv(def[0]);
		glVertex3fv(def[1]);
		glVertex3fv(def[2]);
		glVertex3fv(def[3]);
	glEnd();
}
void stars()
{
	glColor3f(1.0,1.0,1.0);
	glPushMatrix();
		glTranslatefv(starloc[0]);
		glutSolidSphere(0.05,15,20);
	glPopMatrix();	
}
void myReshape(int w, int h)
{
	if(w<600 || h<600)
		glutFullScreen();
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat r = (GLfloat)h/(GLfloat)w;
	if(w<=h)
		glOrtho(-5,5,-5*r,5*r,-10,10);
	else
		glOrtho(-5/r,5/r,-5,5,-10,10);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void displayer()
{
	static int i=0;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glClearColor(0.0,0.0,0.0,0.0);
	g=i;
	glPushMatrix();
	glRotatef(theta[0],0,1,0);
	koch(g);
	glPopMatrix();
	stars();
	defender();
	glFlush();
	glutSwapBuffers();
	glScalef(scaling, scaling, scaling);
	i++;
	if(i==s+1) i=0;
}
void display()
{
	displayer();
	//stars();
	glFlush();
}
void init_tetra(float size)
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			init_tetr[i][j]*=init_size;
}
void keyboard(unsigned char k, int x, int y)
{
	switch (k)
	{
		case 'e':
			glutReshapeWindow(600,600);
			glutPositionWindow((cx-600) / 2, (cy-600) / 2);
			glFlush();
			//glutPostRedisplay();
			break;
		case 'q':
			exit(0);
	}
    glutPostRedisplay();
}
void specialkeys(int k, int x, int y)
{
	switch(k)
	{
		case GLUT_KEY_RIGHT:
			for(int i=0;i<4;i++)
			def[i][0]+=0.2;
			
		break;
		case GLUT_KEY_LEFT:
			for(int i=0;i<4;i++)
			def[i][0]-=0.2;
			
		break;
	}
}
void mouse(int btn,int state,int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN) axis =0;
		glRotatef(theta[0],1,0,0);
	if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN) axis =1;
			glRotatef(theta[1],0,1,0);
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN) axis =2;
			glRotatef(theta[2],0,0,1);
	glFlush();
	glutPostRedisplay();
}
int main(int argc, char* argv[])
{
	int m_width=600;
	int m_height=600;
	#if !(defined(__gnu_linux__)||defined(__linux__))
		cout << "Enter the number of successions : [0-7] ";
		cin >> s;
		cout << "Next you will have to enter the size of the triangle, a float point value between 0 and 5." << endl;
		cout << "Enter the initial size of the triangle : ";
		cin >> init_size;
		if(init_size>5)
		{
			cout << "Maximum limit of size is 5. Restart the program. Bye!";
			exit(0);
		}
		cout << "Enter the initial color of the triangle you wish to see : \n1. RED \n2. GREEN \n3. BLUE \n Enter your choice :";
		cin >> choice;
		choice-=1;
		g=0;
	#else
		char *pEnd;
		if(argc==0)
		{
			cout << "No args.";
			exit(0);
		}
		s = strtod(argv[1],&pEnd);
		init_size = strtod(pEnd,&pEnd);
		choice = strtod(pEnd,NULL);
		choice--;
		g=0;
	#endif
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(m_width,m_height);
	cx = glutGet(GLUT_SCREEN_WIDTH);
	cy = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowPosition ((cx-m_width) / 2, (cy-m_height) / 2);
	glutCreateWindow("GAME");
	glutDisplayFunc(display);
	glutSpecialFunc(specialkeys);
	glutIdleFunc(spintetra);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(myReshape);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0,0.0,0.0,0.0);
	glutMainLoop();
	return 0;
}
