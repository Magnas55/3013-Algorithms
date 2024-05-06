/**
*
*
*  Author:           Sangam Lamichhane
*  Email:            slamichhane0602@my.msutexas.edu
*  Label:            P02
*  Title:            Searching in Json file using Getch function
*  Course:           CMPS 3013
*  Semester:         Spring 2024

 * This C++ program loads a JSON file and performs searches for keys that start 
 * with a specified substring, then stores and returns those key-value pairs using
 * a std::map. This functionality is designed to demonstrate basic JSON handling 
 * and text processing within a C++ environment.
 *
 * Features:
 * - Load JSON data from a file using nlohmann::json.
 * - Search for JSON keys that begin with a user-defined substring.
 * - Collect and display these key-value pairs.
 *
 * Usage:
 * The program contains functions to load a JSON file (`loadJsonFile`), print its
 * content (`printJson`), and search for keys starting with a given substring (`printMatches`).
 * These functionalities encapsulate file operations, JSON parsing, and basic string processing.
 *
 * Functions:
 * - json loadJsonFile(string filePath):
 *     Loads a JSON file from a specified path into a nlohmann::json object.
 * - void printJson(json d):
 *     Prints each key-value pair contained in the json object.
 * - map<string, string> printMatches(json d, string sub):
 *     Searches the json object for keys that begin with the specified substring and stores
 *     them in a std::map, which is then returned.
 *
*/





#include "./headers/json.hpp" // Make sure this points to the correct path of json.hpp
#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

using json = nlohmann::json;

// loads a json file into a variable and returns it
json loadJsonFile(string filePath) {

  // we should add error checking in real life

  ifstream f(filePath);
  json data = json::parse(f);

  return data;
}

// prints out some json file.
void printJson(json d) {
  for (auto &element : d.items()) {
    string key = element.key();
    string val = element.value();

    cout << "key: " << key << " :: val: " << val << endl;
  }
}

map<string,string> printMatches(json d, string sub) {
  // Create a map of strings to integers
  map<string, string> map;

  //vector<string> matches; // to hold any matches
  if(sub.size() == 0) {
    return map;
  }
  // return vector 
  for (auto &element : d.items()) {
    string key = element.key();
    string val = element.value();
    // cout<<"key "<<key<<endl;
    // cout <<"key.substr(0, sub.size() " <<key.substr(0, sub.size()<<endl;
    // cout<"sub "<<sub<<endl;

    // Check if the key contains the partialKey substring
    if (key.substr(0, sub.size()) == sub) {

      //matches.push_back(key);
      map[key] = val;
      // Found a match, do something with it
      // cout << "Found partial match: " << key << " -> " << val
      //      << endl;

    }
  }
  return map;
}

// int main() {

//   json dictionary = loadJsonFile("./dictionary_2mb.json");
//   // printJson(dictionary);

//   printMatches(dictionary, "aba");
//   return 0;
// }
