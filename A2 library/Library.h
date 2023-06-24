//Library.h
#ifndef LIBRARY_H
#define LIBRARY_H
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
class BookRecord
{
public:
	BookRecord();
	BookRecord(string, string, string, string, string, int, int);
	~BookRecord();

	string get_book_id();
	string get_book_title();
	string get_first_name();
	string get_last_name();
	string get_year_published();
	void displaydata_bookrecord();
	int get_number_of_copies();
	int get_number_of_copies_available_for_loan();
	int get_number_of_loaned();
	int number_of_loaned = 0;
private:
	string book_id = " ";
	string book_title = " ";
	string author_first_name = " ";
	string author_last_name = " ";
	string year_published = " ";
	int number_of_copies;
	int number_of_copies_available_for_loan;
};

class borrower
{
public:
	borrower(string, string, string, int, string*);
	borrower();
	~borrower();

	string get_borrower_id();
	string get_first_name();
	string get_last_name();
	int get_number_of_books_loaned();
	string get_array_of_book_ids();
	void displaydata_borrower();
private:

	string borrower_id = " ";
	string first_name = " ";
	string last_name = " ";
	int number_of_books_loaned = 0;
	string array_of_book_ids[100] = { "666" };
};

class Catelogue
{
public:
	Catelogue();
	Catelogue(BookRecord*);
	~Catelogue();
	int get_total_number_of_book_records();//yes
	BookRecord* get_array_of_book_records();
	int total_number_of_book_records = 10;//yes

private:
	BookRecord* array_of_book_records = new BookRecord[100];//yes//在堆上创建解决了在cpp文件中“表达式必须是可修改的左值问题”
};

class Library
{
public:
	Library(Catelogue, borrower*, BookRecord*);//yes
	~Library();//yes
	int get_total_number_of_books_on_loan();
	int get_total_number_of_borrowers();
	Catelogue get_catalogue();
	borrower* get_array_of_borrowers();
	void outputbookrecord(int, BookRecord);
	void outputborrower(int, borrower);
private:
	void set_catalogue(Catelogue);
	void set_array_of_borrowers(borrower*);
	string book_id = " ";
	string book_title = " ";
	string author_first_name = " ";
	string author_last_name = " ";
	string year_published;
	int number_of_copies;
	int number_of_loaned;
	int number_of_copies_available_for_loan = number_of_copies;
	int total_number_of_books_on_loan = 0;//yes
	int total_number_of_borrowers = 0;//yes

	string borrower_id = " ";
	string first_name = " ";
	string last_name = " ";
	int number_of_books_loaned = 0;
	string array_of_book_ids[100] = { "777" };
	Catelogue catalogue;//yes
	borrower* array_of_borrowers = new borrower[100];//yes//在堆上创建解决了在cpp文件中“表达式必须是可修改的左值问题”
};
#endif
/*
The Borrower class should have:
1. An ID field.
2. A first name field.
3. A last name field.
4. A number of books loaned by the borrower field.
5. An array of the book IDs currently loaned by the borrower.
6. An appropriate constructor and destructor.
7. A function that displays the data.
NOTE: In the function that enters a borrower's record, the function should check that the borrower's ID consists of 5 digits. Otherwise an error message should be displayed and the program should terminate.
*/
/*
The BookRecord class should have:
1. A book ID field.
2. A book title field.
3. An author's first name field.
4. An author's last name field.
5. A year of publication field.
6. A total number of book copies field.
7. A number of copies still available for loan field.
8. An appropriate constructor and destructor.
9. A function that returns the book's ID.
10. A function that displays the data.
NOTE: In the function that enters a book record, the function should check that the book ID starts with an uppercase letter, and that the year of publication has 4 digits and starts with a 1 or a 2. Otherwise an error message should be displayed and the program should terminate.
*/
/*
The Catalogue class should have:
1. A total number of book records field.
2. An array of BookRecords
3. An appropriate constructor and destructor.
4. A function that displays the total number of books in the catalogue and the individual book records.
NOTE: The program should update the total number of books on loan and the individual book numbers available for loan, based on the borrowers data.
*/
/*
The Library class should have:
1. A total number of books on loan field.
2. A total number of borrowers field.
3. A Catalogue object (described below). This should be populated during initialization by the constructor.
4. An array of Borrower objects (described below). This should be populated during initialization by the constructor.
5. A constructor that accepts the input data.
6. An appropriate destructor.
7. A function that displays the total number of books on loan, the total number of book records and displays the individual book records.
8. A function that displays the total number of borrowers and the individual borrower records.
*/
//overload operator =
