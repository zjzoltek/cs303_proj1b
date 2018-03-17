//
// Created by Connor Marchand on 3/16/18.
//

#include "../Headers/Employee.h"


Employee::Employee(std::string name) {
    this->_name = name;
    this->_waitTime = 0;
    this->_totalRetainTime = 0;
    this->_holdingBook = false;
    this->_book = nullptr;
}

string Employee::getEmployeeName() {
    return this->std::_name;
}

//Return wait time
int Employee::getWaitTime() {
    return this->_waitTime;
}

//Retrun total time employee has retained a book
int Employee::getTotalRetainTime() {
    return this->_totalRetainTime;
}

//Return is emyploee is holding book
bool Employee::isHoldingBook() {
    return this->_holdingBook;
}

//Return book employee is holding
Book Employee::getBook() {
    return this->*_book;
}


//Set name of employee
void Employee::setEmployeeName(std::string _name) {
    this->std::_name = _name;
}

//Set time employee has to wait
void Employee::setWaitTime(int time) {
    if(time < 0){
        this->_waitTime = 0;
    }
    else{
        this->_waitTime = time;
    }
}

//Set time employee how long retained book
void Employee::setTotalRetainTime(int time) {
    if(time < 0){
        this->_totalRetainTime = 0;
    }
    else
        this->_totalRetainTime = time;
    }
}

//Set if a employee is holding a book or not
void Employee::setHoldingBook(bool holdingBook) {
    this->_holdingBook = holdingBook;
}

//Set name of book emyployee requests
void Employee::requestBook(std::string nameOfBook) {
    this->_bookName = nameOfBook;
}









