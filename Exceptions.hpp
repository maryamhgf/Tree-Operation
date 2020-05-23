#ifndef __EXCEPTIONS_HPP__
#define __EXCEPTIONS_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <bits/stdc++.h> 

using namespace std;

enum OperatorType { Add, Multiply, Not, Median};

#define DUMMY_ROOT 0
#define FAIL 0

class Duplicate_Id_Exception : public exception {
  virtual const char* what() const throw();
};

class Parent_Not_Exist : public exception {
  virtual const char* what() const throw();
};

class Invalid_Parent : public exception {
  virtual const char* what() const throw();
};

class Number_Of_Operands_Exception : public exception {
  virtual const char* what() const throw();
};



#endif


