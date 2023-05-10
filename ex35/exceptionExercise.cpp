#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <stdexcept>

/* Collect integers from a file; store them in a vector */
std::vector<int> readFile(char* filename) {
  std::ifstream fin(filename);

  if (!fin.is_open()) {
    throw std::ios_base::failure("Error: failed to open specified input file.\n");
  }

  std::vector<int> numbers(10);

  int n = 0;
  size_t index = 0;
  while(true) {
    fin >> n;
    if (fin.eof()) { // if we're out of file, return
      return numbers;
    }
    if (fin.fail()) { // if we failed to read an int, throw an exception
      throw std::invalid_argument("File contains non-integer data!\n");
    }
    try {
      // otherwise, just add it into the vector
      numbers.at(index) = n;
    } catch (std::out_of_range e) {
      numbers.push_back(n);
    }
    index++;
    
  }

  throw std::logic_error("ERROR: should never get here!\n");
  return numbers;
}


int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Error: program requires a filename as an argument\n";
    return 0;
  }

  std::vector<int> numbers;
  try {
    numbers = readFile(argv[1]);
  } catch (std::out_of_range &ex) {
    std::cerr << "Error: input size out of vector range" << std::endl;
    return 1;
  } catch (std::ios_base::failure &e) {
    std::cout << e.what();
    return 1;
  } catch (std::invalid_argument &e) {
    std::cout << e.what();
    return 1;
  }
  

  std::cout << "Read numbers: ";
  for(int &i : numbers) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
