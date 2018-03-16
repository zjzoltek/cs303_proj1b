#include "../Headers/Book.h"

Book::Book(std::string name)
{
    _name = name;
    _isArchived = false;
    _circulationStartDate = Date();
    _circulationEndDate = Date();
    _empQueue = PriorityQueue();

}

void Book::pushEmployee(Employee e) {
    _empQueue.push(e);

}

void Book::popEmployee() {
    _empQueue.pop();

}
Employee Book::frontEmployee() {
    return _empQueue.front();

}
bool Book::operator==(const Book &rhs) const {
    return (_name == rhs._name);

}