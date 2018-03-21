#pragma once

class Employee;

#include <string>
#include <vector>
#include <cstdint>
#include "Date.h"

class Employee
{
private:
	uint32_t _waitTime, _totalRetainTime, _id;

	std::string _empName;
	std::string _desiredBook;
	
	bool _holdingBook;
public:
	Employee(std::string name, uint32_t id, std::string& desiredBook);

	std::string getDesiredBook();
	std::string getEmployeeName();
	uint32_t getWaitTime();
	uint32_t getTotalRetainTime();
	uint32_t getID();
	
	void setWaitTime(int32_t time);
	void setTotalRetainTime(int32_t time);
	void setHoldingBook(bool holdingBook);
	void requestBook(std::string& nameOfBook);

	bool isHoldingBook();
	bool operator<(const Employee& rhs) const;

	void tick();
};
