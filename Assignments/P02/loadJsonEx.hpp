#include "./headers/json.hpp" // Make sure this points to the correct path of json.hpp
#include <fstream>
#include <iostream>
#include <string>

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

vector<string> printMatches(json d, string sub) {

  vector<string> matches; // to hold any matches
  if(sub.size() == 0) {
    return matches;
  }
  // return vector 
  for (auto &element : d.items()) {
    string key = element.key().tolower();
    string val = element.value();
    // cout<<"key "<<key<<endl;
    // cout <<"key.substr(0, sub.size() " <<key.substr(0, sub.size()<<endl;
    // cout<"sub "<<sub<<endl;
    
    // Check if the key contains the partialKey substring
    if (key.substr(0, sub.size()) == sub) {

      matches.push_back(key);
      // Found a match, do something with it
      // cout << "Found partial match: " << key << " -> " << val
      //      << endl;
      
    }
  }
  return matches;
}

// int main() {

//   json dictionary = loadJsonFile("./dictionary_2mb.json");
//   // printJson(dictionary);

//   printMatches(dictionary, "aba");
//   return 0;
// }