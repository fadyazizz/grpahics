#include<GameObject.h>

void GameObject::setUpCollider(int minX,int maxX,int minY,int maxY) {
	vector<int> v1;
	this->maxX = maxX;
	this->minX = minX;
	this->maxY = maxY;
	this->minY = minY;
	v1.push_back(minX);
	v1.push_back(maxX);

	this->collider[0] = v1;

	vector<int> v2;
	v2.push_back(minY);
	v2.push_back(maxY);

	this->collider[1] = v2;

}