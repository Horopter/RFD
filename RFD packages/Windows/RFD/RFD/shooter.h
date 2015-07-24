#ifndef SHOOTER_H_INCLUDED
#define SHOOTER_H_INCLUDED

#include<cmath>
typedef float point[3];
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
		c=rand()%7;
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
		init[1]+=0.1;
	}
	float getinitx()
	{
		return this->init[0];
	}
	float getinity()
	{
		return this->init[1];
	}
	void putx(float x, float y)
	{
		init[0]=x;
		init[1]=y;
	}

};

#endif // SHOOTER_H_INCLUDED
