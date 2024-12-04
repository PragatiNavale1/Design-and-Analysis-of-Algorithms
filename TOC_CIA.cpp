//  Turing Machine that simulates obtaining the two's complement of a binary number
#include <iostream>
#include <string>


std::string twoComplement(const std::string& binaryInput) {
    std::string result = binaryInput;
    int n = result.size();

    // Step 1: Traverse from right to left and find the first '1'
    int i = n - 1;
    while (i >= 0 && result[i] != '1') {
        i--;
    }

    // If there's no '1' in the binary number, two's complement remains the same
    if (i < 0) {
        return result;
    }

    // Step 2: Leave all 0's and the first 1 alone, then flip all remaining bits to the left
    i--;  // Move to the next bit on the left of the first '1'
    while (i >= 0) {
        // Flip '0' to '1' and '1' to '0'
        result[i] = (result[i] == '0') ? '1' : '0';
        i--;
    }
    return result;
}

int main() {
    std::string binaryNumber;
    std::cout << "Enter a binary number: ";
    std::cin >> binaryNumber;

    std::string twoComplementResult = twoComplement(binaryNumber);
    std::cout << "Two's complement of " << binaryNumber << " is " << twoComplementResult << std::endl;

    return 0;
}
