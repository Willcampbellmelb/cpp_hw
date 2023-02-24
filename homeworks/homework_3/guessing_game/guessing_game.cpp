#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

// validate user input
string GetLine() {
  string result;
  getline(cin, result);
  return result;
}

int GetInteger() {
  while (true) {
    // get line from user and put into a string stream
    std::stringstream ss;
    int result{};
    ss << GetLine();
    // check that user put in an int
    if (ss >> result) {
      char remaining;
      // check that is all they put in
      if (ss >> remaining) {
        cout << "Unexpected character:" << remaining << endl;
      } else {
        return result;
      }
    } else {
      cout << "Please enter an integer!\n";
    }
    cout << "Retry: ";
  }
}
bool allAlpha(std::string str) {
  auto it = std::find_if_not(str.begin(), str.end(),
                             [](char const &c) { return isalpha(c); });
  return it == str.end(); // if we reach end of string - all values alpha
}
string GetWord() {
  while (true) {
    std::stringstream converter;
    converter << GetLine();
    string input{};
    if (converter >> input) {
      cout << "user input" << input << endl;
      char remainder{};
      if (converter >> remainder) {
        cout << "Unexpected input character " << remainder << endl;
      } else {
        // check word comprised of all aphabetic chars
        if (allAlpha(input)) {
          return input;
        } else {
          cout << "user input not alpha numeric characters: " << input << endl;
        }
      }
    } else {
      cout << "please input a single word!\n";
    }
    cout << "Retry: ";
  }
}

int GenerateRandomNum(int small, int large) {
  // generate random number
  std::random_device random_device;
  std::mt19937 random_engine{random_device()};
  std::uniform_int_distribution<int> distribution{small, large};
  return distribution(random_engine);
}
void playGame() {
  int smallest{};
  int largest{};
  int guess{};
  int num_gueses{0};
  bool win{false};

  cout << "Welcome to the GUESSING GAME!\n"
       << "I will generate a number and you will guess it!\n"
       << "Please provide the smallest number:\n";
  smallest = GetInteger();
  // get largest
  cout << "Please provide the largest number:\n";
  largest = GetInteger();
  // generate random number

  const int rand_num = GenerateRandomNum(smallest, largest);
  cout << "I've generated a number. Try to guess it!\n";
  while (!win) {
    num_gueses++;
    cout << "Please provide the next guess: ";
    guess = GetInteger();
    if (guess < rand_num) {
      cout << "Your number is too small. Try again!\n";
    } else if (guess > rand_num) {
      cout << "Your number is too big. Try again!\n";
    } else {
      // Winner winner chicken dinner
      cout << "You've done it! You guessed the number " << rand_num << " in "
           << num_gueses << " guesses!\n";
      win = true;
    }
  }
}

int main() {
  playGame();

  return 0;
}