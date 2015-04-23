typedef float point[3];
float init_size=1;
class koch_devil
{
	public :
	point init_tetr[4];
	static GLfloat theta;
	GLint axis;
	point color[9];
	int g,choice;
	koch_devil()
	{
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
		//theta=0.0;
		axis=1;
	}
	//void spread(point a, point b, point c,point d, int m);
	void init_tetra(float size)
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				init_tetr[i][j]*=init_size;
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
	static void spintetra()
	{
		theta+=2;
		if(theta>360)
			theta-=360;
		glutPostRedisplay();
	}
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
float koch_devil::theta=0;
