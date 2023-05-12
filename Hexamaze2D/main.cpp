#include<Gl/glut.h>
#include<math.h>
#include "hGon.cpp"


void initGL() {
	// Set "clearing" or background color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
	glutFullScreen();
}

void display() {
	float h2y = sqrt(3.0f) * 0.1f + 0.025f;
	glClear(GL_COLOR_BUFFER_BIT);
	HGon h1(0.0f, 0.0f, 0.0f);
	HGon h2(0.35f, h2y, 0.0f);
	HGon h3(0.0f, 2.0f * h2y, 0.0f);
	HGon h4(-0.35f, h2y, 0.0f);
	HGon h5(0.0f, -2.0f * h2y, 0.0f);
	h1.draw();
	h2.draw();
	h3.draw();
	h4.draw();
	h5.draw();
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