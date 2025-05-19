#include <iostream>
#include <vector>

#include "calculations.h"



void print_results(std::vector<int> participant_weights, int quorum) {
    std::vector<double> rel_banzhaf_indices = calculateBanzhaf(participant_weights, quorum);

    std::cout << "Quorum: " << quorum << std::endl;
    std::cout << "Participant weigths: ";
    for (int w : participant_weights) {
        std::cout << w << ' ';
    };
    std::cout << std::endl;
    std::cout << "Relative Banzhaf indices: ";
    for (double i : rel_banzhaf_indices) {
        std::cout << i << ' ';
    }
    std::cout << "\n\n";
}

int main() {
    std::cout << "Example 1\n";
    print_results(std::vector<int>  {10, 5, 4}, 10);
    std::cout << "Example 2\n";
    print_results(std::vector<int>  {9, 6, 4}, 10);
    std::cout << "EWG 1958–72\n";
    print_results(std::vector<int>  {4, 4, 4, 0, 2, 2, 0, 0, 1}, 12);
    std::cout << "EWG 1973–80\n";
    print_results(std::vector<int>  {10, 10, 10, 10, 5, 5, 3, 3, 2}, 41);

    return 0;
}
