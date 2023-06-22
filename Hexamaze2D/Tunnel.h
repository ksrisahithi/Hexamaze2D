#pragma once
#include <math.h>
extern float hWidth;
class Tunnel {
private:
	float h = sqrtf(3.0f) * 0.5f * hWidth;
	float wt = hWidth * 0.2f;

	float location[2];

	float corssProduct(float x1, float y1, float x2, float y2) {
		return (x1 * y2) - (y1 * x2);
	}

	float coord[6][2] = { 
		{ hWidth - (0.8f * hWidth * 0.5f), -(0.8f * hWidth * sqrtf(3.0f) * 0.5f)},
		{ hWidth - (0.2f * hWidth * 0.5f), -(0.2f * hWidth * sqrtf(3.0f) * 0.5f)},
		{0.0f,(0.6f * hWidth / sqrtf(3.0f) ) },
		{ -hWidth + (0.2f * hWidth * 0.5f), -(0.2f * hWidth * sqrtf(3.0f) * 0.5f)},
		{ -hWidth + (0.8f * hWidth * 0.5f), -(0.8f * hWidth * sqrtf(3.0f) * 0.5f)},
		{0.0f,-0.6f * hWidth / sqrtf(3.0f)}
	};

	float flippedCoord[6][2] = {
		{hWidth - (0.8f * hWidth * 0.5f), -(0.8f * hWidth * sqrtf(3.0f) * 0.5f)},
		{hWidth - (0.2f * hWidth * 0.5f), -(0.2f * hWidth * sqrtf(3.0f) * 0.5f)},
		{0.3f * hWidth, (0.3f * hWidth / sqrtf(3.0f))},
		{0.3f * hWidth, sqrtf(3.0f) * 0.5f * hWidth},
		{-0.3f * hWidth, sqrtf(3.0f) * 0.5f * hWidth},
		{-0.3f * hWidth, -(0.3f * hWidth / sqrtf(3.0f))},
	};

	bool isInsidePoly(float vertices[4][2], float point[2]) {
		float v0[2] = { vertices[0][0], vertices[0][1] };
		for (int i = 1; i <= 4; i++) {
			float v1[2] = { vertices[i % 4][0], vertices[i % 4][1] };
			float v2[2] = { vertices[(i + 1) % 4][0], vertices[(i + 1) % 4][1] };

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

public:
	bool explored = false;
	bool flipped = false;
	int doors[6];

	bool isInsideTunnel(float point[2]);

	Tunnel(int d[3]);

	void draw();
};
