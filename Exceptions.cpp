#include "Exceptions.hpp"

using namespace std;

const char* Duplicate_Id_Exception::what() const throw() {
    return "‫‪Duplicate‬‬ ‫‪node‬‬ ‫‪ID.‬‬";
}

const char* Parent_Not_Exist::what() const throw() {
    return "‫‪Parent‬‬ ‫‪node‬‬ ‫‪not‬‬ ‫‪found.‬‬" ;
}

const char* Invalid_Parent::what() const throw() {
   return "‫‪Invalid‬‬ ‫‪parent.‬‬" ;
}

const char* Number_Of_Operands_Exception::what() const throw() {
    return "‫‪Invalid‬‬ ‫‪tree‬‬ ‫‪structure.‬‬";
}