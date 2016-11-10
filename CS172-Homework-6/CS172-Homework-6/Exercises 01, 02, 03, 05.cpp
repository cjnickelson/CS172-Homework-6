// Carter Nickelson, Homework 6

#include<iostream>
#include<fstream>
#include<ctime>
#include<string>
#include"Complex.h"

using namespace std;

void printIntsToFile();
int countChars();
void evaluateBabyNames(string year, char gender, string name);

int main()
{
	// exercise 5
	
	// initialize four doubles to recieve the input from the user
	double a, b, c, d;
	cout << "Enter the first complex number (real part then imaginary): ";
	// get the first complex number
	cin >> a >> b;
	cout << endl<< "Enter the second complex number (real part then imaginary): ";
	// get the second complex number
	cin >> c >> d;
	// initialize two complex numbers with these parameters
	Complex c1(a, b), c2(c, d);
	// display the resaults of the complex addition, subtraction, multiplication, and division using the overloaded operators + - * / and <<
	cout << c1 << " + " << c2 << " = " << c1 + c2 << endl;
	cout << c1 << " - " << c2 << " = " << c1 - c2 << endl;
	cout << c1 << " * " << c2 << " = " << c1 * c2 << endl;
	cout << c1 << " / " << c2 << " = " << c1 / c2 << endl;
	// display the absolute value of the first complex number
	cout << "|" << c1 << "|" << " = " << c1.abs() << endl;

	// exercise 3

	// initialize strings for the year and name for baby name analysis
	string year,name;
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
		// create a new integer to be the length of that line
		int characterCount = words.length();
		// go through each character in that line to see if it is a space
		for (int i = 0; i < words.length(); i++)
		{
			// if it is, decrease the count of that line by 1
			if (words[i] == ' ')
				characterCount--;
		}
		// add the total characters in the line to the total variable
		total += characterCount;
	}
	// close the file and return the total which was counted
	fin.close();
	return total;
}

// take arguments year, gneder and name
void evaluateBabyNames(string year, char gender, string name)
{
	// all files take the form Babynameranking<year>.txt, so take the string "Babynameranking" and append the string year and ".txt" to the filename
	string filename = "Babynameranking";
	filename += year;
	filename += ".txt";
	// open the specified file
	ifstream file1(filename);
	// check to see if file opened properly, if not say so and quit
	if (!file1)
	{
		cout << "Can't open file." << endl;
		return;
	}
	// create a string to hold each line from the file
	string line1;
	// initialize ints location, iteration and rank to be used withing following while loop
	int location,iteration=0,rank=-1;
	// create a bool variable to track whether the name has been found in the file
	bool found = false;
	// set the location variable to either 1 or 3, depending on which gender the name is being applied to. These values are 1 and 3 because I will be counting the number of tabs 
	// from the start of the line. Males are in the second column, so there will be 1 tab before their names begin, females in the fourth column, so there will be 3 tabs
	if (tolower(gender) == 'm')
		location = 1;
	else location = 3;
	// continue getting lines until the end of the file is reached
	while (!file1.eof())
	{
		// increment the iteration variable each time getline is executed
		iteration++;
		// set the match variable to 0 (to say that we do not have a name match on the current line) and tabs to 0 (there have been no tabs on current line)
		int tabs = 0;
		bool match = false;
		
		// get the current line
		getline(file1, line1);
		// progress through each character in this line
		for (int i = 0; i < line1.length(); i++)
		{
			// for each tab, increment the tabs variable
			if (line1[i] == 9)
				tabs++;
			// on each character, check to see if it is the same as the first letter in the name of interest
			if (tolower(line1[i]) == tolower(name[0]))
			{
				// if it is, set match to true (for now)
				match = true;
				// then, go through the NEXT (starting at j=i+1) however many characters are in the name of interest to see if they all match
				for (int j = i+1; j < i + name.length(); j++)
				{
					// we have to break out of the for loop if we run into a new line feed because it cannot evaluate characters past this point on the line
					if (line1[j] == 10)
					{
						// set match back to false, if we ran out of space, we obviously didn't find the right name
						match = false;
						break;
					}
					// If we ever find a character that is not the same as in the name, set match back to false
					if (line1[j] != name[j - i])
					{
						match = false;
						break;
					}
				}
				// once we leave this loop, if match is still 1 and the next point on the line is not a tab (to ensure that nathaniel is not mistaken for nathan) then set match back to false
				if (match!=false && line1[i + name.length()] != 9)
					match = false;
			}
			// if, once we leave this if statement, match is still 1 and tabs is the same as location (we are in the correct male/female category) then set found to true
			if (match == true && tabs == location)
			{
				found = true;
				break;
			}
		}
		// once we leave the largest for loop, we can break the while loop and set rank (the final rank of the baby name) to the iteration varibale (the line on which we are evaluating)
		if (found)
		{
			rank = iteration;
			break;
		}
	}
	// close the file
	file1.close();
	// rank will be -1 if the name was never found, because this is how we initialized it. Thus cout that the name was not ranked in the top 1000
	if (rank == -1)
		cout <<"The name " << name << " was not ranked in the top 1000 among " << (gender == 'm' ? "males" : "females") << " in the year " << year <<"."<< endl;
	// if it was found, cout that the name was ranked whatever the value of the rank variable is
	else cout <<"The name" << name << " was ranked number " << rank << " among " << (gender == 'm' ? "males" : "females") << " in the year " << year << "." << endl;
}