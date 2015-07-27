#ifndef DEFENDER_H_INCLUDED
#define DEFENDER_H_INCLUDED
typedef float point[3];
class defense
{
	public:
	point def[4];
	defense()
	{
		//point def[] = { { -1.5, -4, 0 }, { -0.5,-4.0, 0 }, { 0, -3.5, 0 }, { 0.5, -4, 0 }, { 1.5, -4, 0 }, { 0, -4.5, 0 } };
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
	float getXPos()
	{
		return (def[1][0]+def[3][0])/2;
	}
};
#endif // DEFENDER_H_INCLUDED
