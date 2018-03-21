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

//How long a "tick" should be in our unit of time
#define TICK_LENGTH 5
//What a tick's unit of time should be defined as. Any other chrono types will work here
#define TICK_TYPE std::chrono::seconds
//Construct a tick using our defined unit of time and tick length
#define TICK TICK_TYPE(TICK_LENGTH)
//Define how "waiting for a tick" should look
#define WAIT_A_TICK std::this_thread::sleep_for(TICK)
//Constant visual seperator to be used in output to the user to make things clearer
#define VISUAL_SEPERATOR "--------------------"

class Library
{
private:
	Date _currentDate;
	std::vector<Employee> _employees;
	std::map<std::string, Book> _books;
	
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

