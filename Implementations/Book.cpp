#include "../Headers/Book.h"

Book::Book(std::string name)
{
    _name = name;
    _isArchived = false;
    _circulationStartDate = Date();
    _circulationEndDate = Date();
    _empQueue = PriorityQueue<Employee>();
}

void Book::pushEmployee(Employee& e) {
	_retainTimes[e.getID()] = 0;
    _empQueue.push(e);
}

void Book::popEmployee() {
    _empQueue.pop();
}

Employee Book::frontEmployee() {
    return _empQueue.front();
}

bool Book::isArchived() {
    return _isArchived;
}

Date Book::getStartDate() {
    return _circulationStartDate;
}

Date Book::getEndDate() {
    return _circulationEndDate;
}

std::string Book::getName()
{
	return _name;
}

bool Book::operator==(const Book &rhs) const {
    return (_name == rhs._name);
}

bool Book::operator<(const Book& rhs) const
{
	return _name < rhs._name;
}