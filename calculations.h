#ifndef CALCULATIONS_H
#define CALCULATIONS_H
#include <vector>


    std::vector<std::vector<int>> indexPowerset(int n);
    std::vector<double> calculateBanzhaf(const std::vector<int>& participant_weights, int quorum);
#endif // CALCULATIONS_H