#include "lcsfinder.hpp"

lcsFinder::lcsFinder() {
    lcsCost = 0;
    rows = 0;
    cols = 0;
}

 // set stringX and string Y from file input
void lcsFinder::SetStrings(std::string fileName){
    std::ifstream inFile;


    inFile.open(fileName);

    // take inputs
    inFile >> stringX >> stringY;

    // set rows and columns
    rows = stringX.length();
    cols = stringY.length();

    // create new table
    cArray.resize(rows+1, std::vector<int>(cols+1));  

    inFile.close();
}

// fills the cArray with matches
void lcsFinder::SetCostArray(){
    // initialize c arrays

    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= cols; j++) {
        cArray[i][j] = 0;
        }
    }

    // populating the array
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (stringX.at(i-1) == stringY.at(j-1)) {
                // increment from diagonal
                cArray[i][j] = cArray[i-1][j-1] + 1;
            } else if (cArray[i-1][j] >= cArray[i][j-1]) {
                // increment from up
                cArray[i][j] = cArray[i-1][j];
            } else {
                // increment from left
                cArray[i][j] = cArray[i][j-1];
            }
        }
    }
}

// recount subsequence / appends to lcs string
void lcsFinder::RecountLCS(int i, int j) {
    if (i == 0 || j == 0) {
        return;
    } else if (stringX.at(i-1) == stringY.at(j-1)) {
        // go to diagonal if match
        RecountLCS(i-1,j-1);
        lcs += stringX.at(i-1);
    } else if(cArray[i-1][j] >= cArray[i][j-1]) {
        RecountLCS(i-1,j);
    } else {
        RecountLCS(i,j-1);
    }

}

// outputs the subsequence and the path of the subsequence
void lcsFinder::OutputResults() {
    RecountLCS(rows,cols);
    std::cout << "LCS Length: " << cArray[rows][cols] << std::endl;
    std::cout << "LCS: " << lcs << std::endl;
}