// bea almonte
// similaritymeasurement.hpp
// this class takes a file input, outputs a matrix of similarity
// only use 2*n space complexity for calculating the LCS
// can recount the path of the lcs
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#ifndef SIMILARITYMEASUREMENT_HPP
#define SIMILARITYMEASUREMENT_HPP

const int MAX_STRINGS = 20;

class SimilarityMeasurement {
private:
    int entries; // number of strings to compare
    int positions[MAX_STRINGS]; // lengths of each string
    std::string fileName;
    std::vector<std::vector<char>> simArray; // similarity matrix
public:
    void SetFileName(std::string fileName); // sets file name to direct access
    void ComputeLengths(); // set string from file input
    void PopulateArray(); // populate the simlarity matrix
    char CalcSimilarity(std::string& stringX, std::string& stringY); // H,M,L,D
    int GetCost(std::string& stringX, std::string& stringY); // get length of lcs
    void OutputResults(); // output similarity matrix
};


#endif