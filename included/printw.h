//-------------------------------------------------------------------------
//  Draws a string at the specified coordinates.
//-------------------------------------------------------------------------
// Courtesy of Ali BaderEddin. Shared in agreement with GNU GPL License.
#include <stdio.h>    //  Standard Input\Output C Library
#include <stdarg.h>   //  To use functions with variables arguments
#include <stdlib.h>   //  for malloc
#include <malloc.h>   // in case malloc is not available. comment this out if stdlib does the work for you.
int _vscprintf (const char * format, va_list pargs) // Portability courtesy of ismail on stackoverflow
{ 
      int retval; 
      va_list argcopy; 
      va_copy(argcopy, pargs); 
      retval = vsnprintf(NULL, 0, format, argcopy); 
      va_end(argcopy); 
      return retval; 
}
GLvoid *font_style = GLUT_BITMAP_HELVETICA_18;
void printw (float x, float y, float z, char const* format, ...)
{
    va_list args;   //  Variable argument list
    int len;        // String length
    int i;          //  Iterator
    char * text;    // Text
 
    //  Initialize a variable argument list
    va_start(args, format);
 
    //  Return the number of characters in the string referenced the list of arguments.
    // _vscprintf doesn't count terminating '\0' (that's why +1)
    len = _vscprintf(format, args) + 1;
 
    //  Allocate memory for a string of the specified size
    text = (char*)malloc(len * sizeof(char));
 
    //  Write formatted output using a pointer to the list of arguments
    vsnprintf(text, len, format, args);
 
    //  End using variable argument list
    va_end(args);
 
    //  Specify the raster position for pixel operations.
    glRasterPos3f (x, y, z);
 
    //  Draw the characters one by one
    for (i = 0; text[i] != '\0'; i++)
    glutBitmapCharacter(font_style, text[i]);
 
    //  Free the allocated memory for the string
    free(text);
}
