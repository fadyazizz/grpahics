#include<GameObject.h>
#include<iostream>
#include<GL/glut.h>
#include<Engine.h>
class mazeBorder:public GameObject {
public:
	
	int number;
	
	mazeBorder(int number) {
		//std::cout << "inconstructor";
		this->tag = "mazeborder";
		this->number = number;

		switch (number)
		{
		case 0: {
			vector<int> v1;
			v1.push_back(0);
			v1.push_back(mazeBorderSize);

			this->collider[0] = v1;

			vector<int> v2;
			v2.push_back(0);
			v2.push_back(windowHeight);

			this->collider[1] = v2;
			break;
		}

		case 1: {
			vector<int> v1;
			v1.push_back(windowWidth-mazeBorderSize);
			v1.push_back(windowWidth);

			this->collider[0] = v1;

			vector<int> v2;
			v2.push_back(0);
			v2.push_back(windowHeight);

			this->collider[1] = v2;
			break;

		}
		case 2: {
			vector<int> v1;
			v1.push_back(mazeBorderSize);
			v1.push_back(windowWidth-mazeBorderSize);

			this->collider[0] = v1;

			vector<int> v2;
			v2.push_back(0);
			v2.push_back(mazeBorderSize);

			this->collider[1] = v2;
			break;

		}
		case 3: {
			vector<int> v1;
			v1.push_back(mazeBorderSize);
			v1.push_back(windowWidth-mazeBorderSize);

			this->collider[0] = v1;

			vector<int> v2;
			v2.push_back(windowHeight-mazeBorderSize);
			v2.push_back(windowHeight);

			this->collider[1] = v2;
			break;
		}
		}
	}
	
	void draw();
	mazeBorder(){}
};
