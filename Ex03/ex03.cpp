#include <iostream>
#include <string>
#include <regex>

std::string replaceFirstOccurrence(const std::string& text, const std::string& str1, const std::string& str2) {
	return std::regex_replace(text, std::regex(str1), str2, std::regex_constants::format_first_only);
}

int main() {
	std::string text, str1, str2;
	std::cout << "Enter text: ";
	std::getline(std::cin, text);
	std::cout << "Enter first string: ";
	std::getline(std::cin, str1);
	std::cout << "Enter second string: ";
	std::getline(std::cin, str2);
	std::cout << "Replace str1 with str2 in text:\n" << replaceFirstOccurrence(text, str1, str2);
}