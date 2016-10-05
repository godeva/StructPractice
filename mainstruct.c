#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// mystruct.h covers the C-style struct functions.
/*Stores function prototype for mainstruct.c*/
#include "mystruct.h"
//Allows the the use time command
#include <time.h>

/** mainstruct.c
* Program demonstrates c knowledge of structs
* @author Goutham Deva
*/

int main() //Runs struct program
{
  /* Allows String/Number generator to generate a different succession of results each rand() call*/
  srand (time(NULL));

  /* Testing if make_employee function works by adding test parameters */
  //Creates new employee and prints the employee information
  employee *Steve = make_employee("Steve Rogers", 1941, 2011);
  employee *Goutham = make_employee("Goutham Deva", 1997, 2016);

  printf("Employee Struct Function Test Example\n");
  printfunc(Steve);
  printf("\n"); // Adds blank space line in terminal to make program easier to view
  printfunc(Goutham);
  printf("\n"); // Adds blank space line in terminal to make program easier to view

  // Generates a random letter by calling ranLetterGen function
  // Note: Function is purposely restricted so that only capital letters are only generated
  printf("Random Single Character Function Call Test\n");
  char s = ranLetterGen(); //Calls random letter generator function and sets to s
  printf("Random Letter: %c \n", s);

  printf("\n"); // Adds blank space line in terminal to make program easier to view

  // Generates a random string by calling ranStringGen function
  printf("Random String Function Call Test\n");
  char* t = ranStringGen(5); //Calls random string generator function and sets to t
  printf("Random string: %s \n", t);

  printf("\n"); // Adds blank space line in terminal to make program easier to view

  // Prints out randomly created struct of Employee type
  printf("Random New Struct Function Call Test\n");
  char* randomString = ranStringGen(5); // Calls new struct with random string set to only 5 characters
  printfunc(addEmployee()); // Prints Employee struct
  printf("\n"); // Adds blank space line in terminal to make program easier to view
  free((void*) randomString); //Frees memory that was allocated

  // Prints out two randomly created struct of Employee type and makes two copies of both
  printf("Number of Random Struct Made and Copied Function Call Test\n");
  employee** example = structGen(2); //Creates to two random employee structs
  printEmployees(example, 2); //Prints out both of the structs twice!

  //Creates a shallowCopy of the previous example above
  printf("Shallow Copy Function Call Test\n");
  employee** example2 = shallowCopy(example, 2); // Sets example2 to shallowCopy of previous example
  printEmployees(example2, 2); // Prints shallowCopy of example2 twice!
  free((void*) example2);// Frees array

  //Creates a deepCopy of the previous example made before shallowCopy
  printf("Deep Copy Function Call Test\n");
  employee** example3 = deepCopy(example, 2); // Sets example3 to shallowCopy of example
  printEmployees(example3, 2); // Prints shallowCopy of example3 twice!
  freedom(example3, 2); // First frees structure in pointer
  free((void*) example3);// Then frees array

  return 0; // Initialized Success!
}
