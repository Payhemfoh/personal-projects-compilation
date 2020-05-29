/*
	This motherfucker program get input of a map and
	calculate the area and length of the land.
	The inputs are in format of:
	height width
	(map in 2d format)
	. for sea
	# for land
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//global variable: height width and map
int height = 0;
int width = 0;
//null pointer
int** map{ 0 };
//vector to store the calculated block for stick area
vector<int*>areaList{};
//vector to store the calculated block for stick area
vector<int*>lengthList{};

//function prototypes
void createMap();
void getMap();
bool sorting(int*, int*);
bool checkStick(int,int);
int calcArea(int, int);
int calcLength(int, int);

int main(int argc, char** argv)
{
	vector<int*>result = {};
	cin >> height >> width;

	//create the map and get input for map
	createMap();
	getMap();

	//loop for each block
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			//if sea block then skip else start calculate
			if (map[row][col] != 0) {
				//check if the block sticks to others land blocks
				if (checkStick(row, col)) {
					int* cal = new int[2];
					cal[0] = calcArea(row, col);
					cal[1] = calcLength(row, col);
					if (cal[0] == 0 || cal[1] == 0)
						continue;
					else
						result.push_back(cal);
				}
				else {
					int* cal = new int[2];
					cal[0] = 1;
					cal[1] = 4;
					result.push_back(cal);
				}
			}
		}
	}
	
	//sort the result and copy to new sorted vector
	vector<int*>output;
	for (int i = 0; i < result.size(); i++) {
		bool insert = false;
		for (int j = 0; j < output.size(); j++) {
			if (result[i][0] > output[j][0]) {
				output.insert(output.begin() + j, result[i]);
				insert = true;
				break;
			}
			else if (result[i][0] == output[j][0]) {
				if (result[i][1] >= output[j][1]) {
					output.insert(output.begin() + j, result[i]);
					insert = true;
					break;
				}
				else
					continue;
			}
		}
		if (output.size()==0||!insert) {
			output.push_back(result[i]);
		}
	}
	
	//display the sorted result
	for (int i = 0; i < output.size(); i++)
		cout << output[i][0] << " " << output[i][1] << endl;

	//destroy the map
	for (int i = 0; i < height; i++)
		delete[] map[i];
	delete[] map;
	return 0;
}

//create the map
void createMap()
{
	map = new int* [height];
	for (int i = 0; i < height; i++)
		map[i] = new int[width];

	//initialize the map with 0 value
	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			map[row][col] = 0;
}

//get map input
void getMap()
{
	char input = '\0';
	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++) {
			cin >> input;
			if (input == '#')
				map[row][col] = 1;
		}
}

/*
	check if the block stick to others land block
	false for no stick to other land block
	true for stick to other land block
*/
bool checkStick(int row, int col)
{
	bool result = false;
	//check bounder
	//(x,0)
	if (row == 0) {
		//(0,0)
		if (col == 0) {
			if (map[row + 1][col] == 1)
				result = true;
			else if (map[row][col+1] == 1)
				result = true;
		}
		//(width-1,0)
		else if (col == width - 1) {
			if (map[row + 1][col] == 1)
				result = true;
			else if (map[row][col-1] == 1)
				result = true;
		}
		//(x,0)
		else {
			if (map[row + 1][col] == 1)
				result = true;
			else if (map[row][col - 1] == 1)
				result = true;
			else if (map[row][col + 1] == 1)
				result = true;
		}
	}
	//(0,y)
	else if (col == 0) {
		//(0,height-1)
		if (row == height - 1) {
			if (map[row - 1][col] == 1)
				result = true;
			else if (map[row][col + 1] == 1)
				result = true;
		}
		//(0,y)
		else {
			if (map[row + 1][col] == 1)
				result = true;
			else if (map[row - 1][col] == 1)
				result = true;
			else if (map[row][col + 1] == 1)
				result = true;
		}
	}
	//(x,height-1)
	else if (row == height - 1) {
		//(width-1,height-1)
		if (col == width - 1) {
			if (map[row - 1][col] == 1)
				result = true;
			else if (map[row][col - 1] == 1)
				result = true;
		}
		//(x,height-1)
		else {
			if (map[row - 1][col] == 1)
				result = true;
			else if (map[row][col - 1] == 1)
				result = true;
			else if (map[row][col + 1] == 1)
				result = true;
		}
	}
	//(width-1,y)
	else if (col == width - 1) {
		if (map[row + 1][col] == 1)
			result = true;
		else if (map[row][col - 1] == 1)
			result = true;
		else if (map[row - 1][col] == 1)
			result = true;
	}
	//(x,y)
	else {
		if (map[row+1][col] == 1)
			result = true;
		else if (map[row-1][col] == 1)
			result = true;
		else if (map[row][col+1] == 1)
			result = true;
		else if (map[row][col-1] == 1)
			result = true;
	}
	return result;
}

