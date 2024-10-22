// the struct version


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const int RUNNERS = 5;
const int RUN_MILES = 7;
const string dataFile = "runners.txt";

struct runnerData
{
	string name;
	double runs[RUN_MILES];
	double aveMiles;
	int totalDistance;
};

int getRunnerInfo(runnerData runners[], int RUNNERS);

void findAve(runnerData runners[], int runCount);

void showCalc(runnerData runners[], int runCount);

int main()
{

	runnerData runners[RUNNERS];
	
	int runCount;

	runCount = getRunnerInfo(runners, RUNNERS);
	if (runCount == -1)
	{
		cout << "to many runs in file" << endl;
		exit;
	}
	
	findAve(runners, runCount);

	showCalc(runners, runCount);
	
}

int getRunnerInfo(runnerData allRunners[], int runners)
{
	ifstream inFile(dataFile);
	int Rec = 0;
	
	if (!inFile)
	{
		cout << "could not open" << dataFile << endl;
		exit;
	}
	
	while (inFile >> allRunners[Rec].name)
	{
		if (Rec < RUNNERS)
		{
			for (int Q = 0; Q < RUN_MILES; Q++)
				inFile >> allRunners[Rec].runs[Q]; 
			Rec++;
		}
		else
			return -1;
	}
	inFile.close();

	return Rec;
	
}

void findAve(runnerData runners[],int runCount)
{
	double total;
	for (int row = 0; row < runCount; row++)
	{
		total = 0;
		for (int col = 0; col < RUN_MILES; col++)
		{
			total += runners[row].runs[col];
		}
		runners[row].aveMiles = total / RUN_MILES;
		runners[row].totalDistance = total; 
	}
}

void showCalc(runnerData runners[], int runCount)
{
	cout << left << setw(10) << "Name" << right << setw(6) << "day 1" << setw(6) << "day 2" << setw(6) << "day 3" << setw(6) << "day 4" << setw(6) << "day 5"
		<< setw(6) << "day 6" << setw(6) << "day 7" << setw(8) << "average" << setw(6) << "total" << endl;
	for (int row = 0; row < runCount; row++)
	{
		cout << left << setw(10) << runners[row].name << " " << setprecision(1) << fixed;
		for (int col = 0; col < RUN_MILES; col++)
			cout << right << setw(5) << runners[row].runs[col] << " ";
		cout << setw(5) << runners[row].aveMiles << " " << setw(5) << runners[row].totalDistance << endl;
	}
}