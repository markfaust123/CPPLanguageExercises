#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::sort;
using std::vector;

typedef struct {
  char letter;
  unsigned count;
} Bucket;

bool bucket_comparator(const Bucket& left, const Bucket& right);

int main(int argc, char **argv) {

  if (argc != 2) {
    std::cerr << "Execute program like: ./;etter_freq <inputfile>" << std::endl;
    return 1;
  }

  std::ifstream in(argv[1]);
  if (!in.is_open()) {
    std::cerr << "Error opening specified input file" << std::endl;
    return 1;
  }

  /*
  Diff ways of inputting
  while (cin >> token)
  while (getline(in, line))
  while (in.get(c))
  */

  std::vector<Bucket> buckets;

  for (int i = 0; i < 26; i++) {
    char letter = 97 + i;
    Bucket bucket = {letter, 0};
    buckets.push_back(bucket);
  }

  char character;
  while (in.get(character)) {
    if (isalpha(character)) {
      int index = tolower(character) - 97;
      (buckets[index].count)++;
    }
  }

  std::sort(buckets.begin(), buckets.end(), bucket_comparator);

  for (std::vector<Bucket>::const_iterator it = buckets.cbegin(); 
  it != buckets.cend();
  it++) {
    if (it->count != 0) 
      std::cout << it->letter << ": " << it->count << std::endl;
  }

  return 0;
}

bool bucket_comparator(const Bucket& left, const Bucket& right) {
  if (left.count == right.count) {
    return left.letter < right.letter;
  }
  return left.count > right.count;
}