#include <iostream>
#include <string>
#include <algorithm>

bool areAnagrams(std::string word1, std::string word2) {
	std::sort(word1.begin(), word1.end());
	std::sort(word2.begin(), word2.end());
	return word1 == word2;
}

int main() {
	std::string word1, word2;
	std::cout << "Enter first word: ";
	std::cin >> word1;
	std::cout << "Enter second word: ";
	std::cin >> word2;
	std::cout << "Words " << (areAnagrams(word1, word2) ? "" : "don't") << " contain the same set of characters";
}