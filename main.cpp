// project 5 bea almonte

#include <iostream>
#include "lcsfinder.hpp"
#include "similaritymeasurement.hpp"

int main() {
    lcsFinder partOne;
    SimilarityMeasurement partTwo;

    // first part outputs lcs and length
    // second part outputs similarity matrix 
    std::cout << "PART ONE\n";
    partOne.SetStrings("twoStrings.txt");
    partOne.SetCostArray();
    partOne.OutputResults();

    std::cout << "=======================================\n";
    std::cout << "PART TWO\n";
    partTwo.SetFileName("multiStrings.txt");
    partTwo.ComputeLengths();
    partTwo.PopulateArray();
    partTwo.OutputResults();
    return 0;
}