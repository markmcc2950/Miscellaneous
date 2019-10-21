#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(void) {
	vector<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(5);
	A.push_back(9);
	A.push_back(9);
	A.push_back(10);

	cout << A.size() << endl;
	int X = 10;
	int N = A.size();
	if (N == 0) {
		return -1;
	}
	int l = 0;
	int r = N;
	while (l < r && A[l] != X) {
		int m = (l + r) / 2;
		cout << "DEBUG: m = " << m << endl;
		if (A[m] > X) {
			r = m - 1;
			cout << "DEBUG: r = " << r << endl;
		}
		else {
			l = m;
			cout << "DEBUG: l = " << l << endl;
		}
	}
	if (A[l] == X) {
		cout << l << endl;
	}
	return -1;
}