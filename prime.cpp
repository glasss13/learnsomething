#include <vector>
#include <iostream>

using namespace std;

vector<int> sieve() {
    vector<bool> primes(2500, true);
    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i < 51; i++) {
        if (primes[i]) {
            for (int j = i * i; j < 2500; j += i) {
                primes[j] = false;
            }
        }
    }

    vector<int> ret;
    ret.reserve(367); // number of primes
    for (int i = 2; i < 2500; i++) {
        if (primes[i]) {
            ret.push_back(i);
        }
    }

    return ret;
}

vector<vector<int>> not_disaster() {
    vector<int> primes = sieve();

    vector<vector<int>> factorizations(2500);

    for (int i = 2; i < 2500; ++i) {
        for (int prime : primes) {
            if (i % prime == 0) {
                int val = i / prime;

                vector<int> factor_factors = factorizations[val];

                factorizations[i] = factor_factors;

                if (val % prime != 0) {
                    factorizations[i].push_back(prime);
                }
            }
        }
    }

    return factorizations;
}

int main() {
    vector<vector<int>> res = not_disaster();


    // for (int i = 0; i < res.size(); ++i) {
    //     cout << i << ": [";
    //     for (auto prime : res[i]) {
    //         cout << prime << ", ";  
    //     }
    //     cout << "]\n";
    // }
    return 0;
}
