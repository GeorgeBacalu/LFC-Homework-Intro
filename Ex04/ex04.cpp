#include <iostream>
#include <string>
#include <regex>

std::string removeOccurrences(const std::string& text, const std::string& str) {
	return std::regex_replace(text, std::regex(str), "");
}

int main() {
	std::string text, str;
	std::cout << "Enter text: ";
	std::getline(std::cin, text);
	std::cout << "Enter string: ";
	std::getline(std::cin, str);
	std::cout << "Remove occurrences of str from text: " << removeOccurrences(text, str);
}