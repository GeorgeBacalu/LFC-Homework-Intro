#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> extractWords(std::string& text) {
	std::vector<std::string> words;
	std::regex wordPattern(R"(\b(\w+)\b)");
	std::smatch match; // special container keeping search results gotten by using regex on string (alias for std::match_results<std::string::const_iterator>)
	while (std::regex_search(text, match, wordPattern)) { // search for first pattern match -> executes instructions inside when found -> remove text up until the matching point for further checks
		words.push_back(match[1]); // match[1] matches "\w+"
		text = match.suffix().str();
	}
	return words;
}

void displayWords(const std::vector<std::string>& words) {
	std::cout << "[";
	for (int i = 0; i < words.size(); i++) {
		std::cout << "\"" << words[i] << "\"";
		if (i != words.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]";
}

int main() {
	std::string text;
	std::cout << "Enter the text: ";
	std::getline(std::cin, text);
	displayWords(extractWords(text));
}