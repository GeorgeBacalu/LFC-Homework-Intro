#include <iostream>
#include <string>
#include <vector>
#include <set>

void readTextWords(std::vector<std::string>& text) {
	std::cout << "Enter " << text.size() << " words:\n";
	for (auto& word : text)
		std::cin >> word;
}

void displayCommonWords(const std::vector<std::string>& text1, const std::vector<std::string>& text2) {
	std::set<std::string> wordsText1{ text1.begin(), text1.end() }, wordsText2{ text2.begin(), text2.end() };
	std::cout << "Common words: ";
	for (const auto& word : wordsText1)
		if (wordsText2.find(word) != wordsText2.end())
			std::cout << word << " ";
}

int main() {
	int size1, size2;
	std::cout << "Enter first text size: ";
	std::cin >> size1;
	std::cout << "Enter second text size: ";
	std::cin >> size2;
	std::vector<std::string> text1, text2;
	text1.resize(size1);
	text2.resize(size2);
	readTextWords(text1);
	readTextWords(text2);
	displayCommonWords(text1, text2);
}