
#include<mazeBorder.h>
#include <vector> 
#include<Engine.h>
#include<player.h>
#include<GL/glut.h>
using std::vector;

//void drawLanes() {
//	glColor3f(1.0, 0.0, 0.0);
//
//	glBegin(GL_POLYGON);
//	glVertex2f(10.0, 10.0);
//	glVertex2f(350.0, 80.0);
//	glVertex2f(100.0, 20.0);
//	glVertex2f(200.0, 100.0);
//	glEnd();
//}
vector<GameObject*> objectsInScene;

vector<GameObject*> movementSubscription;
int windowWidth = 540;
int windowHeight = 520;
int gameObjectsInScene = 0;
int mazeBorderSize = (windowWidth - 500) / 2;
bool up = false;
bool down = false;
bool right = false;
bool left = false;
int dx = 1;
int dy = 1;
void init(int lanesNumber) {
	//setting up mazeborders
	int i;
	player* pler=new player;
	objectsInScene.push_back(pler);
	for ( i = 0; i < 4; i++) {
		
		mazeBorder* mB = new mazeBorder(i);
	
		//ptr->draw();
		//std::cout << mB << std::endl;
		objectsInScene.push_back(mB);
	}

}
int addMovement(bool moveIt, int value1,int value2) {
	if (moveIt) {
		return value1 + value2;
	}
	return value1;
}

void collisionEngine() {
	std::cout << "inCollisionEngine" << std::endl;
	for (int i = 0; i < movementSubscription.size(); i++) {
		vector<int> colliderMoveX = movementSubscription.at(i)->collider[0];
		vector<int> colliderMoveY = movementSubscription.at(i)->collider[1];

		int maxXMover = colliderMoveX.at(1);
		maxXMover= addMovement(right, maxXMover, 1);
		maxXMover = addMovement(left, maxXMover, -1);
		int minXMover = colliderMoveX.at(0);
		minXMover= addMovement(right, minXMover, 1);
		minXMover = addMovement(left, minXMover, -1);
		int maxYMover = colliderMoveY.at(1);
		maxYMover = addMovement(up, maxYMover, 1);
		maxYMover = addMovement(down, maxYMover, -1);
		int minYMover = colliderMoveY.at(0);
		minYMover = addMovement(up, minYMover, 1);
		minYMover = addMovement(down, minYMover, -1);
		bool collid = false;
		for (int j = 0; j < objectsInScene.size(); j++) {
			if (objectsInScene.at(i)->tag == movementSubscription.at(i)->tag) {
				continue;
			}
			vector<int> colliderSceneX = objectsInScene.at(j)->collider[0];
			vector<int> colliderSceneY = objectsInScene.at(j)->collider[1];
			int maxXScene = colliderSceneX.at(1);
			int minXScene = colliderSceneX.at(0);
			int maxYScene = colliderSceneY.at(1);
			int minYScene = colliderSceneY.at(0);
			if ((maxXMover > minXScene && maxXMover < maxXScene) || (maxXScene > minXMover && maxXScene < maxXMover)) {
				if ((maxYMover > minYScene && maxYMover < maxYScene) || (maxYScene > minYMover && maxYScene < maxYMover)) {
					collid = true;
				}
			}
		
		}
		if (collid) {
			movementSubscription.at(i)->canMove = false;
		}
		else {
			movementSubscription.at(i)->canMove = true;
		}

	}
	
}
void physicsEngine(int x) {
	if (movementSubscription.size() != 0) {
		collisionEngine();
		movementSubscription.clear();

	}
	glutPostRedisplay();
	
	glutTimerFunc(100, physicsEngine, 0);
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1.0, 0.0, 0.0);

	for (int i = 0; i < objectsInScene.size(); i++) {
		
		//std::cout << (objectsInScene.at(i)) <<std::endl ;
		objectsInScene.at(i)->draw();
		
	}
	//drawLanes();
	glFlush();
	dy = 1;
	dx = 1;
	up = false;
	down = false;
	right = false;
	left = false;
}


void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}
void inputEngine(int key,int x,int y) {
	if (key == GLUT_KEY_UP) {
		up = true;
	}
	if (key == GLUT_KEY_DOWN) {
		down = true;
		dy = -1;
	}
	if (key == GLUT_KEY_RIGHT) {
		right = true;
		
	}
	if (key == GLUT_KEY_LEFT) {
		left = true;
		dx = -1;
	}
}
int main(int argc, char** argv) {
	//GameObject o;
	glutInit(&argc, argv);

	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("Best Game Evaaaaa !!!!!!");
	init(1);
	glutDisplayFunc(display);
	//glutPassiveMotionFunc(passM);	//call the passive motion function
	//glutMouseFunc(actM);			//call the mouse function + which mouse button is being clicked
	//glutKeyboardFunc(key);			//call the keyboard function
	//glutKeyboardUpFunc(keyUp);		//call the keyboard up function
	glutSpecialFunc(inputEngine);			//call the keyboard special keys function
	//glutSpecialUpFunc(speUp);		//call the keyboard special keys up function
	glutTimerFunc(0, physicsEngine, 0);		//call the timer function
	//glPointSize(25);				//change the point size to be 25
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // white background
	gluOrtho2D(0.0, windowWidth, windowHeight, 0.0);

	glutMainLoop();//don't call any method after this line as it will not be reached.
	return 1;
}