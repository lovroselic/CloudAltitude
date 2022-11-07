// https://www.codeabbey.com/index/task_view/cloud-altitude-measurement
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <chrono>
#include <cmath>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION "1.0"
#define PI 3.14159265

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

int CloudAltitude(int D1, double A, double B);

int main() {
	auto t1 = high_resolution_clock::now();
	cout << "TreeHeight v" << VERSION << "!\n\n";
	//string path = "Test.txt";
	string path = "Try.txt";
	vector<string> raw_data = loadData(path);

	vector<int> solution;

	for (int i = 1; i < raw_data.size(); i++) {
		vector<string> line = splitString(raw_data[i], " ");
		int D1 = stoi(line[0]);
		double A = stod(line[1]);
		double B = stod(line[2]);
		int H = CloudAltitude(D1, A, B);
		solution.push_back(H);
		cout << raw_data[i] << " : " << H << endl;
	}
	cout << "\nSolution: " << joinVector(solution, " ") << endl;;

	/***********************/
	auto t2 = high_resolution_clock::now();
	auto ms_int = duration_cast<milliseconds>(t2 - t1);
	cout << "Execution time: " << ms_int.count() << " ms" << endl;
}
int CloudAltitude(int D1, double A, double B) {
	A = to_radians(A);
	B = to_radians(B);
	double H = (tan(A)*tan(B) * D1) / (tan(B) - tan(A));
	return round(H);
};