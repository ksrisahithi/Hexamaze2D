#include<GL/glut.h>
#include<math.h>

class HGon {
private:
	float w = 0.1f;
	float h = sqrtf(3.0f) * w;
public:
	float location[2];
	float rotation;
	//short doors[6];

	HGon(float x, float y, float r) {
		this->location[0] = x;
		this->location[1] = y;
		this->rotation = r;
	}

	void draw() {
		float winW = glutGet(GLUT_INIT_WINDOW_WIDTH);
		float winH = glutGet(GLUT_INIT_WINDOW_HEIGHT);
		glPushMatrix();
		glTranslatef(location[0],location[1],0.0f);
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 1.0f);
			glVertex2f(-w,h);
			glVertex2f(w, h);
			glVertex2f(2.0f * w, 0.0f);
			glVertex2f(w, -h);
			glVertex2f(-w, -h);
			glVertex2f(-2.0f * w, 0.0f);
		glEnd();
		glPopMatrix();
	}
};