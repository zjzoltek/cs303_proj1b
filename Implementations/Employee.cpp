//
// Created by Connor Marchand on 3/16/18.
//

#include "../Headers/Employee.h"

Employee::Employee(std::string name, uint32_t id, std::string& desiredBook)
{
	this->_empName = name;
	this->_waitTime = 0;
	this->_totalRetainTime = 0;
	this->_holdingBook = false;
	this->_desiredBook = desiredBook;
	this->_id = id;
}

std::string Employee::getEmployeeName()
{
	return this->_empName;
}

//Return wait time
uint32_t Employee::getWaitTime()
{
	return this->_waitTime;
}

//Retrun total time employee has retained a book
uint32_t Employee::getTotalRetainTime()
{
	return this->_totalRetainTime;
}

uint32_t Employee::getID()
{
	return _id;
}

//Return is emyploee is holding book
bool Employee::isHoldingBook()
{
	return this->_holdingBook;
}

//Set name of employee
void Employee::setEmployeeName(std::string& _name)
{
	this->_empName = _name;
}

//Set time employee has to wait
void Employee::setWaitTime(int32_t time)
{
	this->_waitTime = time;
}

//Set time employee how long retained book
void Employee::setTotalRetainTime(int32_t time)
{
	this->_totalRetainTime = time;
}

//Set if a employee is holding a book or not
void Employee::setHoldingBook(bool holdingBook)
{
	this->_holdingBook = holdingBook;
}

//Set name of book emyployee requests
void Employee::requestBook(std::string& nameOfBook)
{
	this->_desiredBook = nameOfBook;
}

bool Employee::operator<(const Employee& rhs) const
{
	return (_totalRetainTime - _waitTime) < (rhs._totalRetainTime - rhs._waitTime);
}
