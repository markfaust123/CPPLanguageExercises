// 601.220 - example of inheritance, virtual functions, dynamic binding

#include "Aclass.h"
#include "Bclass.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main (void) {
  A aobj(1);
  A* aptr;
  B bobj(2);
  B* bptr;

  aptr = &aobj;
  aptr->show();
  aptr->display(); 
  cout << endl;
  // aobj.d = 17.5;  
  /* class A has its field "d"  
  as having the protected access modifier, meaning it can
  only be accessed by funcitons of the A class itself or any
  functions of A's derived classes
  */

  bptr = &bobj;
  aptr = bptr;   
  // aptr->setb(15); 
  /*
  aptr has type A*, so it can only hold objects of type A;
  therefore, when it is assigned the object pointed to by bptr, object slicing occurs,
  causing aptr to be unable to access the member methods of 
  class B
  */

  aptr->seta(3);
  aptr->show();     
  cout << endl;
  aptr->display();  

  cout << endl;
  aobj = A(10);
  aobj.show();
  aobj = bobj;
  aobj.show();
  A a5(5);
  // bobj = a5;  
  /*
  The assignment operator is not defined for the B class
  rather, the default assignment operator requires the
  explicit parameter to be of cont <class>& type
  */

}


