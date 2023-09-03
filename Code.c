#include <stdio.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define a structure for student accounts
struct StudentAccount {
    int studentID;
    char name[50];
    float feesPaid;
    float feesDue;
};

// Define a structure for employee accounts
struct EmployeeAccount {
    int employeeID;
    char name[50];
    float salary;
};

// Arrays to store student and employee accounts
struct StudentAccount students[MAX_ACCOUNTS];
struct EmployeeAccount employees[MAX_ACCOUNTS];

// Variables to keep track of the number of accounts
int numStudents = 0;
int numEmployees = 0;

// Function to insert a new student account
void insertStudent() {
    if (numStudents < MAX_ACCOUNTS) {
        struct StudentAccount newStudent;
        printf("Enter Student ID: ");
        scanf("%d", &newStudent.studentID);
        printf("Enter Student Name: ");
        scanf("%s", newStudent.name);
        printf("Enter Fees Paid: ");
        scanf("%f", &newStudent.feesPaid);
        printf("Enter Fees Due: ");
        scanf("%f", &newStudent.feesDue);

        students[numStudents++] = newStudent;
        printf("Student account added successfully.\n");
    } else {
        printf("Maximum number of student accounts reached.\n");
    }
}

// Function to modify a student account
void modifyStudent(int studentID) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].studentID == studentID) {
            printf("Enter new Fees Paid: ");
            scanf("%f", &students[i].feesPaid);
            printf("Enter new Fees Due: ");
            scanf("%f", &students[i].feesDue);
            printf("Student account modified successfully.\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", studentID);
}

// Function to search for a student account
void searchStudent(int studentID) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].studentID == studentID) {
            printf("Student ID: %d\n", students[i].studentID);
            printf("Student Name: %s\n", students[i].name);
            printf("Fees Paid: %.2f\n", students[i].feesPaid);
            printf("Fees Due: %.2f\n", students[i].feesDue);
            return;
        }
    }
    printf("Student with ID %d not found.\n", studentID);
}

// Function to delete a student account
void deleteStudent(int studentID) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].studentID == studentID) {
            for (int j = i; j < numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            numStudents--;
            printf("Student account deleted successfully.\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", studentID);
}

// Function to insert a new employee account
void insertEmployee() {
    if (numEmployees < MAX_ACCOUNTS) {
        struct EmployeeAccount newEmployee;
        printf("Enter Employee ID: ");
        scanf("%d", &newEmployee.employeeID);
        printf("Enter Employee Name: ");
        scanf("%s", newEmployee.name);
        printf("Enter Salary: ");
        scanf("%f", &newEmployee.salary);

        employees[numEmployees++] = newEmployee;
        printf("Employee account added successfully.\n");
    } else {
        printf("Maximum number of employee accounts reached.\n");
    }
}

// Function to modify an employee account
void modifyEmployee(int employeeID) {
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].employeeID == employeeID) {
            printf("Enter new Salary: ");
            scanf("%f", &employees[i].salary);
            printf("Employee account modified successfully.\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", employeeID);
}

// Function to search for an employee account
void searchEmployee(int employeeID) {
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].employeeID == employeeID) {
            printf("Employee ID: %d\n", employees[i].employeeID);
            printf("Employee Name: %s\n", employees[i].name);
            printf("Salary: %.2f\n", employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", employeeID);
}

// Function to delete an employee account
void deleteEmployee(int employeeID) {
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].employeeID == employeeID) {
            for (int j = i; j < numEmployees - 1; j++) {
                employees[j] = employees[j + 1];
            }
            numEmployees--;
            printf("Employee account deleted successfully.\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", employeeID);
}

int main() {
    int choice;

    while (1) {
        printf("\nSchool Billing System Menu:\n");
        printf("1. Insert Student Account\n");
        printf("2. Modify Student Account\n");
        printf("3. Search Student Account\n");
        printf("4. Delete Student Account\n");
        printf("5. Insert Employee Account\n");
        printf("6. Modify Employee Account\n");
        printf("7. Search Employee Account\n");
        printf("8. Delete Employee Account\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStudent();
                break;
            case 2:
                printf("Enter Student ID to modify: ");
                int modifyID;
                scanf("%d", &modifyID);
                modifyStudent(modifyID);
                break;
            case 3:
                printf("Enter Student ID to search: ");
                int searchID;
                scanf("%d", &searchID);
                searchStudent(searchID);
                break;
            case 4:
                printf("Enter Student ID to delete: ");
                int deleteID;
                scanf("%d", &deleteID);
                deleteStudent(deleteID);
                break;
            case 5:
                insertEmployee();
                break;
            case 6:
                printf("Enter Employee ID to modify: ");
                scanf("%d", &modifyID);
                modifyEmployee(modifyID);
                break;
            case 7:
                printf("Enter Employee ID to search: ");
                scanf("%d", &searchID);
                searchEmployee(searchID);
                break;
            case 8:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &deleteID);
                deleteEmployee(deleteID);
                break;
            case 9:
                printf("Exiting School Billing System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
