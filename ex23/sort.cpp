#include <iostream>
#include <cassert>
#include <vector>

void sort( std::vector< int > &values );
void sort( std::vector< int > &values, int start, int end);
void merge( std::vector< int > &values, int start, int mid, int end);

int main( void )
{
  std::vector< int > vec;
  size_t count;

  std::cout << "Enter the count: ";

  // PART 2 TO DO: read in the count of random numbers from the standard input.
  std::cin >> count;

  // PART 3 TO DO: Make the "vec" vector store "count" random values
  for (size_t i = 0; i < count; i++) {
    vec.push_back(rand());
  }

  sort( vec );

  for( size_t i=1 ; i<vec.size() ; i++ ) assert( vec[i-1]<=vec[i] );

  return 0;
}

void sort( std::vector< int > &values )
{
  // PART 5 TO DO: Define the sort function
  sort(values, 0, int(values.size()));
}

void sort( std::vector<int> &values, int start, int end) {
  if (start > end) {
    return;
  }
  int mid = (end + start) / 2;
  sort(values, start, mid);
  sort(values, mid + 1, end);
  merge(values, start, mid, end);
}

void merge( std::vector<int> &values, int start, int mid, int end) {

  int n1 = mid - start + 1;
  int n2 = end - mid;

  int left[n1];
  int right[n2];

  for (int i = 0; i < n1; i++) {
    left[i] = values[start + i];
  }
  for (int j = 0; j < n2; j++) {
    right[j] = values[mid + j + 1];
  }

  int i = 0;
  int j = 0;
  int k = start;

  while (i < n1 && j < n2) {

    if (left[i] <= right[j]) {
      values[k] = left[i];
      i++;
    } else {
      values[k] = right[j];
      j++;
    } 
    k++;
  }

  while (i < n1) {
    values[k] = left[i];
    i++;
    k++;
  }

  while (j < n2) {
    values[k] = right[j];
    j++;
    k++;
  }

}