#include<GL/glut.h>
#include<math.h>
#include <cmath>

extern float hWidth;
extern float bgColor[3];
extern float borderColor[3];

class Door {
private:
	float hHeight = sqrtf(3.0f) * 0.5f * hWidth;
	float dh = hWidth * 0.2f;
	float doorHalfWidth = hWidth * 0.3f;
	float doorHalfHeight = dh * 0.5f;

	float h = (hHeight + doorHalfHeight) * 0.5f;
	float w = 0.75f * hWidth + sqrtf(3.0f) * 0.5f * doorHalfHeight;

	float corssProduct(float x1, float y1, float x2, float y2) {
		return (x1 * y2) - (y1 * x2);
	}
	const float PI = 22.0f / 7.0f;

public:
	float location[2];
	float rotation;
	bool explored = false;
	bool locked = false;
	int hex1 = -1;
	int hex2 = -1;

	Door(int x, int y, int r, int h1, int h2) {
		this->location[0] = x * w;
		this->location[1] = y * h;
		this->rotation = r * 60.0f;
		this->hex1 = h1;
		this->hex2 = h2;
	}

	bool isInsideDoor(float point[2]) {
		// Translate point to local coordinate system
		float xPrime = point[0] - location[0];
		float yPrime = point[1] - location[1];

		// Rotate the point
		float cosAngle = cosf(-rotation * PI / 180.0f);
		float sinAngle = sinf(-rotation * PI / 180.0f);
		float xfloatPrime = xPrime * cosAngle - yPrime * sinAngle;
		float yfloatPrime = xPrime * sinAngle + yPrime * cosAngle;

		// Calculate half-width and half-height of the unrotated rectangle
		float halfWidth = doorHalfWidth;
		float halfHeight = doorHalfHeight + 0.02f; // increased door height for calculating inside.

		return
			(xfloatPrime >= -halfWidth) &&
			(xfloatPrime <= halfWidth) &&
			(yfloatPrime >= -halfHeight) &&
			(yfloatPrime <= halfHeight);
	}

	void draw() {
		glPushMatrix();
		glTranslatef(location[0], location[1], 0.0f);
		glRotatef(rotation, 0.0f, 0.0f, 1.0f);
		glBegin(GL_POLYGON);
		glColor3fv(bgColor);
		glVertex2f(-doorHalfWidth, doorHalfHeight);
		glVertex2f(doorHalfWidth, doorHalfHeight);
		glVertex2f(doorHalfWidth, -doorHalfHeight);
		glVertex2f(-doorHalfWidth, -doorHalfHeight);
		glEnd();
		if (locked) {
			float blockSize = doorHalfWidth / 4.5f;
			glBegin(GL_QUADS);
			glColor3fv(borderColor);
			glVertex2f(-3.5f*blockSize,doorHalfHeight);
			glVertex2f(-2.5f * blockSize, doorHalfHeight);
			glVertex2f(-2.5f * blockSize, -doorHalfHeight);
			glVertex2f(-3.5f * blockSize, -doorHalfHeight);

			glVertex2f(-1.5f * blockSize, doorHalfHeight);
			glVertex2f(-0.5f * blockSize, doorHalfHeight);
			glVertex2f(-0.5f * blockSize, -doorHalfHeight);
			glVertex2f(-1.5f * blockSize, -doorHalfHeight);

			glVertex2f(1.5f * blockSize, doorHalfHeight);
			glVertex2f(0.5f * blockSize, doorHalfHeight);
			glVertex2f(0.5f * blockSize, -doorHalfHeight);
			glVertex2f(1.5f * blockSize, -doorHalfHeight);

			glVertex2f(3.5f * blockSize, doorHalfHeight);
			glVertex2f(2.5f * blockSize, doorHalfHeight);
			glVertex2f(2.5f * blockSize, -doorHalfHeight);
			glVertex2f(3.5f * blockSize, -doorHalfHeight);
			glEnd();
		}
		glPopMatrix();
	}
};