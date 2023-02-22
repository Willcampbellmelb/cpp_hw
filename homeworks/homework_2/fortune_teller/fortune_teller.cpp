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
/**
 * @brief Read the two adjectives from the user inputs in and store them in an
array or vector.
// Use the modulo division by the size of the array of your adjectives on the
length of
// the provided <NAME> to get an index that you can use to get an adjective from
your array of adjectives
*/

std::string lookup_ending(string b) {
  string ending = "The end";
  return ending;
}
/**
 * @brief prints fortune based on string input using custom list of words
 *
 */
void printFortune(std::string name, std ::string season, std::string adj,
                  string noun, string ending) {
  cout << " Here is your description:\n";
  // <NAME>, the <ADJECTIVE> <NOUN> that <ENDING>
  cout << name + ", the "s + adj + " " + noun + " that "s + ending << endl;
}
std::map<string, string> noun = {{"spring", "STL guru"},
                                 {"summer", "C++ expert"},
                                 {"autumn", "coding beast"},
                                 {"winter", "software design hero"}};

const std::vector<string> ending{"eats UB for breakfast",
                                 "finds errors quicker than the compiler",
                                 "is not afraid of C++ error messages"};
int main() {
  // Print a welcome statement:
  cout << "Welcome to the fortune teller program!\n";
  // Ask the user for their name:
  std::string name;
  std::string season;
  std::string adjective_01;
  std::string adjective_02;
  std::vector<string> adj{};
  cout << "Please enter your name:\n";
  cin >> name;

  // Enter Ask the user when they were born:
  cout << "Please enter the time of year when  you were born: (pick from \n"
          "'spring', 'summer', 'autumn', 'winter'):\n";
  cin >> season; // need to type check this
  // Ask for adjectives:
  cout << "Please enter an adjective:\n";
  cin >> adjective_01; // type check this
  adj.emplace_back(adjective_01);
  cout << "Please enter another:\n";
  cin >> adjective_02; // type check this
  adj.emplace_back(adjective_02);
  int mod = adj.size() % name.length();
  printFortune(name, season, adj[mod - 1], noun[season], ending[mod - 1]);
}
