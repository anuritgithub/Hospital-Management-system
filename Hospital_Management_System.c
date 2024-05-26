#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for patient data
typedef struct patient {
    long long ID;
    char firstname[50];
    char lastname[50];
    int age;
    char blood[5];
    char gender;
} patient;

// Define structure for queue
typedef struct queue {
    patient* patients;
    int front, rear, size, capacity;
    char departmentname[50];
} queue;

// Initialize the queue
void init_queue(queue* q, int capacity) {
    q->patients = (patient*)malloc(capacity * sizeof(patient));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;
}

// Check if the queue is empty
int is_empty(queue* q) {
    return q->size == 0;
}

// Check if the queue is full
int is_full(queue* q) {
    return q->size == q->capacity;
}

// Resize the queue
void resize_queue(queue* q) {
    q->capacity *= 2;
    q->patients = (patient*)realloc(q->patients, q->capacity * sizeof(patient));
}

// Read number input
int readnumber() {
    char b[20];
    fgets(b, sizeof(b), stdin);
    return atoi(b);
}

// Search for a patient in the queue by ID
int search(queue* q, long long item) {
    for (int i = q->front; i <= q->rear; i++) {
        if (q->patients[i].ID == item)
            return 1;
    }
    return 0;
}

// Input patient data
patient input(queue* q) {
    patient p;
    int flag = 0;

    printf("\n   Please enter data for patient\n");
    printf("\n   First name     : ");
    fgets(p.firstname, sizeof(p.firstname), stdin);
    p.firstname[strcspn(p.firstname, "\n")] = 0; // Remove newline character

    printf("   Last name      : ");
    fgets(p.lastname, sizeof(p.lastname), stdin);
    p.lastname[strcspn(p.lastname, "\n")] = 0; // Remove newline character

    do {
        printf("   Blood Group    : ");
        scanf("%s", p.blood);
        while (getchar() != '\n'); // Clear input buffer

        if (strcmp(p.blood, "A+") == 0 || strcmp(p.blood, "a+") == 0 || strcmp(p.blood, "A-") == 0 || strcmp(p.blood, "a-") == 0 ||
            strcmp(p.blood, "B+") == 0 || strcmp(p.blood, "b+") == 0 || strcmp(p.blood, "B-") == 0 || strcmp(p.blood, "b-") == 0 ||
            strcmp(p.blood, "O+") == 0 || strcmp(p.blood, "o+") == 0 || strcmp(p.blood, "O-") == 0 || strcmp(p.blood, "o-") == 0 ||
            strcmp(p.blood, "AB+") == 0 || strcmp(p.blood, "ab+") == 0 || strcmp(p.blood, "AB-") == 0 || strcmp(p.blood, "ab-") == 0) {
            flag = 1;
        } else {
            printf("\n   Invalid Blood Group. Try Again..\n\n");
        }
    } while (flag == 0);

    printf("   Gender(m/f)    : ");
    scanf("%c", &p.gender);
    while (getchar() != '\n'); // Clear input buffer

    printf("   Age            : ");
    scanf("%d", &p.age);
    while (getchar() != '\n'); // Clear input buffer

    printf("   Mobile number  : ");
    scanf("%lld", &p.ID);
    while (getchar() != '\n'); // Clear input buffer

    if (search(q, p.ID)) {
        p.ID = 0;
        printf("\n   Data not valid. Operation cancelled.\n");
    }

    return p;
}

