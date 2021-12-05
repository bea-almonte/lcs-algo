// bea almonte
// lcsfinder.hpp
// this class takes two inputs, finds the lcs, outputs it's subsequence,
// and the subsequence length
#include <iostream>
#include <fstream>
#include <vector>

#ifndef LCSFINDER_HPP
#define LCSFINDDER_HPP

class lcsFinder {
private:
    std::string stringX;
    std::string stringY;
    std::string lcs; // longest common subsequence
    int rows;
    int cols;
    int lcsCost; // total cost of lcs
    std::vector<std::vector<int>> cArray; // cost array
public:
    lcsFinder();
    void SetStrings(std::string fileName); // set string from file input
    void SetCostArray();    // fills the cArray
    void RecountLCS(int i, int j); // recount subsequence / print LCS
    void OutputResults();

    int GetLcsCost();
    std::string GetLscString();
};


#endif