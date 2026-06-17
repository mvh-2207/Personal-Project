#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>

const int MAX_NUM = 50;       //maximum word in file
const int MAX_GUESSING = 20;  //maximum guessing time

//function declaration
void readFile(std::ifstream &fileName, std::string words[], int size);
std::string chosenWord (std::string words[], int size);
bool guessingWord (std::string target, int length);
void swapLetters(char &a, char &b);

int main() {
    std::srand(std::time(nullptr)); //seed to choose random word in the array
    char choice;
    std::string words[MAX_NUM]; //array to store the word

    std::ifstream file("words.txt");
    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
    }
    readFile(file, words, MAX_NUM);

    do {
        std::string target = chosenWord(words, MAX_NUM); //the chosen word

        int length = target.length(); //the length of the word

        std::cout << "The length of the chosen word is: " << std::setfill('*') << std::setw(length + 1) <<
            "(" << length << ")" << std::endl;

        bool guess = guessingWord(target, length);  // result whether the user guessed the word or not

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

/**
 *
 * @param fileName access the file to read the words in it
 * @param words array to store 50 words in the file
 * @param size  maximum size of the array
 */
void readFile(std::ifstream &fileName, std::string words[], int size) {
    std::string line;
    int i = 0;

    while (std::getline(fileName, line) && i < size) {
        words[i] = line;
        i++;
    }
    fileName.close();
}

/**
 *
 * @param words array stores 50 words in the file
 * @param size  maximum size of the array
 * @return the word which the random element resulted in
 */
std::string chosenWord (std::string words[], int size) {
    int num;
    std::string chosenWord;
    num = std::rand() % size;

        if (num >= 0 && num < size) {
            chosenWord = words[num];
        }
    return chosenWord; // return the word
}

/**
 *
 * @param target the chosen word in the array
 * @param length the lenth of the word
 * @return whether the player guessed the word or not
 */
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

        if (letter <= 'A' && letter >= 'Z'|| letter <= 'a' && letter >= 'z') {
            std::cout << "Not a letter! Try again!" << std::endl;
        }
            for (int i = 0; i < length; i++) {
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

/**
 *
 * @param a the position of the letter in the guessing word
 * @param b the original position of the letter in the word
 */
void swapLetters(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}
