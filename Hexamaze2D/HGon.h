#ifndef __HGON_H__
#define __HGON_H__
extern float hWidth;
class HGon {
private:
	float h = sqrtf(3.0f) * 0.5f * hWidth;
	float wt = hWidth * 0.2f;

	float corssProduct(float x1, float y1, float x2, float y2) {
		return (x1 * y2) - (y1 * x2);
	}
	
	void drawPattern();

public:
	float location[2];
	bool explored = false;
	int doors[6];
	int designFlag = 0;

	bool isInsideHex(float point[2]);

	HGon(int x, int y, int d[6]);

	void draw();

};
#endif // !1