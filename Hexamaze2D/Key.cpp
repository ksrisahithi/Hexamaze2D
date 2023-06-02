#include<GL/glut.h>
#include<math.h>
#include "Key.h"
#define PI 3.14159265f

Key::Key(int pNum, float loc[2], float sz, float clr[3]) {
	this->parentNum = pNum;
	this->size = sz;
	this->color[0] = clr[0];
	this->color[1] = clr[1];
	this->color[2] = clr[2];
	this->location[0] = loc[0];
	this->location[1] = loc[1];
	
}

void Key::drawShape(float clr[3]) {
	glPushMatrix();
	glTranslatef(-1.5f * size, 0.0f, 0.0f);
	glBegin(GL_QUAD_STRIP);
	glColor3f(clr[0], clr[1], clr[2]);
	float angle;
	int numOfSegments = 32;
	float thicknessFac = 0.4f;
	for (int i = 0; i < numOfSegments; i++) {
		angle = i * 2.0f * PI / numOfSegments;  // 360 deg for all segments
		glVertex2f(cosf(angle) * size * (1.0f - thicknessFac), sinf(angle) * size * (1.0f - thicknessFac));
		glVertex2f(cosf(angle) * size, sinf(angle) * size);
	}
	glVertex2f(cosf(0.0f) * size * (1.0f - thicknessFac), sinf(0.0f) * size * (1.0f - thicknessFac));
	glVertex2f(cosf(0.0f) * size, sinf(0.0f) * size);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(size - 0.002f, size * thicknessFac * 0.5f);
	glVertex2f(size * 3.5f, size * thicknessFac * 0.5f);
	glVertex2f(size * 3.5f, size * thicknessFac * -0.5f);
	glVertex2f(size - 0.002f, size * thicknessFac * -0.5f);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(size * 2.0f, size * thicknessFac * -0.5f);
	glVertex2f(size * 2.0f + size * thicknessFac, size * thicknessFac * -0.5f);
	glVertex2f(size * 2.0f + size * thicknessFac, size * thicknessFac * -0.5f - size * thicknessFac);
	glVertex2f(size * 2.0f, size * thicknessFac * -0.5f - size * thicknessFac);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(size * 2.0f + 2.0f * size * thicknessFac, size * thicknessFac * -0.5f);
	glVertex2f(size * 2.0f + 2.0f * size * thicknessFac + size * thicknessFac, size * thicknessFac * -0.5f);
	glVertex2f(size * 2.0f + 2.0f * size * thicknessFac + size * thicknessFac, size * thicknessFac * -0.5f - 2.0f * size * thicknessFac);
	glVertex2f(size * 2.0f + 2.0f * size * thicknessFac, size * thicknessFac * -0.5f - 2.0f * size * thicknessFac);
	glEnd();
	glPopMatrix();
}

void Key::draw() {
	glPushMatrix();
	glTranslatef(location[0], location[1], 0.0f);
	float black[3] = { 0.0f,0.0f,0.0f };
	drawShape(black);
	glTranslatef(0.002f, 0.002f, 0.0f);
	drawShape(color);
	glPopMatrix();
}

bool Key::isInsideKey(float pnt[2]) {
	return
		location[0] - size * 2.0f <= pnt[0] &&
		location[0] + size * 2.0f >= pnt[0] &&
		location[1] - size <= pnt[1] &&
		location[1] + size >= pnt[1];
}