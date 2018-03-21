#pragma once

class Library;

#include "Headers\Book.h"
#include "Headers\Employee.h"
#include "Headers\PriorityQueue.h"

#include <vector>
#include <fstream>
#include <cstdint>
#include <cstdlib>
#include <cassert>
#include <chrono>
#include <thread>
#include <map>
#include <iostream>

#define TICK_LENGTH 5
#define TICK_TYPE std::chrono::seconds
#define TICK TICK_TYPE(TICK_LENGTH)
#define WAIT_A_TICK std::this_thread::sleep_for(TICK)
#define VISUAL_SEPERATOR "--------------------"

class Library
{
private:
	Date _currentDate;
	std::vector<Employee> _employees;
	std::map<std::string, Book> _books;
	bool _isRunning;
	
	void printBookSummary();
public:
	Library(Date startDate);

	void addEmployee(Employee e);
	void addEmployee(std::string name, std::string desiredName);
	void addBook(Book b);
	void addBook(std::string name);


	void readEmployeesFromFile(std::string filename);
	void readBooksFromFile(std::string& filename);
	
	void start();
};
