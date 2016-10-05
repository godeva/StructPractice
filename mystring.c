/** mystring.c
* @author Mike Ciaraldi and Goutham Deva
* My own versions of some of the C-style string functions
*/
#include <string.h>
// stdlib.h is needed to use malloc()
#include <stdlib.h>
// mystring.h covers the C-style string functions.
/*Stores function prototype for mystring.c*/
#include "mystring.h"

/** Creates a pointer to a new string which is a duplicate of the string
* @param src Pointer to string to be copied
* @return Pointer to freshly-allocated string containing a duplicate of src
* or null if no memory is available
*/

char* mystrdup(char* src) { //Runs Program
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;  // Leaves Number of characters/length of C stringpace for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  // Note: strcpy() always puts the null terminator at the tend of the string.
  mystrcpy(newstr, src);
  return newstr;
}

/** Duplicates a C-style string. If s is
* longer  than  n,  only  n bytes are copied, and
* a terminating null byte ('\0') is added.
* @param src Pointer to string to be copied
* @param size_t n Maximum number of characters from “src" to be copied
* @return Pointer to freshly-allocated string containing a duplicate of src
* or null if no memory is available based on number of n bytes entered
*/

char* mystrndup(char* src, size_t n) {
  int length; // Length of the source string
  char* dest; // Pointer to memory which will hold new string

  length = mystrlen(src) + 1; // Leave sNumber of characters/length of C stringpace for the terminator
  dest = (char*) malloc (length); // Must cast!

  if (n < length) { // Sets length to n if n is less so it can copy the n portion of the string
    length = n;
  }

  if(!dest) { // If no memory was available, return immediately
    return 0;
  }
  // Otherwise, copy the string and return pointer to new string up to size of n
  // Note: strcpy() always puts the null terminator at the tend of the string.
  dest[length] = '\0';
  return (char*) mystrncpy(dest, src, length);
}

/** Counts and returns the length of the C string (must have \0 at end of str).
* @param src Points to each character in C string
* @return Number of characters/length of C string
*/

int mystrlen(char* src) { // Runs Program
  char* ptr = src; //Sets pointer to each character in C string
  int len = 0; // Keeps track of length of C string

  while (*ptr != 0) { // Terminates when /0 is detected at end of C string
    ptr++; // Points to the next character in C string
    len++; // Counts each character in C string till terminated
  }
  return len;
}

/** Copies contents that are pointed in src to contents of dest.
* Make sure dest is equal to or larger than mystrlen(src) + 1 otherwise overflow.
* @param src pointer of the string that is copied
* @param dest pointer to array that the string will be copied into
* @return a pointer to a new string
*/

char* mystrcpy(char* dest, char* src) { // Runs Program
  char* sptr = src; // Set pointer to string that is copied
  char* dptr = dest; // Sets pointer to string that will be copied in

  while(*sptr != 0) { //Termiantes at end of C string '\0'
  *(dptr++) = *(sptr++); //Copies the value from sptr to dptr and then increments
}

*dptr = '\0';
return dest; // Returns orginal pointer
}

/** Appends part of a string to another string
* @param char* dest: Points to a string terminated by ‘\0’
* @param char* src:  Points to a string with characters appended to end of “dest”
* @return pointer to new dest which is the new appended string
*/

char* mystrcat(char* dest, char* src) {
  size_t i,j; // Keeps track of each element

  for(i=0; dest[i] != '\0'; i++); // i contains length of dest
  for(j=0; src[j] != '\0'; j++) { // j contains length of src
    dest[i+j] = src[j]; // Appends strings to create new string
  }

  dest[i+j] = '\0';
  return dest;
}

/** Appends part of a string to another string
* Note: the function appends X amount of characters from src to end of dest. If src has less characters than X, function will stop when it encounters '\0'
* @param char* dest: Points to a string terminated by ‘\0’
* @param char* src:  Points to a string with characters appended to end of “dest”
* @param size_t n:  Maximum number of characters from “src" appended to “dest”
* @return pointer to new dest which is the new appended string
*/

char* mystrncat(char* dest, char* src, size_t n) {
  size_t dest_len = mystrlen(dest); // Intent is to point to the new string (dest) after append
  size_t i; // Keeps track of each element

  for (i = 0 ; i < n && src[i] != '\0' ; i++) {  // Terminates when pointer reaches end of c string
    dest[dest_len + i] = src[i]; // Appends strings to create new string
    dest[dest_len + i] = '\0';
  }
  return dest;
}

/** Copies characters of a string by taking n character bytes and adding null termination at the end of the string
* @param char* dest: Points to area in memory that receives copied characters and must hold n amount of characters
* @param char* src:  Points to a string of characters that will be copied
* @param size_t n: Number of characters to copy
* @return new de*@param size_t n:  Maximum number of characters from “src" appended to “dest”st which is the new copied string
*/
char* mystrncpy(char* dest, char* src, size_t n) { // Runs program
  size_t i; // Keeps track of each element

  for (i = 0; i < n && src[i] != '\0'; i++) { // Terminates when it reaches n and null terminator on c string,
    dest[i] = src[i]; // Each character src point to is copied in dest
  }
  for ( ; i < n; i++) { //Terminates when array element reaches null terminator

    dest[i] = '\0';
  }
  return dest;
}
