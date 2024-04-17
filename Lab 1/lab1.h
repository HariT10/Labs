#define NUM_EMP 3
/* definition of an employee record*/

struct employee
{
	//NUM_EMP is 3, so there are 3 employees

	//employee first name 
	char fname[20]; 
	//employee last name
	char lname[20];
	//employee ID
	int id;
	//amount of dependents an employee can have(no more then 3)
   	char dependents [3][20];     // assume no emp can have more than 3 registered dependents
};

typedef struct employee Employees;

// add function prototypes here

void saveEmployees(Employees arrEmployees[NUM_EMP], int c, const char *fileName);

int loadEmployees(Employees arrEmployees[NUM_EMP], const char *fileName);

void printAnEmployee(Employees);

int searchFirstName(char firstN[], Employees emp[]);



