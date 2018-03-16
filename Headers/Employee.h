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
    int totalWaitTime, totalHoldTime;
    std::string _name;



public:
    Employee(std::string name);

};

#endif
