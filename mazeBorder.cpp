#include<mazeBorder.h>

#include<iostream>
#include<GL/glut.h>
using namespace std;
float red = 1.0;
float green = 0.0;
float blue = 1.0;

void mazeBorder::draw() {
	//cout << "helloDraw" << endl;

	switch (this->number)
	{
	case 0: {
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(0.0, 0.0);
		glVertex2f(mazeBorderSize, 0.0);
		glVertex2f(mazeBorderSize, windowWidth-mazeBorderSize);
		glVertex2f(0.0, windowWidth-mazeBorderSize);
		glEnd();
		//border
		glColor3f(red, green, blue);
		glLineWidth(3);
		glBegin(GL_LINE_LOOP);
		glVertex2f(0.0, 0.0);
		glVertex2f(20.0, 0.0);
		glVertex2f(20.0, 520.0);
		glVertex2f(0.0, 520.0);
		glEnd();
		break;
	}

	case 1: {
		//cout << "hello1" << endl;
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(windowWidth - mazeBorderSize, 0.0);
		glVertex2f(windowWidth, 0.0);
		glVertex2f(windowWidth, windowWidth - mazeBorderSize);
		glVertex2f(windowWidth - mazeBorderSize, windowWidth - mazeBorderSize);
		glEnd();
		//border
		glColor3f(red, green, blue);
		glLineWidth(3);
		glBegin(GL_LINE_LOOP);
		glVertex2f(windowWidth - mazeBorderSize, 0.0);
		glVertex2f(windowWidth, 0.0);
		glVertex2f(windowWidth, windowWidth - mazeBorderSize);
		glVertex2f(windowWidth - mazeBorderSize, windowWidth - mazeBorderSize);
		glEnd();
		break;

	}
	case 2: {

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(mazeBorderSize, 0.0);
		glVertex2f(windowWidth-mazeBorderSize, 0.0);
		glVertex2f(windowWidth-mazeBorderSize, mazeBorderSize);
		glVertex2f(mazeBorderSize, mazeBorderSize);
		glEnd();
		//border
		glColor3f(red, green, blue);
		glLineWidth(3);
		glBegin(GL_LINE_LOOP);
		glVertex2f(mazeBorderSize, 0.0);
		glVertex2f(windowWidth - mazeBorderSize, 0.0);
		glVertex2f(windowWidth - mazeBorderSize, mazeBorderSize);
		glVertex2f(mazeBorderSize, mazeBorderSize);
		glEnd();
		break;



	}
	case 3: {

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(mazeBorderSize, windowHeight-mazeBorderSize);
		glVertex2f(windowWidth - mazeBorderSize, windowHeight-mazeBorderSize);
		glVertex2f(windowWidth - mazeBorderSize, windowHeight);
		glVertex2f(mazeBorderSize,windowHeight);
		glEnd();
		//border
		glColor3f(red, green, blue);
		glLineWidth(3);
		glBegin(GL_LINE_LOOP);
		glVertex2f(mazeBorderSize, windowHeight - mazeBorderSize);
		glVertex2f(windowWidth - mazeBorderSize, windowHeight - mazeBorderSize);
		glVertex2f(windowWidth - mazeBorderSize, windowHeight);
		glVertex2f(mazeBorderSize, windowHeight);
		glEnd();
		break;
	}
	}
}