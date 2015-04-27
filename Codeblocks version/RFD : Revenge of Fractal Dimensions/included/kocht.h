#ifndef KOCHT_H_INCLUDED
#define KOCHT_H_INCLUDED

#include<cmath>
typedef float point[3];
float posX=0.0;
class koch_bombs
{
	public:
	point init[3],color[9];
	int g,choice,position;
	float mycenterx, mycentery;
	int dummy;
	int divisions, coloring;
	public:
	koch_bombs(int a, int b, float p)
	{
		divisions=a;
		coloring=b;
		mycenterx=mycentery=0;
		position=3;
		init[0][0]=0;
		init[0][1]=2.512;
		init[0][2]=0;
		init[1][0]=0.0266;
		init[1][1]=2;
		init[1][2]=0;
		init[2][0]=-0.0266;
		init[2][1]=2;
		init[2][2]=0;
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
		kochb(a,b);
		dummy=attack(p);
	}
	void reset()
	{
		init[0][0]=0;
		init[0][1]=2.512;
		init[0][2]=0;
		init[1][0]=0.0266;
		init[1][1]=2;
		init[1][2]=0;
		init[2][0]=-0.0266;
		init[2][1]=2;
		init[2][2]=0;
		mycenterx=0;
		mycentery=0;
		kochb(divisions,coloring);
		dummy=attack(this->position-0.1*pow(-1,rand()%5));
	}
	void triangle(point a, point b, point c, int m)
	{
		glColor3fv(color[(m+rand()%4)%9]);
		glBegin(GL_TRIANGLES);
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
			diff[i]=(b[i]-a[i]);
		for(int i=0;i<3;i++)
		{
			v1[i]=a[i]+diff[i]/3;
			v2[i]=v1[i]+diff[i]/3;
		}
		double s60 = sin(60 * M_PI *pow(-1,(m%2+g%2+1)) / 180.0);
		double c60 = cos(60 * M_PI *pow(-1,(m%2+g%2+1)) / 180.0);
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
		triangle(a,b,c,m);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_LINES);
			glVertex3fv(a);
			glVertex3fv(b);
		glEnd();
		if(m>0)
		{
			findvertex(c,a,m);
			findvertex(b,c,m);
		}
		else
			return;
	}
	void kochb(int m,int c)
	{
		g=m;
		choice=c;
		triangle(init[0],init[1],init[2],g);
		glFlush();
		if(m>0)
		{
			findvertex(init[0],init[1],m);
			findvertex(init[1],init[2],m);
			findvertex(init[2],init[0],m);
		}
	}
	int attack(float x)
	{
		float a;
		position=x;
		int n;
		a=-fabs(atan(-6.25/x));
		n=((posX<0)?-1:1);
		for(int i=0;i<3;i++)
		{
			this->init[i][0]+=0.15*cos(a)*n;
			this->init[i][1]+=0.15*sin(a);
			this->mycenterx=this->mycentery=0;
			this->mycenterx+=this->init[i][0];
			this->mycentery+=this->init[i][1];
		}
		this->mycenterx/=3;
		this->mycentery/=3;
		glFlush();
		if(this->init[1][1]<=-6)
		{
			this->reset();
			return 0;
		}
		return 1;
	}

};

#endif // KOCHT_H_INCLUDED
