#include<Gl/glut.h>
#include<math.h>
#include "hGon.cpp"


void initGL() {
	// Set "clearing" or background color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
	glutFullScreen();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	HGon hgons[27] = { HGon(-6,8),HGon(-4,8),HGon(-5,7),HGon(-3,-7),HGon(-4,6),
		HGon(0,6),HGon(2,6),HGon(-3,5),HGon(-1,5),HGon(1,5),HGon(-4,4),HGon(-2,4),
		HGon(0,4),HGon(2,4),HGon(-1,3),HGon(1,3),HGon(3,3),HGon(-2,2),HGon(0,2),
		HGon(2,2),HGon(-3,1),HGon(-1,1),HGon(1,1),HGon(3,1),HGon(-2,0),HGon(0,0),HGon(2,0) };
	for (HGon h : hgons )
	{
		h.draw();
	}
	glFlush();
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
	// Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping area to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset the projection matrix
	if (width >= height) {
		// aspect >= 1, set the height from -1 to 1, with larger width
		gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
	}
	else {
		// aspect < 1, set the width to -1 to 1, with larger height
		gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
	}
}

/* Callback handler for normal-key event */
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27:     // ESC key
		exit(0);
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("hexaMaze");
	initGL();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}