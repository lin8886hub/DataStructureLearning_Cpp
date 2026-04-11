#include<iostream>
#include<string>
#include<stack>

using namespace std;

template<class T>
class Stack :public stack<T> {
public:
	T pop()
	{
		T tmp = top();
		stack<T>::pop();
		return tmp;
	}
};

class Cell
{
public :
	Cell(int i = 0; int j = 0) {
		x = i;
		y = j;
	}
	bool operator==(const Cell& c) {
		return x == c.x && y == c.y;
	}
private:
	int x;
	int y;
	friend class Maze;
};

class Maze
{
public:
	Maze();
	void exitMaze();
private:
	Cell currentCell, exitCell, entryCell;
	const char exitMarker, entryMarker, visited, passage, wall;
	Stack<Cell> mazeStack;
	char** store; //array of strings;
	void pushUnvisited(int,int);
	friend ostream& operator<<(ostream& , const Maze& );
	int rows, cols;
};

Maze::Maze():exitMarker('e'), entryMarker('m'), visited('.'), passage('0'), wall('1')
{
	Stack<char*> mazeRows;
	char str[80], * s;
	int col, row = 0;
	cout <<
}