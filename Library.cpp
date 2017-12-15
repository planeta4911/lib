#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include "LibClass.h"

using namespace std;

void PrintBooks(vector<Book*> b)
{
	for (int i = 0; i < b.size(); i++)
	{
		cout << "book " << i << ":    title - " << b[i]->title << ", author - " << b[i]->author << ", year - " << b[i]->year << endl;
	}
}

void StartCommandSystem(LibClass& lib)
{
	string command = "";
	while (command != "stop")
	{
		cout << ">>>";
		cin >> command;

		if (command == "print") {
			//выводим списов книг по автору
			cout << "by authors:" << endl;
			for (int i = 0; i < lib.authors.size(); i++)
			{
				cout << "author - " << lib.authors[i].name << "-----------------------------------" << endl;
				PrintBooks(lib.authors[i].books);
			}
			cout << "========================================================" << endl;
			//выводим списов книг по году
			cout << "by years:" << endl;
			for (int i = 0; i < lib.years.size(); i++)
			{
				cout << "year - " << lib.years[i].year << "---------------------------------------" << endl;
				PrintBooks(lib.years[i].books);
			}
			cout << "========================================================" << endl;
		}
		else if (command == "add") //команда на добавление новых элементов
		{
			cout << "what do you want to add? (book/author)\n==>>>";
			cin >> command;
			if (command == "book") {
				string title;
				string author;
				int year;
				cout << "enter the title of the book \n==-->>>";
				cin >> title;
				cout << "enter the author \n==-->>>";
				cin >> author;
				cout << "enter the year \n==-->>>";
				cin >> command;
				year = atoi(command.c_str());
				lib.AddBook(title, author, year);
				cout << "done!\n";
			}
			else if (command == "author")
			{
				cout << "enter the name of the author\n==-->>>";
				cin >> command;
				lib.AddAuthor(command);
				cout << "done!\n";
			}
			else
				cout << "error! you should write book or author" << endl;
		}
		else if (command == "help") {
			cout << "allowed commands: add, print, stop, get, clear" << endl;
		}
		else if (command == "clear") {
			system("cls");
		}
		else if (command == "get")
		{
			cout << "how do you want to search? (title/author/year)\n==>>>";
			cin >> command;
			if (command == "title")
			{
				cout << "enter the title \n==>>>";
				cin >> command;
				Book* book = lib.SearchBookByTitle(command);
				if (book != NULL)
					cout << "book found - " << book->title << " by " << book->author << ", " << book->year << endl;
				else
					cout << "there is no book is entitled " << command << endl;
			}
			else if (command == "author")
			{
				cout << "enter the name of the author \n==>>>";
				cin >> command;
				vector<Book*> books = lib.SearchBooksByAuthor(command);
				if (books.size() != 0)
					PrintBooks(books);
				else
					cout << "books not found";
			}
			else if (command == "year")
			{
				cout << "enter the year \n==>>>";
				cin >> command;
				vector<Book*> books = lib.SearchBooksByYear(atoi(command.c_str()));
				if (books.size() != 0)
					PrintBooks(books);
				else
					cout << "books not found";
			}
		}
		else if (command == "debug")
		{
			//cout << _bin_tree->GetByID(0)->fio;
		}
		else if (command == "delete")
		{
			cout << "what do you want to delete? (book/author)\n==>>>";
			cin >> command;
			if (command == "book")
			{
				cout << "enter title of the book \n==-->>>";
				cin >> command;
				lib.DeleteBook(command);
				cout << "done!" << endl;
			}
			else if (command == "author")
			{
				cout << "ATTENTION! All books by this author will be deleted!\nenter the name of the author \n==-->>>";
				cin >> command;
				lib.DeleteAuthor(command);
				cout << "done!" << endl;
			}
		}
		else if (command != "stop")
			cout << "unknown command" << endl;
	}
}




int main()
{
	LibClass lib;
	StartCommandSystem(lib);

    return 0;
}

