//Library.cpp
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include"library.h"
using namespace std;

Library::Library(Catelogue catelogue1, borrower* borrower1, BookRecord* bookrecord1) 
	: catalogue(catelogue1), array_of_borrowers(borrower1)
{
	int number_of_book_records_to_follow;
	int number_of_borrower_records_to_follow;

	// 读入将要录入的书籍记录的数量
	cin >> number_of_book_records_to_follow;

	//忽略掉换行符
	cin.ignore();

	// 动态分配一个指向BookRecord类型数组的指针BOOKarr
	BookRecord* BOOKarr = nullptr;
	// 动态分配一个指向borrower类型数组的指针BORROWERarr
	borrower* BORROWERarr = nullptr;

	// 检查是否能够成功分配内存，如果不能，则输出错误信息并退出程序
	try
	{
		BOOKarr = new BookRecord[number_of_book_records_to_follow];
	}
	catch (const bad_alloc& e)
	{
		cout << "内存分配失败: " << e.what() << endl;
		abort();
	}
	if (BOOKarr == nullptr)
	{
		cout << "内存分配失败" << endl;
		abort();
	}
	BOOKarr = new BookRecord[number_of_book_records_to_follow];

	// 读入将要录入的书籍记录
	for (int i = 0; i < number_of_book_records_to_follow; i++)
	{
		// 使用分隔符';'从字符串ss中提取数据，将其存储到book_id、book_title、author_first_name、author_last_name、year_published和number_of_copies变量中
		//ss的长度并没有变短，只是它的读取位置发生了变化。
		//每次调用getline函数后，ss的读取位置就会移动到下一个分隔符的后面.
		string line;
		getline(cin, line);
		stringstream ss(line);
		getline(ss, book_id, ';');
		getline(ss, book_title, ';');
		getline(ss, author_first_name, ' ');
		getline(ss, author_last_name, ';');
		getline(ss, year_published, ';');
		ss >> number_of_copies;

		// 如果书籍ID不以大写字母开头，则输出错误信息并退出程序
		if (!isupper(book_id[0])) {

			cout << "Error: book ID should start with uppercase letter." << endl;
			exit(1);
		}

		// 如果书籍ID不是5位数字，则输出错误信息并退出程序
		if (year_published.length() != 4 || (year_published[0] != '1' && year_published[0] != '2')) {
			cout << year_published << "Error: publish year should be 4-digit number starting with 1 or 2." << endl;
			exit(1);
		}
		BookRecord bookrecrdi(book_id, book_title, author_first_name, author_last_name, year_published, number_of_copies, number_of_books_loaned);
		BOOKarr[i] = bookrecrdi;
	}
	
	cin >> number_of_borrower_records_to_follow;
	cin.ignore();

	//检查内存是否分配成功
	try
	{
		BORROWERarr = new borrower[number_of_borrower_records_to_follow];
	}
	catch (const bad_alloc& e)
	{
		cout << "内存分配失败: " << e.what() << endl;
		abort();
	}
	if (BORROWERarr == nullptr)
	{
		cout << "内存分配失败" << endl;
		abort();
	}
	BORROWERarr = new borrower[number_of_borrower_records_to_follow];

	//读入将要录入的借书记录
	for (int j = 0; j < number_of_borrower_records_to_follow; j++)
	{
		string line;
		getline(cin, line);
		stringstream ss(line);
		getline(ss, borrower_id, ';');
		getline(ss, first_name, ' ');
		getline(ss, last_name, ';');
		ss >> number_of_books_loaned;
		ss.ignore(1, ';');
		
		total_number_of_books_on_loan += number_of_books_loaned;
		if (borrower_id.length() != 5 || !isdigit(borrower_id[0]) || !isdigit(borrower_id[1])
			|| !isdigit(borrower_id[2]) || !isdigit(borrower_id[3]) || !isdigit(borrower_id[4])) {
			cerr << "Error: Borrower ID should consist of 5 digits" << endl;
			exit(1);
		}
		for (int k = 0; k < number_of_books_loaned; k++)
		{
			getline(ss, array_of_book_ids[k], ';');

		}
		if (array_of_book_ids == nullptr)
		{
			cout << "aha!" << endl;
			exit(1);
		}
		//
		borrower borrowerj(borrower_id,first_name,last_name,number_of_books_loaned,array_of_book_ids);
		BORROWERarr[j] = borrowerj;	
		//遍历每个借书记录中借的每一本书，如果和图书馆中的书一样，则该书的借出数量实时更新
		for (int k = 0; k < number_of_books_loaned; k++)
		{
			for (int kk = 0; kk < number_of_book_records_to_follow; kk++)
			{
				if (BOOKarr[kk].get_book_id() == array_of_book_ids[k])
				{
					BOOKarr[kk].number_of_loaned++;

				}
			}
		}
		total_number_of_borrowers = number_of_borrower_records_to_follow;
	}
	

	catelogue1 = Catelogue(BOOKarr);
	cout << "Total number of books on loan: " <<get_total_number_of_books_on_loan() << endl;
	catelogue1.total_number_of_book_records = number_of_book_records_to_follow;
	cout << "Total number of books in catalogue: " << catelogue1.get_total_number_of_book_records() << endl;
	cout << endl;
	for (int i = 0; i < number_of_borrower_records_to_follow; i++)
	{
		cout << "Book Record " << i << endl;
		cout << "=============" << endl;
		outputbookrecord(number_of_book_records_to_follow, BOOKarr[i]);
	}

	cout << "Total number of borrowers: " << get_total_number_of_borrowers() << endl;
	for (int i = 0; i < number_of_borrower_records_to_follow; i++)
	{
		cout << "Borrower " << i << endl;
		cout << "==========" << endl;
		outputborrower(number_of_borrower_records_to_follow,BORROWERarr[i]);
	}
	//new完之后delete手动释放内存
	delete[]BOOKarr;
	delete[]BORROWERarr;
}
Library::~Library()
{
	//delete[] array_of_borrowers;//这是一个导致程序崩溃的原因。
	//这个问题可能是由于在使用容器时，意外地删除了容器中的元素，从而导致了指针指向被删除的元素，而此时进行访问就会出现访问冲突的问题。
}
void Library::set_catalogue(Catelogue cat)
{
	catalogue = cat;
}
void Library::set_array_of_borrowers(borrower* array)
{
	array_of_borrowers = array;
}
int Library::get_total_number_of_books_on_loan()
{
	return total_number_of_books_on_loan;
}
int Library::get_total_number_of_borrowers()
{
	return total_number_of_borrowers;
}
Catelogue Library::get_catalogue()
{
	return catalogue;
}
borrower* Library::get_array_of_borrowers()
{
	return array_of_borrowers;
}






