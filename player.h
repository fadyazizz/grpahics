#pragma once
#include<GameObject.h>
class player:public GameObject {
	public:
		int moveX=0;
		int moveY=0;
		
	player();
	player(int minX, int maxX, int minY, int maxY);
	void draw();
	void move(int dx,int dy,int totalX,int totalY);
	void handleTriggerEvent(GameObject* obj, int indexInScene);
};