int calcArea(int row, int col)
{
	//check if the block is calculated
	for (int i = 0; i < areaList.size(); i++) {
		if (row == areaList[i][0] && col == areaList[i][1])
			return 0;
	}

	//append the block into checked list
	int* append = new int[2];
	append[0] = row;
	append[1] = col;
	areaList.push_back(append);

	//the area must be 1
	int area = 1;
	vector<int*>block{};
	int* push = new int[2];
	//check bounder
	//(x,0)
	if (row == 0) {
		//(0,0)
		if (col == 0) {
			if (map[row + 1][col] == 1) {
				push[0] = row + 1;
				push[1] = col;
				block.push_back(push);
				push = new int[2];
			}
			else if (map[row][col + 1] == 1) {
				push[0] = row;
				push[1] = col + 1;
				block.push_back(push);
				push = new int[2];
			}
		}
		//(width-1,0)
		else if (col == width - 1) {
			if (map[row + 1][col] == 1) {
				push[0] = row + 1;
				push[1] = col;
				block.push_back(push);
				push = new int[2];
			}
			
			if (map[row][col - 1] == 1) {
				push[0] = row;
				push[1] = col - 1;
				block.push_back(push);
				push = new int[2];
			}
		}
		//(x,0)
		else {
			if (map[row + 1][col] == 1) {
				push[0] = row + 1;
				push[1] = col;
				block.push_back(push);
				push = new int[2];
			}
			
			if (map[row][col - 1] == 1) {
				push[0] = row;
				push[1] = col - 1;
				block.push_back(push);
				push = new int[2];
			}
			
			if (map[row][col + 1] == 1) {
				push[0] = row;
				push[1] = col + 1;
				block.push_back(push);
				push = new int[2];
			}
		}
	}
	//(0,y)
	else if (col == 0) {
		//(0,height-1)
		if (row == height - 1) {
			if (map[row - 1][col] == 1) {
				push[0] = row - 1;
				push[1] = col;
				block.push_back(push);
				push = new int[2];
			}

			if (map[row][col + 1] == 1) {
				push[0] = row;
				push[1] = col + 1;
				block.push_back(push);
				push = new int[2];
			}
		}
		//(0,y)
		else {
			if (map[row + 1][col] == 1) {
				push[0] = row+1;
				push[1] = col;
				block.push_back(push);
				push = new int[2];
			}
			
			if (map[row - 1][col] == 1) {
				push[0] = row - 1;
				push[1] = col;
				block.push_back(push);
				push = new int[2];
			}
			
			if (map[row][col + 1] == 1) {
				push[0] = row;
				push[1] = col + 1;
				block.push_back(push);
				push = new int[2];
			}
		}
	}
	//(x,height-1)
	else if (row == height - 1) {
		//(width-1,height-1)
		if (col == width - 1) {
			if (map[row - 1][col] == 1) {
				push[0] = row - 1;
				push[1] = col;
				block.push_back(push);
				push = new int[2];
			}
			if (map[row][col - 1] == 1) {
				push[0] = row;
				push[1] = col - 1;
				block.push_back(push);
				push = new int[2];
			}
		}
		//(x,height-1)
		else {
			if (map[row - 1][col] == 1) {
				push[0] = row - 1;
				push[1] = col;
				block.push_back(push);
				push = new int[2];
			}
			if (map[row][col - 1] == 1) {
				push[0] = row;
				push[1] = col - 1;
				block.push_back(push);
				push = new int[2];
			}
			if (map[row][col + 1] == 1) {
				push[0] = row;
				push[1] = col + 1;
				block.push_back(push);
				push = new int[2];
			}
		}
	}
	//(width-1,y)
	else if (col == width - 1) {
		if (map[row + 1][col] == 1) {
			push[0] = row + 1;
			push[1] = col;
			block.push_back(push);
			push = new int[2];
		}

		if (map[row][col - 1] == 1) {
			push[0] = row;
			push[1] = col - 1;
			block.push_back(push);
			push = new int[2];
		}

		if (map[row - 1][col] == 1) {
			push[0] = row - 1;
			push[1] = col;
			block.push_back(push);
			push = new int[2];
		}
	}
	//(x,y)
	else {
		if (map[row + 1][col] == 1) {
			push[0] = row + 1;
			push[1] = col;
			block.push_back(push);
			push = new int[2];
		}
		
		if (map[row - 1][col] == 1) {
			push[0] = row - 1;
			push[1] = col;
			block.push_back(push);
			push = new int[2];
		}

		if (map[row][col + 1] == 1) {
			push[0] = row;
			push[1] = col + 1;
			block.push_back(push);
			push = new int[2];
		}

		if (map[row][col - 1] == 1) {
			push[0] = row;
			push[1] = col - 1;
			block.push_back(push);
			push = new int[2];
		}
	}

	//if the block sticks to others not in the list
	for (int i = 0; i < block.size(); i++) {
		area += calcArea(block[i][0], block[i][1]);
	}
	block.clear();
	return area;
}

