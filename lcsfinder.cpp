#include "lcsfinder.hpp"

lcsFinder::lcsFinder() {
    lcsCost = 0;
    rows = 0;
    cols = 0;
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

    // create new table
    cArray.resize(rows+1, std::vector<int>(cols+1));  

    inFile.close();
}

void lcsFinder::SetCostArray(){
    // initialize c arrays

    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= cols; j++) {
        cArray[i][j] = 0;
        }
    }

    // algo
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (stringX.at(i-1) == stringY.at(j-1)) {
                // increment diagonal
                cArray[i][j] = cArray[i-1][j-1] + 1;
            } else if (cArray[i-1][j] >= cArray[i][j-1]) {
                cArray[i][j] = cArray[i-1][j];
            } else {
                cArray[i][j] = cArray[i][j-1];
            }
        }
    }
}

// recount subsequence / print LCS
void lcsFinder::RecountLCS(int i, int j) {
    if (i == 0 || j == 0) {
        return;
    } else if (stringX.at(i-1) == stringY.at(j-1)) {
        RecountLCS(i-1,j-1);
        lcs += stringX.at(i-1);
    } else if(cArray[i-1][j] >= cArray[i][j-1]) {
        RecountLCS(i-1,j);
    } else {
        RecountLCS(i,j-1);
    }

}

void lcsFinder::OutputResults() {
    RecountLCS(rows,cols);
    std::cout << "rows: " << rows << std::endl;
    std::cout << "cols: " << cols << std::endl;
    std::cout << "lcs: " << cArray[rows][cols] << std::endl;
    std::cout << lcs << std::endl;
/*     for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= cols; j++) {
        std::cout << cArray[i][j] << " ";
        }
        std::cout << std::endl;
    } */
}


int lcsFinder::GetLcsCost() {
    return 0;
}

std::string lcsFinder::GetLscString() {
    return "bitch";
}
