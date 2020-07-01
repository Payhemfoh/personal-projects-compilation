#include<iostream>
#include<ctime>
using namespace std;

struct GameObject
{
	string name;
	int x;
	int y;
	int hp;
	bool alive;
};

GameObject getEnemy();

int main()
{
	GameObject enemy[20];
	int a = 0;
	for (int i = 0; i < 20; i++)
		enemy[i] = getEnemy();
	for(int i=0;i<20;i++)
		if (enemy[i].hp == 0 && enemy[i].alive == false) {
			cout << "Enemy " << a++ << endl;
			cout << "-----------------------" << endl;
			cout << enemy[i].name << endl;
			cout << enemy[i].x << endl;
			cout << enemy[i].y << endl;
			cout << enemy[i].hp << endl;
			cout << enemy[i].alive << endl;
		}
	return 0;
}

GameObject getEnemy()
{
	srand(time(0));
	GameObject x;
	x.name = "Enemy";
	x.x = rand() % 800 + 1;
	x.y = rand() % 600 + 1;
	x.hp = rand() % 11;
	x.alive = static_cast<bool>(rand() % 2);

	return x;
}