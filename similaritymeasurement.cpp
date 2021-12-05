#include "similaritymeasurement.hpp"

// set file file for inputs
void SimilarityMeasurement::SetFileName(std::string fileName) {
    this->fileName = fileName;
}

// compute the length of each string
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

    simArray.resize(entries-1, std::vector<char>(entries));  

    inFile.close();
}
void SimilarityMeasurement::PopulateArray() {
    std::string stringX;
    std::string stringY;
    std::ifstream inFile;
    int i, j, currentPos = positions[0];

    inFile.open(fileName);

    inFile.seekg(currentPos);

    // compare each string
    for (i = 1; i < entries-1; i++) {
        inFile >> stringX;
        // compared each row, fill in when already checked
        for (j = i+1; j < entries; j++) {
            inFile >> stringY;
            simArray.at(i-1).at(j-1) = CalcSimilarity(stringX, stringY);
            simArray.at(j-2).at(i-1) = '-';
        }

        currentPos += positions[i];
        inFile.seekg(currentPos);
    }

    // fill in last row with blanks
    for (i = 0; i < entries-1; i++) {
        simArray.at(entries-2).at(i) = '-';
    }

}

// gets the cost of the lcs using only a 2 * n array
int SimilarityMeasurement::GetCost(std::string& stringX, std::string& stringY){
    // initialize c arrays
    std::vector<std::vector<int>> cArray; // cost array
    
    int rows = stringX.length();
    int cols = stringY.length();

    // array 2 * n for smaller space complexity
    cArray.resize(2, std::vector<int>(cols+1));  

    // initialize array
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= cols; j++) {
        cArray[i][j] = 0;
        }
    }

    // increment diagonal when match is found
    // replce current chs
    for (int i = 1; i <= rows; i++) {
        // replace top row with bottom row
        for (int j = 0; j <= cols; j++) {
            cArray[0][j] = cArray [1][j];
        }
        for (int j = 1; j <= cols; j++) {
            if (stringX.at(i-1) == stringY.at(j-1)) {
                // increment from diagonal
                cArray[1][j] = cArray[0][j-1] + 1;
            } else if (cArray[0][j] >= cArray[1][j-1]) {
                // increment from up
                cArray[1][j] = cArray[0][j];
            } else {
                // increment from left
                cArray[1][j] = cArray[1][j-1];
            }
        }
    }
 
    // return lcs
    return cArray[1][cols];
}

// outputs a char that represents similarity of the input strings
char SimilarityMeasurement::CalcSimilarity(std::string& stringX, std::string& stringY) {
    const int PERCENT = 100;
    int longLength = stringX.length();
    int shortLength = stringY.length();
    int lcs = GetCost(stringX, stringY);
    int ratio = 0; // ratio between the short and the long subsequence
    int shortToLCS = 0;  // ratio between short string and lcs

    // switch length if X is longer
    if (shortLength > longLength) {
        longLength = stringY.length();
        shortLength = stringX.length();
    }

    ratio = PERCENT * (static_cast<float>(shortLength) / longLength);
    shortToLCS = PERCENT * (static_cast<float>(lcs) / shortLength);

    // tests similarity of each subsequence
    if (ratio >= 90 && shortToLCS >= 90) {
        return 'H';
    } else if (ratio >= 80 && shortToLCS >= 80) {
        return 'M';
    } else if (ratio >= 60 && shortToLCS >= 50) {
        return 'L';
    } else {
        return 'D';
    }
    
}


// outputs the similaritty matrix
void SimilarityMeasurement::OutputResults() {
    std::cout << "   ";

    // formats column header
    for (int i = 1; i < entries; i++) {
        std::cout << std::setfill('0') << std::setw(2) << i << " ";
    }
    std::cout << std::endl;

    // rows are one less than columns
    for (int i = 0; i < entries - 1; i++) {
        // formats row headers
        std::cout << std::setfill('0') << std::setw(2) << i+1 << "  ";
        for (int j = 0; j < entries; j++) {
        std::cout << simArray[i][j] << "  ";
        }
        std::cout << std::endl;
    }

}