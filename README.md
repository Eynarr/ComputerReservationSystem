# Computer Reservation System Prototype

This is a CLI-based prototype created for educational purposes to manage computer reservations in a programming lab. The program is written in C and was primarily developed to run on Windows, using libraries such as `<windows.h>`. It simulates a reservation system that allows only authorized students to reserve computers.

## Features

The program includes the following functionalities:

1. **View Occupied and Available Computer Seats**: Displays which computers are occupied and which are available.
2. **Reserve a Computer**: Allows an authorized student (identified by their ID) to reserve a computer. The system verifies if the ID is authorized and shows the available seats.
3. **Exit the Lab**: Releases a computer seat once the student leaves, making it available for others.
4. **Lab Usage Record**: Shows a list of all students who have used the lab.
5. **List of Authorized Students**: Displays the list of students (ID and name) authorized to use the lab.
6. **Exit the System**: Allows the operator to exit the program.

The main screen also shows the number of available computers. The program includes checks to ensure:
- A maximum of 12 students can access the lab at a time.
- Only authorized students can reserve computers.
- Occupied seats cannot be reserved again.

## Getting Started

### Prerequisites
- This program requires a C compiler that supports Windows libraries (e.g., GCC for Windows or Visual Studio).
- It is designed to run on **Windows** due to the use of `<windows.h>`.

### Compilation and Execution
1. Compile the program (using GCC on Windows):
   ```bash
   gcc -o computer_reservation computer_reservation.c
