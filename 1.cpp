#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

int main()
{
	string line;
	string search;
	ifstream inFile;
	unsigned int curLine = 0;
	
	inFile.open("test.txt");	
	
	cout << "Enter Student ID: ";
	cin >> search;
	cout << "\n";

	for (curLine; getline(inFile, line); curLine++)
	{
		string studentid, fname, lname, year, section, load;
		stringstream inputString(line);
		getline(inputString, studentid, ',');
		getline(inputString, fname, ',');
		getline(inputString, lname, ',');
		getline(inputString, year, ',');
		getline(inputString, section, ',');
		getline(inputString, load, ',');
		if (line.find(search) != string::npos)
		{
			cout << "Student ID: " << studentid << endl;
			cout << "Name: " << fname << " " << lname << endl;
			cout << "Year: " << year << " Year" << endl;
			cout << "Section: " << section << endl;
			cout << "Academic Load: " << load << endl;
		}
	}

	inFile.close();
	// if (inFile.is_open())
	// {
	// 	while (getline(inFile, line))
	// 	{
	// 		curLine++;
	// 		if (line.find(search) != string::npos)
	// 		{
	// 			cout << "Found: " << search
	// 		}
	// 	}
	// }	
	// while (inFile.good())
	// {
	// 	getline(inFile, line);
	// 	pos = line.find(search);
	// 	if (pos!=string::npos)
	// 		{
	// 			cout << "Found!\n\n";
	// 		}
	// }
	

}
