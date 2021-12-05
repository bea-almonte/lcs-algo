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
    std::string fileName;
    std::vector<std::vector<char>> simArray; // cost array
public:
    void SetFileName(std::string fileName);
    void ComputeLengths(); // set string from file input
    void PopulateArray();
    char CalcSimilarity(std::string& stringX, std::string& stringY);
    int GetCost(std::string& stringX, std::string& stringY);
    void OutputResults();
};


#endif