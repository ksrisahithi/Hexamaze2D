#include<GL/glut.h>
#include<math.h>
#include "Tunnel.h"

extern float hWidth;
extern float bgColor[3];
extern float borderColor[3];

Tunnel::Tunnel(int d[6]) {
	this->location[0] = -3 * (1.5f * hWidth + (0.5f * wt * sqrtf(3.0f)));
	this->location[1] = 5 * (h + 0.5f * wt);
	for (int i = 0; i < 6; i++) {
		this->doors[i] = d[i];
	}
}

bool Tunnel::isInsideTunnel(float point[2]) {
	float poly1[4][2] = {
		{location[0] + coord[0][0],location[1] + coord[0][1]},
		{location[0] + coord[1][0],location[1] + coord[1][1]},
		{location[0] + coord[2][0],location[1] + coord[2][1]},
		{location[0] + coord[5][0],location[1] + coord[5][1]}
	};
	float poly2[4][2] = {
		{location[0] + coord[5][0],location[1] + coord[5][1]},
		{location[0] + coord[2][0],location[1] + coord[2][1]},
		{location[0] + coord[3][0],location[1] + coord[3][1]},
		{location[0] + coord[4][0],location[1] + coord[4][1]}
	};
	float fpoly1[4][2] = {
		{location[0] + flippedCoord[0][0],location[1] + flippedCoord[0][1]},
		{location[0] + flippedCoord[1][0],location[1] + flippedCoord[1][1]},
		{location[0] + flippedCoord[2][0],location[1] + flippedCoord[2][1]},
		{location[0] + flippedCoord[5][0],location[1] + flippedCoord[5][1]}
	};
	float fpoly2[4][2] = {
		{location[0] + flippedCoord[5][0],location[1] + flippedCoord[5][1]},
		{location[0] + flippedCoord[2][0],location[1] + flippedCoord[2][1]},
		{location[0] + flippedCoord[3][0],location[1] + flippedCoord[3][1]},
		{location[0] + flippedCoord[4][0],location[1] + flippedCoord[4][1]}
	};
	if (!flipped) {
		return isInsidePoly(poly1, point) || isInsidePoly(poly2, point);
	}
	else {
		return isInsidePoly(fpoly1, point) || isInsidePoly(fpoly2, point);
	}
}

void Tunnel::draw() {
	glPushMatrix();
	glTranslatef(location[0], location[1], 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.2f,0.2f,0.2f);
	glVertex2f(hWidth * -0.5f, h);
	glVertex2f(hWidth * 0.5f, h);
	glVertex2f(hWidth, 0.0f);
	glVertex2f(hWidth * 0.5f, -h);
	glVertex2f(hWidth * -0.5f, -h);
	glVertex2f(-hWidth, 0.0f);
	glEnd();
	if (flipped == false) {
		glBegin(GL_QUAD_STRIP);
		glColor3f(bgColor[0], bgColor[1], bgColor[2]);
		glVertex2fv(coord[0]);
		glVertex2fv(coord[1]);
		glVertex2fv(coord[5]);
		glVertex2fv(coord[2]);
		glVertex2fv(coord[4]);
		glVertex2fv(coord[3]);
		glEnd();
	}
	else {
		glBegin(GL_QUAD_STRIP);
		glColor3f(bgColor[0], bgColor[1], bgColor[2]);
		glVertex2fv(flippedCoord[0]);
		glVertex2fv(flippedCoord[1]);
		glVertex2fv(flippedCoord[5]);
		glVertex2fv(flippedCoord[2]);
		glVertex2fv(flippedCoord[4]);
		glVertex2fv(flippedCoord[3]);
		glEnd();
	}
	glPopMatrix();
}