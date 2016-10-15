#include <iostream>
using namespace std;

void fillLibrary(int countBooks, struct Library* library);
void printAllBook(int countBooks, struct Library* library);
void editBook(int idBook, struct Library* library);
void skanAuthor(int countBooks, struct Library* library, int &idBook);
void skanTitle(int countBooks, struct Library* library, int &idBook);
void sortTitle(int countBooks, struct Library* library);
void sortAuthor(int countBooks, struct Library* library);
void sortPublisher(int countBooks, struct Library* library);

struct Library
{
	char* Title; 
	char* Author;
	char* Publisher;
	char* Genre;
};

enum Menu
{
	Exit = 0,
	PrintAllBook = 1,
	EditBook = 2,
	SkanAuthor = 3,
	SkanTitle = 4,
	SortTitle = 5,
	SortAuthor = 6,
	SortPublisher = 7
};

void main()
{
	int idBook = 0;
	int strSize = 50;
	int countBooks = 10;
	struct Library* library = new Library[countBooks];
	for (int i = 0; i < countBooks; i++)
	{
		library[i].Title = new char[strSize];
		library[i].Author = new char[strSize];
		library[i].Publisher = new char[strSize];
		library[i].Genre = new char[strSize];
	}

	fillLibrary(countBooks, library);
	cout << "the list of books in library; " << endl;	//первый вход
	printAllBook(countBooks, library);					//вывод книг
	int menu;
	do																		//меню для общения с пользователем
	{
		cout << "print all book: 1\nedit book: 2\nskan author: 3\nskan title: 4\n"
			"sort title: 5\nsort author: 6\nsort publisher: 7\nexit: 0\nenter: ";
		cin >> menu; fflush(stdin);
		switch (Menu(menu))									//выбор действий
		{
		case PrintAllBook: printAllBook(countBooks, library);
			break;
		case EditBook: editBook(idBook, library);
			break;
		case SkanAuthor: skanAuthor(countBooks, library, idBook);
			break;
		case SkanTitle: skanTitle(countBooks, library, idBook);
			break;
		case SortTitle: sortTitle(countBooks, library);
			break;
		case SortAuthor: sortAuthor(countBooks, library);
			break;
		case SortPublisher: sortPublisher(countBooks, library);
			break;
		default: menu = 10;
			break;
		}
	} while (menu != 0);														//выход

	for (int i = 0; i < countBooks; i++)									 
	{
		delete[] library[i].Title;
		delete[] library[i].Author;
		delete[] library[i].Publisher;
		delete[] library[i].Genre;
	}
	delete[] library;
}

///заполненая библиотека:
void fillLibrary(int countBooks, struct Library* library)	
{
	strcpy(library[0].Title, "be");
	strcpy(library[0].Author, "dev");
	strcpy(library[0].Publisher, "fer");
	strcpy(library[0].Genre, "dut");

	strcpy(library[1].Title, "rew");
	strcpy(library[1].Author, "ler");
	strcpy(library[1].Publisher, "um");
	strcpy(library[1].Genre, "so");

	strcpy(library[2].Title, "her");
	strcpy(library[2].Author, "dev");
	strcpy(library[2].Publisher, "se");
	strcpy(library[2].Genre, "so");

	strcpy(library[3].Title, "rety");
	strcpy(library[3].Author, "rew");
	strcpy(library[3].Publisher, "um");
	strcpy(library[3].Genre, "set");

	strcpy(library[4].Title, "erw");
	strcpy(library[4].Author, "ler");
	strcpy(library[4].Publisher, "fe");
	strcpy(library[4].Genre, "ret");

	strcpy(library[5].Title, "ruy");
	strcpy(library[5].Author, "yt");
	strcpy(library[5].Publisher, "yth");
	strcpy(library[5].Genre, "ytr");

	strcpy(library[6].Title, "rje");
	strcpy(library[6].Author, "yu");
	strcpy(library[6].Publisher, "trh");
	strcpy(library[6].Genre, "uy");

	strcpy(library[7].Title, "wdk");
	strcpy(library[7].Author, "vk");
	strcpy(library[7].Publisher, "ewml");
	strcpy(library[7].Genre, "io");

	strcpy(library[8].Title, "wefk");
	strcpy(library[8].Author, "vo");
	strcpy(library[8].Publisher, "lewr");
	strcpy(library[8].Genre, "uy");

	strcpy(library[9].Title, "rwe");
	strcpy(library[9].Author, "vk");
	strcpy(library[9].Publisher, "se");
	strcpy(library[9].Genre, "io");
}	

