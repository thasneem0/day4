#include <stdio.h>
#include <string.h>

struct employee {
    int id;
    char name[300];
    float salary;
    char department[50];
};
typedef struct employee emp;

void reademployees(emp employees[], int employecount);
void displayemployees(emp employees[], int employecount);
emp findhighestsalaried(emp employees[], int employecount);

int main() {
    int employecount, i;
    printf("enter the number of employees:"); 
    scanf("%d", &employecount); 

    emp employees[1000];
    reademployees(employees, employecount);
    displayemployees(employees, employecount);
    emp highestsalaried = findhighestsalaried(employees, employecount);

    printf("Employee with highest salary: %s, %.2f (%s)\n", highestsalaried.name, highestsalaried.salary, highestsalaried.department);
    return 0;
}

void reademployees(emp employees[], int employecount) {
    for (int i = 0; i < employecount; i++) {
        printf("enter the employee id:");
        scanf("%d", &employees[i].id); 

        printf("enter the employee name:");
        scanf(" %s", employees[i].name); 

        printf("enter the employee salary:");
        scanf("%f", &employees[i].salary); 

        printf("enter the employee department:");
        scanf(" %s", employees[i].department); 
    }
}

void displayemployees(emp employees[], int employecount) {
    for (int i = 0; i < employecount; i++) {
        printf("the employee id: %d\n", employees[i].id); 
        printf("the employee name: %s\n", employees[i].name); 
        printf("the employee salary is: %f\n", employees[i].salary); 
        printf("the employee department is: %s\n\n", employees[i].department); 
        printf("\n"); 
    }
}

emp findhighestsalaried(emp employees[], int employecount) {
    emp highest = employees[0]; 
    for (int i = 1; i < employecount; i++) {
        if (employees[i].salary > highest.salary) {
            highest = employees[i];
        }
    }
    return highest;
}
