#include "Library.h"

Library::Library(Date date)
{
	srand(static_cast<unsigned int>(time(0)));
	_currentDate = date;
}

void Library::addEmployee(Employee e)
{
	_employees.push_back(e);
}

void Library::addEmployee(std::string name, std::string desiredBook)
{
	_employees.push_back(Employee(name, _employees.size()+1, desiredBook));
}

void Library::addBook(Book b)
{
	_books[b.getName()] = b;
}

void Library::addBook(std::string name)
{
	_books[name] = Book(name, _currentDate);
}

void Library::readEmployeesFromFile(std::string filename)
{
	std::ifstream fin(filename);
	std::string name, id, desiredName;
	while (fin)
	{
		fin >> name >> id >> desiredName;
		addEmployee(name, desiredName);
	}

	fin.close();
}

void Library::readBooksFromFile(std::string& filename)
{
	std::ifstream fin;
	std::string name;
	while (fin)
	{
		fin >> name;
		addBook(name);
	}

	fin.close();
}

void Library::printBookSummary()
{
	std::cout << "LIBRARY BOOK SUMMARY" << std::endl << std::endl;

	for (auto& book : _books)
	{
		if (book.second.isFinished()) continue;
		auto _b = book.second;
		std::cout << _b.getName() << std::endl;
		std::cout << VISUAL_SEPERATOR << std::endl;
		std::cout << "Circulation Start Date: " << _b.getStartDate().toString() << std::endl;
		std::cout << "Pass On Date: " << _b.getEndDate().toString() << std::endl;
		std::cout << VISUAL_SEPERATOR << std::endl;
	}
}

void Library::start()
{
	assert(!_books.empty() && !_employees.empty() && "The system needs at least one employee and book in order to function!");

	//Put the employees in the right book queues based on their desired book
	for (size_t i = 0; i < _employees.size(); i++)
	{
		_books[_employees[i].getDesiredBook()].pushEmployee(_employees[i]);
	}

	//Output some useful information
	std::cout << "Employees have been assigned! We have a total of " << _employees.size() << " employees" << std::endl << std::endl;

	uint32_t minTime = _employees.size(), maxTime = _employees.size() * MAX_POSSIBLE_CIRCULATION_TIME;

	std::cout << "Estimated time of completion: " << minTime * TICK_LENGTH << "-" << maxTime * TICK_LENGTH << " seconds" << std::endl << std::endl;

	do 
	{
		std::cout << std::endl;
		std::cout << "Current Date: " << _currentDate.toString() << std::endl << std::endl;

		auto itr = _books.begin();
		while (itr != _books.end())
		{
			//If the book still has people remaining (therefore is not finished), give it the current date
			//and call its tick method
			if (!itr->second.isFinished())
			{
				itr->second.setCurrentDate(_currentDate);
				itr->second.tick();
				if (itr->second.isFinished())
				{
					itr = _books.erase(itr);
					continue;
				}
			}

			if (itr == _books.end()) continue;
			itr++;
		}

		std::cout << std::endl;
		if(!_books.empty()) printBookSummary();
		_currentDate.add_days(1);
		WAIT_A_TICK;
	} while (!_books.empty());

	std::cout << std::endl;
	std::cout << "Program is finished! No more employees are waiting on anymore books!" << std::endl;
	std::cout << "Press ENTER to quit";
	cin.get();
}