#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int registration()
{
    fstream account;
    string regid;
    string regpass, regconf;

    cout << "[Account Registration]"  << endl;
    cout << "Enter your Student ID [SCCGTI-2022-XXX]: ";
    cin >> regid;
    cout << "Enter your password: ";
    cin >> regpass;
    account.open("account.csv", ios::app);
    account << regid << "," << regpass << "\n";
    account.close();

    cout << "[Account Creation Successful]";
    system ("PAUSE");
}

int login()
{
    fstream account;
    string logid;
    string logpass;
    string line;
    unsigned int curLine = 0;

    account.open("account.csv", ios::in);
    system ("CLS");
    cout << "[Account Login]" << endl;
    cout << "Enter your Student ID: ";
    cin >> logid;
    cout << "Enter your password: ";
    cin >> logpass;

    for (curLine; getline(account, line); curLine++)
        {
            string user, pass;
            stringstream inputString(line);
            getline(inputString, user, ',');
            getline(inputString, pass, ',');

            if (line.find(logid) == string::npos)
                {
                    cout << "[Account not Found]" << endl;
                    for (curLine; getline(account, line); curLine++){}
                    system ("PAUSE");
                }

            else if (line.find(logid) != string::npos)
                {
                    if (logpass == pass)
                        {
                            cout << "[Login Successful]" << endl;
                            for (curLine; getline(account, line); curLine++){}
                            system ("PAUSE");
                        }

                    else if (logpass != pass)
                        {
                            cout << "[Incorrect Password]" << endl;
                            system ("PAUSE");
                            system ("CLS");
                            cout << "[REDIRECTING TO MAIN PAGE]" << endl;
                            system ("PAUSE");
                        }

                }

        }
    account.close();
}

int main()
{
    int userc;
    while (userc != 3)
    {
    system ("CLS");
    cout << "1. Register 2. Login 3. Exit" << endl;
    cout << "Type here: ";
    cin >> userc;

    if (userc == 1)
        {
            system ("CLS");
            registration();
        }

    else if (userc == 2)
        {
            system ("CLS");
            login();
        }
    }
}
