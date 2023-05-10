#ifndef _ACLASS_H
#define _ACLASS_H

#include <iostream>
#include <string>
#include <sstream>

class A { // base class

private: 
  int a;

protected:
  double d;

public: 
  A(int val = 0, double num = 0): a(val), d(num) { }
  int geta() const { return a; }
  void seta(int val) { a = val; }
  void setd(double dval) { d = dval; }
  virtual std::string toString() const;
  virtual int fun() const = 0;
};

std::string A::toString() const {
  std::stringstream ss;
  ss << "[Aclass: a = " << a << ", d = " << d << ", size = " << sizeof(*this) << "]" << std::endl;
  return ss.str();
}

#endif