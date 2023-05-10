#ifndef COMPLEX
#define COMPLEX

#include <iostream>

class Complex {
    public:

        Complex() : real(0), imaginary(0) {}
        Complex(float r) : real(r), imaginary(0) {}
        Complex(float r, float i) : real(r), imaginary(i) {}
        Complex(const Complex& rhs);

        friend std::ostream& operator<<(std::ostream& os, const Complex& c);
        friend Complex operator*(const float& lhs, const Complex& rhs);

        Complex& operator=(const Complex& rhs);
        Complex operator+(const Complex& rhs) const;
        Complex operator-(const Complex& rhs) const;
        Complex operator*(const Complex& rhs) const;
        Complex operator*(const float& rhs) const;
        Complex operator/(const Complex& rhs) const;

    private:
        float real, imaginary;
};

#endif