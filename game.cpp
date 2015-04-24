#include"included/includer.h"
int s,choice=1,g;
int counter =20;
int cx, cy;
typedef float point[3];
point starloc[] = { { -5.5, 3, -1 }, { -3, 4, -1 }, { -8, 2, -1 }, { -2.5, 1, -1 }, { 7.5, 1, -1 }, { 3.5, 4, -1 }, { 5.5, 3, -1 }, { 10, 4, -1 }, { 9, 3, -1 }, { -10, 4, -1 }, { -4.7, -2, -1 }, { -9, 3, -1 }, { -6, -4, -1 }, { 4, -1, -1 }, { 5, -4, -1 }, { 8, -2, -1 }, { -8, -4, -1 }, { -8.7, -2.2, -1 } };
/*
class shooter
{
	public:
	typedef float point[3];
	int id,c;
	static int top=-1;
	point color[9];
	point shape[4];
	point init;
	shooter(point a)
	{
		init[0]=a[0];
		init[1]=a[1];
		init[2]=a[2];
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
		instack();
		setidnc();
	}
	~shooter()
	{
		outstack();
	}
	static void setidnc()
	{
		id=top+1;
		c=rand()%9;
	}
	static void instack()
	{
		top++;
	}
	static void outstack()
	{
		top--;
	}
	void drawshooter()
	{
		glBegin(GL_POLYGON);
			glColor3fv(color[c]);
			glVertex3f(init[0]-0.05,init[1],0);
			glVertex3f(init[0]+0.05,init[1],0);
			glVertex3f(init[0],init[1]+0.1,0);
		glEnd();
	}
	void shoot()
	{
		for(int i=0;i<n;i++)
			shape[i][1]+=0.2;
	}
	
};
int shooter::top=-1;
defense *d = new defense();
koch_devil *kd=new koch_devil();
koch_bombs *kb=new koch_bombs(4,3,0);
koch_bombs *kb1=new koch_bombs(4,3,0);
int stack s[S_MAX];
int top=-1;
void push(int id)
{
	s[top++]=id;
}
void pop()
{
	top--;
}
*/
void glTranslatefv(point v)
{
	glTranslatef(v[0],v[1],v[2]);
}
void stars()
{
	glColor3f(1.0, 1.0, 1.0);
	for (GLint i = 0; i < 25; i++)
	{
		glPushMatrix();
		glTranslatefv(starloc[i]);
		glutSolidSphere(0.03, 15, 20);
		glPopMatrix();
	}	
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
void counterinc()
{
	//cout<< "kb cen y :: " << kb->mycentery << endl;
	float xm=0,ym=0,xm1,ym1;
	for(int i=0;i<3;i++)
	{
		xm+=kb->init[i][0];
		ym+=kb->init[i][1];
	}
	xm/=3;
	ym/=3;
	for(int i=0;i<3;i++)
	{
		xm1+=kb1->init[i][0];
		ym1+=kb1->init[i][1];
	}
	xm1/=3;
	ym1/=3;
	if(fabs(-4-ym)<0.3)
	{	//cout << xm <<"  "<<  d->def[0][0] <<"  "<< d->def[4][0]<< endl;
		if((d->def[0][0]<=xm) && (d->def[4][0]>=xm))
		{
			counter--;
			kb->position=(d->def[0][0]+d->def[4][0])/2;
			kb->reset();
		} 
	}
	if(fabs(-4-ym1)<0.3)
	{
		if((d->def[0][0]<=xm1) && (d->def[4][0]>=xm1))
		{
			counter--;
			kb1->position=(d->def[0][0]+d->def[4][0])/2;
			kb1->reset();
		}

	}
	//cout<< "kb1 cen y :: " << kb1->mycentery << endl;
	//if(fabs(-4-kb1->mycentery)<0.5)
	//	if(d->def[0][0]>=kb1->mycenterx && d->def[4][0]<=kb1->mycenterx)
	//		counter--;
}
void displayer()
{
	static int i=0;
	int f1=0,f2=0;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glClearColor(0.0,0.0,0.0,0.0);
	printw (6, 4.5, 0, "%s : %d", "Lives left :", counter);
	if(counter==0)
		exit(0);
	g=i;
	glPushMatrix();
	glRotatef(kd->theta,0,1,0);
	kd->koch(g,choice);
	glPopMatrix();
	stars();
	d->defender();
	kb->kochb(4,3);
	kb1->kochb(4,3);
	f1=kb->attack(kb->position);
	f2=kb1->attack(kb1->position);
	counterinc();
	if(!f1)
	{
		kb->position=(d->def[0][0]+d->def[4][0])/2;
		posX=kb->position;
	}
	if(!f2)
	{
		kb1->position=4-kb->position;
	}
	glFlush();
	glutSwapBuffers();
	i++;
	if(i==s+1) i=0;
}
void keyboard(unsigned char k, int x, int y)
{
	switch (k)
	{
		case 'e':
			glutReshapeWindow(600,600);
			glutPositionWindow((cx-600)/2, (cy-600)/2);
			glutReshapeWindow(600,600);
			glutPositionWindow((cx-600)/2, (cy-600)/2);
			glFlush();
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
			for(int i=0;i<6;i++)
				d->def[i][0]+=0.25;
			
		break;
		case GLUT_KEY_LEFT:
			for(int i=0;i<6;i++)
				d->def[i][0]-=0.25;
			
		break;
	}
}
void beingIdle()
{
	kd->spintetra();
	glFlush();
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
	glutCreateWindow("RFD : Revenge of Fractal Dimensions");
	glutFullScreen();
	glutDisplayFunc(displayer);
	glutSpecialFunc(specialkeys);
	glutIdleFunc(beingIdle);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(myReshape);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0,0.0,0.0,0.0);
	glutMainLoop();
	return 0;
}
