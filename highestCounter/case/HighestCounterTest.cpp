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
#include <utility>
#include <cassert>

// Function to find the character with the highest count
std::pair<char, int> highestCharacterCount(const std::string& input) {
// Initialize a vector to count ASCII characters
std::vector<int> counts(128, 0);

// Iterate over each character using a traditional for loop
for (size_t j = 0; j < input.length(); ++j) {
counts[static_cast<int>(input[j])]++;
}

// Debug output: Print counts for each character
std::cout << "Character counts:\n";
for (int i = 0; i < counts.size(); ++i) {
if (counts[i] > 0) {
std::cout << "'" << static_cast<char>(i) << "' : " << counts[i] << std::endl;
}
}

// Find character with highest count
int maxCount = 0;
char highestChar = '\0';

for (int i = 0; i < counts.size(); i++) {
if (counts[i] > maxCount) {
maxCount = counts[i];
highestChar = static_cast<char>(i);
}
}

// Use the constructor of std::pair instead of an initializer list
return std::make_pair(highestChar, maxCount);
}

// Function to run tests
void runTests() {
std::cout << "Running tests..." << std::endl;

// Test cases
std::pair<char, int> result;

// Test with a simple string
result = highestCharacterCount("aaaabc");
assert(result == std::make_pair('a', 4)); // Expected: ('a', 1)

result = highestCharacterCount("teeeeemmmmpppp");
assert(result == std::make_pair('m', 4)); // Expected: ('a', 2)

result = highestCharacterCount("aabbcc");
assert(result == std::make_pair('a', 2)); // Expected: ('a', 2)

result = highestCharacterCount("DDDDDDESSSTROY LONey");
assert(result == std::make_pair('D', 6)); // Expected: ('a', 4)

result = highestCharacterCount("");
assert(result == std::make_pair('\0', 0)); // Expected: ('\0', 0)

result = highestCharacterCount("!@#$%^&*()");
assert(result == std::make_pair('!', 1)); // Expected: ('!', 1)

result = highestCharacterCount("!@!!!!");
assert(result == std::make_pair('!', 5)); // Expected: ('!', 2)

result = highestCharacterCount("About Time TOOOM");
assert(result == std::make_pair('O', 3)); // Expected: ('a', 2)

result = highestCharacterCount("AaAa");
assert(result == std::make_pair('A', 2)); // Expected: ('A', 2)

std::cout << "All Test completed..." << std::endl;
}

int main() {
// Run the tests
runTests();

// Step 1: Ask user for string
std::string input;
std::cout << "Enter a string: ";
std::getline(std::cin, input);

// Step 2: Get highest character count
auto [highestChar, maxCount] = highestCharacterCount(input);

// Step 3: Print character
std::cout << "'" << highestChar << "' " << maxCount << std::endl;

return 0;
}