#include <iostream>
#include<string>
using namespace std;
int length = 4;
struct Account
{
    string user_name;
    string pass_word;
    float balance = 0;
    string id;
    string gender;
    int age;

    string job;
};

Account users[10000]; ///index = i;

void createClients()//(function of recorded clients)
{
    string names[4] = { "menna", "nour", "habiba", "mayar" };
    string passwords[4] = { "2020", "2021", "2022", "2023" };
    float balances[4] = { 10000, 8000, 20000, 15000 };
    string UserId[4] = { "100","101","102","103" };
    string UserGender[4] = { "Female","Female","Female","Female" };
    int UserAge[4] = { 19,18,20,30 };
    string UserJob[4] = { "Teacher","Doctor","Dentist","Vet" };
    for (int i = 0; i < 4; ++i)
    {
        Account& user = users[i];
        user.user_name = names[i];
        user.pass_word = passwords[i];
        user.balance = balances[i];
        user.id = UserId[i];
        user.gender = UserGender[i];
        user.age = UserAge[i];
        user.job = UserJob[i];
    }
}

int findUser(string username, string password)  //(function of find the user recorded)
{
    int userIndex = -1;
    for (int i = 0; i < length; i++)
    {
        if (username == users[i].user_name && password == users[i].pass_word)
        {
            userIndex = i;
            break;
        }
    }
    if (userIndex >= 0)
        cout << "login successfully" << endl;
    else
        cout << "Wrong password or username" << endl;
    return userIndex;
}

