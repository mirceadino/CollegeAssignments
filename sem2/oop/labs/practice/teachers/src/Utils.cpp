#include "Utils.h"
#include <cstring>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

std::vector<std::string> tokenize(std::string buffer, char separator) {
  vector<string> tokens;
  istringstream ss(buffer);
  string token = "";
  string tmp;

  while (getline(ss, token, separator))
    tokens.push_back(token);

  return tokens;
}

int str_to_int(std::string& buffer) {
  int value;
  stringstream ss(buffer);
  ss >> value;
  return value;
}

double str_to_double(std::string& buffer) {
  double value;
  stringstream ss(buffer);
  ss >> value;
  return value;
}
