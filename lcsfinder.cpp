#include "lcsfinder.hpp"

lcsFinder::lcsFinder() {
    lcsCost = 0;
    rows = 0;
    cols = 0;
}

lcsFinder::~lcsFinder() {
    for (int i = 0; i < rows; i++) {
        delete [] cArray[i];
    }
    delete[] cArray;
}
 // set string from file input
void lcsFinder::SetStrings(std::string fileName){
    std::ifstream inFile;


    inFile.open(fileName);

    // take inputs
    inFile >> stringX >> stringY;

    // set rows and columns
    rows = stringX.length();
    cols = stringY.length();

    // dynamically allocate new table
    cArray = new int*[rows];

    for (int i = 0; i < rows; i++) {
        cArray[i] = new int[cols];
    }

    inFile.close();
}

void lcsFinder::SetCostArray(){

}
// recount subsequence / print LCS
void lcsFinder::FindLcsStringFromArr() {
    

}

void lcsFinder::OutputResults() {
    std::cout << "rows: " << rows;
    std::cout << "cols: " << cols;

}


int lcsFinder::GetLcsCost() {
    return 0;
}

std::string lcsFinder::GetLscString() {
    return "bitch";
}
