#include<GL/glut.h>
#include<math.h>

class Door {
private:
	float doorHalfWidth = 0.06f;
	float doorHalfHeight = 0.02f;
	float hgonW = 0.2f;
	float hgonH = sqrtf(3.0f) * 0.5f * hgonW;
	float h = (hgonH + doorHalfHeight) * 0.5f;
	float w = 0.15f + sqrtf(3.0f) * 0.5f * doorHalfHeight;
	
public:
	float location[2];
	int rotation;

	Door(float x, float y, int r) {
		this->location[0] = x;
		this->location[1] = y;
		this->rotation = r;
	}
	void draw() {
		glPushMatrix();
		glTranslatef(location[0] * w,location[1] * h, 0.0f);
		glRotatef(rotation * 60.0f, 0.0f, 0.0f, 1.0f);
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-doorHalfWidth, doorHalfHeight);
		glVertex2f(doorHalfWidth, doorHalfHeight);
		glVertex2f(doorHalfWidth, -doorHalfHeight);
		glVertex2f(-doorHalfWidth, -doorHalfHeight);
		glEnd();
		glPopMatrix();
	}
};