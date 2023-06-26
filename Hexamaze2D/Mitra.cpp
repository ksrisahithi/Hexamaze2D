#include<GL/glut.h>
#include<math.h>
#include <cmath>
#define PI 3.14159265f

extern float borderColor[3];
extern float bgColor[3];

class Mitra {
private:
	float location[2];
	float corssProduct(float x1, float y1, float x2, float y2) {
		return (x1 * y2) - (y1 * x2);
	}
public:

	bool collected = false;

	Mitra(float loc[2]) {
		this->location[0] = loc[0];
		this->location[1] = loc[1];
	}

	bool isInsideMitra(float point[2]) {
		float vertices[5][2] = {
			{location[0] - 0.1f, location[1] + 0.045f},
			{location[0] - 0.05f, location[1] + 0.105f},
			{location[0] + 0.05f, location[1] + 0.105f},
			{location[0] + 0.1f, location[1] + 0.045f},
			{location[0], location[1] - 0.105f}
		};

		float v0[2] = { vertices[0][0], vertices[0][1] };
		for (int i = 1; i <= 5; i++) {
			float v1[2] = { vertices[i % 5][0], vertices[i % 5][1] };
			float v2[2] = { vertices[(i + 1) % 5][0], vertices[(i + 1) % 5][1] };

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

	void draw() {
		glPushMatrix();
		glTranslatef(location[0],location[1],0.0f);
		glRotatef(60.0f, 0.0f, 0.0f, 1.0f);
		glColor3f(0.5f, 0.5f, 1.0f);
		glBegin(GL_QUADS);
		glVertex2f(-0.1f, 0.045f);
		glVertex2f(-0.05f, 0.105f);
		glVertex2f(0.05f, 0.105f);
		glVertex2f(0.1f, 0.045f);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.1f, 0.045f);
		glVertex2f(0.1f, 0.045f);
		glVertex2f(0.0f, -0.105f);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(0.2f);
		glVertex2f(-0.1f, 0.045f);
		glVertex2f(-0.05f, 0.105f);
		glVertex2f(0.05f, 0.105f);
		glVertex2f(0.1f, 0.045f);
		glVertex2f(0.0f, -0.105f);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex2f(-0.025f, 0.105f);
		glVertex2f(-0.05f, 0.045f);
		glVertex2f(0.0f, -0.105f);
		glVertex2f(0.05f, 0.045f);
		glVertex2f(0.025f, 0.105f);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(-0.1f, 0.045f);
		glVertex2f(0.1f, 0.045f);
		glEnd();
		glPopMatrix();
	}
};