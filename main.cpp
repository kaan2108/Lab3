/*  Kaan Yuecel
	C++ Fall 2021
	Due: 9/29/21
	Lab 3 User and File I/O
	Lab description: Write an interactive C++ program that computes and outputs the mean and  
	population standard deviation of a set of four integers that are inputted by a file called 
	“inMeanStd.dat” and the user (should handle both). Although the individual values are integers,
	the results are floating-point values. Be sure to use proper formatting and appropriate comments 
	in your code. Provide appropriate prompts to the user. The output should be to the screen for the 
	user inputted values and to a file called “outMeanStd.dat”. The programs output should be 
	labeled clearly and formatted neatly. You must calculate the mean and standard deviation in 
	separate functions.
*/

#include <fstream>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

float calculateSD(float data[]); 
float calculateMEAN(float data[]);

int main()
{
	string inputFileName = "C:/C++/Lab 3/Lab 3/inMeanStd.dat";
	string outputFileName = "outMeanStd.dat";

	ifstream infile;
	infile.open(inputFileName); // Assumes input file is in the project folder

	ofstream outfile;
	outfile.open(outputFileName); // Places output file in the project folder

	int data1;
	int data2;
	int data3;
	int data4;

	//getline(inFile, data);
	infile >> data1 >> data2 >> data3 >> data4;

	float val[4] = { data1, data2, data3, data4 };
	float variance = 0.0, stdDeviation1, sum1 = 0.0, mean1;
	int i;


	for (i = 0; i < 4; ++i) // Calculating the mean with the numbers from the file "inMeanStd.dat"
		sum1 += val[i];
	mean1 = sum1 / 4;
	for (i = 0; i < 4; ++i) // Calculating the standard deviation with the numbers from the file "inMeanStd.dat"
		variance += pow(val[i] - mean1, 2);
	variance = variance / 4;
	stdDeviation1 = sqrt(variance);


	cout << "Mean value of a set of four integers that are inputted by a file called inMeanStd.dat = " << endl << mean1 << endl;
	cout << endl << "Population standard deviation of a set of four integers that are inputted by a file called inMeanStd.dat = " << endl << stdDeviation1 << endl;
	outfile << data1 << data2 << data3 << data4;
	
	infile.close();
	outfile << endl << "The mean is = " << mean1 << endl;
	outfile << "The population standard deviation is =" << stdDeviation1 << endl;
	outfile.close();



	int k;
	float data[4];

	cout << endl << "Enter 4 elements: "; // user can input 4 numbers
	for (k = 0; k < 4; ++k) {
		cin >> data[k];
	}

	cout << endl << "The mean of the numbers that the user inputed = " << endl << calculateMEAN(data) << endl;
	cout << endl << "The standard deviation of the numbers that the user inputed = " << endl << calculateSD(data) << endl;


	return 0;
}


float calculateSD(float data[]) {
	float sum = 0.0, mean, stdDeviation = 0.0; // Calculating the standard deviation for the numbers inputed by the user
	int k;

	for (k = 0; k < 4; ++k) {
		sum += data[k];
	}

	mean = sum / 4;

	for (k = 0; k < 4; ++k) {
		stdDeviation += pow(data[k] - mean, 2); 
	}

	return sqrt(stdDeviation / 4);
}

float calculateMEAN(float data[]) { // Calculating the mean for the numbers inputed by the user
	float sum = 0.0, mean;
	int k;

	for (k = 0; k < 4; ++k) {
		sum += data[k];
	}

	mean = sum / 4;

	return mean;





}