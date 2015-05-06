#ifndef PRINTW_H_INCLUDED
#define PRINTW_H_INCLUDED

#include<string.h>
class printer
{
	public:
	GLvoid *font_styles;
	printer()
	{
		font_styles = GLUT_BITMAP_HELVETICA_18;
	}
	void printw(float x, float y, int num, const char *st)
	{
		int len,i;
		char cmdbuf[500];
		glRasterPos2f(x,y);
		_snprintf_s(cmdbuf, sizeof(cmdbuf), "%s :: %d",st, num);
		len=strlen(cmdbuf);
		for(i=0;i<len;i++)
		{
			glutBitmapCharacter(font_styles,cmdbuf[i]);
		}
	}
};
#endif // PRINTW_H_INCLUDED
