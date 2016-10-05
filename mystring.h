/** mystring.h
* @author Mike Ciaraldi and Goutham Deva
* My own versions of some of the C-style string functions
*/

#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>

// Function Protoypes

char* mystrdup(char* src);
char* mystrndup(char* src, size_t n);
int mystrlen(char* src);
char* mystrcpy(char* dest, char* src);
char* mystrcat(char* dest, char* src);
char* mystrncat(char* dest, char* src, size_t n);
char* mystrncpy(char* dest, char* src, size_t n);

#endif
