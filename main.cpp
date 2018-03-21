#include "Library.h"

int main()
{
	//Date can be anything you want it to be. 
	Date startDate = Date(2018, 3, 20);

	Library lib(startDate);

	lib.addBook("Moby Dick");
	lib.addBook("My Mom and Me");
	lib.addBook("Women United");

	lib.addEmployee("Jane", "Moby Dick");
	lib.addEmployee("Joe", "Moby Dick");
	lib.addEmployee("Smoe", "Moby Dick");

	//Uncomment if you wish for a more complicated simulation
	/*lib.addEmployee("Fi", "My Mom and Me");
	lib.addEmployee("Phi", "My Mom and Me");
	lib.addEmployee("Pho", "My Mom and Me");

	lib.addEmployee("Tyrone", "Women United");
	lib.addEmployee("Jamal", "Women United");
	lib.addEmployee("Raquesh", "Women United");*/

	lib.start();
}