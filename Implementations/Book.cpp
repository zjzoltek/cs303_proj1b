#include "../Headers/Book.h"

Book::Book()
{
	_isFinished = true;
}

Book::Book(std::string name, Date currentDate)
{

    _name = name;
	_isArchived = true;
	_isFinished = false;

    _circulationStartDate = currentDate;
	_circulationStartDate.add_days(RANDOM_NUMBER(1, MAX_POSSIBLE_CIRCULATION_DELAY));

    _circulationEndDate = _circulationStartDate;
	_circulationEndDate.add_days(RANDOM_NUMBER(1, MAX_POSSIBLE_CIRCULATION_TIME));

	_currentDate = Date();
    _empQueue = PriorityQueue<Employee*>(&_employee_comparator);
	_bookUser = nullptr;
}

void Book::pushEmployee(Employee& e) {
	if (_retainTimes.find(e.getID()) != _retainTimes.end())
	{
		e.setTotalRetainTime(_retainTimes[e.getID()]);
		_empQueue.push(&e);
	} else
	{
		_retainTimes[e.getID()] = 0;
		_empQueue.push(&e);
	}
}

void Book::popEmployee() {
    _empQueue.pop();
}

Employee * Book::frontEmployee() {
    return _empQueue.front();
}

bool Book::isArchived() {
    return _isArchived;
}

bool Book::isFinished()
{
	return _isFinished;
}

Date Book::getStartDate() {
    return _circulationStartDate;
}

void Book::setCurrentDate(Date date)
{
	_currentDate = date;
}

Date Book::getEndDate() {
    return _circulationEndDate;
}

std::string Book::getName()
{
	return _name;
}

size_t Book::getSizeOfWaitlist()
{
	return _empQueue.size();
}

bool Book::operator==(const Book &rhs) const {
    return (_name == rhs._name);
}

bool Book::operator<(const Book& rhs) const
{
	return _name < rhs._name;
}

void Book::tick()
{
	if (_bookUser == nullptr)
	{
		if (_empQueue.is_empty())
		{
			_isFinished = true;
			_isArchived = true;
			std::cout << "[" << _name << "]: " << "I have no more employees in my queue. I'm finished. The system will now archive me." << std::endl;
		} else
		{
			if (_currentDate == _circulationStartDate)
			{
				_bookUser = _empQueue.front();
				_empQueue.pop();
				_bookUser->setHoldingBook(true);
				std::cout << "[" << _name << "]: " << "I have assigned myself to " << _bookUser->getEmployeeName() << std::endl;
			}
		}
	} else
	{
		for (auto& emp : _empQueue)
		{
			emp->tick();
		}

		_bookUser->tick();

		_empQueue.sort_internal_heap();

		if (_currentDate == _circulationEndDate)
		{
			if (_empQueue.is_empty())
			{
				_retainTimes[_bookUser->getID()] = _bookUser->getTotalRetainTime();
				_bookUser->setTotalRetainTime(0);
				_bookUser->setWaitTime(0);
				_bookUser->setHoldingBook(false);
				std::cout << "[" << _name << "]: " << "I have no more employees in my queue. I'm finished. The system will now archive me." << std::endl;
				_isFinished = true;
				_isArchived = true;
				return;
			}

			_retainTimes[_bookUser->getID()] = _bookUser->getTotalRetainTime();
			_bookUser->setTotalRetainTime(0);
			_bookUser->setWaitTime(0);
			_bookUser->setHoldingBook(false);

			_bookUser = _empQueue.front();
			_empQueue.pop();
			_bookUser->setHoldingBook(true);

			_circulationEndDate = _currentDate;
			_circulationEndDate.add_days(RANDOM_NUMBER(1, MAX_POSSIBLE_CIRCULATION_TIME));

			std::cout << "[" << _name << "]: " << "I have moved the book on to " << _bookUser->getEmployeeName() << std::endl;
		}
	}

	
}