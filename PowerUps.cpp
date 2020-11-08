#include<PowerUps.h>
#include<GL/glut.h>
PowerUps::PowerUps(std::string func,int minX,int maxX,int minY,int maxY) {
	this->setUpCollider(minX, maxX, minY, maxY);
	this->tag = "powerUps";
	this->isTrigger = true;
	this->func = func;
}

void PowerUps::draw() {
	glColor3f(1.0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(this->minX, this->minY);
	glVertex2f(this->maxX, this->minY);
	glVertex2f(this->maxX, this->maxY);
	glVertex2f(this->minX, this->maxY);
	glEnd();
	//border
	glColor3f(0, 0, 0);
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(this->minX, this->minY);
	glVertex2f(this->maxX, this->minY);
	glVertex2f(this->maxX, this->maxY);
	glVertex2f(this->minX, this->maxY);
	glEnd();
}