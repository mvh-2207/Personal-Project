#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

const int MAX_NUM = 5;

int chosenLevel(int &num, int numOfBets[]);
bool guessingNumber(int &randomNum, int numOfBets[], int &num, int &count);
double finalBets(double &bets, int &num);

int main() {
    std::srand(std::time(nullptr)); // seed to generate random number
    int num;
    char choice;
    double bets, totalLeft, balance = 0.0;
    int randomNum;
    int numOfBets[MAX_NUM];
        std::cout << std::endl;
        std::cout << "-- Welcome you to my Casino Guessing Game --" << std::endl;
        std::cout << std::endl;
    do {
        int count = 0;
        std::cout << "Straight (1): 1 numbers " << std::endl;
        std::cout << "Split    (2): 2 numbers " << std::endl;
        std::cout << "Street   (3): 3 numbers " << std::endl;
        std::cout << "Coorner  (4): 4 numbers " << std::endl;
        std::cout << "Sixline  (5): 6 numbers " << std::endl;
        std::cout << "Please choose the wager you want to bet: ";
        std::cin >> num;
        randomNum = chosenLevel(num, numOfBets);
        std::cout << "How much do you bets: ";
        std::cin >> bets;
        for (int i = 0; i < num; i++) {
            std::cout << numOfBets[i] << std::endl;
        }
        bool found = guessingNumber(randomNum, numOfBets, num, count);
        totalLeft = finalBets(bets, num); // bet / num of wager
        balance += totalLeft; // keep the number of each wager
        if (found) {
            std::cout << "Your bet will be double and multiply with the numbers you guessed right!" << std::endl;
            std::cout << "Numbers of number you guessed right: " << count << std::endl;
            std::cout << "Here is the reward after you have guessed right " << count << " times: " << std::fixed
            << std::setprecision(2) << totalLeft * 2 * count << std::endl;
            balance += totalLeft * 2 * count; // num of each wager will be doubled with the number of right guessing
            balance -= totalLeft * 2 * (num - count); // minus the bet with the wrong guessing
            if (num == 5) {
                balance -= totalLeft * 2 * (6 - count);
            }
        }
        else {
            std::cout << "You lost. Your bet will belong to other players." << std::endl;
            balance -= totalLeft * 2 * (num - count); // minus the bet with they guess wrong
            if (num == 5) {
                balance -= totalLeft * 2 * (6 - count);
            }
        }
        std::cout << "Your current balance is: " << balance << std::endl;
        std::cout << "Do you want to continue betting?(y/n): ";
        std::cin >> choice;
        if (choice == 'N' || choice == 'n') {
            std::cout << "Thank you for playing. Hope to see you again!" << std::endl;
        }
    }while (choice == 'Y' || choice == 'y');
return 0;
}

/**
 *
 * @param num the chosen number of wager
 * @param numOfBets this will load in the number based on the wager
 * @return the num for straight wager
 */
int chosenLevel(int &num, int numOfBets[]) {
    int randomNum;
    randomNum = std::rand() % 37;
    if (num == 1) {
        randomNum = std::rand() % 37;
    }
    else if (num == 2) {
        for (int i = 0; i < num; i++) {
            numOfBets[i] = std::rand() % 37;
        }
    }
    else if (num == 3) {
        for (int i = 0; i < num; i++) {
            numOfBets[i] = std::rand() % 37;
        }
    }
    else if (num == 4) {
        for (int i = 0; i < num; i++) {
            numOfBets[i] = std::rand() % 37;
        }
    }
    else if (num == 5) {
        for (int i = 0; i < 6; i++) {
            numOfBets[i] = std::rand() % 37;
        }
    }
    return randomNum;
}

/**
 *
 * @param randomNum /random number for straight wager
 * @param numOfBets hold random numbers of other wager
 * @param num the chosen wager
 * @param count the number of time which the user bet the right numbers
 * @return whether player found the number or not
 */
bool guessingNumber(int &randomNum, int numOfBets[], int &num, int &count) {
    int num1, num2, num3, num4, num5, num6;
    do {
        std::cout << "Bet on numbers that you think will appear (0-37): ";
        if (num == 1) {
            std::cin >> num1;
            if (num1 == randomNum) {
                count ++;
                 return true;
            }
        }
        else if (num == 2) {
            std::cin >> num1 >> num2;
            for (int i = 0; i < num; i++) {
                if (num1 == numOfBets[i] || num2 == numOfBets[i]) {
                    count++;
                }
                 return true;
            }
        }
        else if (num == 3) {
            std::cin >> num1 >> num2 >> num3;
            for (int i = 0; i < num; i++) {
                if (num1 == numOfBets[i] || num2 == numOfBets[i] || num3 == numOfBets[i]) {
                    count++;
                }
                return true;
            }
        }
        else if (num == 4) {
            std::cin >> num1 >> num2 >> num3 >> num4;
            for (int i = 0; i < num; i++) {
                if (num1 == numOfBets[i] || num2 == numOfBets[i] || num3 == numOfBets[i] || num4 == numOfBets[i]) {
                    count++;
                }
                return true;
            }
        }
        else if (num == 5) {
            std::cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6;
            for (int i = 0; i < 6; i++) {
                if (num1 == numOfBets[i] || num2 == numOfBets[i] || num3 == numOfBets[i] || num4 == numOfBets[i]
                    || num5 == numOfBets[i] || num6 == numOfBets[i]) {
                    count++;
                    }
                return true;
            }
        }
    }while (num1 < 0 && num1 > 37 || num2 < 0 && num2 > 37 || num3 < 0 && num3 > 37 || num4 < 0 && num4 > 37 || num5 < 0 && num5 > 37 || num6 < 0 && num6 > 37);
    return false;
}

/**
 *
 * @param bets how much will the player wants to bet
 * @param num the chosen wager
 * @return the bet will be divided into each wager they have
 */
double finalBets(double &bets, int &num) {
    double total;
    if (num == 1) {
        total = bets;
    }
    else if (num == 2) {
        total = bets / 2;
    }
    else if (num == 3) {
        total = bets / 3;
    }
    else if (num == 4) {
        total = bets / 4;
    }
    else if (num == 5) {
        total = bets / 6;
    }
    return total;
}