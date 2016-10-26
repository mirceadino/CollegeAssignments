#ifndef UTILS_H_
#define UTILS_H_

#include <vector>
#include <string>

std::vector<std::string> tokenize(std::string buffer, char separator = 0);
int str_to_int(std::string& buffer);
double str_to_double(std::string& buffer);

#endif /* UTILS_H_ */
