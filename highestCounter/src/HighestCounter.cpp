//============================================================================
// Name        : HighestCharacter.cpp
// Author      : StewCode
// Version     : 1.0
// Description : Highest Character Counter
//============================================================================
#include <iostream>
#include <string>
#include <vector>

int main() {
    // Step 1: Ask user for string
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    // Initialize a vector to count ASCII characters
    std::vector<int> counts(128, 0);

    // Step 2: Iterate over each character
    for (char i : input) {
        // Add a counter for each character
        counts[static_cast<int>(i)]++;
    }

    // Step 3: Find character with highest counter
    int maxCount = 0;
    char highestChar = '\0';

    for (int i = 0; i < counts.size(); i++) {
        if (counts[i] > maxCount) {
            maxCount = counts[i];
            highestChar = static_cast<char>(i);
        }
    }

    // Step 4: Print character
    std::cout << "'" << highestChar << "' " << maxCount << std::endl;

    return 0;
}
