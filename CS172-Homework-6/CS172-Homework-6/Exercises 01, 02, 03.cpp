// Carter Nickelson, Homework 6

#include<iostream>
#include<fstream>
#include<ctime>
#include<string>

using namespace std;

void printIntsToFile();
int countChars();
void evaluateBabyNames(string year, char gender, string name);

int main()
{
	// exercise 3

	// initialize strings for the year and name for baby name analysis
	string year, name;
	// initialize a char varibale to hold the gender type
	char gender;
	// get all of these values from the user
	cout << "Enter the name and year you are interested in and the gender to which the name belongs." << endl;
	cout << "Name: ";
	cin >> name;
	cout << endl << "Year: ";
	cin >> year;
	cout << endl << "Gender (m or f): ";
	cin >> gender;
	cout << endl;
	// cout the rank of that baby name (if applicapble using the function)
	evaluateBabyNames(year, gender, name);
	
	// exercise 2

	// cout the number of characters in the file using this function
	cout << "The total number of characters (including periods) in Exercise13_1.txt is " << countChars() << "." << endl;

	// exercise 1

	// print the random integers to the file using the function
	printIntsToFile();
	return 0;
}

void printIntsToFile()
{
	// create an output file stream with the desired name, set to append
	ofstream fout("Exercise13_1.txt",ios::app);
	// check if the file opened, if not say so and exit
	if (!fout)
	{
		cout << "Can't open file" << endl;
		return;
	}
	// set the random seed
	srand(time(NULL));
	// for each of 100 iterations, print a random number between 1 and 100 to the file, separated by a space
	for (int i = 0; i < 100; i++)
		fout << rand() % 100 + 1 << " ";
	// close the file
	fout.close();
}

int countChars()
{
	// get the file name from which to count characters from the user
	cout << "Enter file name to evaluate" << endl;
	string filename;
	cin >> filename;
	// open the file with that name
	ifstream fin(filename);
	// check to see if it opened properly, if not say so and exit
	if (!fin)
	{
		cout << "Could not open file" << endl;
		return -1;
	}
	// create a string to hold each line of text from the file
	string words;
	// initialize an int variable to count the characters
	int total = 0;
	// keep getting lines from the file until the end of file is reached
	while (!fin.eof())
	{
		// for each line, get the line from the file and give it to words
		getline(fin, words);
		// create a new integer to be the length of that 
		int characterCount = words.length();
		for (int i = 0; i < words.length(); i++)
		{
			if (words[i] == ' ')
				characterCount--;
		}
		total += characterCount;
	}
	fin.close();
	return total;
}

void evaluateBabyNames(string year, char gender, string name)
{
	string filename = "Babynameranking";
	filename += year;
	filename += ".txt";
	ifstream file1(filename);
	if (!file1)
	{
		cout << "Can't open file." << endl;
		return;
	}
	string line1;
	int location,iteration=0,rank=-1;
	if (tolower(gender) == 'm')
		location = 1;
	else location = 3;
	while (!file1.eof())
	{
		iteration++;
		int match = 0, tabs = 0;
		bool found = false;
		getline(file1, line1);
		for (int i = 0; i < line1.length(); i++)
		{
			if (line1[i] == 9)
				tabs++;
			if (tolower(line1[i]) == tolower(name[0]))
			{
				match = 1;
				for (int j = i+1; j < i + name.length(); j++)
				{
					if (line1[j] == 10)
					{
						match = 0;
						break;
					}
					if (line1[j] != name[j - i])
					{
						match = 0;
						break;
					}
				}
				if (match!=0 && line1[i + name.length()] != 9)
					match = 0;
			}
			if (match == 1 && tabs == location)
			{
				found = true;
				break;
			}
		}
		if (found)
		{
			rank = iteration;
			break;
		}
	}
	file1.close();
	if (rank == -1)
		cout <<"The name " << name << " was not ranked in the top 1000 among " << (gender == 'm' ? "males" : "females") << " in the year " << year <<"."<< endl;
	else cout <<"The name" << name << " was ranked number " << rank << " among " << (gender == 'm' ? "males" : "females") << " in the year " << year << "." << endl;
}