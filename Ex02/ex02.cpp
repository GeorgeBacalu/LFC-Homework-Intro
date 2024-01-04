#include <iostream>
#include <string>
#include <vector>
#include <regex>

struct NumberPattern {
	std::regex regex;
	std::string type;
};

std::string identifyNumberType(const std::string& number, const std::vector<NumberPattern>& numberPatterns) {
	for (const auto& numberPattern : numberPatterns)
		if (std::regex_match(number, numberPattern.regex))
			return numberPattern.type;
	return "No pattern applies!";
}

int main() {
	std::vector<NumberPattern> numberPatterns{
		{std::regex(R"(\d+)"), "Natural"},
		{std::regex(R"([+-]?\d+)"), "Integer"},
		{std::regex(R"([+-]?\d+(\.\d+)?)"), "Real"},
		{std::regex(R"([+-]?\d+(\.\d+)?([eE][+-]?\d+)?)"), "Real exponential"}
	};
	std::string number;
	std::cout << "Enter a number: ";
	std::cin >> number;
	std::cout << identifyNumberType(number, numberPatterns);
}