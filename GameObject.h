#pragma once
#include <vector> 
#include<iostream>
using std::vector;
class GameObject {
public:
	bool isTrigger = false;
	bool hasSound;
	bool canMove;
	std::string tag;
	void setUpCollider(int minX, int maxX, int minY, int maxY);
	virtual void draw() {}
	virtual void move(int dx,int dy, int totalX, int totalY){}
	virtual void handleTriggerEvent(GameObject* obj, int indexInScene) {}
	//GameObject();


	//collider array should be in the format @0 (min x, max x), @1(min y, max y)
	int minX;
	int maxX;
	int minY;
	int maxY;
	vector<int> collider[2];
	///*GameObject*/(int number);


};
