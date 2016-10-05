/** mystruct.h
* @author Goutham Deva
* My own versions of some of the C-style struct functions
*/

#ifndef MYSTRUCT_H
#define MYSTRUCT_H

#include <stdio.h>

#define SOME_LEN 20 // symbolic constant

// Function Protoypes
typedef struct employee { //Carries Employee information on name, favorite color, birth and start year
  char name[SOME_LEN];
  int birth_year;
  int starting_year;
} employee ; //replaces "employee" with "struct employee" due to typedef


employee* make_employee(const char* name, int birth_year, int starting_year);
char ranLetterGen();
char* ranStringGen(size_t size);
employee* addEmployee();
void printfunc(employee* parameter);
void printEmployees(employee** list, int count);
employee** structGen(int count);
employee** shallowCopy(employee** employees, int count);
void freedom(employee** employees, int count);
employee** deepCopy(employee** employees, int count);

#endif
