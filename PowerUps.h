#pragma once
#include<GameObject.h>
class PowerUps :public  GameObject {
public:
	std::string func;
	PowerUps(std::string func,int minX, int maxX, int minY, int maxY);
	void draw();
	

};
