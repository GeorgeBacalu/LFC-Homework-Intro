#include <iostream>
#include <string>
#include <regex>

int main() {
	std::regex pattern(R"([+-]?\d+(\.\d+)?)");
	std::string string1, string2;
	std::cin >> string1 >> string2;
	std::cout << "Match string: " << std::regex_match(string1, pattern);
	std::cout << "\nReplace: " << std::regex_replace(string2, std::regex("a"), "d");
	std::cout << "\nReplace first only: " << std::regex_replace(string2, std::regex("a"), "d", std::regex_constants::format_first_only);
}