#include "LibClass.h"
#include <vector>


LibClass::LibClass()
{
}


LibClass::~LibClass()
{
}

void LibClass::AddAuthor(std::string name)
{
	authors.push_back(name);
}

int LibClass::DeleteAuthor(std::string name)
{
	//находим автора
	int i = 0;
	for (i = 0; i < authors.size(); i++) {
		if (authors[i].name == name)
			break;
		else if (i = authors.size() - 1) {
			return -1; //нет такого автора
		}
	}
	Author& author = authors[i]; 

	//удаляем все книги с этим автором
	for (int k = 0; k < author.books.size(); k++)
		DeleteBook(author.books[k]->title);

	//удаляем автора
	authors.erase(authors.begin() + i);
	return 0;
}

void LibClass::AddBook(std::string title, std::string author, int year)
{
	//находим автора
	int i = 0;
	if (authors.size() == 0)
		authors.push_back(author);
	else {
		for (i = 0; i < authors.size(); i++) {
			if (authors[i].name == author)
				break;
			else if (i == authors.size() - 1) {
				authors.push_back(author);
				i++;
				break;
			}
		}
	}

	//находим year
	int j = 0;
	if (years.size() == 0)
		years.push_back(year);
	else {
		for (j = 0; j < years.size(); j++) {
			if (years[j].year == year)
				break;
			else if (j == years.size() - 1) {
				years.push_back(Year(year));
				j++;
				break;
			}
		}
	}

	//добавляем книгу в массив книг, в массив указателей по году и по автору
	Book* book = new Book(title, author, year);
	books.push_back(*book);
	authors[i].books.push_back(book);
	years[j].books.push_back(book);
}

void LibClass::DeleteBook(std::string title)
{
	//находим книгу
	int b;
	for (b = 0; b < books.size(); b++) {
		if (books[b].title == title)
			break;
	}
	Book* book = &books[b];

	//находим автора
	int i = 0;
	for (i = 0; i < authors.size(); i++) {
		if (authors[i].name == book->author)
			break;
	}
	//находим год
	int j = 0;
	for (j = 0; j < years.size(); j++) {
		if (years[j].year == book->year)
			break;
		j++;
	}

	//удаляем ссылки, потом саму книгу
	for (int m = 0; m < authors[i].books.size(); m++)
		if (authors[i].books[m]->title == title)
		{
			authors[i].books.erase(authors[i].books.begin() + m);
			break;
		}
	for (int l = 0; l < years[i].books.size(); l++)
		if (years[j].books[l]->title == title)
		{
			years[j].books.erase(years[j].books.begin() + l);
			break;
		}
	if (years[j].books.size() == 0)
		years.erase(years.begin() + j);
	books.erase(books.begin() + b);
}

std::vector<Book*> LibClass::SearchBooksByAuthor(std::string name)
{
	//находим автора
	int i = 0;
	for (i = 0; i < authors.size(); i++) {
		if (authors[i].name == name)
			return authors[i].books;
	}
	std::vector<Book*> v;
	return v;
}

std::vector<Book*> LibClass::SearchBooksByYear(int year)
{
	//находим год
	int i = 0;
	for (i = 0; i < authors.size(); i++) {
		if (years[i].year == year)
			return years[i].books;
	}
	std::vector<Book*> v;
	return v;
}

Book* LibClass::SearchBookByTitle(std::string title)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].title == title)
			return &books[i];
	}
	return NULL;
}

