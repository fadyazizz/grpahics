#pragma once
#include <vector> 
#include<iostream>
using std::vector;
class GameObject {
public:
	bool isTrigger;
	bool hasSound;
	bool canMove;
	std::string tag;
	virtual void draw() {}
	//GameObject();


	//collider array should be in the format @0 (min x, max x), @1(min y, max y)
	vector<int> collider[2];
	///*GameObject*/(int number);


};
