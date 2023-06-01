#include<Gl/glut.h>
#include<math.h>
#include<iostream>
#include "HGon.h"
#define PI 3.14159265f

extern float hWidth;

class Pearl {
private:
	const float radius = 0.02f;
	float h = sqrtf(3.0f) * 0.5f * hWidth;
	float location[2];

public:
	int position = 0;
	bool collected = false;
	int parentNum;

	Pearl(float parentLoc[2], int pos, int pNum) {
		this->parentNum = pNum;
		this->position = pos;
		this->location[0] = parentLoc[0] + sinf((-30.0f + 60.0f * (position - 1)) * PI / -180.0f) * 0.5f * hWidth;
		this->location[1] = parentLoc[1] + cosf((-30.0f + 60.0f * (position - 1)) * PI / -180.0f) * 0.5f * hWidth;
	}

	bool isInsidePearl(float point[2]) {
		//std::sqrt(std::pow(x - a, 2) + std::pow(y - b, 2));
		float distance = sqrtf(powf(point[0] - location[0], 2.0f) + powf(point[1] - location[1], 2.0f));
		if (distance <= radius) {
			return true;
		}
		else {
			return false;
		}
	}

	void draw() {
		{
			glPushMatrix();
			glTranslatef(location[0], location[1], 0.0f);
			glBegin(GL_TRIANGLE_FAN);
			glColor3f(0.0f, 0.0f, 1.0f);  // Blue
			glVertex2f(0.0f, 0.0f);       // Center of circle
			int numSegments = 32;
			GLfloat angle;
			for (int i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
				angle = i * 2.0f * PI / numSegments;  // 360 deg for all segments
				glVertex2f(cos(angle) * radius, sin(angle) * radius);
			}
			glEnd();
			glPopMatrix();
		}
		
	}
};