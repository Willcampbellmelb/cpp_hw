/**
 * @file fortune_teller.cpp
 * @author William Campbvell(wacampbvel@gmail.com)
 * @brief  A C++ program that communicates with the user by using screams.
 * @version 0.1
 * @date 2023-02-21
 *
 * @copyright Copyright (c) 2023
 *
 */
// version one without objects
// version two uses user objects
#include <iostream>
#include <map>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::string_literals::operator""s;
std::string generated_adjective(string a, string b) {
  string adj = "HELLA";
  return adj;
}
std::string lookup_ending(string a, string b) {
  string ending = "The end";
  return ending;
}
/**
 * @brief prints fortune based on string input using custom list of words
 *
 */
void printFortune(std::string name, std ::string season, std::string a_01,
                  std::string a_02) {

  auto adj = generated_adjective(a_01, a_02);
  auto ending = lookup_ending(a_01, a_02);
  // <NAME>, the <ADJECTIVE> <NOUN> that <ENDING>
  cout << name + ", the "s + adj + " COOL GUY "s + " that "s + ending << endl;
}

int main() {
  // Print a welcome statement:
  cout << " Welcome to the fortune teller program!\n";
  // Ask the user for their name:
  std::string name;
  std::string season;
  std::string adjective_01;
  std::string adjective_02;

  cout << "Please enter your name:";
  cin >> name;

  // Enter Ask the user when they were born:
  cout << "Please enter the time of year when  you were born: (pick from "
          "'spring', 'summer', 'autumn', 'winter'):";
  cin >> season;
  // Ask for adjectives:
  cout << "Please enter an adjective:";
  cin >> adjective_01;
  cout << "Please enter another:";
  cin >> adjective_02;
  printFortune(name, season, adjective_01, adjective_02);
}
