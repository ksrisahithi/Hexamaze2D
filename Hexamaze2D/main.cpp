#include<Gl/glut.h>
#include<math.h>
#include<iostream>
#include<cmath>

#include "hGon.cpp"
#include "Door.cpp"

const int KEY_UP = 72;
const int KEY_DOWN = 80;
const int KEY_LEFT = 75;
const int KEY_RIGHT = 77;

extern float hWidth;

HGon hgons[27] = {
	HGon(-6,8),
	HGon(-4,8), HGon(-5,7), HGon(-3,7), HGon(-4,6),
	HGon(0,6), HGon(2,6), HGon(-3,5), HGon(-1,5),
	HGon(1,5),HGon(-4,4),HGon(-2,4), HGon(0,4),
	HGon(2,4),HGon(-1,3),HGon(1,3),HGon(3,3),
	HGon(-2,2),HGon(0,2), HGon(2,2),HGon(-3,1),
	HGon(-1,1),HGon(1,1),HGon(3,1),HGon(-2,0),
	HGon(0,0),HGon(2,0)
};

Door doors[27] = {
	Door(-11,15,1),
	Door(-8,14,0), Door(-9,13,1), Door(-6,12,0), Door(-1,11,-1),
	Door(3,11,-1), Door(-8,10,0), Door(0,10,0), Door(-7,9,-1),
	Door(-5,9,1), Door(-1,9,1), Door(1,9,-1), Door(-3,7,1),
	Door(-1,7,-1), Door(1,7,1), Door(-4,6,0), Door(0,6,0),
	Door(4,6,0), Door(3,5,1), Door(5,5,-1), Door(-2,4,0),
	Door(3,3,-1), Door(5,3,1), Door(-4,2,0), Door(0,2,0),
	Door(4,2,0), Door(-5,1,1)
};

float playerPosition[2] = { 0.0f, 0.0f };
float playerRotation = 0.0f;
float playerSpeed = 0.02f;
float playerRotSpeed = 3.0f;
bool keyStates[256];

void initGL() {
	// Set "clearing" or background color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
	glutFullScreen();
	hgons[25].explored = true;
	doors[24].explored = true;
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix
	glLoadIdentity();                // Reset the model-view matrix
	glPushMatrix();
	glRotatef(-playerRotation, 0.0f, 0.0f, 1.0f);
	glTranslatef(-playerPosition[0], -playerPosition[1], 0.0f);
		for (HGon h : hgons) {
			h.draw();
		}
		for (Door d : doors) {
			d.draw();
		}
	glPopMatrix();
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-hWidth * 0.1f, -hWidth * 0.07f);
	glVertex2f(hWidth * 0.1f, -hWidth * 0.07f);
	glVertex2f(0.0f, hWidth * 0.23f);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-hWidth * 0.1f, -hWidth * 0.07f);
	glVertex2f(hWidth * 0.1f, -hWidth * 0.07f);
	glVertex2f(0.0f, hWidth * 0.23f);
	glEnd();
	
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

/* Callback handler for special keys */
void specialKeys(int key, int x, int y) {
	float rot = (90.0f - playerRotation) * 22.0f / 7.0f / 180.0f;
	switch (key)
	{
	case GLUT_KEY_UP:
		playerPosition[0] -= playerSpeed * cos(rot);
		playerPosition[1] += playerSpeed * sin(rot);
		std::cout << "Player position - " << "X: " << playerPosition[0] << "Y: " << playerPosition[1] << ".\n";
		break;
	case GLUT_KEY_RIGHT:
		playerRotation -= playerRotSpeed;
		std::cout << "Player Rotation: " << playerRotation << ".\n";
		break;
	case GLUT_KEY_LEFT:
		playerRotation += playerRotSpeed;
		std::cout << "Player Rotation: " << playerRotation << ".\n";
		break;
	default:
		break;
	}
	glutPostRedisplay();

}

void specialKeysUp(int key, int x, int y) {
	keyStates[key] = false;
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("hexaMaze");
	initGL();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	glutMainLoop();
	return 0;
}