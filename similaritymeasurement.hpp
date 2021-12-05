#include <iostream>
#include <fstream>
#include <vector>

#ifndef SIMILARITYMEASUREMENT_HPP
#define SIMILARITYMEASUREMENT_HPP

const int MAX_STRINGS = 20;

class SimilarityMeasurement {
private:
    int entries;
    int positions[MAX_STRINGS];
    std::vector<std::vector<char>> simArray; // cost array
public:
    void ComputeLengths(std::string fileName); // set string from file input
    void PopulateArray(std::string fileName);
    char CalcSimilarity(std::string stringX, std::string stringY);
    void OutputResults();

    int GetLcsCost();
    std::string GetLscString();
};


#endif