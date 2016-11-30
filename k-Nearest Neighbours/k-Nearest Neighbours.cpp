// k-Nearest Neighbours.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <math.h>

void printAbout() {
	std::cout << "k-Nearest Neighbour\n";
	std::cout << "Author: Simon Gustav Cordes, 2016\n";
	std::cout << "Copyright according to Danish law\n";
}

struct dataPoint {
	double x;
	double y;
	int classification;
};

std::vector<dataPoint> readDataset(std::string filePath) {
	std::vector<dataPoint> dataset;
	std::ifstream datafile(filePath);
	std::string pointLine;
	while (std::getline(datafile, pointLine)) {
		std::istringstream iss(pointLine);
		double x, y;
		int classification;
		if (!(iss >> x >> y >> classification)) { break; }
		dataPoint dp;
		dp.x = x;
		dp.y = y;
		dp.classification = classification;
		dataset.push_back(dp);
	}
	return dataset;
}

double calcDistance(dataPoint dp1, dataPoint dp2) {
	return sqrt(pow(dp2.y - dp1.y, 2) + pow(dp2.x - dp1.x, 2));
}

// TODO: Add functionality which allows the program to write the classification to a file.
// TODO: Make a function which calculates the zero-loss function
int main(int argc, char** argv)
{
	printAbout();
	if (argc < 3) {
		std::cout << "Error: Not enough arguments\n";
		std::cout << "Corret use: kNN <k> <fileIn> <fileOut>\n";
		getchar();
		return -1;
	}
	int k;
	std::string trainIn, testIn;

	k = std::stoi(argv[1]);
	trainIn = argv[2];
	testIn = argv[3];

	if (k % 2 == 0) {
		std::cout << "k is not odd. Press enter to quit.\n";
		getchar();
		return -1;
	}

	std::vector<dataPoint> dataset = readDataset(trainIn);


	std::cout << "something done";
	std::cin;
    return 0;
}



