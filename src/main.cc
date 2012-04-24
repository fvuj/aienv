#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

template <class T>
inline std::string convertToString (const T& t)
{
	std::stringstream ss;
	ss << t;
	return ss.str();
}


class Vector2
{
public:
	int x;
	int y;

	Vector2 operator+(Vector2 _other)
	{
		Vector2 returnVector;
		returnVector.x = x + _other.x;
		returnVector.y = y + _other.y;
		return returnVector;
	}

	Vector2 operator-(Vector2 _other)
	{
		Vector2 returnVector;
		returnVector.x = x - _other.x;
		returnVector.y = y - _other.y;
		return returnVector;
	}

	string ToString()
	{
		return "(" + convertToString(x) + "|" + convertToString(y) + ")";
	}
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


bool map[10][10] = {false};

int main(int argc, char** argv) {
	  std::cout << "Hello, World!" << std::endl;
	  Actor actor;
	  cout << "This is a simple AStar test" << endl;
	  cout << "Enter start point" << endl;
	  cin >> actor.pos.x;
	  cin >> actor.pos.y;

	  if(actor.pos.x >= 10 || actor.pos.y >= 10)
	  {
		  cout << "Start point out of bounds";
		  return -1;
	  }
	  else
	  {
		  cout << "Start point is at " + actor.pos.ToString();
	  }

	  Vector2 endPoint;
	  cout << "Enter end point" << endl;
	  cin >> endPoint.x;
	  cin >> endPoint.y;

	  if(endPoint.x >= 10 || endPoint.y >= 10)
	  {
		  cout << "End point out of bounds";
		  return -1;
	  }
	  else
	  {
		  cout << "End point is at " + endPoint.ToString();
	  }

	  vector<AStarTile> openFields;
	  vector<AStarTile> closedFields;
	  AStarTile startingTile;
	  startingTile.pos = actor.pos;
	  startingTile.G = 0;
	  startingTile.H = Startin
	  openFields.push_back(startingTile);
	  bool done = false;
	  while(!done)
	  {
			AStarTile 
	  }
	  fflush(stdin);
	  getchar();
	  return 0;
}
