/*
USTH Retake 2024-2025 prime factorization using Linked List
*/

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int val_) : val(val_), next(nullptr) {}
};

class Solution {
public:
    Node* prime_factors(int x) {
        Node* head = nullptr;
        Node* tail = nullptr;
    

        while (x % 2 == 0) {
            if (head == nullptr) {
                head = tail = new Node(2);
            } else {
                tail -> next = new Node(2);
                tail = tail -> next;
            }
            x /= 2;
        }

        for (int i = 3; i * i <= x; i += 2) {
            while (x % i == 0) {
                if (head == nullptr) {
                    head = tail = new Node(i);
                } else {
                    tail -> next = new Node(i);
                    tail = tail -> next;
                }
                x /= i;
            }
        }

        if (x > 2) {
            if (head == nullptr) {
                head = tail = new Node(x);
            } else {
                tail -> next = new Node(x);
            }
        }

        return head;
    }

    
    bool isDivisibleByBiggerFactors(int small, int big) {
        Node* factors_big = prime_factors(big);

        while (factors_big != nullptr) {
            if (small % factors_big -> val != 0) {
                return false;
            }
            factors_big = factors_big -> next;
        }
        return true;
    }

    int calculate_HCF(int A, int B) {
        Node* factor_A = prime_factors(A);
        Node* factor_B = prime_factors(B);

        int hcf = 1;
        while (factor_A != nullptr && factor_B != nullptr) {
            if (factor_A -> val == factor_B -> val) {
                hcf *= factor_A -> val;
                factor_A = factor_A -> next;
                factor_B = factor_B -> next;
            
            } else if (factor_A -> val < factor_B -> val) {
                factor_A = factor_A -> next;
            
            } else {
                factor_B = factor_B -> next;
            }
        }

        return hcf;
    }

    void display (Node* head) {
        while (head != nullptr) {
            cout << head -> val << " ";
            head = head -> next;
        }
    }

    void delete_(Node* head) {
        while (head != nullptr) {
            Node* temp = head;
            head = head -> next;
            delete temp;
        }
    }
};

int main() {
    Solution solution;

    int A {};
    cout << "Enter the first number: ";
    cin >> A;
    
    int B {};
    cout << "Enter the second number: ";
    cin >> B;

    cout << "Prime factors of " << A << " are: ";
    Node* factor_A = solution.prime_factors(A);
    solution.display(factor_A);
    cout << endl;

    cout << "Prime factors of " << B << " are: ";
    Node* factor_B = solution.prime_factors(B);
    solution.display(factor_B);
    cout << endl;

    if (solution.isDivisibleByBiggerFactors(A, B)) {
        cout << A << " is divisible by all prime factors of " << B << endl;
    } else {
        cout << A << " is not divisible by all prime factors of " << B << endl;
    }

    int hcf = solution.calculate_HCF(A, B);
    cout << "The HCF of " << A << " and " << B << " is: " << hcf << endl;

    solution.delete_(factor_A);
    solution.delete_(factor_B);

    return 0;
}