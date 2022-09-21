/*
 * Name: Adam Clements
 * Date Submitted: 9/21/2022
 * Lab Section: 2121-002
 * Assignment Name: Finding Groups with Recursion
 */

#include "Grouping.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//Implement the (parameterized) constructor and findGroup functions below
Grouping::Grouping(string fileName){
	//initialize and open the text file
	ifstream f(fileName);
	//run through each element in the grid in the given text file, 
	//and convert all of the values into integers, placing them into the grid
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			char val;
			f >> val;
			if(val == '.'){
				grid[i][j] = 0;
			}
			else{
				grid[i][j] = 1;
			}
		}
	}
	//file is done being used, so close it out
	f.close();
	//var for later
	int group = 0;
	//run through each value in the newly populated grid array
	//if the value in the array is 1 (meaning that  it is a filled square), run the findGroup function
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(grid[i][j] == 1){
				//add an additional vector to the 2-D vector of groups to be populated
				vector<GridSquare> temp;
				groups.push_back(temp);
				//search the surrounding squares
				findGroup(i,j,group);
				//once this point in the code is reached, all of the members of the 
				//previous group have been populated to the vector, so we can move on to the next group.
				group++;
			}
		}
	}
}

//search the surrounding squares, and determine how many, and which ones, are in groups
//I also added a "group" variable to make it easy to determine which group each square belongs to
void Grouping::findGroup(int row, int col, int group){
	/* Base Cases:
	* the position is out of bounds
	* the position is empty
	* the position is already in a group */
	if(row > 9 || row < 0 || col > 9 || col < 0){
		return;
	}
	else if(grid[row][col] == 0){
		return;
	}
	//if the position is filled, check the adjacent squares
	if(grid[row][col] == 1){
		//once the square has been confirmed to be full, set the value to 0 so that it will be skipped on the next check
		grid[row][col] = 0;
		//create a new grid square for the space, and push it to the groups vector for the current group
		GridSquare temp(row,col);
		groups[group].push_back(temp);
		//checking all adjacent squares
		findGroup(row+1,col,group);
		findGroup(row-1,col,group);
		findGroup(row,col+1,group);
		findGroup(row,col-1,group);
	}
}




//Simple main function to test Grouping
//Be sure to comment out main() before submitting
/*int main()
{
    Grouping input1("input1.txt");
    input1.printGroups();
    
    return 0;
}
*/
//Do not modify anything below

GridSquare::GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square

GridSquare::GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square

//Compare with == operator, used in test cases
bool GridSquare::operator== (const GridSquare r) const
{
    if ((row == r.row) && (col == r.col))
    {
        return true;
    }
    return false;
}

int GridSquare::getRow() //return row value
{
    return row;
}

int GridSquare::getCol() //return column value
{
    return col;
}

//Output using << operator, used in Grouping::printGroups()
//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

Grouping::Grouping() : grid{},groups() {} //Default constructor, no groups

void Grouping::printGroups() //Displays grid's groups of squares
{
    for(int g=0; g<groups.size(); g++)
    {
        cout << "Group " << g+1 << ": ";
        for(int s=0; s<groups[g].size(); s++)
        {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }
}

vector<vector<GridSquare>> Grouping::getGroups() //Needed in unit tests
{
    return groups;
}