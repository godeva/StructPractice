/** mystring.c
* @author Goutham Deva
* My own versions of some of the C-style struct functions
*/

#include <string.h>
// stdlib.h is needed to use malloc()
#include <stdlib.h>
// Allows Printf
#include <stdio.h>
/*Stores function prototype for mystruct.c*/
#include "mystruct.h"
/* Allows the use time command  */
#include <time.h>

/** Allocates employee struct of that type and fills its fields with data passed in as parameters
* @param name Pointer that stores the full name of the employee
* @param birth_year integer type stores birth year of employee
* @param starting_year integer type that stores the year the employee started working
* @return Pointer that stores all the field data
*/

struct employee* make_employee(const char* name, int birth_year, int starting_year) { // Runs Program
  struct employee* ptr = (employee*)malloc(sizeof(employee)); // Allocates memory to struct
  strcpy(ptr->name, name); // Copies string of that points to name
  ptr->birth_year = birth_year; // Points to birth_year
  ptr->starting_year = starting_year; // Points to starting_year
  return ptr;
}


/** Generates and returns a single random character
* Function is restricted to the 26 upper-case letters ABC...XYZ
* @return Random single character letter
*/

char ranLetterGen() { // Runs Program
  return 'A' + (random() % 26); // Generates and returns a random captial letter
}

/** Prints Struct
* @param parameter pointer that points to selected struct
* @return Printed Struct
*/

void printfunc(employee* parameter) { // Runs Program
  printf("Name: %s\n",parameter ->name); // Points to name and prints value
  printf("Birth Year: %d\n",parameter->birth_year); // Points to birth_year and prints value
  printf("Starting Year: %d\n",parameter ->starting_year); // Points to starting_year and prints value
}

/** generates a random string of printable characters, with a specified length.
* @param size specfied length of the string
* @return Random string of specfied length
*/

char* ranStringGen(size_t size) { // Runs Program
  char* randomString = NULL;

  if (size) { // Checks if size is entered
    randomString = malloc(sizeof(char)*(size+1));  // Allocates memory

    if (randomString) {
      for (int n = 0; n < size; n++) { // Terminates when string size is meet
        char value = ranLetterGen(); // Calls random letter generator function
        randomString[n] = value; // Generates each random characters in string
      }
      randomString[size] = '\0';
    }
  }
  return randomString;
}

/** Creates a struct of the type you have chosen and fills it with random data.
* Generates random string and two random years above 1950 for birth year and above
* 1990 for starting year
* @return Randomly generated struct
*/

employee* addEmployee() { // Runs program
  struct employee* ptr = (employee*)malloc(sizeof(employee)); // Allocates memory
  char* randomString; // Used to store random string
  const int length = 5; // Keeps string length at 5 characters

  randomString = ranStringGen(length); // Enters specfied length randomly generated string
  int birth = (rand()%11) + 1950; /* Random int between 1950 to 1960*/
  int start = (rand()%11) + 1990; /* Random int between 1990 to 2000 */

  ptr->birth_year = birth; // Sets randomly generated year to birth_year
  ptr->starting_year = start; // Sets randomly generated year to starting_year
  strcpy(ptr->name,randomString); // Sets and copies randomly generated string to name
  free((void*) randomString); // Frees allocated memory

  return ptr;
}

/** Allocate an array which can hold specified amount of pointers to the struct
* @param count Number of structs to generate
* @return Specfied number of randomly generated structs
*/

employee** structGen(int count) { // Runs Program
  employee** ptr = (employee**)malloc(sizeof(employee*) * count); // Allocates memory
  int i; // Keeps track of each struct created

  for(i = 0; i < count; i++) { // Terminates when specfied number is meet
    employee* randEmployee = addEmployee(); // calls addEmployee which creates random struct
    ptr[i] = randEmployee;
  }

  return ptr;
}

/** Takes an array of pointers and a count, and prints out all the structs
* @param list array of pointers randomly generated
* @param count Number of structs to print
* @return printed number of employees
*/

void printEmployees(employee** list, int count) { // Runs Program
  int i; // Keeps track of numumber of printsber of prints

  for(i = 0; i < count; i++) { // Termiantes when number of prints is meet
    printfunc(list[i]); // Prints array of pointers
    printf("\n"); // Adds blank line so each print is easily readable
  }
  return;
}

/** Duplicates an array of pointers to structs of this type
* Note: Function duplicates the pointers but not the things pointed to
* @param employees list array of pointers randomly generated
* @param count keeps track of each pointer
* @return copy of array of pointers
*/

employee** shallowCopy(employee** employees, int count) { // Runs program
  employee** ptr = (employee**)malloc(sizeof(employee*) * count); // Allocates memory
  int i; // Keeps track of count in loop

  for(i = 0; i < count; i++) { // Termiantes when count is meet
    ptr[i] = employees[i];

  }
  return ptr;
}

/** Create a function which takes an array of pointers to the
* struct, and frees (de-allocates) all the structs pointed to.
* assume it hasn't been freed already (change)
* doesn't free orginal array so there is still array as an object (change)
* @param employees list array of pointers randomly generated
* @param count keeps track of each pointer
*/

void freedom(employee** employees, int count) { // Runs program
  int i; // Keeps track of specied count

  for(i = 0; i < count; i++) { // Terminates when specfied amount is meet
    free(employees[i]); // Frees each pointer
  }
}

/** Function which duplicates an array of pointers to the structs
* Note: This function duplicates the structs, then fill the array
* with pointers to these new structs.
* @param employees list array of pointers randomly generated
* @param count keeps track of each pointer
* @return copy of array of pointers
*/

employee** deepCopy(employee** employees, int count) { // Runs program
  employee** ptr = (employee**)malloc(sizeof(employee*) * count); // Allocates memory
  int i; // Keeps track of specied count

  for(i = 0; i < count; i++) { // Terminates when specfied amount is meet
    employee* temp = employees[i]; // Temporary employee pointer
    ptr[i] = make_employee(temp->name, temp->birth_year, temp->starting_year); // Following pointers to the fields

  }
  return ptr;
}
