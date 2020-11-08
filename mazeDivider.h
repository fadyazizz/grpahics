#pragma once
#include<GameObject.h>
class mazeDivider :public GameObject {
public:
	mazeDivider(int minX, int maxX, int minY, int maxY);
	void draw();
	
};