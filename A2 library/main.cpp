//main.cpp
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include"library.h"
#include<iomanip>
#include<sstream>
#include<stdexcept>
using namespace std;

int main()
{
	Catelogue catelogue1 = NULL;
	borrower* borrower1 = nullptr;
	BookRecord* bookrecord1 = nullptr;
	Library library(catelogue1, borrower1, bookrecord1);
}
/*
write a main() function that displays the total number of books on loan, the total number of books in the catalogue, the individual book records, the total number of borrowers and the individual borrower records. An example output, given the provided input is as follows:
Total number of books on loan: 6
Total number of books in catalogue: 3
Book Record 0
=============
Book ID: N123
Title: Object-Oriented Programming
Author: Dave Smith
Year published: 2009
Total number of copies: 3
Number available for loan: 1
Book Record 1
=============
Book ID: A251
Title: UML Modelling and Design
Author: Barry Arthurs
Year published: 2005
Total number of copies: 1
Number available for loan: 0
Book Record 2
=============
Book ID: Z001
Title: Practical Guide to STL
Author: John Johnson
Year published: 2000
Total number of copies: 5
Number available for loan: 2
Total number of borrowers: 3
Borrower 0
===========
Borrower ID: 12345
Name: Joe Bloggs
Number of loaned books: 3
IDs of books on loan: N123 A251 Z001
Borrower 1
===========
Borrower ID: 20498
Name: Alex Alexis
Number of loaned books: 1
IDs of books on loan: Z001
Borrower 2
===========
Borrower ID: 19090
Name: Mike Mike
Number of loaned books: 2
IDs of books on loan: N123 Z001

*/

/*
reads data from the keyboard, and has the format below:
3
N123;Object-Oriented Programming;Dave Smith;2009;3
A251;UML Modelling and Design;Barry Arthur;2005;1
Z001;Practical Guide to STL;John Johnson;2000;5

Then you should reads data from the keyboard, and has the following format:
3
12345;Joe Bloggs;3;N123;A251;Z001
20498;Ales Alexis;1;Z001
19090;Mike Mike;2;N123;Z001
*/