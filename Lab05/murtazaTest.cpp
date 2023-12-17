#include<iostream>
#include <bitset>
using namespace std;

int main() {
    int num = 9;
    bitset<4> binary(num);
    int rem;
    int base = 1;

    // // Convert decimal to binary
    // while (num > 0) {
    //     rem = num % 2;
    //     num = num / 2;
    //     binary = binary * 10 + rem;
    // }

    cout << binary << endl;  // Prints the binary representation of 9

    binary = binary << 1;    // Performs a bitwise left shift on the binary representation

    cout << binary << endl;  // Prints the result of the left shift

    return 0;
}
