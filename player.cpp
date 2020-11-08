#include<player.h>
#include<Engine.h>
#include<PowerUps.h>
#include<GL/glut.h>
int speed = 1;
player::player(int minX,int maxX,int minY,int maxY) {
	this->canMove = false;
	this->tag = "player";
	this->setUpCollider(minX, maxX, minY, maxY);
	movementSubscription.push_back(this);
	
}
void player::draw() {
			vector<int> vX = this->collider[0];
			vector<int> vY = this->collider[1];
			vector<int> vx;
			vx.push_back(this->minX);
			vx.push_back(this->maxX);

			this->collider[0] = vx;



			vector<int> vy;
			vy.push_back(this->minY );
			vy.push_back(this->maxY);

			this->collider[1] = vy;
			
			glColor3f(0.0, 1.0, 0.0);
			glBegin(GL_POLYGON);
			glVertex2f(this->minX, this->minY);
			glVertex2f(this->maxX, this->minY);
			glVertex2f(this->maxX, this->maxY);
			glVertex2f(this->minX, this->maxY);
			glEnd();
		
			


	
	
}
void player::move(int dx,int dy,int totalX,int totalY) {
	this->maxX = this->maxX + dx*speed;
	this->minX = this->minX + dx * speed;
	this->maxY = this->maxY + dy * speed;
	this->minY = this->minY + dy * speed;

	this->moveX = totalX;
	this->moveY = totalY;
	
}
void player::handleTriggerEvent(GameObject* obj,int indexInScene) {
	std::cout << "trigger" << std::endl;
	if (obj->tag == "powerUps") {
		PowerUps* p = (PowerUps*)obj;
		std::string func = p->func;
		if (func == "speed") {
			speedTaken = true;
			std::cout << speed << std::endl;
			if (speed < 2) { 
				speed *= 2;
			}
			
		}
		if (func == "bridge") {
			bridgeTaken = true;
			std::cout << "bridge" << std::endl;
			int index = -1;
			for (int i = 0; i < objectsInScene.size(); i++) {
				GameObject* object = objectsInScene.at(i);
				if (object->tag == "mazeDivider") {
					
					if (object->minY < this->minY) {
						std::cout << "found!" << std::endl;
						std::cout << i << std::endl;
						index = i;
						break;
					}
				}
			}
			if (index > 0) {
				GameObject* divider = objectsInScene.at(index);
				divider->setUpCollider(mazeBorderSize, this->minX, divider->minY, divider->maxY);
				GameObject* divider1 = objectsInScene.at(index+1);
				divider1->setUpCollider(this->minX + 30, windowWidth - mazeBorderSize, divider->minY, divider->maxY);
			}
			
		}
	}
}