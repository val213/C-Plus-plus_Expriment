/****************************************************
*   Functions to solve mazes.                       *
*                                                   *
*   Datafile must still contain size as first data. *
*                                                   *
*   Four functions are only stubs.                  *
****************************************************/

#include <iostream>
#include <fstream>
#include "Maze.h"
using namespace std;

// The following enumerated type indicates directions within the maze

enum Direction { DOWN, LEFT, UP, RIGHT }; // œ¬◊Û…œ”“À≥ ±’Î

// Overload the prefix increment operator for the Direction enum
Direction& operator++(Direction& direction)
{
	if (direction == RIGHT)
	{
		direction = static_cast<Direction>(0);
		return direction;
	}
	direction = static_cast<Direction>(direction + 1);
	return direction;
}

// Overload the prefix decrement operator for the Direction enum
Direction& operator--(Direction& direction)
{
	if (direction == DOWN)
	{
		direction = static_cast<Direction>(3);
		return direction;
	}
	direction = static_cast<Direction>(direction - 1);
	return direction;
}

// This struct is used for locations within the maze
struct Position
{
	int H, V;
};

// The maze itself is indicated by # for the walls
// All other locations in the maze can be any other character
// Global variables defining the maze to be solved

int mazeWidth, mazeHeight;    // Width and height of the maze
int n;                        // Size of the maze (mazeWidth * mazeHeight)
char* maze = new char[n];     // Array to store the maze
int* posi = new int[n];       // Array to store the path
int* visited = new int[n];    // Array to track visited positions
int i = 0;                    // Index into posi array
// Function prototypes
void FindEntrance(int&);
bool AtExit(int);
void ReportPosition(int);
void WheresRight(int, Direction, int&);
bool Wall(int);
void TurnRight(Direction&);
void MoveForward(int&, Direction);
void WheresAhead(int, Direction, int&);
void TurnLeft(Direction&);

// This function loads the maze from the specified file,
// returning the maze and its dimensions
bool LoadMaze(const char fname[])
{
	ifstream ifs(fname);

	if (ifs.good())
	{
		ifs >> mazeWidth >> mazeHeight;
		maze = new char[mazeWidth * mazeHeight];
		posi = new int[mazeWidth * mazeHeight];
		visited = new int[mazeWidth * mazeHeight];
		// Initialize visited array with all elements set to 0
		memset(visited, 0, sizeof(int) * mazeWidth * mazeHeight);

		for (int i = 0; i < mazeHeight; i++)
		{
			for (int j = 0; j < mazeWidth; j++)
			{
				ifs >> maze[i * mazeWidth + j];
			}
		}

		ifs.close();
		return true;
	}
	else
	{
		cerr << "File not found." << endl;
		return false;
	}
}

// This function solves the maze using the 'hand on left wall'
// rule, printing the maze position as it proceeds
void SolveMaze()
{
	int pos, other;
	Direction heading;

	FindEntrance(pos);
	heading = DOWN;

	while (!AtExit(pos))
	{
		posi[i] = pos;
		visited[pos]++;
		i++;

		// Check if array size is too small
		// if (i >= 289)
		// {
		// 	cout << "array too small\n";
		// 	abort();
		// }

		WheresRight(pos, heading, other); // Get the position to the right
		if (!Wall(other))
		{
			TurnRight(heading);
			MoveForward(pos, heading);
		}
		else
		{
			WheresAhead(pos, heading, other); // Get the position ahead
			if (!Wall(other))
				MoveForward(pos, heading);
			else
				TurnLeft(heading);
		}
	}

	posi[i] = pos;
	visited[pos]++;
	i++;

	// Check if array size is too small
	// if (i >= 400)
	// {
	// 	cout << "array too small\n";
	// 	abort();
	// }

	int counter = 0;
	for (int j = 0; j < i; j++)
	{
		if (posi[j] < 0)
			continue;

		// Skip repeated paths
		if ((j < i - 1) && (visited[posi[j]] > 1) && (visited[posi[j + 1]] > 1))
			continue;

		cout << "Current position: (" << posi[j] / mazeWidth << ',' << posi[j] % mazeWidth << ')' << "visited:" << visited[posi[j]] << endl;
		counter++;
	}

	cout << "total steps:" << counter << endl;
	cout << "Maze solved" << endl;
}

// This function scans the maze array for the first non-wall item
// It assumes that the entrance is in the top row of the maze array
void FindEntrance(int& pos)
{
	pos = 0;
	while (Wall(pos))
		pos++;
}

// This function returns true if the maze position is the exit,
// identified by being in the last row of the array
bool AtExit(int pos)
{
	return (pos >= (mazeHeight - 1) * mazeWidth);
}

// This function displays the position in the maze
// At this time, it specifies the row and column of the array
void ReportPosition(int pos)
{
	cout << "Current position: (" << pos / mazeWidth << ',' << pos % mazeWidth << ')' << endl;
}

// This function takes a maze position and a heading and determines
// the position to the right of this position
void WheresRight(int pos, Direction heading, int& right)
{
	right = pos;
	switch (heading)
	{
	case DOWN:
		right--;
		break;
	case LEFT:
		right -= mazeWidth;
		break;
	case UP:
		right++;
		break;
	case RIGHT:
		right += mazeWidth;
		break;
	}
}

// This function returns true if maze position is a wall
bool Wall(int pos)
{
	return (maze[pos] == '#');
}

// This function changes the heading by turning right
// Take the current heading and adjust so that the direction is to the right
void TurnRight(Direction& heading)
{
	++heading;
}

// This function changes the position in the maze by determining
// the next position in the current direction
void MoveForward(int& pos, Direction heading)
{
	switch (heading)
	{
	case DOWN:
		pos += mazeWidth;
		break;
	case LEFT:
		pos--;
		break;
	case UP:
		pos -= mazeWidth;
		break;
	case RIGHT:
		pos++;
		break;
	}
}

// This function determines the position in the direction
// currently heading
void WheresAhead(int pos, Direction heading, int& ahead)
{
	ahead = pos;
	switch (heading)
	{
	case DOWN:
		ahead += mazeWidth;
		break;
	case LEFT:
		ahead--;
		break;
	case UP:
		ahead -= mazeWidth;
		break;
	case RIGHT:
		ahead++;
		break;
	}
}

// This function changes the heading by turning left
void TurnLeft(Direction& heading)
{
	--heading;
}