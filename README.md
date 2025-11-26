# Banking System Project

This is a C project based on a basic banking system.  
It has options to create an account, deposit money, withdraw money and show the balance.

## Features
- Create Account  
- Deposit Amount  
- Withdraw Amount  
- Check Balance  
- Multiple Accounts Support
- File Storage
## Folder Structure
- src → contains all .c files  
- include → contains header file  
- docs → contains project report
- assets → empty  
- sample_input.txt → example input
## Compilation
Run the following command:
gcc -Iinclude src/main.c src/bank.c -o banking
## Running the program
./banking
To run the project using the sample input, use:
./banking < sample_input.txt
## File Handling
All accounts are stored in:
accounts.txt

Each line contains:
AccountNumber Name Balance
## Author
Pratik Mehra  
SAP ID: 590027706