//recursive function
int calcLength(int row, int col)
{
	//if the block is calculated, then return 0
	for (int j = 0; j < lengthList.size(); j++) {
		if (row == lengthList[j][0] && col == lengthList[j][1]) {
			return 0;
		}
	}

	int length = 0;
	vector<int*>block;
	int* push = new int[2];

	//add the block to calculated list
	int* append = new int[2];
	append[0] = row;
	append[1] = col;
	lengthList.push_back(append);

	//check the border
	//if stick to block, append the block into vector
	//else +length
	if (row == 0) {
		//(0,0)
		if (col == 0) {
			if (map[row + 1][col] == 0) {
				length++;
			}
			else {
				push[0] = row + 1;
				push[1] = col;
				block.push_back(push);
				push = new int[2];
			}
			if (map[row][col + 1] == 0)
				length++;
			else {
				push[0] = row;
				push[1] = col + 1;
				block.push_back(push);
				push = new int[2];
			}
			length += 2;
		}
		//(width-1,0)
		else if (col == width - 1) {
			if (map[row + 1][col] == 0)
				length++;
			else {
				push[0] = row + 1;
				push[1] = col;
				block.push_back(push);
				push = new int[2];
			}
			if (map[row][col - 1] == 0)
				length++;
			else {
				push[0] = row;
				push[1] = col - 1;
				block.push_back(push);
				push = new int[2];
			}
			length += 2;
		}
		//(x,0)
		else {
			if (map[row + 1][col] == 0)
				length++;
			else {
				push[0] = row + 1;
				push[1] = col;
				block.push_back(push);
				push = new int[2];
			}
			if (map[row][col - 1] == 0)
				length++;
			else {
				push[0] = row;
				push[1] = col - 1;
				block.push_back(push);
				push = new int[2];
			}
			if (map[row][col + 1] == 0)
				length++;
			else {
				push[0] = row;
				push[1] = col + 1;
				block.push_back(push);
				push = new int[2];
			}
			length++;
		}
	}
	//(0,y)
	else if (col == 0) {
		//(0,height-1)
		if (row == height - 1) {
			if (map[row - 1][col] == 0)
				length++;
			else {
				push[0] = row - 1;
				push[1] = col;
				block.push_back(push);
				push = new int[2];
			}
			if (map[row][col + 1] == 0)
				length++;
			else {
				push[0] = row;
				push[1] = col + 1;
				block.push_back(push);
				push = new int[2];
			}
			length += 2;
		}
		//(0,y)
		else {
			if (map[row + 1][col] == 0)
				length++;
			else {
				push[0] = row + 1;
				push[1] = col;
				block.push_back(push);
				push = new int[2];
			}
			if (map[row - 1][col] == 0)
				length++;
			else {
				push[0] = row - 1;
				push[1] = col;
				block.push_back(push);
				push = new int[2];
			}
			if (map[row][col + 1] == 0)
				length++;
			else {
				push[0] = row;
				push[1] = col + 1;
				block.push_back(push);
				push = new int[2];
			}
			length++;
		}
	}
	//(x,height-1)
	else if (row == height - 1) {
		//(width-1,height-1)
		if (col == width - 1) {
			if (map[row - 1][col] == 0)
				length++;
			else {
				push[0] = row - 1;
				push[1] = col;
				block.push_back(push);
				push = new int[2];
			}
			if (map[row][col - 1] == 0)
				length++;
			else {
				push[0] = row;
				push[1] = col - 1;
				block.push_back(push);
				push = new int[2];
			}
			length += 2;
		}
		//(x,height-1)
		else {
			if (map[row - 1][col] == 0)
				length++;
			else {
				push[0] = row - 1;
				push[1] = col;
				block.push_back(push);
				push = new int[2];
			}
			if (map[row][col - 1] == 0)
				length++;
			else {
				push[0] = row;
				push[1] = col - 1;
				block.push_back(push);
				push = new int[2];
			}
			if (map[row][col + 1] == 0)
				length++;
			else {
				push[0] = row;
				push[1] = col + 1;
				block.push_back(push);
				push = new int[2];
			}
			length++;
		}
	}
	//(width-1,y)
	else if (col == width - 1) {
		if (map[row + 1][col] == 0)
			length++;
		else {
			push[0] = row + 1;
			push[1] = col;
			block.push_back(push);
			push = new int[2];
		}
		if (map[row][col - 1] == 0)
			length++;
		else {
			push[0] = row;
			push[1] = col - 1;
			block.push_back(push);
			push = new int[2];
		}
		if (map[row - 1][col] == 0)
			length++;
		else {
			push[0] = row - 1;
			push[1] = col;
			block.push_back(push);
			push = new int[2];
		}
		length++;
	}
	//(x,y)
	else {
		if (map[row + 1][col] == 0)
			length++;
		else {
			push[0] = row + 1;
			push[1] = col;
			block.push_back(push);
			push = new int[2];
		}
		if (map[row - 1][col] == 0)
			length++;
		else {
			push[0] = row - 1;
			push[1] = col;
			block.push_back(push);
			push = new int[2];
		}
		if (map[row][col + 1] == 0)
			length++;
		else {
			push[0] = row;
			push[1] = col + 1;
			block.push_back(push);
			push = new int[2];
		}
		if (map[row][col - 1] == 0)
			length++;
		else {
			push[0] = row;
			push[1] = col - 1;
			block.push_back(push);
			push = new int[2];
		}
	}
	
	//add the length with others
	for (int i = 0; i < block.size();i++) {
		length += calcLength(block[i][0], block[i][1]);
	}

	block.clear();
	return length;
}