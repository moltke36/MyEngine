#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h> 
#include <CoreLib.h>
#include <crtdbg.h>

// const
const int BOUNDARY = 50;
// fields
bool gameOver = false;
int monsterCount;
EngineLib::list<char*>* NameOfMonsters;
EngineLib::Node<char*>* MonsterNameNode;
char* myName = new char[64];
EngineLib::Point2D  playerPosition(0);
int** monsterPosition;
EngineLib::list<int>* MonsterLifeTime;
int newMonsterCount;

// Methods
void InitMonsters();
void PrintPositionInfo();
void UpdateMovement(char input);
void GenerateNewMonster(int _i);
void CheckCollision();
int main() 
{



	// read input number of monster
	printf("The number of initial monsters you want : \n");
	do
	{

		scanf_s("%d", &monsterCount);
		getchar();
		if (monsterCount <= 0)
			printf("Invalid Input! Please enter a number.\n");
	} while (monsterCount <= 0);
	//_CrtSetBreakAlloc(73);
	NameOfMonsters = new EngineLib::list<char*>();
	//NameOfMonsters = new char*[monsterCount]();
	MonsterLifeTime = new EngineLib::list<int>();
	//monsterLifeTime = new int[monsterCount]();
	MonsterNameNode = NameOfMonsters->Gethead();
	for (int i = 0; i < monsterCount; i++)
	{
		char* temp = new char[64];
		//cout << "Input the no." << i << " monster's name: "<<endl;
		printf("Input the no.%d monster's name: ", i);
		
		MonsterLifeTime->InsertList(rand() % 10 + 5);	// life time will be random from 5 to 15
		gets_s(temp, 64);
		//getchar();
		NameOfMonsters->InsertList(temp);
		//printf("Monster Name: %s \n", NameOfMonsters[i]);
	}

	// display all monsters' name
	printf("You get ");
	MonsterNameNode = NameOfMonsters->Gethead();  // Reset Node Point of MonsterName
	for (MonsterNameNode; MonsterNameNode != nullptr; MonsterNameNode = MonsterNameNode->Next)
	{
		// print all name in the console
		printf("%s ", MonsterNameNode->Data);
	}
	printf(", totally %d monsters in the scene.\nPlease input your name: ", monsterCount);
	gets_s(myName, 64);

	// init monster and player
	InitMonsters();
	PrintPositionInfo();
	int c;

	// Main game loop
	char* tempInput = new char[5]();
	do {
		if (!gameOver) {
			printf("Press 'A' to move left, 'D' to move right, 'W' to move up, 'S' to move down\n");
			// get the first character of the char*
			c = gets_s(tempInput, 5)[0];

			if (c != 'a' && c != 'd' && c != 's' && c != 'w') {
				printf("Invalid Input! Please enter again.\n");
			}
			else
			{
				UpdateMovement(c);
				PrintPositionInfo();
			}
		}
		else
		{
			_CrtDumpMemoryLeaks();
			for (size_t i = 0; i < monsterCount; i++)
			{
				delete[] monsterPosition[i];
 				delete[] NameOfMonsters;
			}
			delete [] monsterPosition;
			delete [] NameOfMonsters;
			delete [] MonsterLifeTime;
			printf("\nYou die at (%d, %d), please press 'q' to quit\n", playerPosition.X, playerPosition.Y);
			c = gets_s(tempInput, 5)[0];
			if (c != 'q') {
				printf("Invalid Input! Please enter again.\n");
			}
			delete[] myName;
			delete[] tempInput;
			//delete playerPosition;
			_CrtDumpMemoryLeaks();
		}

		//printf("You input: %c", c);
	} while (c != 'q');

}

void InitMonsters() {
	monsterPosition = new int*[monsterCount]();
	for (size_t i = 0; i < monsterCount; i++)
	{
		monsterPosition[i] = new int[2]();
		// init X pos
		monsterPosition[i][0] = rand() % BOUNDARY - BOUNDARY / 2;
		// init Y pos
		monsterPosition[i][1] = rand() % BOUNDARY - BOUNDARY / 2;

	}
}
void PrintPositionInfo() {
	printf("You are in (%d,%d). Monsters ara in: \n", playerPosition.X, playerPosition.Y);
	MonsterNameNode = NameOfMonsters->Gethead();  // Reset Node Point of MonsterName
	for (size_t i = 0; i < monsterCount; i++)
	{

		printf("%s: (%d, %d) ", MonsterNameNode->Data, monsterPosition[i][0], monsterPosition[i][1]);
		if (i == monsterCount - 1)
			printf("\n");
	}
}

void UpdateMovement(char input) {
	// update player position
	switch (input)
	{
	case 'a': {
		playerPosition.X -= 1;
		if (playerPosition.X < -BOUNDARY / 2)
			playerPosition.X = -BOUNDARY / 2;
		break;
	}

	case 'd': {
		playerPosition.X += 1;
		if (playerPosition.X > BOUNDARY / 2)
			playerPosition.X = BOUNDARY / 2;
		break; }
	case 'w': {
		playerPosition.X += 1;
		if (playerPosition.X > BOUNDARY / 2)
			playerPosition.X = BOUNDARY / 2;
		break; }
	case 's': {
		playerPosition.Y -= 1;
		if (playerPosition.X < -BOUNDARY / 2)
			playerPosition.X = -BOUNDARY / 2;
		break; }
	default:
		break;
	}
	CheckCollision();
	if (!gameOver) {
		// update monster position
		EngineLib::Node<int>* LifeTimeNode = MonsterLifeTime->Gethead();
		MonsterNameNode = NameOfMonsters->Gethead();
		for (int i = 0; i < monsterCount; i++)
		{
			int deltaX = playerPosition.X - monsterPosition[i][0];
			int deltaY = playerPosition.Y - monsterPosition[i][1];
			if (LifeTimeNode->Data > 0) {
				LifeTimeNode->Data--;
				LifeTimeNode = LifeTimeNode->Next;

				if (abs(deltaX) >= abs(deltaY)) {
					if (deltaX > 0)
						monsterPosition[i][0]++;
					else
						monsterPosition[i][0]--;
				}
				else
				{
					if (deltaY > 0)
						monsterPosition[i][1]++;
					else
						monsterPosition[i][1]--;
				}
			}
			else
			{
				printf("\nMonster %s died!\n", MonsterNameNode->Data);
				delete[] monsterPosition[i];
				GenerateNewMonster(i);
			}
			if (MonsterNameNode->Next != nullptr)
			{
				MonsterNameNode = MonsterNameNode->Next;
			}
			
		}

		CheckCollision();
	}

}

void GenerateNewMonster(int _i) {

	char* temp = new char[64];
	// new life time
	MonsterLifeTime->InsertList(rand() % 10 + 5);
	// new respawn name
	sprintf_s(temp, 64, "NewMonster%d", newMonsterCount);
	NameOfMonsters->InsertList(temp);
	// init X pos
	monsterPosition[_i][0] = rand() % BOUNDARY - BOUNDARY / 2;
	// init Y pos
	monsterPosition[_i][1] = rand() % BOUNDARY - BOUNDARY / 2;


	printf("New Monster: %s appears!\n\n", temp);
	newMonsterCount++;
	delete[] temp;
}

void CheckCollision() {
	for (size_t i = 0; i < monsterCount; i++)
	{
		if (playerPosition.X == monsterPosition[i][0] && playerPosition.Y == monsterPosition[i][1]) {
			gameOver = true;
		}
	}
}
