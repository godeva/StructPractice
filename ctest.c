#include <stdio.h>
// string.h covers the C-style string functions.
#include <string.h>
/*Stores function prototype for ctest.c*/
#include "mystring.h"

/** ctest.c
* Program to demonstrate character arrays and
* dynamically-allocated memory.
* @author Mike Ciaraldi and Goutham Deva
*/

const int MAX_CHARS = 20; // Maximum number of characters in array

int main() // Runs Program
{
  char a1[MAX_CHARS + 1]; // Character array--initially empty
  char a2[] = "Hello"; // Character array--unsized but initialized
  char a3[MAX_CHARS + 1]; // Character array--we will underfill it
  char* p1 = "Hello"; // Pointer to constant string
  char* p2;           // Will be a pointer to dynamically-allocated string
  int copy_limit;     // Maximum characters to copy
  char b[MAX_CHARS + 1]; // Test for mystrncpy() if string duplicated works with specified corner cases
  char b1[] = "DUCKS"; // Test for mystrndup() if string duplicated works with specified corner cases
  char* p4;           // Pointer to dynamically-allocated string using mystrndup

  mystrcpy(a3, "Hello, also"); // Initialize underfilled character array

  /* Print the pointers.
  Note: this example prints
  the values of the pointers themselves, not the targets.
  */
  printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
  printf("          p1 = %p p2 = %p\n", p1, p2);

  mystrcpy(a1, "Hi"); // Initialize character array

  printf("Contents of a1 = %s\n", a1);
  printf("Contents of a2 = %s\n", a2);
  printf("Contents of a3 = %s\n", a3);

  // Concatenate two character arrays, then print.
  mystrcat(a1, a2);
  printf("After concatenating a2 to a1, contents of a1 = %s\n", a1);

  // Concatenate two character arrays with limit, then print.
  mystrncat(a1, a2, 8);
  printf("After concatenating a2 to a1, max length 8, contents of a1 = %s\n",
  a1);

  // Copy with limit.
  mystrncpy(a1, a2, 3);
  printf("After copying a2 to a1, max length 3, contents of a1 = %s\n", a1);
  printf("Note that copied string was not terminated.\n");

  // Reset a1
  mystrcpy(a1, "Hi"); // Initialize character array
  printf("Resetting. a1 = %s\n", a1);

  // Concatenate two character arrays with limit, then print.
  mystrncat(a1, a2, 2);
  printf("After concatenating a2 to a1, max length 2, contents of a1 = %s\n",
  a1);
  printf("Note that copied string was terminated.\n");


  // Duplicate a string, using my function, then print
  printf("Before dup, pointer a2 = %p, contents = %s\n", a2, a2);
  p2 = mystrdup(a2);
  printf("After dup, pointer p2 = %p, contents = %s\n", p2, p2);

  printf("\n"); // Adds blank space line in terminal to make program easier to view

  printf("Testing corner cases for mystrncpy\n");
  //Test if string being copied is longer than the specified length.
  //Fills first ten elements as well as the terminator in b[10]
  mystrcpy(b , "ABCDEFGHIJ");
  printf("String b = %s\n", b);
  //Only copies first 5 characters
  mystrncpy(b, "ILIKEDUCKS", 5);
  printf("String b with n less then length is = %s\n", b);

  //Test if string being copied is the same as the specified length.
  //Only copies 10 characters
  mystrncpy(b, "ILIKEDUCKS", 10);
  printf("String b with n = length shouldn't append to ILIKEDUCKS = %s\n", b);

  //Test if string being copied is less than the specified length.
  //Copies 12 characters which is more characters than in string
  mystrncpy(b, "ILIKEDUCKS", 12);
  printf("String b with n > length shouldn't append to ILIKEDUCKS  = %s\n", b);

  printf("\n"); // Adds blank space line in terminal to make program easier to view


  //Test if string being copied is longer than the specified length.
  printf("Testing corner cases for mystrndup\n");
  //Printing pointers
  printf("Pointers: b1 = %p\n", b1);
  printf("          p4 = %p\n", p4);

  //Duplicate string using mystrndup then, prints result
  //Test if string duplicated is longer than the specified length.
  printf("Before dup, pointer b1 = %p, contents = %s\n", b1, b1);
  p4 = mystrndup(b1, 3);
  printf("After dup more than specfied length, pointer p4 = %p, contents = %s\n", p4, p4);
  //Test if string duplicated is the same as the specified length.
  printf("Before dup, pointer b1 = %p, contents = %s\n", b1, b1);
  p4 = mystrndup(b1, 5);
  printf("After dup length equal to specfied length, pointer p4 = %p, contents = %s\n", p4, p4);
  //Test if string duplicated is less than the specified length.
  printf("Before dup, pointer b1 = %p, contents = %s\n", b1, b1);
  p4 = mystrndup(b1, 10);
  printf("After dup less than specfied length, pointer p4 = %p, contents = %s\n", p4, p4);

  return 0; // Initialized Success!
}
