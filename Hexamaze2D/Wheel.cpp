#include<GL/glut.h>
#include<math.h>
#include <cmath>
#define PI 3.14159265f

extern float borderColor[3];
extern float bgColor[3];

class Wheel {
private: 
	int noOfDivs = 16;
	float radius = 0.1f;
	float location[2];

public:
	bool playerInside = false;
	Wheel(float loc[2]) {
		this->location[0] = loc[0];
		this->location[1] = loc[1];
	}
	bool isInsideWheel(float point[2]) {
		float distance = sqrtf(powf(point[0] - location[0], 2.0f) + powf(point[1] - location[1], 2.0f));
		if (distance <= radius) {
			return true;
		}
		else {
			return false;
		}
	}
	void draw() {
		glPushMatrix();
		glTranslatef(location[0], location[1], 0.0f);
		glBegin(GL_TRIANGLE_FAN);
		glColor3fv(borderColor);  // Blue
		glVertex2f(0.0f, 0.0f);       // Center of circle
		GLfloat angle;
		for (int i = 0; i <= noOfDivs; i++) { // Last vertex same as first vertex
			angle = i * 2.0f * PI / noOfDivs;  // 360 deg for all segments
			glVertex2f(cos(angle) * radius, sin(angle) * radius);
		}
		glEnd();
		glColor3fv(bgColor);
		for (int i = 0; i < 8; i++) {
			glPushMatrix();
			glRotatef(45.0f * i, 0.0f, 0.0f, 1.0f);
			glBegin(GL_TRIANGLES);
			glVertex2f(-0.2f * radius, 0.8f * radius);
			glVertex2f(0.2f * radius, 0.8f * radius);
			glVertex2f(0.0f, 0.2f * radius);
			glEnd();
			glPopMatrix();
		}
		glPopMatrix();
	}
};