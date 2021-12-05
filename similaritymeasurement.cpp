#include "similaritymeasurement.hpp"

void SimilarityMeasurement::ComputeLengths(std::string fileName){
    std::ifstream inFile;
    std::string tempSequence;
    inFile.open(fileName);

    entries = 0;
    positions[0] = 0;

    
    while (getline(inFile,tempSequence)) {
        positions[entries] = tempSequence.length()+1;
        entries++;
    }


    inFile.close();
}
void SimilarityMeasurement::PopulateArray(std::string fileName) {
    std::string stringX;
    std::string stringY;
    std::ifstream inFile;
    int i, j, currentPos = positions[0];

    inFile.open(fileName);

    inFile.seekg(currentPos);

    for (i = 1; i < entries - 1; i++) {
        inFile >> stringX;
        for (j = i+1; j < entries; j++) {
            inFile >> stringY;
            std::cout << stringX << " compared with " << stringY << std::endl;
        }
        currentPos += positions[i];
        inFile.seekg(currentPos);
    }



}
/* char SimilarityMeasurement::CalcSimilarity(std::string stringX, std::string stringY) {

}
void SimilarityMeasurement::OutputResults() {

}
int SimilarityMeasurement::GetLcsCost() {

}
std::string SimilarityMeasurement::GetLscString() {

} */