#ifndef MY_TEMPLATE
#define MY_TEMPLATE

#include <vector>

void calc_token_info(std::vector<std::string>& strings, int& ntok, int& ntok_c) {
  for (std::vector<std::string>::const_iterator it = strings.cbegin();
  it != strings.cend();
  it++) {
    ntok++;
    ntok_c += it->size();
  }
}

template <typename T>
void calc_sum(std::vector<T> &vec, T& sum) {
  for (typename std::vector<T>::const_iterator it = vec.cbegin();
  it != vec.cend();
  it++) {
    sum += *it;
  }
}

#endif