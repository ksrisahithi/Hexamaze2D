#include<GL/glut.h>
#include<math.h>
#include <cmath>

extern float hWidth;

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

	
public:
	int location[2];
	int rotation;
	bool explored = false;
	bool locked = false;
	int hex1 = -1;
	int hex2 = -1;

	Door(int x, int y, int r, int h1, int h2) {
		this->location[0] = x;
		this->location[1] = y;
		this->rotation = r;
		this->hex1 = h1;
		this->hex2 = h2;
	}

	bool isInsideDoor(float point[2]) {
		// Translate point to local coordinate system
		float xPrime = point[0] - location[0] * w;
		float yPrime = point[1] - location[1] * h;

		// Rotate the point
		float cosAngle = cos(-rotation);
		float sinAngle = sin(-rotation);
		float xfloatPrime = xPrime * cosAngle + yPrime * sinAngle;
		float yfloatPrime = -xPrime * sinAngle + yPrime * cosAngle;

		// Calculate half-width and half-height of the unrotated rectangle
		float halfWidth = doorHalfWidth;
		float halfHeight = doorHalfHeight;

		// Check if the rotated point is inside the unrotated rectangle
		if (std::abs(xfloatPrime) <= halfWidth && std::abs(yfloatPrime) <= halfHeight) {
			return true;
		}

		return false;
	}

	void draw() {
		glPushMatrix();
		glTranslatef(location[0] * w,location[1] * h, 0.0f);
		glRotatef(rotation * 60.0f, 0.0f, 0.0f, 1.0f);
		glBegin(GL_POLYGON);
		if (explored) {
			glColor3f(1.0f, 1.0f, 1.0f);
		}
		else
		{
			glColor3f(0.5f, 0.5f, 0.5f);
		}
		glVertex2f(-doorHalfWidth, doorHalfHeight);
		glVertex2f(doorHalfWidth, doorHalfHeight);
		glVertex2f(doorHalfWidth, -doorHalfHeight);
		glVertex2f(-doorHalfWidth, -doorHalfHeight);
		glEnd();
		glPopMatrix();
	}
};