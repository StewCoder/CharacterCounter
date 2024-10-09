//============================================================================
// Name : HighestCounter.test
// Author : StewCode
// Version : 1.0
// Description : Program prompts the user to input a string, counts the
// occurrences of each ASCII character, and identifies the character
// that appears the most frequently along with its count.

// Arguments : None (User input).
// Return Value :
// - Returns 0 if the program executes successfully.
// - Returns a non-zero value if error
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