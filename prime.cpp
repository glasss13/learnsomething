#include <vector>
#include <iostream>
#include "prime.h"
#include <cstring>

using namespace std;

vector<vector<int>> PrimeFactorizer::not_disaster() {
    vector<int> smallest_factors(2500, 2);

    for (int i = 3; i < 2500; i += 2) smallest_factors[i] = i;

    for (int i = 3; i < 2500; i += 2) {
        // if at this point smallest_factors[i] is still i,
        // then we know i is prime
        if (smallest_factors[i] == i) {
            for (int j = i * i; j < 2500; j += 2 * i) {
                if (smallest_factors[j] == j) {
                    smallest_factors[j] = i;
                }
            }
        }
    }

    vector<vector<int>> factorizations(2500);
    for (int i = 2; i < 2500; ++i) {
        int val = i / smallest_factors[i];
        factorizations[i].reserve(50);

        factorizations[i].insert(factorizations[i].end(), factorizations[val].begin(), factorizations[val].end());

        if (val % smallest_factors[i] != 0)  {
            factorizations[i].push_back(smallest_factors[i]);
        }
    }

    return factorizations;
}

