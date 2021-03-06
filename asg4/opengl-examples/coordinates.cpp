// $Id: coordinates.cpp,v 1.37 2016-07-20 20:33:42-07 - - $

// Draw line from (0,0) to (1,1).

#include <iostream>
using namespace std;

#include <GL/freeglut.h>
#include <libgen.h>

struct {
   size_t width = 256;
   size_t height = 256;
} window;

void show (const char* ctext, GLfloat xpos, GLfloat ypos) {
   auto utext = reinterpret_cast<const GLubyte*> (ctext);
   void* font = GLUT_BITMAP_HELVETICA_12;
   GLfloat xadjust = glutBitmapLength (font, utext);
   GLfloat yadjust = glutBitmapHeight (font);
   GLfloat xdelta = xadjust / window.width;
   GLfloat ydelta = yadjust / window.height;
   glRasterPos2f (xpos * 0.8 - xdelta, ypos * 0.8 - ydelta);
   glutBitmapString (font, utext);
}

void display() {
   glClearColor (1.0, 1.0, 1.0, 0);
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3ub (0, 0, 0);
   show ("(0,0)", 0, 0);
   show ("(+1,+1)", +1, +1);
   show ("(-1,+1)", -1, +1);
   show ("(+1,-1)", +1, -1);
   show ("(-1,-1)", -1, -1);
   glutSwapBuffers();
}

int main (int argc, char** argv) {
   glutInit (&argc, argv);
   glutInitWindowSize (window.width, window.height);
   glutInitWindowPosition (128, 128);
   glutCreateWindow (basename (argv[0]));
   glutDisplayFunc (display);
   glutMainLoop();
   return 0;
}

