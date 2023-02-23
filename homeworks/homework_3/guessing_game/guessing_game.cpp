#include <iostream>
#include <random>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

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
  cin >> smallest;
  // get largest
  cout << "Please provide the largest number:\n";
  cin >> largest;
  // generate random number

  int rand_num = GenerateRandomNum(smallest, largest);
  cout << "I've generated a number. Try to guess it!\n";
  while (!win) {
    num_gueses++;
    cout << "Please provide the next guess:";
    if (!(std::cin >> guess)) {
      std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    if (guess < rand_num) {
      cout << "Your number is too small. Try again!\n";
    } else if (guess > rand_num) {
      cout << "Your number is too big. Try again!\n";
    } else {
      // Winner winner chicken dinner
      cout << " You've done it! You guessed the number " << rand_num << " in "
           << num_gueses << " guesses!\n";
      win = true;
    }
  }
}

int main() {
  playGame();

  return 0;
}