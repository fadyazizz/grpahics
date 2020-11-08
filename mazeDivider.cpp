#include<mazeDivider.h>
#include<GL/glut.h>
#include<Engine.h>

void mazeDivider::draw() {
	
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(this->minX, this->minY);
	glVertex2f(this->maxX,this->minY);
	glVertex2f(this->maxX, this->maxY);
	glVertex2f(this->minX,this->maxY);
	glEnd();
	//border
	glColor3f(0.5, 0, 1);
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glVertex2f(this->minX, this->minY);
	glVertex2f(this->maxX, this->minY);
	glVertex2f(this->maxX, this->maxY);
	glVertex2f(this->minX, this->maxY);
	glEnd();
}
mazeDivider::mazeDivider(int minX,int maxX,int minY,int maxY ) {
	this->tag = "mazeDivider";
	this->setUpCollider(minX, maxX, minY, maxY);

}