// Output patient data
void output(patient* p) {
    printf("\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
    printf("\n   Patient data:\n");
    printf("\n   First Name         : %s", p->firstname);
    printf("\n   Last Name          : %s", p->lastname);
    printf("\n   Gender             : %c", p->gender);
    printf("\n   Age                : %d", p->age);
    printf("\n   Blood Group        : %s", p->blood);
    printf("\n   Mobile Number      : %lld", p->ID);
    printf("\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
}

// Insert a patient at the beginning
void insertatbeg(queue* q) {
    if (is_full(q)) {
        resize_queue(q);
    }

    patient p = input(q);

    if (p.ID == 0)
        return;

    if (is_empty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        for (int i = q->rear + 1; i > q->front; i--) {
            q->patients[i] = q->patients[i - 1];
        }
        q->rear++;
    }

    q->patients[q->front] = p;
    q->size++;
    system("clear");
    printf("\n\tPatient added:");
    output(&q->patients[q->front]);
}

// Insert a patient at the end
void insertatend(queue* q) {
    if (is_full(q)) {
        resize_queue(q);
    }

    patient p = input(q);

    if (p.ID == 0)
        return;

    if (is_empty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }

    q->patients[q->rear] = p;
    q->size++;
    system("clear");
    printf("\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
    printf("\n  |-- HOSPITAL MANAGEMENT SYSTEM --|");
    printf("\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\n  ----------PATIENT ADDED-----------");
    output(&q->patients[q->rear]);
}

// Remove and return the patient at the front
void getpatientout(queue* q) {
    system("clear");
    if (is_empty(q)) {
        printf("\n  No Patient to operate\n");
    } else {
        patient* p = &q->patients[q->front];
        printf("\n  Patient to operate:");
        output(p);
        for (int i = q->front; i < q->rear; i++) {
            q->patients[i] = q->patients[i + 1];
        }
        q->rear--;
        q->size--;
    }
}

// List all patients
void listofpatients(queue* q) {
    if (is_empty(q)) {
        printf("\n  No patient\n");
        return;
    }
    system("clear");
    printf("\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
    printf("\n  |-- HOSPITAL MANAGEMENT SYSTEM --|");
    printf("\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    for (int i = q->front; i <= q->rear; i++) {
        output(&q->patients[i]);
    }
    printf("\n");
}

// Department menu
void departmentmenu(queue* q) {
    int choice = 0;
    while (choice != 5) {
        system("clear");
        printf("\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
        printf("\n  |-- HOSPITAL MANAGEMENT SYSTEM --|");
        printf("\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        printf("\n  1. Add Patient at beginning");
        printf("\n  2. Add Patient at end");
        printf("\n  3. List of Patients");
        printf("\n  4. Operate Patient");
        printf("\n  5. Exit");
        printf("\n\n  Enter your choice: ");
        choice = readnumber();

        switch (choice) {
            case 1:
                insertatbeg(q);
                break;
            case 2:
                insertatend(q);
                break;
            case 3:
                listofpatients(q);
                break;
            case 4:
                getpatientout(q);
                break;
            case 5:
                break;
            default:
                printf("\n  Invalid choice\n");
        }

        if (choice != 5) {
            printf("\n  Press Enter to continue...");
            getchar(); // Wait for Enter key press
        }
    }
}

// Main menu
void mainmenu(queue* queues[], int num_departments) {
    int choice = 0;
    while (choice != num_departments + 1) {
        system("clear");
        printf("\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
        printf("\n  |-- HOSPITAL MANAGEMENT SYSTEM --|");
        printf("\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        for (int i = 0; i < num_departments; i++) {
            printf("\n  %d. %s", i + 1, queues[i]->departmentname);
        }
        printf("\n  %d. Exit", num_departments + 1);
        printf("\n\n  Enter your choice: ");
        choice = readnumber();

        if (choice >= 1 && choice <= num_departments) {
            departmentmenu(queues[choice - 1]);
        } else if (choice == num_departments + 1) {
            break;
        } else {
            printf("\n  Invalid choice\n");
            printf("\n  Press Enter to continue...");
            getchar(); // Wait for Enter key press
        }
    }
}

int main() {
    int num_departments = 3;
    queue* queues[num_departments];

    queues[0] = (queue*)malloc(sizeof(queue));
    init_queue(queues[0], 2);
    strcpy(queues[0]->departmentname, "Cardiology");

    queues[1] = (queue*)malloc(sizeof(queue));
    init_queue(queues[1], 2);
    strcpy(queues[1]->departmentname, "Neurology");

    queues[2] = (queue*)malloc(sizeof(queue));
    init_queue(queues[2], 2);
    strcpy(queues[2]->departmentname, "Orthopedics");

    mainmenu(queues, num_departments);

    for (int i = 0; i < num_departments; i++) {
        free(queues[i]->patients);
        free(queues[i]);
    }

    return 0;
}
