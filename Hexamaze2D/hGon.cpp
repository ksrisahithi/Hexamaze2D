#include<GL/glut.h>
#include<math.h>

class HGon {
private:
	float w = 0.2f;
	float h = sqrtf(3.0f) * 0.5f * w;
	float wt = 0.04f;
public:
	int location[2];

	HGon(int x, int y) {
		this->location[0] = x;
		this->location[1] = y;
	}

	void draw() {
		float winW = glutGet(GLUT_INIT_WINDOW_WIDTH);
		float winH = glutGet(GLUT_INIT_WINDOW_HEIGHT);
		glPushMatrix();
		glTranslatef(location[0] * (1.5f * w + (2.0f * wt / sqrtf(3.0f))), location[1] * (h + 0.5f * wt), 0.0f);
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 1.0f);
			glVertex2f(w * -0.5f,h);
			glVertex2f(w * 0.5f, h);
			glVertex2f(w, 0.0f);
			glVertex2f(w * 0.5f, -h);
			glVertex2f(w * -0.5f, -h);
			glVertex2f(-w, 0.0f);
		glEnd();
		glPopMatrix();
	}
};