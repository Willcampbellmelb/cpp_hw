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
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
std::map<string, string> noun = {{"spring", "STL guru"},
                                 {"summer", "C++ expert"},
                                 {"autumn", "coding beast"},
                                 {"winter", "software design hero"}};

const std::vector<string> ending{"eats UB for breakfast",
                                 "finds errors quicker than the compiler",
                                 "is not afraid of C++ error messages"};
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
string GetSeason() {
  while (true) {
    string season = GetWord();
    // check that word is in season map
    if (noun.count(season)) {
      return season;
    } else {
      cout << "user input missmatch:" << season << " is not a valid input\n";
    }
    cout << "Retry (pick from 'spring', 'summer', 'autumn', 'winter'):";
  }
}
using std::string_literals::operator""s;
/**
 * @brief Read the two adjectives from the user inputs in and store them in an
array or vector.
// Use the modulo division by the size of the array of your adjectives on the
length of
// the provided <NAME> to get an index that you can use to get an adjective from
your array of adjectives
*/
string lookup_ending(string b) {
  string ending = "The end";
  return ending;
}
/**
 * @brief prints fortune based on string input using custom list of words
 *
 */
void printFortune(std::string name, std ::string season, std::string adj,
                  string noun, string ending) {
  cout << "\nHere is your description:\n";
  // <NAME>, the <ADJECTIVE> <NOUN> that <ENDING>
  cout << name + ", the "s + adj + " " + noun + " that "s + ending << endl;
}

int main() {
  std::vector<string> adj{};
  cout << "Welcome to the fortune teller program!\n";
  cout << "Please enter your first name:\n";
  string name = GetWord();
  cout << "Please enter the time of year when you were born:\n"
          "(pick from 'spring', 'summer', 'autumn', 'winter')\n";
  string season = GetSeason();
  cout << "Please enter an adjective:\n";
  string adjective_01 = GetWord();
  cout << "Please enter another adjective:\n";
  string adjective_02 = GetWord();
  adj.emplace_back(adjective_01);
  adj.emplace_back(adjective_02);
  uint adj_index = name.size() % adj.size() - 1;
  adj_index = adj_index > adj.size() - 1 ? adj.size() - 1
                                         : adj_index; // check out of bounds
  uint end_index = name.size() % ending.size();
  adj_index = end_index > ending.size() - 1 ? ending.size() - 1
                                            : end_index; // check out of bounds

  printFortune(name, season, adj[adj_index], noun[season], ending[end_index]);
}
