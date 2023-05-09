#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "my_template.h"

using std::string;
using std::stringstream;
using std::cin;
using std::cout;
using std::endl;

void calc_token_info(std::vector<std::string> &vec, int& num_tok, int& num_char);

int main() {

  double sum_fp = 0.0;  // sum of floating point tokens
  int sum_i = 0;        // sum of integer tokens
  int ntok = 0;         // count of non-numeric tokens
  int ntok_c = 0;       // number of characters in non-numeric tokens

  std::vector<double> floats;
  std::vector<int> ints;
  std::vector<std::string> strings;

  string token;

  // TODO: implement statements to get input, determine and count the token types
  double double_temp;
  int int_temp;
  std::string string_temp;
  bool is_ival, is_fval = false;

  while (cin >> token) {
    std::stringstream integer(token);
    if (integer >> int_temp) {
      if (!(integer >> string_temp)) {
        ints.push_back(int_temp);
        is_ival = true;
      }
    }
    if (!is_ival) {
      std::stringstream floating(token);
      if (floating >> double_temp) {
        floats.push_back(double_temp);
        is_fval = true;
      }
    }
    if (!is_ival && !is_fval) {
      std::stringstream string(token);
      if (string >> string_temp) {
        strings.push_back(string_temp);
      }
    }

    is_ival = false;
    is_fval = false;
    
  }

  calc_sum(floats, sum_fp);
  calc_sum(ints, sum_i);
  calc_token_info(strings, ntok, ntok_c);

  cout << "Floating point sum: " << sum_fp << endl;
  cout << "Integer sum: " << sum_i << endl;
  cout << "Number of non-numeric tokens: " << ntok << endl;
  cout << "Number of characters in non-numeric tokens: " << ntok_c << endl;

  return 0;
}