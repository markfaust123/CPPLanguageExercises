#include "complex.h"

// You will add function definitons to this file
// See TODOs in complex.h

//// things to be added for part 2 ////
// TODO: operator<<
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    return os << c.real << " + " << c.imaginary << "i";
}

//// things to be added for part 3 ////
// TODO: copy constructor
Complex::Complex(const Complex& rhs) : real(rhs.real), imaginary(rhs.imaginary) { }

// TODO: assignment operator
Complex& Complex::operator=(const Complex& rhs) {
    this->real = rhs.real;
    this->imaginary = rhs.imaginary;
    return *this;
}

// TODO: add operator
Complex Complex::operator+(const Complex& rhs) const { 
    float sum_real = this->real + rhs.real;
    float sum_imaginary = this->imaginary + rhs.imaginary;
    Complex result(sum_real, sum_imaginary);
    return result;
}

// TODO: minus operator
Complex Complex::operator-(const Complex& rhs) const {
    float diff_rel = this->real - rhs.real;
    float diff_img = this->imaginary - rhs.imaginary;
    Complex result(diff_rel, diff_img);
    return result;
}

// TODO: times operator
Complex Complex::operator*(const Complex& rhs) const {
    float mult_rel = this->real * rhs.real + (-1 * (this->imaginary * rhs.imaginary));
    float mult_img = this->imaginary * rhs.imaginary;
    Complex new_complex(mult_rel, mult_img);
    return new_complex;
}

// TODO: times operator (float)
Complex Complex::operator*(const float& rhs) const {
    float mult_rel = this->real * rhs;
    float mult_img = this->imaginary * rhs;
    Complex result(mult_rel, mult_img);
    return result;
}

// TODO: divide operator
Complex Complex::operator/(const Complex& rhs) const {
    float left_num = this->real * rhs.real + this->imaginary * rhs.imaginary;
    float left_den = rhs.real * rhs.real + rhs.imaginary * rhs.imaginary;
    float right_num = this->imaginary *rhs.real - this->real *rhs.imaginary;
    float right_den = left_den;
    Complex result(left_num / left_den, right_num / right_den);
    return result;
}

//// things to be added for part 4 ////
// TODO: times operator for float times complex
Complex operator*(const float& lhs, const Complex& rhs) {
    float mult_rel = lhs * rhs.real;
    float mult_img = lhs * rhs.imaginary;
    Complex result(mult_rel, mult_img);
    return result;
}

