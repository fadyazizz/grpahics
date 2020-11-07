#include<player.h>
#include<Engine.h>
#include<GL/glut.h>
player::player() {
	this->canMove = false;
	this->tag = "player";
	vector<int> v1;
	v1.push_back(25);
	v1.push_back(45);

	this->collider[0] = v1;

	vector<int> v2;
	v2.push_back(475);
	v2.push_back(495);

	this->collider[1] = v2;
	
}
void player::draw() {
	vector<int> vX = this->collider[0];
	vector<int> vY = this->collider[1];
	if (up || down || right || left) {
		move();

		
		if (this->canMove) {


			vector<int> vx;
			vx.push_back(vX.at(0) + dx);
			vx.push_back(vX.at(1) + dx);

			this->collider[0] = vx;



			vector<int> vy;
			vy.push_back(vY.at(0) - dy);
			vy.push_back(vY.at(1) - dy);

			this->collider[1] = vy;

			glColor3f(0.0, 1.0, 0.0);
			glBegin(GL_POLYGON);
			glVertex2f(vx.at(0), vy.at(0));
			glVertex2f(vx.at(1), vy.at(0));
			glVertex2f(vx.at(1), vy.at(1));
			glVertex2f(vx.at(0), vy.at(1));
			glEnd();
		}
		
	}
	else
	{
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(vX.at(0), vY.at(0));
		glVertex2f(vX.at(1), vY.at(0));
		glVertex2f(vX.at(1), vY.at(1));
		glVertex2f(vX.at(0), vY.at(1));
		glEnd();

	}
	//this->canMove = false;
}
void player::move() {
	movementSubscription.push_back(this);
}