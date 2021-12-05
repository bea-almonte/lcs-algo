// project 5 bea almonte


#include <iostream>
#include "lcsfinder.hpp"

int main() {
    lcsFinder test[3];

    test[0].SetStrings("first-test.txt");
    test[0].SetCostArray();
    test[0].OutputResults();

    test[1].SetStrings("second-test.txt");
    test[1].SetCostArray();
    test[1].OutputResults();


    return 0;
}