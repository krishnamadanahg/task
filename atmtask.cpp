#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function prototypes
void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();

// Global variables
char menuInput;
vector<string> userIds;     
vector<string> passwords;    
vector<double> balances;     

int main()
{
    cout << "Hi! Welcome to Mr. Zamar's ATM Machine!" << endl;
    start();
    return 0;
}

void printIntroMenu()
{
    cout << "\nPlease select an option from the menu below:" << endl;
    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

void printMainMenu()
{
    cout << "\nd -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

void start()
{
    while (true)
    {
        printIntroMenu();
        cin >> menuInput;

        switch (menuInput)
        {
        case 'l':
            login();
            break;
        case 'c':
            createAccount();
            break;
        case 'q':
            cout << "Thanks for stopping by!" << endl;
            exit(0);
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }
}

void createAccount()
{
    string newUserId, newPassword;
    cout << "\nPlease enter a user ID: ";
    cin >> newUserId;

    for (const string& id : userIds)
    {
        if (id == newUserId)
        {
            cout << "User ID already exists. Please choose a different ID." << endl;
            return;
        }
    }

    cout << "Please enter a password: ";
    cin >> newPassword;

    
    userIds.push_back(newUserId);
    passwords.push_back(newPassword);
    balances.push_back(0.0);

    cout << "Thank you! Your account has been created successfully!" << endl;
}

void login()
{
    string enteredUserId, enteredPassword;
    cout << "\nPlease enter your user ID: ";
    cin >> enteredUserId;
    cout << "Please enter your password: ";
    cin >> enteredPassword;
    
    for (size_t i = 0; i < userIds.size(); ++i)
    {
        if (userIds[i] == enteredUserId && passwords[i] == enteredPassword)
        {
            cout << "Access Granted!" << endl;
            while (true)
            {
                printMainMenu();

                char mainMenuInput;
                cin >> mainMenuInput;

                switch (mainMenuInput)
                {
                case 'd': // Deposit Money
                {
                    double depositAmount;
                    cout << "Enter deposit amount: Rs";
                    cin >> depositAmount;
                    if (depositAmount > 0)
                    {
                        balances[i] += depositAmount;
                        cout << "Deposited Rs" << depositAmount << " successfully." << endl;
                    }
                    else
                    {
                        cout << "Invalid amount. Please enter a positive value." << endl;
                    }
                    break;
                }
                case 'w': // Withdraw Money
                {
                    double withdrawAmount;
                    cout << "Enter withdrawal amount: Rs";
                    cin >> withdrawAmount;
                    if (withdrawAmount > 0 && withdrawAmount <= balances[i])
                    {
                        balances[i] -= withdrawAmount;
                        cout << "Withdrew Rs" << withdrawAmount << " successfully." << endl;
                    }
                    else
                    {
                        cout << "Invalid amount. Either insufficient balance or negative value entered." << endl;
                    }
                    break;
                }
                case 'r': 
                    cout << "Your current balance is: Rs" << balances[i] << endl;
                    break;
                case 'q':
                    cout << "Returning to the main menu." << endl;
                    return;
                default:
                    cout << "Invalid option. Please try again." << endl;
                }
            }
        }
    }
    cout << "******** LOGIN FAILED! ********" << endl;
}
