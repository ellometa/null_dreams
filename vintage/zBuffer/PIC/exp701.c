#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_DEPT_LEN 30
#define MAX_PROJ_NAME 50

typedef enum { SALES, TECHNICAL } Role;

typedef union {
    struct {
        float commission;
        float sales_target;
    } sales;
    struct {
        char project_name[MAX_PROJ_NAME];
        float project_allowance;
    } technical;
} RoleData;

typedef struct Employee {
    int id;
    char name[MAX_NAME_LEN];
    int age;
    char department[MAX_DEPT_LEN];
    float basic_salary;
    Role role;
    RoleData role_data;
    struct Employee *next;
} Employee;

Employee *head = NULL;

void add() {
    Employee *new_emp = (Employee *)malloc(sizeof(Employee));
    if (!new_emp) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter Employee ID: ");
    scanf("%d", &new_emp->id);
    printf("Enter Name: ");
    scanf("%s", new_emp->name);
    printf("Enter Age: ");
    scanf("%d", &new_emp->age);
    printf("Enter Department: ");
    scanf("%s", new_emp->department);
    printf("Enter Basic Salary: ");
    scanf("%f", &new_emp->basic_salary);
    
    printf("Select Role (0 for SALES, 1 for TECHNICAL): ");
    scanf("%d", (int *)&new_emp->role);
    
    if (new_emp->role == SALES) {
        printf("Enter Commission: ");
        scanf("%f", &new_emp->role_data.sales.commission);
        printf("Enter Sales Target: ");
        scanf("%f", &new_emp->role_data.sales.sales_target);
    } else {
        printf("Enter Project Name: ");
        scanf("%s", new_emp->role_data.technical.project_name);
        printf("Enter Project Allowance: ");
        scanf("%f", &new_emp->role_data.technical.project_allowance);
    }
    
    new_emp->next = head;
    head = new_emp;
    printf("Employee added successfully!\n");
}

void display() {
    Employee *temp = head;
    if (!temp) {
        printf("No employees found.\n");
        return;
    }
    
    while (temp) {
        printf("\nEmployee ID: %d\n", temp->id);
        printf("Name: %s\n", temp->name);
        printf("Age: %d\n", temp->age);
        printf("Department: %s\n", temp->department);
        printf("Basic Salary: %f\n", temp->basic_salary);
        
        if (temp->role == SALES) {
            printf("Role: Sales\n");
            printf("Commission: %f\n", temp->role_data.sales.commission);
            printf("Sales Target: %f\n", temp->role_data.sales.sales_target);
            printf("Total Salary: %f\n", temp->basic_salary + temp->role_data.sales.commission);
        } else {
            printf("Role: Technical\n");
            printf("Project Name: %s\n", temp->role_data.technical.project_name);
            printf("Project Allowance: %f\n", temp->role_data.technical.project_allowance);
            printf("Total Salary: %f\n", temp->basic_salary + temp->role_data.technical.project_allowance);
        }
        temp = temp->next;
    }
}

void search() {
    int id;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);
    
    Employee *temp = head;
    while (temp) {
        if (temp->id == id) {
            printf("Employee Found:\n");
            printf("Name: %s, Age: %d, Department: %s, Basic Salary: %f\n", 
                   temp->name, temp->age, temp->department, temp->basic_salary);
            return;
        }
        temp = temp->next;
    }
    printf("Employee not found.\n");
}

void delete() {
    int id;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);
    
    Employee *temp = head, *prev = NULL;
    while (temp) {
        if (temp->id == id) {
            if (prev) prev->next = temp->next;
            else head = temp->next;
            free(temp);
            printf("Employee deleted successfully!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Employee not found.\n");
}

void update() {
    int id;
    printf("Enter Employee ID to update: ");
    scanf("%d", &id);
    
    Employee *temp = head;
    while (temp) {
        if (temp->id == id) {
            printf("Enter New Name: ");
            scanf("%s", temp->name);
            printf("Enter New Age: ");
            scanf("%d", &temp->age);
            printf("Enter New Department: ");
            scanf("%s", temp->department);
            printf("Enter New Basic Salary: ");
            scanf("%f", &temp->basic_salary);
            printf("Employee data updated successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Employee not found.\n");
}


int main() {
    int choice;
    do {
        printf("\n1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee Data\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: delete(); break;
            case 6: printf("Exiting.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}
