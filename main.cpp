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

    cout << "[Account Creation]"  << endl;
    cout << "Enter your Student ID [SCCGTI-2022-XXX]: ";
    cin >> regid;
    cout << "Enter your password: ";
    cin >> regpass;
    account.open("account.csv", ios::app);
    account << regid << "," << regpass << "\n";
    account.close();

    cout << "[Account Creation Successful]";
    return 0;
}

int login()
{
    fstream account;
    string logid;
    string logpass;
}

int main()
{
    registration();
}
