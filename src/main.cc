#include <iostream>
#include <vector>

using namespace std;

class Vector2
{
public:
	int x;
	int y;
};

class Actor
{
public:
	Vector2 pos;
};

class AStarTile
{
public:	
	Vector2 pos;
	int G;
	int H;
	AStarTile *parentTile;
};


bool map[10][10];

int main(int argc, char** argv) {
	  std::cout << "Hello, World!" << std::endl;
	  for(int i = 0; i < 10; i++)
	  {
			for(int j = 0; j < 10; j++)
			{
				map[i][j] = false;
			}
	  }

	  vector<AStarTile> openFields;

	  Actor actor;
	  actor.pos.x = 0;
	  actor.pos.y = 0;
	  bool done = false;
	  while(!done)
	  {
		
	  }
	  fflush(stdin);
	  getchar();
	  return 0;
}
