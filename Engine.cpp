
#include<mazeBorder.h>
#include <vector> 
#include<Engine.h>
#include<player.h>
#include<mazeDivider.h>
#include <time.h>
#include<PowerUps.h>
#include<GL/glut.h>
using std::vector;


vector<GameObject*> objectsInScene;

vector<GameObject*> movementSubscription;
int windowWidth = 540;
int windowHeight = 520;
int gameObjectsInScene = 0;
int mazeBorderSize = (windowWidth - 500) / 2;
int timeSinceStart=0;
int dx = 0;
int dy = 0;
int totalX = 0;
int totalY = 0;
bool moveIt=false;
int elFagwaWidth = 30;
int dividerheight = 5;
int timeSinceUpdate = 0;
int lanesNumber = 5;
bool speedTaken = false;
bool bridgeTaken = false;
void createLanes(int lanesNumber) {
	int laneHeight = (windowHeight - 2 * mazeBorderSize) / lanesNumber;
	int fromWhereToWhere = (windowWidth - 2 * mazeBorderSize) - elFagwaWidth;

	for (int i = 0; i < lanesNumber - 1; i++) {
		int elFagwa = (rand() % fromWhereToWhere) + elFagwaWidth;
		int dividerY = windowHeight - (laneHeight * (i + 1)) - (1 * mazeBorderSize) + dividerheight;
		mazeDivider* prt1 = new mazeDivider(mazeBorderSize, elFagwa, dividerY - dividerheight, dividerY);
		mazeDivider* prt2 = new mazeDivider(elFagwa + elFagwaWidth, windowWidth - mazeBorderSize, dividerY - dividerheight, dividerY);
		objectsInScene.push_back(prt1);
		objectsInScene.push_back(prt2);


	}
}
void createPowerUps(int lanesNumber) {
	for (int i = 0; i < 2; i++) {
		std::string type = "";
		if (i % 2 == 0) {
			type = "speed";
		}
		else {
			type = "bridge";
		}

		int laneHeight = (windowHeight - 2 * mazeBorderSize) / lanesNumber;
		int powerY = rand() % (lanesNumber - 1);
		int powerX = rand() % (windowWidth - mazeBorderSize-30);
		powerX = powerX + mazeBorderSize;
		powerY++;
		int yPosition = (windowHeight - mazeBorderSize) - (powerY * laneHeight);
		PowerUps* p= new PowerUps(type, powerX, powerX + 30, yPosition - 30, yPosition);
		if (i % 2 == 0 && !speedTaken) {
			objectsInScene.push_back(p);
		}
		if (!(i % 2 == 0) && !bridgeTaken) {
			objectsInScene.push_back(p);
		
		}
	}

	

}

void init(int lanesNumber) {
	//setting up mazeborders
	int i;
	player* pler=new player(30,55,480,495);
	objectsInScene.push_back(pler);
	srand((unsigned)time(NULL));
	for ( i = 0; i < 4; i++) {
		mazeBorder* mB = new mazeBorder(i);
		objectsInScene.push_back(mB);
	}
	createLanes(lanesNumber);
	createPowerUps(lanesNumber);
	
}
int addMovement(bool moveIt, int value1,int value2) {
	if (moveIt) {
		return value1 + value2;
	}
	return value1;
}

void collisionEngine() {
	for (int i = 0; i < movementSubscription.size(); i++) {
		vector<int> colliderMoveX = movementSubscription.at(i)->collider[0];
		vector<int> colliderMoveY = movementSubscription.at(i)->collider[1];
		GameObject* mover = movementSubscription.at(i);
		int maxXMover = mover->maxX+dx;
		int minXMover = mover->minX+dx;
		int maxYMover = mover->maxY+dy;
		int minYMover = mover->minY+dy;
		bool collid = false;
		for (int j = 0; j < objectsInScene.size(); j++) {
			if (objectsInScene.at(j)->tag == movementSubscription.at(i)->tag) {
				continue;
			}
			vector<int> colliderSceneX = objectsInScene.at(j)->collider[0];
			vector<int> colliderSceneY = objectsInScene.at(j)->collider[1];
			int maxXScene = colliderSceneX.at(1);
			int minXScene = colliderSceneX.at(0);
			int maxYScene = colliderSceneY.at(1);
			int minYScene = colliderSceneY.at(0);
			if (((maxXMover >=minXScene && maxXMover <= maxXScene) || (maxXScene >= minXMover && maxXScene <= maxXMover))) {
				if (((maxYMover >= minYScene && maxYMover <= maxYScene) || (maxYScene >= minYMover && maxYScene <= maxYMover))) {
					std::cout << "Collision!" << std::endl;
					if (objectsInScene.at(j)->isTrigger) {
						
						mover->handleTriggerEvent(objectsInScene.at(j), j);
						objectsInScene.erase(objectsInScene.begin()+ j);
					}
					else {
						collid = true;
					}
					
				}
			}
		
		}
		if (!collid) {
			objectsInScene.at(i)->move(dx, dy,totalX,totalY);
		}
		

	}
	
}
void changeElFagwa() {
	int dividerCount = 0;
	int startIndex = 0;
	bool Entered = false;

	for (int i = 0; i < objectsInScene.size(); i++) {
		if (objectsInScene.at(i)->tag == "mazeDivider") {
			dividerCount++;
			if (!Entered) {
				Entered = true;
				startIndex = i;
			}
			
		}

	}
	objectsInScene.erase(objectsInScene.begin() + startIndex, objectsInScene.begin() + startIndex + dividerCount);
	createLanes((dividerCount / 2) + 1);
}
void changePowerUps() {
	
	
	int indexFirstPowerUp = -1;
	int indexSecondPowerUp = -1;
	bool entered = false;
	for (int i = 0; i < objectsInScene.size(); i++) {
		if (objectsInScene.at(i)->tag == "powerUps") {
			if (!entered) {
				
				indexFirstPowerUp = i;
				objectsInScene.erase(objectsInScene.begin() + indexFirstPowerUp);
				i--;
			}
			else {
				
				indexSecondPowerUp = i;
				objectsInScene.erase(objectsInScene.begin() + indexSecondPowerUp);
			}
			
		}
	}
	
	
	createPowerUps(lanesNumber);
}
void TimedEvents() {
	if (timeSinceStart - timeSinceUpdate>10000) {
		changeElFagwa();
		changePowerUps();
	timeSinceUpdate = timeSinceStart;
	}
}
void physicsEngine(int x) {
	if (moveIt) {
		moveIt = false;
		collisionEngine();
	}
	TimedEvents();
	glutPostRedisplay();
	timeSinceStart = timeSinceStart + 1;
	glutTimerFunc(1, physicsEngine, 0);
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < objectsInScene.size(); i++) {
		objectsInScene.at(i)->draw();
	}
	glFlush();
}

void inputEngine(int key,int x,int y) {
	dy = 0; dx = 0;
	if (key == GLUT_KEY_UP) {
		totalY--;
		dy=-2;
	}
	if (key == GLUT_KEY_DOWN) {
		totalY++;
		dy = 2; 
	}
	if (key == GLUT_KEY_RIGHT) {
		totalX++;
		dx=2;
		
	}
	if (key == GLUT_KEY_LEFT) {
		totalX--;
		dx=-2 ;
	}
	moveIt = true;
}

int main(int argc, char** argv) {
	//GameObject o;
	glutInit(&argc, argv);

	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("Best Game Evaaaaa !!!!!!");
	init(lanesNumber);
	glutDisplayFunc(display);
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