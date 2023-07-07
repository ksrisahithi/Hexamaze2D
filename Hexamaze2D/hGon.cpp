#include<GL/glut.h>
#include<math.h>
#include "HGon.h"

extern float hWidth;
extern float bgColor[3];
extern float borderColor[3];
extern float patternColor1[3];
extern float patternColor2[3];

HGon::HGon(int x, int y, int d[6]) {
	this->location[0] = x * (1.5f * hWidth + (0.5f * wt * sqrtf(3.0f)));
	this->location[1] = y * (h + 0.5f * wt);
	for (int i = 0; i < 6; i++) {
		this->doors[i] = d[i];
	}
}

bool HGon::isInsideHex(float point[2]) {
	float vertices[6][2] = {
		{location[0] - 0.5f * hWidth, location[1] + h},
		{location[0] + 0.5f * hWidth, location[1] + h},
		{location[0] + hWidth, location[1]},
		{location[0] + 0.5f * hWidth, location[1] - h},
		{location[0] - 0.5f * hWidth, location[1] - h},
		{location[0] - hWidth, location[1]}
	};

	float v0[2] = { vertices[0][0], vertices[0][1] };
	for (int i = 1; i <= 6; i++) {
		float v1[2] = { vertices[i % 6][0], vertices[i % 6][1] };
		float v2[2] = { vertices[(i + 1) % 6][0], vertices[(i + 1) % 6][1] };

		float vector1[2] = { v1[0] - v0[0], v1[1] - v0[1] };
		float vector2[2] = { v2[0] - v0[0], v2[1] - v0[1] };
		float vectorP[2] = { point[0] - v0[0], point[1] - v0[1] };

		float cross1 = this->corssProduct(vector1[0], vector1[1], vectorP[0], vectorP[1]);
		float cross2 = this->corssProduct(vector1[0], vector1[1], vector2[0], vector2[1]);

		if (cross1 * cross2 < 0)
			return false;

		v0[0] = v1[0];
		v0[1] = v1[1];
	}

	return true;
}

void HGon::draw() {
	glPushMatrix();
	glTranslatef(location[0], location[1], 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(bgColor[0], bgColor[1], bgColor[2]);
	glVertex2f(hWidth * -0.5f, h);
	glVertex2f(hWidth * 0.5f, h);
	glVertex2f(hWidth, 0.0f);
	glVertex2f(hWidth * 0.5f, -h);
	glVertex2f(hWidth * -0.5f, -h);
	glVertex2f(-hWidth, 0.0f);
	glEnd();
	for (int i = 0; i < 6; i++) {
		glPushMatrix();
		glRotatef(i * 60.0f, 0.0f, 0.0f, 1.0f);
		glBegin(GL_POLYGON);
		glColor3fv(borderColor);
		glVertex2f(-0.5f*hWidth,h);
		glVertex2f(0.5f * hWidth, h);
		glVertex2f(0.45f * hWidth, h * 0.9f);
		glVertex2f(-0.45f * hWidth, h * 0.9f);
		glEnd();
		glPopMatrix();
	}
	drawPattern();
	glPopMatrix();
}

void HGon::drawPattern() {
	GLfloat angle;
	switch (designFlag)
	{
	case 1: 
		for (int a = 0; a < 8; a++) 
		{
			glPushMatrix();
			glRotatef(a * 45.0f, 0.0f, 0.0f, 1.0f);
			if (a % 2 == 1) {
				glBegin(GL_TRIANGLES);
				glColor3fv(patternColor1);
				glVertex2f(0.0f, 0.0f);
				glVertex2f(-0.5f * hWidth * 0.25f, h * 0.25f);
				glVertex2f(0.0f, 0.5f * h);
				glColor3fv(patternColor2);
				glVertex2f(0.0f, 0.0f);
				glVertex2f(0.5f * hWidth * 0.25f, h * 0.25f);
				glVertex2f(0.0f, 0.5f * h);
				glEnd();
			}
			else {
				glBegin(GL_TRIANGLES);
				glColor3fv(patternColor1);
				glVertex2f(0.0f, 0.0f);
				glVertex2f(-0.5f * hWidth * 0.25f, h * 0.25f);
				glVertex2f(0.0f, 0.75f * h);
				glColor3fv(patternColor2);
				glVertex2f(0.0f, 0.0f);
				glVertex2f(0.5f * hWidth * 0.25f, h * 0.25f);
				glVertex2f(0.0f, 0.75f * h);
				glEnd();
			}
			glPopMatrix();
		}
		break;
	case 0:
		glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
		glColor3fv(patternColor2);
		glVertex2f(0.0f, 0.0f);
		for (int i = 0; i <= 32; i++) {
			angle = i * 2.0f * 3.14f / 32.0f;
			glVertex2f(cosf(angle) * 0.625f * h, sinf(angle) * 0.625f * h);
		}
		glEnd();
		glBegin(GL_TRIANGLE_FAN);
		glColor3fv(bgColor);
		glVertex2f(0.0f, 0.0f);
		for (int i = 0; i <= 32; i++) {
			angle = i * 2.0f * 3.14f / 32.0f;
			glVertex2f(cosf(angle) * 0.55f * h, sinf(angle) * 0.55f * h);
		}
		glEnd();
		for (int a = 0; a < 6; a++)
		{
			glPushMatrix();
			glRotatef(a * 60.0f, 0.0f, 0.0f, 1.0f);
			glBegin(GL_POLYGON);
			glColor3fv(patternColor1);
			glVertex2f(0.0f, 0.0f);
			glVertex2f(-0.4f * hWidth * 0.25f, h * 0.25f);
			glVertex2f(0.0f, 0.75f * h);
			glVertex2f(0.4f * hWidth * 0.25f, h * 0.25f);
			glEnd();
			glPopMatrix();
		}
		glBegin(GL_TRIANGLE_FAN);
		glColor3fv(patternColor2);
		glVertex2f(0.0f, 0.0f);
		for (int i = 0; i <= 32; i++) {
			angle = i * 2.0f * 3.14f / 32.0f;
			glVertex2f(cosf(angle) * 0.02f, sinf(angle) * 0.02f);
		}
		glEnd();
		glPopMatrix();
		break;
	default:
		break;
	}
}