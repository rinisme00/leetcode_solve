/*
Retake ADS 2024-2025
==============================
Exercise 1:
- A function to complete the prime factorization for natural, prime factor can be stored in an array
- A function to check whether the smaller value is divisible by found prime factor of the bigger value.
- Another array can be used to stored these prime divisors.
- A function to calculate the product of the common prime factor and return HCF (highest common factor)
- A main function to test
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> prime_factors(int x) {
        vector<int> factors;
    
        while (x % 2 == 0) {
            factors.push_back(2);
            x /= 2;
        }

        for (int i = 3; i * i <= x; i += 2) {
            while (x % i == 0) {
                factors.push_back(i);
                x /= i;
            }
        }

        if (x > 2) {
            factors.push_back(x);
        }
        return factors;
    }

    bool isDivisibleByBiggerFactors(int small, int big) {
        vector<int> factors_big = prime_factors(big);

        for (auto factor: factors_big) {
            if (small % factor != 0) {
                return false;
            }
        }
        return true;
    }

    int calculate_HCF(int A, int B) {
        vector<int> factor_A = prime_factors(A);
        vector<int> factor_B = prime_factors(B);

        vector<int> cf;
        for (int i = 0; i < factor_A.size(); ++i) {
            for (int j = 0; j < factor_B.size(); ++j) {
                if (factor_A.at(i) == factor_B.at(j)) {
                    cf.push_back(factor_A.at(i));
                    factor_B.erase(factor_B.begin() + j);
                    break;
                }
            }    
        }

        int hcf = 1;
        for (auto f: cf) {
            hcf *= f;
        }
        return hcf;
    }
};

int main () {
    Solution solution;

    int A {};
    cout << "Enter the first number: ";
    cin >> A;
    
    int B {};
    cout << "Enter the second number: ";
    cin >> B;

    cout << "Prime factors of " << A << " are: ";
    vector<int> factors_A = solution.prime_factors(A);
    for (auto f: factors_A) {
        cout << f << " ";
    }
    cout << endl;

    cout << "Prime factors of " << B << " are: ";
    vector<int> factors_B = solution.prime_factors(B);
    for (auto f: factors_B) {
        cout << f << " ";
    }
    cout << endl;

    if (solution.isDivisibleByBiggerFactors(A, B)) {
        cout << A << " is divisible by all prime factors of " << B << endl;
    } else {
        cout << A << " is not divisible by all prime factors of " << B << endl;
    }

    int hcf = solution.calculate_HCF(A, B);
    cout << "The HCF of " << A << " and " << B << " is: " << hcf << endl;

    return 0;
}
