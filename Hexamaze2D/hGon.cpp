#include<GL/glut.h>
#include<math.h>

extern float hWidth;
class HGon {
private:
	float h = sqrtf(3.0f) * 0.5f * hWidth;
	float wt = hWidth * 0.2f;

	float corssProduct(float x1, float y1, float x2, float y2) {
		return (x1 * y2) - (y1 * x2);
	}

public:
	int location[2];
	bool explored = false;
	int doors[6];

	HGon(int x, int y, int d[6]) {
		this->location[0] = x;
		this->location[1] = y;
		for (int i = 0; i < 6; i++) {
			this->doors[i] = d[i];
		}
	}

	bool isInsideHex(float point[2]) {
		float vertices[6][2] = {
			{location[0] - 0.5f * hWidth, location[1] + h},
			{location[0] + 0.5f * hWidth, location[1] + h},
			{location[0] + hWidth, location[1]},
			{location[0] + 0.5f * hWidth, location[1] - h},
			{location[0] - 0.5f * hWidth, location[1] - h},
			{location[0] - hWidth, location[1]}
		};

		float v0[2] = {vertices[0][0], vertices[0][1]};
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
		glVertex2f(hWidth * -0.5f, h);
		glVertex2f(hWidth * 0.5f, h);
		glVertex2f(hWidth, 0.0f);
		glVertex2f(hWidth * 0.5f, -h);
		glVertex2f(hWidth * -0.5f, -h);
		glVertex2f(-hWidth, 0.0f);
		glEnd();
		glPopMatrix();
	}
};