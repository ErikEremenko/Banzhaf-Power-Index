#include "calculations.h"
#include <vector>
#include <numeric>

// generate powerset from indices 0 to n-1
std::vector<std::vector<int>> indexPowerset(int n) {
    std::vector<std::vector<int>> subsets = {{}};
    subsets.reserve(1 << n); // preallocate for large n
    for (int i = 0; i < n; ++i) {
        int prevSize = subsets.size(); // prevents infinite set growth
        for (int j = 0; j < prevSize; ++j) {
            auto new_subset = subsets[j];
            new_subset.push_back(i);
            subsets.emplace_back(std::move(new_subset));
        }
    }
    return subsets;
}

std::vector<double> calculateBanzhaf(const std::vector<int>& participant_weights, int quorum) {
    int n = participant_weights.size();
    std::vector<int> swings_by_participant(n, 0); // count critical participants that made the coalition succeed
    auto coalitions = indexPowerset(n);

    for (const auto& coalition : coalitions) {
        int sum = 0;
        for (int idx : coalition) sum += participant_weights[idx];
        if (sum < quorum) continue; // skipping losing coalitions

        // get critical participants that make the coalition possible and sum their power
        for (int idx: coalition) {
            if (sum - participant_weights[idx] < quorum) {
                swings_by_participant[idx]++;
            }
        }
    }
    // normalizing swings_by_participant to get relative Banzhaf indices
    int banzhaf_sum = std::accumulate(swings_by_participant.begin(), swings_by_participant.end(), 0);
    std::vector<double> relative_indices(n, 0.0);

    if (banzhaf_sum > 0) {
        for (int i = 0; i < n; ++i) {
            relative_indices[i] = double(swings_by_participant[i]) / double(banzhaf_sum);
        }
    }
    return relative_indices;
}

