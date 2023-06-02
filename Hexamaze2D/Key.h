#pragma once
class Key {
private:
	void drawShape(float clr[2]);
public:
	float location[2];
	float color[3];
	float size;
	int parentNum;
	bool collected = false;

	Key(int pNum, float loc[2], float sz, float clr[3]);
	void draw();
	bool isInsideKey(float point[2]);
};