borrower::borrower(string borrower_id, string first_name,string last_name, int number_of_books_loaned, string* array_of_book_ids)
	:borrower_id(borrower_id), first_name(first_name), last_name(last_name), number_of_books_loaned(number_of_books_loaned)
{
	//必须在构造函数中把Library对象的array_of_book_ids作为参数传给borrower对象的array_of_book_ids
	for (int i = 0; i < number_of_books_loaned; i++)
	{
		this->array_of_book_ids[i] = array_of_book_ids[i];
	}
}
borrower::~borrower()
{
}
borrower::borrower()
	:borrower_id(" "), first_name(" "),last_name (" "),number_of_books_loaned(0),array_of_book_ids()
{

}
string borrower::get_borrower_id()
{
	return borrower_id;
}
string borrower::get_first_name()
{
	return first_name;
}
string borrower::get_last_name()
{
	return last_name;
}
int borrower::get_number_of_books_loaned()
{
	return number_of_books_loaned;
}
string borrower::get_array_of_book_ids()
{
	return *array_of_book_ids;
}

void borrower::displaydata_borrower()
{
	cout << "Borrower ID: " << borrower_id << endl;
	cout << "First name: " << first_name << endl;
	cout << "Last name: " << last_name << endl;
	cout << "Number of books on loan: " << number_of_books_loaned << endl;
	cout << "Book IDs on loan: ";
	for (int k = 0; k < number_of_books_loaned; k++)
	{
		cout << array_of_book_ids[k]<< " ";
	}
	cout << endl;
}


BookRecord::BookRecord()
	:book_id(" "), book_title(" "), author_first_name(" "), author_last_name(" "), year_published(" "), number_of_copies(0), number_of_loaned(0), number_of_copies_available_for_loan(0)
{}
BookRecord::BookRecord(string book_id,string book_title,string first_name,string last_name,string year_published,int number_of_copies,int number_of_loaned) 
	:book_id(book_id), book_title(book_title), author_first_name(first_name), author_last_name(last_name), year_published(year_published), number_of_copies(number_of_copies), number_of_loaned(number_of_loaned), number_of_copies_available_for_loan(number_of_copies- number_of_loaned)
{

}
BookRecord::~BookRecord()
{
}
string BookRecord::get_book_id()
{
	return book_id;
}
string BookRecord::get_book_title()
{
	return book_title;
}
string BookRecord::get_first_name()
{
	return author_first_name;
}
string BookRecord::get_last_name()
{
	return author_last_name;
}
string BookRecord::get_year_published()
{
	return year_published;
}
void BookRecord::displaydata_bookrecord()
{
	
	cout << "Book ID: " << book_id << endl;
	cout << "Book Title: " << book_title << endl;
	cout << "Author: " <<author_first_name << " " << author_last_name << endl;
	cout << "Year Published: " << year_published << endl;
	cout << "Number of Copies: " << number_of_copies << endl;
	cout << "Number of Copies Available for Loan: " << get_number_of_copies_available_for_loan ()<< endl;
	cout << endl;
}
int BookRecord::get_number_of_copies()
{
	return number_of_copies;
}
int BookRecord::get_number_of_loaned()
{
	return number_of_loaned;
}
int BookRecord::get_number_of_copies_available_for_loan()
{
	return number_of_copies-number_of_loaned;
}



Catelogue::Catelogue()
{
}

Catelogue::Catelogue(BookRecord* bookrecord):total_number_of_book_records(0),array_of_book_records(bookrecord)
{
}
Catelogue::~Catelogue()
{
	
}
int Catelogue::get_total_number_of_book_records()
{
	return total_number_of_book_records;
}
BookRecord* Catelogue::get_array_of_book_records()
{
	return array_of_book_records;
}
void Library::outputborrower(int number_of_borrower_records_to_follow,borrower borrower1)
{
		borrower1.displaydata_borrower();
}
void Library::outputbookrecord(int number_of_book_records_to_follow,BookRecord bookrecord1)
{
		bookrecord1.displaydata_bookrecord();
}

