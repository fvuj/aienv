#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

template <class T>
inline std::string convertToString (const T& _t)
{
	std::stringstream ss;
	ss << _t;
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

	float Length()
	{
		return sqrt((float)(x*x + y*y));
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

	int GetG()
	{
		if(parentTile != NULL)
		{
			if(G != 0)
				return G;
			G = 10 + parentTile ->GetG();
			return 10 + parentTile ->GetG();
		}
		else
		{
			G = 0;
			return 0;
		}
	}

	void PrintPath()
	{
		cout << pos.ToString() << endl;
		if(parentTile != NULL)
		{
			parentTile->PrintPath();
		}
	}
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
		  cout << "End point is at " + endPoint.ToString() << endl;
	  }

	  vector<AStarTile> openFields;
	  vector<AStarTile> closedFields;
	  AStarTile startingTile;
	  startingTile.pos = actor.pos;
	  startingTile.G = 0;
	  startingTile.H = (int)(startingTile.pos - endPoint).Length();
	  startingTile.parentTile = NULL;
	  openFields.push_back(startingTile);
	  bool done = false;
	  while(!done)
	  {
		  int lowestF = openFields[0].GetG() + openFields[0].H;
		  AStarTile lowestTile = openFields[0];
		  int lowestIndex = 0;
		  for(int i = 1 ; i < openFields.size(); i++)
		  {
			  if(openFields[i].G + openFields[i].H > lowestF)
			  {
					lowestF = openFields[i].GetG() + openFields[i].H;
					lowestTile = openFields[i];
					lowestIndex = i;
			  }
		  }
		  openFields.erase(openFields.begin()+lowestIndex);
		  closedFields.push_back(lowestTile);
		  cout << "Adding tile to closed list: " + lowestTile.pos.ToString() << endl;
		  for(int x = lowestTile.pos.x - 1; x <= lowestTile.pos.x + 1; x++)
		  {
			  if(x < 0 || x >= 10)
				  continue;

			  for(int y = lowestTile.pos.y - 1; y <= lowestTile.pos.y + 1; y++)
			  {
				  if(y < 0 || y >= 10)
						continue;

				  if(y == lowestTile.pos.y && x == lowestTile.pos.x)
						continue;

				  if(y == endPoint.y && x == endPoint.x)
				  {
					  AStarTile endTile;
					  endTile.pos.x = x;
					  endTile.pos.y = y;
					  endTile.parentTile = &lowestTile;
					  openFields.push_back(endTile);
					  done = true;
					  break;
				  }

				  if(map[x][y] == false)
				  {
					  bool inClosed = false;
					  for(int i = 0 ; i < closedFields.size(); i++)
					  {
							if(closedFields[i].pos.x == x && closedFields[i].pos.y == y)
							{
								inClosed = true;
								break;
							}
					  }
					  if(inClosed)
						  continue;

					  AStarTile newTile;
					  newTile.parentTile = &lowestTile;
					  newTile.pos.x = x;
					  newTile.pos.y = y;
					  newTile.G = 0;
					  newTile.H = (int)(newTile.pos - endPoint).Length();
					  cout << "Inspecting Tile: " + newTile.pos.ToString() << endl;

					  bool inOpen = false;
					  for(int i = 0 ; i < openFields.size(); i++)
					  {
							if(openFields[i].pos.x == x && openFields[i].pos.y == y)
							{
								  inOpen = true;
								  if(openFields[i].GetG() > newTile.GetG())
								  {
									  openFields[i].parentTile = newTile.parentTile;
								  }
							}
					  }
					  if(!inOpen)
					  {
						  openFields.push_back(newTile);
						  cout << "Adding Tile to open list: " + newTile.pos.ToString() << endl;
					  }
				  }
			  }
			  if(done)
				  break;
		  }

	  }
	  cout << "Path found" << endl;
	  openFields[openFields.size() -1].PrintPath();
	  fflush(stdin);
	  getchar();
	  return 0;
}