///Печать всех книг:
void printAllBook(int countBooks, Library * library)
{
	cout << "Id|" << "Title \t\t" << "Author \t\t" << "Publisher \t\t" << "Genre \t" << endl;
	for (int i = 0; i < countBooks; i++)
	{
		cout << i << " | " << library[i].Title << "\t";
		if (strlen(library[i].Title) < 12)
		{
			cout << "\t";
			if (strlen(library[i].Title) < 4)
			{
				cout << "\t";
			}
		}
		cout << " " <<library[i].Author << "\t";
		if (strlen(library[i].Author) < 4)
		{
			cout << "\t";
		}
		cout << " " << library[i].Publisher << "\t";
		if (strlen(library[i].Publisher) < 12)
		{
			cout << "\t";
			if (strlen(library[i].Publisher) < 6)
			{
				cout << "\t";
			}
		}
		cout << " " << library[i].Genre << endl;
	}
}

/// Редактировать книгу 
void editBook(int idBook, Library * library)
{
	char* chek = new char[5];
	do
	{
		cout << "you skan a book to edit? Yes/y | No/n\nenter: ";		//проведён ли поиск книги
		getchar();
		cin.getline(chek, 5); 
		if (0 == strcmp(chek, "Yes") ||									
			0 == strcmp(chek, "y"))
		{
			break;																						//если да идём дальше
		}
		else
		{
			cout << "you know Id editing books? Yes/y | No/n\nenter: ";	//знает ли id книги
			fflush(stdin);
			cin.getline(chek, 5); 
			if (0 == strcmp(chek, "Yes") ||
				0 == strcmp(chek, "y"))
			{
				cout << "enter id book: ";														//ввод id
				cin >> idBook;
				break;
			}
			else
			{
				cout << "use search, id get the book automatically" << endl;	//воспользоваться поиском
				return;
			}
		}
	} while (0); //наличие id книги, после поиска книга автаматически передат id найденой книги

	cout << "Title: " << library[idBook].Title << endl << "edit Title?  Yes/y | No/n\nenter: ";	//редоктировать или нет
	cin.getline(chek, 5); fflush(stdin);
	if (0 == strcmp(chek, "Yes") ||
		0 == strcmp(chek, "y"))
	{
		cout << "enter new title: ";
		cin.getline(library[idBook].Title, 50);
	}

	cout << "Author: " << library[idBook].Author << endl << "edit Author?  Yes/y | No/n\nenter: ";		//редоктировать или нет
	cin.getline(chek, 5); fflush(stdin);
	if (0 == strcmp(chek, "Yes") ||
		0 == strcmp(chek, "y"))
	{
		cout << "enter new Author: ";
		cin.getline(library[idBook].Author, 50);
	}

	cout << "Publisher: " << library[idBook].Publisher << endl << "edit Publisher?  Yes/y | No/n\nenter: ";	//редоктировать или нет
	cin.getline(chek, 5); fflush(stdin);
	if (0 == strcmp(chek, "Yes") ||
		0 == strcmp(chek, "y"))
	{
		cout << "enter new Publisher: ";
		cin.getline(library[idBook].Publisher, 50);
	}

	cout << "Genre: " << library[idBook].Genre << endl << "edit Genre?  Yes/y | No/n\nenter: ";		//редоктировать или нет
	cin.getline(chek, 5); fflush(stdin);
	if (0 == strcmp(chek, "Yes") ||
		0 == strcmp(chek, "y"))
	{
		cout << "enter new Genre: ";
		cin.getline(library[idBook].Genre, 50);
	}
}

/// Поиск книг по автору 
void skanAuthor(int countBooks, struct Library* library, int &idBook)
{
	char* author = new char[50];
	cout << "enter author: ";														
	cin.getline(author, 50); fflush(stdin);										//ввод автора
	int count = 0;
	int* idBookAuthor = new int[countBooks];
	for (int i = 0; i < countBooks; i++)	
	{
		if (0 == strcmp(author, library[i].Author))
		{
			count++;
			idBookAuthor[i] = i;
		}
	}				//поиск всех книг выбраного автора
	if (count == 1)
	{
		return;
	}
	else if (count == 0)
	{
		cout << "there is no book with such author " << endl;					//ищет автора
	}
	else
	{
		for (int i = 0; i < count; i++)
		{
			cout << "book " << i + 1 << ":" << endl;
			cout << "Title: " << library[idBookAuthor[i]].Title << endl;
			cout << "Author: " << library[idBookAuthor[i]].Author << endl;
			cout << "Publisher: " << library[idBookAuthor[i]].Publisher << endl;
			cout << "Genre: " << library[idBookAuthor[i]].Genre << endl << endl;
		}
		int id;
		do
		{
			cout << "enter number of the book from the list: ";
			cin >> id;
		} while (id-1 >= count || id <= 0);
		return;
	}
	

}

