#include<iostream>
#include<cmath>
#include<unistd.h>
#include<cstdlib>
#include<ctime>
#include<GL/graph.h>
#include"printw.h"
using namespace std;
int d,choice=1;
static int power=d;
float init_size=1;
typedef float point[3];
point init_tri[] = 
{
	{0,1,0},
	{0.866,-0.5,0},
	{-0.866,-0.5,0}
};
point color[] = {{1,0,0},{0,1,0},{0,0,1},{1,1,1}};
void spread(point a, point b, point c, int m);
void triangle(point a, point b, point c)
{
	glColor3fv(color[choice]);
	glBegin(GL_LINE_LOOP);
		glVertex3fv(a);
		glVertex3fv(b);
		glVertex3fv(c);
	glEnd();
}
void findvertex(point a, point b,int m)
{
	point c= {0.0};
	point v1,v2,diff;
	for(int i=0;i<3;i++)
		diff[i]=b[i]-a[i];
	for(int i=0;i<3;i++)
	{
		v1[i]=a[i]+diff[i]/3;
		v2[i]=v1[i]+diff[i]/3;
	}
	double s60 = sin(60 * M_PI *pow(-1,(m%2+power%2)) / 180.0);    
	double c60 = cos(60 * M_PI *pow(-1,(m%2+power%2)) / 180.0);
	c[0]= c60 * (v1[0] - v2[0]) - s60 * (v1[1] - v2[1]) + v2[0];
	c[1]= s60 * (v1[0] - v2[0]) + c60 * (v1[1] - v2[1]) + v2[1];
	c[2]=0;
	spread(v1,v2,c,m-1);
	if(m>1)
	{
		findvertex(v1,a,m-1);
		findvertex(b,v2,m-1);
	}
}
void spread(point a, point b, point c, int m)
{
	point v1,v2,v3;
	triangle(a,b,c);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		glVertex3fv(a);
		glVertex3fv(b);
	glEnd();
	int j;
	if(m>0)
	{
		findvertex(c,a,m);
		findvertex(b,c,m);		
	}
	else
		return;
}
void koch(int m)
{
	triangle(init_tri[0],init_tri[1],init_tri[2]);
	printw (0.3, 4.6, 0, "%s : %d", "Succession number", m);
	glFlush();
	if(m>0)
	{
		findvertex(init_tri[0],init_tri[1],m);
		findvertex(init_tri[1],init_tri[2],m);
		findvertex(init_tri[2],init_tri[0],m);
	}
}
void myReshape(int w, int h)
{
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
void display()
{
	for(int i=0;i<=d;i++)
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		glClearColor(1.0,1.0,1.0,1.0);
		power=i-1;
		koch(i);
		glFlush();
		sleep(2);
	}
}
void init_triangle(float size)
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			init_tri[i][j]*=init_size;
}
int main(int argc, char* argv[])
{
	cout << "Enter the number of successions : [0-7] ";
	cin >> d;
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
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Koch curve");
	init_triangle(init_size);
	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1,1,1,1);
	glutMainLoop();
	return 0;
}
