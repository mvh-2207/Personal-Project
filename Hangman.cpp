#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

const int MAX_NUM = 50;
const int MAX_GUESSING = 20;

void readFile(std::ifstream &fileName, std::string words[], int size);
std::string chosenWord (std::string words[], int size);
bool guessingWord (std::string target, int length);
void swapLetters(char &a, char &b);

int main() {
    char choice;
    std::string words[MAX_NUM];
    std::ifstream file("words.txt");
    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
    }
    readFile(file, words, MAX_NUM);

    do {
        std::string target = chosenWord(words, MAX_NUM); //the chosen word
        int length = target.length(); //the length of the word
        std::cout << "The length of your chosen word is: " << std::setfill('*') << std::setw(length + 1) <<
            "(" << length << ")" << std::endl;
        bool guess = guessingWord(target, length); // result whether the user guessed the word or not
        if (guess) {
            std::cout << "Congratulation! You have guessed the word \""<< target << "\" right!" << std::endl;
        }
        else {
            std::cout << "You have run out of chances to guess the word T-T." << std::endl;
        }
        std::cout << "Do you want to try again? (Y/N) ";
        std::cin >> choice;
        if (choice == 'N' || choice == 'n') {
            std::cout << "Thank you for playing!" << std::endl;
        }
    }while (choice == 'Y' || choice == 'y');

    return 0;
}

void readFile(std::ifstream &fileName, std::string words[], int size) {
    std::string line;
    int i = 0;
    while (std::getline(fileName, line) && i < size) {
        words[i] = line;
        i++;
    }
    fileName.close();
}

std::string chosenWord (std::string words[], int size) {
    int num;
    std::string chosenWord;
    do {
        std::cout << "Please choose your favorite number (0-49): ";
        std::cin >> num;
        if (num >= 0 && num < size) {
            chosenWord = words[num];
        }
        else {
            std::cout << "Invalid number! ";
        }
    }while (num < 0 || num > size);

    return chosenWord; // return the word
}

bool guessingWord (std::string target, int length) {
    bool found = false;
    int count = 0;
    char letter;
    int remaining = length;
    std::string  word = "";
    do {
        // a copy so it won't directly decrease the length
        std::cout<< "Guess the letter for the word: ";
        std::cin >> letter;
        //(letter <= "A" && letter >= "Z" || letter <= "a" && letter >= "z"
        if (letter <= 'A' && letter >= 'Z'|| letter <= 'a' && letter >= 'z') {
            std::cout << "Not a letter! Try again!" << std::endl;
        }
            for (int i = 0; i < length; i++) {
                //char ch = letter[i];
                if (letter == target[i]){
                    remaining--;
                    found = true;
                    if (remaining < 0) {
                        remaining = 0;
                    }
                    std::cout << "Letter \"" << target[i] <<"\" found at position " << i + 1 << ". Word remaining: " << remaining << std::endl;
                    word += target[i];
                    if (word[i] != target[i]) {
                        swapLetters(word[i], target[i]);
                    }
                        std::cout << word << std::endl;
                }
            }

        if ( !found) {
            std::cout << "Word remaining: " << remaining << std::endl;
            std::cout << word << std::endl;
        }

        if (word == target) {
            return true;
        }
        count++;

        if (remaining == 0) {
            return true;
        }

    }while (count < MAX_GUESSING);

    return false;
}

void swapLetters(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}