#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#define MAX_ERRORS 6

void runGame(const std::string& chosenWord, std::string& displayedWord, int& errors) {
	while (errors < MAX_ERRORS && displayedWord != chosenWord) {
		std::cout << displayedWord << "\n";
		char guess;
		std::cout << "Enter a letter: ";
		std::cin >> guess;
		guess = std::toupper(guess);
		if (wordContainsLetter(chosenWord, guess)) {
			for (int i = 0; i < chosenWord.size(); i++)
				if (chosenWord[i] == guess)
					displayedWord[i] = guess;
		}
		else std::cout << "EROARE! Mai aveti " << MAX_ERRORS - (++errors) << " esecuri permise.\n";
	}
	if (displayedWord == chosenWord)
		std::cout << "FELICITĂRI ATI REUSIT!\n";
	else
		std::cout << "Din pacate, ai epuizat numarul de esecuri permise. Cuvantul era: " << chosenWord << "\n";
}

bool wordContainsLetter(const std::string& word, char letter) {
	return word.find(letter) != std::string::npos;
}

int main() {
	srand(time(nullptr));
	std::vector<std::string> words = { "CONTRATENOR", "SPANZURATOAREA", "PROGRAMARE" };
	std::string chosenWord = words[rand() % words.size()], displayedWord = std::string(chosenWord.size(), '_');
	int errors = 0;
	runGame(chosenWord, displayedWord, errors);
}