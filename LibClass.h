#pragma once
#include <vector>

class Book;
class Author;
class Year;

class LibClass
{
public:
	LibClass();
	~LibClass();
	std::vector<Book> books;
	std::vector<Year> years;
	std::vector<Author> authors;

	void AddAuthor(std::string name);
	int DeleteAuthor(std::string name);
	void AddBook(std::string title, std::string author, int year);
	void DeleteBook(std::string title);
	std::vector<Book*> SearchBooksByAuthor(std::string name);
	std::vector<Book*> SearchBooksByYear(int year);
	Book* SearchBookByTitle(std::string title);

};

class Author
{
public:
	Author(){}
	Author(std::string name)
	{
		this->name = name;
	}
	std::string name;
	std::vector<Book*> books;
};

class Year
{
public:
	Year(){}
	Year(int year)
	{
		this->year = year;
	}
	int year;
	std::vector<Book*> books;
};

class Book
{
public:
	Book() {}
	Book(std::string title, std::string author, int year)
	{
		this->title = title;
		this->author = author;
		this->year = year;
	}
	std::string title;
	std::string author;
	int year;
};
