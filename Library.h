#ifndef LIBRARY_H
#define LIBRARY_H

#include "Headers\Book.h"
#include "Headers\Employee.h"
#include "Headers\PriorityQueue.h"

/*
- System inits and grabs book
- Employees init, add themselves to the system
- Add every employee to the right book queue

- System starts message queue
	-Look at each book queue
		-If the book is available, look at the front of the queue, set book times and give the book to the employee and reset their waitime and begin counting up on their holding time
		-If the book isn't available, up the count on the holding employee and increment every other employee waiting time (do these in their update functions)
		-if the employee needs to to give the book back, reset waiting time, take the book away from them, pop them out of the queue and set the book back to archived in the system
		-Book class should have table that maps employee ids to their holding times so that when they leave the queue and come back their retain times are not set to 0 and instead set to
		 their old retain time

*/

class Library
{

};

#endif