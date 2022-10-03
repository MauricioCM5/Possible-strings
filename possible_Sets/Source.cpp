#include<iostream>
using namespace std;
#include <chrono>
#include <fstream>
#include <string>
using namespace std::chrono;
auto start = high_resolution_clock::now();;


const int tam = 15;
int ratio = 3;
int test[tam] = {};
long long  times[tam];



void fun(int n, string cad) {
	if (cad.size() == n) {
		return;
	}
	fun(n, cad + "0");
	fun(n, cad + "1");
}

long long get_time(int n, long long previous) {
	if (n < 23) {
		start = high_resolution_clock::now();
		fun(n, "");
		return duration_cast<microseconds>(high_resolution_clock::now() - start).count();
	}
	//interpolation
	else {
		return previous * (1 << 2);
	}
};


int main() {
	cout << "ALL POSSSIBLE STRINGS\n";
	cout << "-----------------------\n";
	cout << "n\ttime\n";
	string tmp;
	ofstream MyFile("computational times.txt");
	for (int i = 0; i < tam; i++) {
		test[i] = (i + 1) * 2;
		times[i] = get_time((i + 1) * 2, times[i-1]);

		tmp = to_string(test[i]) + "\t" + to_string(times[i]) + "\n";
		cout << tmp;
		MyFile << tmp;
	}

	MyFile.close();


	return 0;
}