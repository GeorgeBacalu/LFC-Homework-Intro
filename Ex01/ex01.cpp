#include <iostream>
#include <string>

int countOccurrences(const std::string& str, char ch) {
	return std::count(str.begin(), str.end(), ch);
}

int main() {
	std::string str;
	char ch;
	std::cout << "Enter string: ";
	std::getline(std::cin, str);
	std::cout << "Enter char: ";
	std::cin >> ch;
	std::cout << ch << " appears " << countOccurrences(str, ch) << " times";
}