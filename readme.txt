Name: Goutham Deva

Program Description: 

In the “assig3” folder, there are 10 files/directories. Note: Objects files will not be included in this guide as all the descriptions would be simply compiled code from the corresponding code files.

NOTE: IF YOU WANT TO USE DOXYEGEN COMMAND "Make Docs", TAKE THE READ ME FILE OUT OF THE ZIP IN A SEPERATE DIRECTORY SO THAT DOXYGEN DOESN'T REGISTER readme.txt syntax as file members online. Thanks! 

ctest: This file is an executable that prints and shows all the functions created for string including mystrlen, mystrdup, mystrcpy, mystrcat, mystrncat, strncpy, and strndup.

ctest.c: This is human readable code file for ctest. All the code from this file was compiled to create the executable.

mainstruct: This file is an executable that prints two tested examples of employees which contain the name of employee and birth year and starting year, one random capital single letter, one random string, one random employee, two random employees, and two copies of those two employees respectively.

mainstruct.c: This is human readable code file for mainstruct. All the code from this file was compiled to create the executable.

mystring.c: This is the code file that runs the functions mystrdup, mystrndup, mystrlen, mystrcpy, mystrcat, mystrncat, and mystrncpy which are all replicas of all of there respectives functions. In order to calculate values, this file must be linked with ctest.c and mainstruct.c

mystring.h: This is the header file and contains the function prototype. This requires the program mystring.c to work since it’s needed when compiling a source file that uses a function from a different file. 

mystruct.c: This is the code file that runs the functions make_employee, ranLetterGen, ranStringGen, addEmployee, printfunc, printEmployees, structGen, shallowCopy, freedom, and deepCopy. In order to calculate values, this file must be linked with mainstruct.c.

mystruct.h: This is the header file and contains the function prototype. This requires the program mystruct.c to work since it’s needed when compiling a source file that uses a function from a different file.

Makefile: Makefile takes all of the code files and compiles them so that they are ready to be used for the computer to read. In the contents of the file, makefile shows the files that that are told to be compiled and link together and cleaned. This include the files ctest.c, mainstruct.c, mystruct.c, and mystring. To activate the contents of Makefile, type “make” on the command line which will allow the code files to be compiled to run the program. If you wish to un-compile the code files which removes the .o file, type “make clean” on the command prompt.

How to compile: 

Unzip the tar file and type "make" in the command prompt inside the assign3 directory. This will compile all the files in the folder as well as link the header files with the same named code file. If you wish to uncompile, type "make clean" and it will delete all the object files and leave you with the code files, header files, Doxyfile, and makefile.

Test Data:

ctest: 

//Check if the program runs

Input: ./ctest

What to Expect: 

Pointers: a1 = 0x7ffe2ebdd660, a2 = 0x7ffe2ebdd6d0, a3 = 0x7ffe2ebdd640
          p1 = 0x400f7c p2 = 0x5f5f00656d697474
Contents of a1 = Hi
Contents of a2 = Hello
Contents of a3 = Hello, also
After concatenating a2 to a1, contents of a1 = HiHello
After concatenating a2 to a1, max length 8, contents of a1 = HiHello
After copying a2 to a1, max length 3, contents of a1 = Helello
Note that copied string was not terminated.
Resetting. a1 = Hi
After concatenating a2 to a1, max length 2, contents of a1 = Hi
Note that copied string was terminated.
Before dup, pointer a2 = 0x7ffe2ebdd6d0, contents = Hello
After dup, pointer p2 = 0x1bf0420, contents = Hello

Testing corner cases for mystrncpy
String b = ABCDEFGHIJ
String b with n less then length is = ILIKEFGHIJ
String b with n = length shouldn't append to ILIKEDUCKS = ILIKEDUCKS
String b with n > length shouldn't append to ILIKEDUCKS  = ILIKEDUCKS

Testing corner cases for mystrndup
Pointers: b1 = 0x7ffe2ebdd6e0
          p4 = 0x7465675f6f736476
Before dup, pointer b1 = 0x7ffe2ebdd6e0, contents = DUCKS
After dup more than specfied length, pointer p4 = 0x1bf0440, contents = DUC
Before dup, pointer b1 = 0x7ffe2ebdd6e0, contents = DUCKS
After dup length equal to specfied length, pointer p4 = 0x1bf0460, contents = DUCKS
Before dup, pointer b1 = 0x7ffe2ebdd6e0, contents = DUCKS
After dup less than specfied length, pointer p4 = 0x1bf0480, contents = DUCKS

_________________________________________________________

mainstruct: 

//Check if the program runs

Input: ./mainctruct

What to Expect:

Employee Struct Function Test Example
Name: Steve Rogers
Birth Year: 1941
Starting Year: 2011

Name: Goutham Deva
Birth Year: 1997
Starting Year: 2016

Random Single Character Function Call Test
Random Letter: K 

Random String Function Call Test
Random string: GIIPA 

Random New Struct Function Call Test
Name: KAODM
Birth Year: 1958
Starting Year: 1992

Number of Random Struct Made and Copied Function Call Test
Name: QTXLI
Birth Year: 1953
Starting Year: 1992

Name: LQGIV
Birth Year: 1959
Starting Year: 1993

Shallow Copy Function Call Test
Name: QTXLI
Birth Year: 1953
Starting Year: 1992

Name: LQGIV
Birth Year: 1959
Starting Year: 1993

Deep Copy Function Call Test
Name: QTXLI
Birth Year: 1953
Starting Year: 1992

Name: LQGIV
Birth Year: 1959
Starting Year: 1993
_________________________________________________________
