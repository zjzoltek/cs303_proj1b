#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Date.h"
#include "Employee.h"
#include "StringTokenizer.h"
#include "PriorityQueue.h"
#include "Book.h"
#include <string>

class Employee
{
private:
    int _waitTime, _totalRetainTime;
    Book *_book;
    bool _holdingBook;
    std::string _name;
    std::string _bookName;



public:
    Employee(std::string name);

    string getEmployeeName();
    int getWaitTime();
    int getTotalRetainTime();
    bool isHoldingBook();
    Book getBook();

    void setEmployeeName(std::string _name);
    void setWaitTime(int time);
    void setTotalRetainTime(int time);
    void setHoldingBook(bool holdingBook);
    void requestBook(std::string nameOfBook);

};

#endif
