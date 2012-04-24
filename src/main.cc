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


bool map[10][10] = {0};

int main(int argc, char** argv) {
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
