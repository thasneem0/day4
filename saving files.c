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
void saveemployees(emp employees[], int employecount);
void loademployees(emp employees[], int employecount);

int main() {
    int employecount;
    printf("Enter the number of employees: "); 
    scanf("%d", &employecount); 

    emp employees[1000];
    reademployees(employees, employecount);
    saveemployees(employees, employecount);
    loademployees(employees, employecount);
    displayemployees(employees, employecount);
    emp highestsalaried = findhighestsalaried(employees, employecount);

    printf("Employee with highest salary: %s, %.2f (%s)\n", highestsalaried.name, highestsalaried.salary, highestsalaried.department);
    return 0;
}

void reademployees(emp employees[], int employecount) {
    for (int i = 0; i < employecount; i++) {
        printf("Enter the employee id: ");
        scanf("%d", &employees[i].id); 

        printf("Enter the employee name: ");
        scanf(" %s", employees[i].name); 

        printf("Enter the employee salary: ");
        scanf("%f", &employees[i].salary); 

        printf("Enter the employee department: ");
        scanf(" %s", employees[i].department); 
    }
}

void saveemployees(emp employees[], int employecount) {
    FILE* file = fopen("employee.txt", "w");
    if (file == NULL) {
        printf("Error in creating file.\n");
        return;
    }
    for (int i = 0; i < employecount; i++) {
        fprintf(file, "%d %s %.2f %s\n", employees[i].id, employees[i].name, employees[i].salary, employees[i].department);
    }
    fclose(file); 
}

void loademployees(emp employees[], int employecount) {
    FILE* file = fopen("employee.txt", "r"); 
    if (file == NULL) {
        printf("Error in reading file.\n");
        return;
    }
    for (int i = 0; i < employecount; i++) {
        fscanf(file, "%d %s %f %s", &employees[i].id, employees[i].name, &employees[i].salary, employees[i].department);
    }
    fclose(file); 

void displayemployees(emp employees[], int employecount) {
    for (int i = 0; i < employecount; i++) {
        printf("The employee id: %d\n", employees[i].id); 
        printf("The employee name: %s\n", employees[i].name); 
        printf("The employee salary is: %.2f\n", employees[i].salary); 
        printf("The employee department is: %s\n\n", employees[i].department); 
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
