// Jason, Samantha, Ravi, Sheila, and Ankit are preparing for an upcoming marathon. Each day of the week,
// they run a certain number of miles and write them into a notebook.At the end of the week, they would
// like to know the number of miles run each day, the total miles for the week, and average miles run each
// day.Write a program to help them analyze their data.
// Your program must contain parallel arrays :
//      • an array to store the names of the runners
//      • a two - dimensional array of five rows and seven columns to store the number of miles run by
//      each runner each day.
// Furthermore, your program must contain at least the following functions :
//      • a function to read and store the runners’ names and the numbers of miles run each day;
//      • a function to find the total miles run by each runner and the average number of miles run each
//        day;
//      • a function to output the results.
// The output must be in the form of a table where the columns contain
//      • The runner’s name
//      • A column for each day of the week with the miles run that day
//      • The total miles run for the week
//      • The average miles run per day
// There should be a row for each runner.Use the iomanip function setw() to ensure that your table
// columns line up correctly


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const int RUNNERS = 5;
const int RUN_MILES = 7;
const string dataFile = "runners.txt";

int getRunnerInfo(string Names[], double runs[][RUN_MILES], int RUNNERS);

void findAve(const double runs[][RUN_MILES], double averages[], int runCount, int totalMiles[]);

void showCalc(string runnerNames[], double runs[][RUN_MILES], double averages[], int totalMiles[], int runCount);

int main()
{


	string runnerNames[RUNNERS];
	double runs[RUNNERS][RUN_MILES];
	double AverageMiles[RUNNERS];
	int totalMiles[RUNNERS];

	int runCount;

	runCount = getRunnerInfo(runnerNames, runs, RUNNERS);
	if (runCount == -1)
	{
		cout << "to many runs in file" << endl;
		exit;
	}
	
	findAve(runs, AverageMiles, runCount, totalMiles);

	showCalc(runnerNames, runs, AverageMiles, totalMiles, runCount);

}

int getRunnerInfo(string names[], double runs[][RUN_MILES], int runners)
{
	ifstream inFile(dataFile);
	int Rec = 0;
	
	if (!inFile)
	{
		cout << "coud not open" << dataFile << endl;
		exit;
	}
	
	while (inFile >> names[Rec])
	{
		if (Rec < RUNNERS)
		{
			for (int Q = 0; Q < RUN_MILES; Q++)
				inFile >> runs[Rec][Q];
			Rec++;
		}
		else
			return -1;
	}
	inFile.close();

	return Rec;
	
}

void findAve(const double runs[][RUN_MILES], double averages[], int runCount, int totalMiles[])
{
	double total;
	for (int row = 0; row < runCount; row++)
	{
		total = 0;
		for (int col = 0; col < RUN_MILES; col++)
		{
			total += runs[row][col];
		}
		averages[row] = total / RUN_MILES;
		totalMiles[row] = total;
	}
}

void showCalc(string runnerNames[], double runs[][RUN_MILES], double averages[], int totalMiles[], int runCount)
{
	cout << left << setw(10) << "Name" << right << setw(6) << "day 1" << setw(6) << "day 2" << setw(6) << "day 3" << setw(6) << "day 4" << setw(6) << "day 5"
		<< setw(6) << "day 6" << setw(6) << "day 7" << setw(8) << "average" << setw(6) << "total" << endl;
	for (int row = 0; row < runCount; row++)
	{
		cout << left << setw(10) << runnerNames[row] << " " << setprecision(1) << fixed;
		for (int col = 0; col < RUN_MILES; col++)
			cout << right << setw(5) << runs[row][col] << " ";
		cout << setw(5) << averages[row] << " " << setw(5) << totalMiles[row] << endl;
	}
}