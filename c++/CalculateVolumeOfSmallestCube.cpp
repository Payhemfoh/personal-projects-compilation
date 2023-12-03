#include <iostream>
#include <vector>
using namespace std;

/*
    This function receive input in belowing format
    height (int)
    width (int)
    length (int)
    number of knife (int)

    for(number of knife)
        direction (0 for horizontal, 1 for vertical)
        distance

    this function will then construct a cube, cutting the cube horizontally and vertically
    and compute the volume of smallest cube
*/

int CalculateVolumeOfSmallestCube() {
    //initialization
    int height = 0, width = 0, length = 0, numKnife = 0;
    cin >> length >> width >> height >> numKnife;

    int** cube = new int* [length];
    for (int i = 0; i < length; ++i)
        cube[i] = new int[width];

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            cube[i][j] = 0;
        }
    }

    vector<int> counterList = { 0 };
    //deals with the knifes
    for (int knife = 0; knife < numKnife; ++knife) {
        int direction = 0, distance = 0;
        cin >> direction >> distance;

        //perform calculation to the blocks after the knife apply
        int size = 0;
        switch (direction) {
        case 0:
            for (int i = distance; i < length; ++i) {
                for (int j = 0; j < width; ++j) {
                    cube[i][j] += 1;
                }
            }
            size = counterList.size();
            for (int i = 0; i < size;++i) {
                int temp = counterList[i];
                temp += 1;
                counterList.push_back(temp);
            }
            break;
        case 1:
            for (int j = distance; j < width; ++j) {
                for (int i = 0; i < length; ++i) {
                    cube[i][j] += 10;
                }
            }
            size = counterList.size();
            for (int i = 0; i < size; ++i) {
                int temp = counterList[i];
                temp += 10;
                counterList.push_back(temp);
            }
            break;
        }
    }

    int smallestArea = 0;

    //calculation process
    for (int &counter:counterList) {
        int area = 0;
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; ++j) {
                if (cube[i][j] == counter)
                    ++area;
            }
        }
        if (area < smallestArea || smallestArea == 0) {
            smallestArea = area;
        }

    }

    //display result in volume
    cout << smallestArea * height << endl;

    //delete dynamic pointers
    for (int i = 0; i < length; ++i)
        delete[] cube[i];
    delete[] cube;

    return 0;
}