/// Поиск книги по названию 
void skanTitle(int countBooks, struct Library* library, int &idBook)
{
	char* title = new char[50];
	cout << "enter title: ";
	cin.getline(title, 50); fflush(stdin);
	int count = 0;
	int* idBookTitle = new int[countBooks];
	for (int i = 0; i < countBooks; i++)
	{
		if (0 == strcmp(title, library[i].Title))
		{
			count++;
			idBookTitle[i] = i;
		}
	}				//поиск всех книг выбраного автора
	if (count == 1)
	{
		return;
	}
	else if (count == 0)
	{
		cout << "there is no book with such title " << endl;
	}
	else
	{
		for (int i = 0; i < count; i++)
		{
			cout << "book " << i + 1 << ":" << endl;
			cout << "Title: " << library[idBookTitle[i]].Title << endl;
			cout << "Author: " << library[idBookTitle[i]].Author << endl;
			cout << "Publisher: " << library[idBookTitle[i]].Publisher << endl;
			cout << "Genre: " << library[idBookTitle[i]].Genre << endl << endl;
		}
		int id;
		do
		{
			cout << "enter number of the book from the list: ";
			cin >> id;
		} while (id - 1 >= count || id <= 0);
		return;
	}
}

/// Сортировка массива по названию книг 
void sortTitle(int countBooks, struct Library* library)
{
	for (int i = 0; i < countBooks-1; i++)
	{
		for (int j = 0; j < countBooks-1-i; j++)
		{
			if (strcmp(library[j].Title, library[j+1].Title) > 0 )
			{
				char* title = new char[50];
				char* author = new char[50];
				char* publisher = new char[50];
				char* genre = new char[50];
				strcpy(title, library[j].Title);
				strcpy(author, library[j].Author);
				strcpy(publisher, library[j].Publisher);
				strcpy(genre, library[j].Genre);
				strcpy(library[j].Title, library[j+1].Title);
				strcpy(library[j].Author, library[j+1].Author);
				strcpy(library[j].Publisher, library[j+1].Publisher);
				strcpy(library[j].Genre, library[j+1].Genre);
				strcpy(library[j + 1].Title, title);
				strcpy(library[j + 1].Author, author);
				strcpy(library[j + 1].Publisher, publisher);
				strcpy(library[j].Genre, genre);
				delete[] title;
				delete[] author;
				delete[] publisher;
				delete[] genre;
			}
		}
	}
}

/// Сортировка массива по автору 
void sortAuthor(int countBooks, struct Library* library)
{
	for (int i = 0; i < countBooks - 1; i++)
	{
		for (int j = 0; j < countBooks - 1 - i; j++)
		{
			if (strcmp(library[j].Author, library[j + 1].Author) > 0)
			{
				char* title = new char[50];
				char* author = new char[50];
				char* publisher = new char[50];
				char* genre = new char[50];
				strcpy(title, library[j].Title);
				strcpy(author, library[j].Author);
				strcpy(publisher, library[j].Publisher);
				strcpy(genre, library[j].Genre);
				strcpy(library[j].Title, library[j + 1].Title);
				strcpy(library[j].Author, library[j + 1].Author);
				strcpy(library[j].Publisher, library[j + 1].Publisher);
				strcpy(library[j].Genre, library[j + 1].Genre);
				strcpy(library[j + 1].Title, title);
				strcpy(library[j + 1].Author, author);
				strcpy(library[j + 1].Publisher, publisher);
				strcpy(library[j].Genre, genre);
				delete[] title;
				delete[] author;
				delete[] publisher;
				delete[] genre;
			}
		}
	}
}

/// Сортировка массива по издательству
void sortPublisher(int countBooks, struct Library* library)
{
	for (int i = 0; i < countBooks - 1; i++)
	{
		for (int j = 0; j < countBooks - 1 - i; j++)
		{
			if (strcmp(library[j].Publisher, library[j + 1].Publisher) > 0)
			{
				char* title = new char[50];
				char* author = new char[50];
				char* publisher = new char[50];
				char* genre = new char[50];
				strcpy(title, library[j].Title);
				strcpy(author, library[j].Author);
				strcpy(publisher, library[j].Publisher);
				strcpy(genre, library[j].Genre);
				strcpy(library[j].Title, library[j + 1].Title);
				strcpy(library[j].Author, library[j + 1].Author);
				strcpy(library[j].Publisher, library[j + 1].Publisher);
				strcpy(library[j].Genre, library[j + 1].Genre);
				strcpy(library[j + 1].Title, title);
				strcpy(library[j + 1].Author, author);
				strcpy(library[j + 1].Publisher, publisher);
				strcpy(library[j].Genre, genre);
				delete[] title;
				delete[] author;
				delete[] publisher;
				delete[] genre;
			}
		}
	}
}