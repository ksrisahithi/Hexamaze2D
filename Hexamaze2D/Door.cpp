#include<GL/glut.h>
#include<math.h>

extern float hWidth;

class Door {
private:
	float hHeight = sqrtf(3.0f) * 0.5f * hWidth;
	float dh = hWidth * 0.2f;
	float doorHalfWidth = hWidth * 0.3f;
	float doorHalfHeight = dh * 0.5f;
	
	float h = (hHeight + doorHalfHeight) * 0.5f;
	float w = 0.75f * hWidth + sqrtf(3.0f) * 0.5f * doorHalfHeight;
	
public:
	int location[2];
	int rotation;
	bool explored = false;
	bool locked = false;

	Door(int x, int y, int r) {
		this->location[0] = x;
		this->location[1] = y;
		this->rotation = r;
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