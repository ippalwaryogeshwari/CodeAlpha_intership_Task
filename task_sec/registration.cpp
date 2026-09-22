#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void registerUser()
{
    bool exists = false;
    string username;
    string password;
    cout << "enter username : ";
    cin >> username;

    cout << "enter password : ";
    cin >> password;

    string storedUsername;
    string storedPassword;

    ifstream file;
    file.open("user.txt");
    if (!file)
    {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    while (file >> storedUsername >> storedPassword)
    {
        if (username == storedUsername)
        {
            exists = true;
            break;
        }
    }
    file.close();

    if (exists)
    {
        cout << "Username already exists!\n";
    }
    else
    {
        ofstream file;

        file.open("user.txt", ios::app);
        file << username << " " << password << endl;

        file.close();

        cout << "Register successful!\n";
    }
}

void loginUser()
{
    string username;
    string password;

    cout << "enter username : ";
    cin >> username;

    cout << "enter password : ";
    cin >> password;

    ifstream file;

    file.open("user.txt");
    string storedUsername;
    string storedPassword;

    bool login = false;
    while (file >> storedUsername >> storedPassword)
    {
        if (username == storedUsername && password == storedPassword)
        {
            login = true;
            break;
        }
    }

    if (login)
    {
        cout << "login successfuly " << endl;
    }
    else
    {
        cout << "invalid username and password!" << endl;
    }

    file.close();
}

int main()
{
    int choise = 0;
    while (choise != 3)
    {
        cout << "=======Registration System=========\n";
        cout << "       1.Registration   \n";
        cout << "       2.Login     \n";
        cout << "       3.Exit     \n";

        cout << "enter your choice(1,2,3) : ";
        cin >> choise;

        if (choise == 1)
        {
            registerUser();
        }
        else if (choise == 2)
        {
            loginUser();
        }
        else if (choise == 3)
        {
            cout << " Exiting.....\n";
        }
        else
        {
            cout << " ***enter valid choise*** \n";
        }
    }
}