#include "similaritymeasurement.hpp"
void SimilarityMeasurement::SetFileName(std::string fileName) {
    this->fileName = fileName;
}


void SimilarityMeasurement::ComputeLengths(){
    std::ifstream inFile;
    std::string tempSequence;
    inFile.open(fileName);

    entries = 0;
    positions[0] = 0;

    
    while (getline(inFile,tempSequence)) {
        positions[entries] = tempSequence.length()+1;
        entries++;
    }

    simArray.resize(entries, std::vector<char>(entries));  
    std::cout << "entries" << entries << std::endl;

    inFile.close();
}
void SimilarityMeasurement::PopulateArray() {
    std::string stringX;
    std::string stringY;
    std::ifstream inFile;
    int i, j, currentPos = positions[0];

    inFile.open(fileName);

    inFile.seekg(currentPos);

    for (i = 1; i < entries-1; i++) {
        inFile >> stringX;
        for (j = i+1; j < entries; j++) {
            inFile >> stringY;
/*             std::cout << stringX << " compared with " << stringY << std::endl;
            std::cout << GetCost(stringX,stringY) <<std::endl;
            std::cout << i-1 << "|" << j-2 << std::endl; */
            simArray.at(i-1).at(j-1) = CalcSimilarity(stringX, stringY);
            simArray.at(j-2).at(i-1) = '-';
        }

        currentPos += positions[i];
        inFile.seekg(currentPos);
    }



}

int SimilarityMeasurement::GetCost(std::string& stringX, std::string& stringY){
    // initialize c arrays
    std::vector<std::vector<int>> cArray; // cost array

    int rows = stringX.length();
    int cols = stringY.length();

    cArray.resize(rows+1, std::vector<int>(cols+1));  

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
                // up
                cArray[i][j] = cArray[i-1][j];
            } else {
                // left
                cArray[i][j] = cArray[i][j-1];
            }
        }
    }

    return cArray[rows][cols];
}

char SimilarityMeasurement::CalcSimilarity(std::string& stringX, std::string& stringY) {
    GetCost(stringX, stringY);
    return 'g';
}



void SimilarityMeasurement::OutputResults() {
    std::cout << "   ";

    for (int i = 1; i < entries; i++) {
        std::cout << "0" << i << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < entries-2; i++) {
        std::cout << "0" << i+1 << "  ";
        for (int j = 0; j < entries; j++) {
        std::cout << simArray[i][j] << "  ";
        }
        std::cout << std::endl;
    }

}
/* int SimilarityMeasurement::GetLcsCost() {

}
std::string SimilarityMeasurement::GetLscString() {

} */