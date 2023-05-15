#include<GL/glut.h>
#include<math.h>

extern float hWidth;
class HGon {
private:
	float h = sqrtf(3.0f) * 0.5f * hWidth;
	float wt = hWidth * 0.2f;
public:
	int location[2];
	bool explored = false;

	HGon(int x, int y) {
		this->location[0] = x;
		this->location[1] = y;
	}

	void draw() {
		glPushMatrix();
		glTranslatef(
			location[0] * (1.5f * hWidth + (0.5f * wt * sqrtf(3.0f))),
			location[1] * (h + 0.5f * wt), 0.0f
		);
		glBegin(GL_POLYGON);
		if (explored) {
			glColor3f(1.0f, 1.0f, 1.0f);
		}
		else
		{
			glColor3f(0.5f, 0.5f, 0.5f);
		}
			glVertex2f(hWidth * -0.5f,h);
			glVertex2f(hWidth * 0.5f, h);
			glVertex2f(hWidth, 0.0f);
			glVertex2f(hWidth * 0.5f, -h);
			glVertex2f(hWidth * -0.5f, -h);
			glVertex2f(-hWidth, 0.0f);
		glEnd();
		glPopMatrix();
	}
};