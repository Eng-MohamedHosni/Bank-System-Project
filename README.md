# Bank System Application

This project is a simple bank management system built using C++. It allows users to manage clients, transactions, users, and currency exchange operations. The application also includes login and password encryption features to enhance security.

## Features

### Main Menu
The main menu provides the following options for managing clients and users:
1. **Show Client List** - View all the registered clients.
2. **Add New Client** - Register a new client by entering their details.
3. **Delete Client** - Remove a client from the system.
4. **Update Client Info** - Modify an existing client's information.
5. **Find Client** - Search for a specific client by their details.
6. **Transactions** - Access the transaction menu to handle deposits, withdrawals, and transfers.
7. **Manage Users** - Manage user accounts, including adding, deleting, and updating users.
8. **Login Register** - Login to the system or register a new user.
9. **Currency Exchange** - Manage currency exchange operations, including rate updates and currency calculations.
10. **Logout** - Log out of the system.

### Transactions Menu
This menu allows users to manage their financial transactions:
1. **Deposit** - Deposit funds into an account.
2. **Withdraw** - Withdraw funds from an account.
3. **Total Balances** - View the total balance of a specific account.
4. **Transfer** - Transfer funds between accounts.
5. **Transfer Log** - View a log of all transfers made.
6. **Main Menu** - Return to the main menu.

### Manage Users Menu
Manage the system's users with the following options:
1. **List Users** - View all registered users.
2. **Add New User** - Add a new user to the system.
3. **Delete User** - Remove a user from the system.
4. **Update User** - Modify a user's information.
5. **Find User** - Search for a specific user.
6. **Main Menu** - Return to the main menu.

### Currency Exchange Menu
This menu provides options for handling currency exchange:
1. **List Currencies** - View all available currencies.
2. **Find Currency** - Search for a specific currency.
3. **Update Rate** - Update the exchange rate of a currency.
4. **Currency Calculator** - Calculate the equivalent amount in a different currency.
5. **Main Menu** - Return to the main menu.

## Additional Features
- **Login Screen**: Secure login mechanism for users to access the system. Users must register before logging in.
- **Password Encryption**: Passwords are encrypted and stored securely in the database to protect user information.
- **Database Integration**: All user and client data are stored in a database, which can be easily updated or retrieved.

## Testing the Features
To test the application, use the following credentials for the login screen:
- **Username**: User2
- **Password**: 1234

These credentials are pre-registered in the system and can be used to access and test all features.

## Technologies Used
- C++ (for the main application logic)
- File-based storage (for database management)

