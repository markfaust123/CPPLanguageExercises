/**
 * Hint: resolve the TODOs in grade_list.h first.
 * 
 * TODO: Write a program that declares a GradeList
 *       variable and adds to it all the even
 *       numbers 0-100:
 *       
 *       {0, 2, 4, ..., 98, 100}
 * 
 *       then prints out the minimum, maximum,
 *       median, mean and 75th percentile, all
 *       nicely labelled.
 */

#include <iostream>
#include "grade_list.h"

int main(void) {
    GradeList list;
    for (double i = 0; i <= 100; i=i+2) {
        list.add(i);
    }
    std::cout << "Minimum: " << list.percentile(0.0) << std::endl;
    std::cout << "Maximum: " << list.percentile(100.0) << std::endl;
    std::cout << "Median: " << list.median() << std::endl;
    std::cout << "Mean: " << list.mean() << std::endl;
    std::cout << "75th percentile: " << list.percentile(75.0) << std::endl;
    return 0;
}