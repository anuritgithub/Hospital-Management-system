Hospital Management System
Description
This C program implements a simple Hospital Management System (HMS) that manages patient data across multiple departments using dynamic memory allocation. It provides functionality for adding, listing, and removing patients in a queue, and dynamically resizes the queue as needed.

Features
Manage patient data including ID, first name, last name, age, blood group, and gender.
Multiple departments with separate queues for each.
Add patients to the beginning or end of the queue.
List all patients in a department.
Remove and display the patient at the front of the queue.
Dynamic resizing of queues to handle more patients.
Getting Started
Prerequisites
A C compiler (e.g., GCC)
Installation
Clone the repository:

bash
Copy code
git clone https://github.com/your-username/hospital-management-system.git
Navigate to the project directory:

bash
Copy code
cd hospital-management-system
Compile the program:

bash
Copy code
gcc hms.c -o hms
Run the compiled executable:

bash
Copy code
./hms
Usage
Follow the on-screen menu to navigate through the system:
Select a department.
Add normal or critically ill patients.
List all patients in a department.
Remove the patient at the front of the queue for operation.
Example Departments
Cardiology
Neurology
Orthopedics
License
This project is licensed under the MIT License.