void addUser() //(function of adding anew account)
{
    cout << "Enter User Name : ";
    cin >> users[length].user_name;
    cout << "Enter Password : " << endl;
    cin >> users[length].pass_word;
    cout << "Enter Balance :" << endl;
    cin >> users[length].balance;
    cout << "Enter His Job :" << endl;
    cin >> users[length].job;
    cout << "Enter His Age :" << endl;
    cin >> users[length].age;
    cout << "Enter His Gender :" << endl;
    cin >> users[length].gender;
    length++;
}
void listAllAccounts() //(function of all recorded accounts)
{

    cout << "\nUsers in the system :" << endl;
    cout << "Id" << " \t " << "User Name" << " \t " << "Password" << "\t " << "Balance" << "\t " << "Gender" << "\t\t" << "Job" << "\t\t " << "Age" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << users[i].id << "\t " << users[i].user_name << "\t\t" << users[i].pass_word << "  \t\t" << users[i].balance << "\t\t" << users[i].gender << " \t\t" << users[i].job << "\t\t" << users[i].age << endl;
    }
}
void modifyAllAccounts(string id) //(function of modifying any recorded account)
{

    int index;   //return the value of i
    for (int i = 0; i < length; i++)
    {
        if (id == users[i].id)
        {
            index = i;
            break;
        }

    }
    cout << "Enter User Name : ";
    cin >> users[index].user_name;
    cout << "Enter Password : ";
    cin >> users[index].pass_word;
    cout << "Enter His Job :";
    cin >> users[index].job;
    cout << "Enter His Age :";
    cin >> users[index].age;
    cout << "Enter His Gender :";
    cin >> users[index].gender;
}
void closeAccount(string id) //(function of closing any recorded account)
{
    int index;
    for (int i = 0; i < length; i++)
    {
        if (id == users[i].id)
        {
            index = i;
            break;
        }
    }
   users[index] = {};
    for (int i = index; i <= length - 1; i++)
    {
        users[i] = users[i + 1];
    }
    length -= 1;
}
// **BONOUS**
void transfer(int userindex)  //( function of transfering account to another account)
{
    string id;
    int index;
    float money;
    cout << "Enter The Id Of The User That You Want To Transfer:";
    cin >> id;
    for (int i = 0; i < length; i++)
    {
        if (id == users[i].id)
        {
            index = i;
            break;
        }
    }
    cout << "How Much do you want to transfer:";
    cin >> money;
    users[index].balance += money;
    users[userindex].balance -= money;
}
void Deposit(float& balance)
{
    float amount;
    cout << "How much are you going to deposit?" << endl;
    cin >> amount;
    balance += amount;
}
void Withdraw(float& balance)
{
    float amount;
    cout << "How much are you going to withdraw?" << endl;
    cin >> amount;
    balance -= amount;
}
void userMain(std::string&, std::string&);
void adminMain(std::string& username, std::string& password, bool& verifiedAdmin)//(function of Admin)
{
    cout << "Enter username:" << endl;
    cin >> username;
    cout << "Enter password:" << endl;
    cin >> password;
    if (username != "basma" || password != "2462002")
    {
        cout << "\nWrong" << endl;
        verifiedAdmin = false;
    }
    else
    {
        verifiedAdmin = true;
        cout << "\nlogin successfuly" << endl;
    }
    if (verifiedAdmin == true)
    {
        int answer = 1;
        int op;
        string id;
        while (answer == 1)
        {
            cout << "\nChoose your operation: " << endl;
            cout << "1-Add new account" << endl << endl
                << "2-Modify account" << endl << endl
                << "3-Close account" << endl << endl
                << "4-List all accounts" << endl;
            cout << "Please Enter Your Choice:";
            cin >> op;
            if (op == 1)
            {
                addUser();
            }
            else if (op == 2)
            {
                cout << "Enter the user's Id:";
                cin >> id;
                modifyAllAccounts(id);
            }
            else if (op == 3)
            {
                cout << "Enter User's Id:";
                cin >> id;
                closeAccount(id);
            }
            else if (op == 4)
            {
                listAllAccounts();
            }
            else {
                cout << "invalid operation" << endl;
            }
            cout << "Another operation?,press 1 " << endl;
            cout << "1-continue" << endl << "2-Log out" << endl;
            cin >> answer;
            if (answer == 2)
            {
                string username;
                string password;
                bool verifiedAdmin = true;
                int choice;
                cout << "1:Admin" << endl;
                cout << "2:User" << endl;

                cout << "Please Enter Your Choice:";
                cin >> choice;
                if (choice == 1)
                {
                    adminMain(username, password, verifiedAdmin);
                }
                if (choice == 2)
                {
                    userMain(username, password);
                }
            }

        }
    }
}
void userMain(std::string& username, std::string& password) //(function of USER)
{
    cout << "Enter username:" << endl;
    cin >> username;
    cout << "Enter password:" << endl;
    cin >> password;
    int userIndex = findUser(username, password);
    if (userIndex >= 0)
    {
        float& balance = users[userIndex].balance;
        float deposit, withdraw;


        int op;
        int answer = 1;
        while (answer == 1)
        {
            cout << "Choose your operation: " << endl;
            cout << "1.Balance Enquiry      2. Withdraw Amount    3.Deposit AmountBalance Enquiry     4.Transfer" << endl;
            cout << "Please Enter Your Choice:";
            cin >> op;
            if (op == 1)
                cout << "Current Balance: " << balance << endl;
            else if (op == 2)
                Withdraw(balance);
            else if (op == 3)
                Deposit(balance);
            else if (op == 4)
                transfer(userIndex);
            else
                cout << "Invlaid operation" << endl;
            cout << "Another operation?," << " press 1" << endl;
            cout << "1-continue" << endl << "2-Log out" << endl;
            cin >> answer;
            if (answer == 2)
            {
                string username;
                string password;
                bool verifiedAdmin = true;
                int choice;

                cout << "1:Admin" << endl;
                cout << "2:User" << endl; cout << "Please Enter Your Choice:";
                cin >> choice;
                if (choice == 1)
                {
                    adminMain(username, password, verifiedAdmin);
                }
                if (choice == 2)
                {
                    userMain(username, password);
                }

            }
        }

    }
}
int main()
{
    createClients();
    cout << "\t\t\t\t\t" << "*****BANKING RECORD SYSTEM*****" << endl;
    cout << "____________________________________________________________________________________________________________________" << endl;

    string username;
    string password;
    bool verifiedAdmin = true;
    int choice;
    cout << "1:Admin" << endl;
    cout << "2:User" << endl;
    cout << "Please Enter Your Choice:";
    cin >> choice;
    if (choice == 1)
    {
        adminMain(username, password, verifiedAdmin);
    }
    else if (choice == 2)
    {
        userMain(username, password);
    }
    else 
    {
        cout << "DNE" << endl;
    }
    return 0;
}