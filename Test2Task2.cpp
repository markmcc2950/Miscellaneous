#include <vector>
#include <iostream>

using namespace std;

int main(void) {
	vector<int> A;
	A.push_back(0);		// 0
	A.push_back(0);		// 1
	A.push_back(0);		// 2
	A.push_back(0);		// 3
	A.push_back(0);		// 4
	A.push_back(0);		// 5
	A.push_back(0);		// 6
	A.push_back(1);		// 7
	A.push_back(0);		// 8
	A.push_back(1);		// 9
	A.push_back(1);		// 10
	A.push_back(1);		// 11
	A.push_back(1);		// 12
	A.push_back(1);		// 13

	int counter = 0;	// For counting the number of switches
	int subCtr = 1;		// For finding max subarray (always minimum of size 1)
	int saveCtr = 0;
	int index = 0;		// Beginning of max subarray
	int size = A.size();
	int i = 0;


	// Base case: Empty vector
	if (size == 0) {
		return 0;
	}
	// Base case: Single value vector
	else if (size == 1) {
		return 0;
	}
	// Base case: Two value vector
	else if (size == 2) {
		// If First and Second index values are different, no switch needed
		if ((A[0] == 1 && A[1] == 0) || (A[0] == 0 && A[1] == 1)) {
			return 0;
		}
		// If they're different, then one must flip
		else {
			return 1;
		}
	}
	// Find max subarray of alternating values
	for (i = 1; i < size; i++) {
		if (A[i] == 1 && A[i - 1] == 0) {
			subCtr++;		// If next value is alternated, add sub counter			
		}
		else if (A[i] == 0 && A[i - 1] == 1) {
			subCtr++;		// If next value is alternated, add sub counter			
		}
		else {
			// If we've reached a higher max subarray, save that value
			if (subCtr != 0 && subCtr > saveCtr) {
				index = i - subCtr;		// Lets us know where the list starts
				saveCtr = subCtr;		// Save the max length counted
				subCtr = 1;				// Reset our subCtr for next count (if needed)
			}			
		}
	}

	// Find the flips needed, to the left first
	if (index != 0) {
		for (i = index; i > 0; i--) {
			if (A[i] == A[i - 1]) {
				if (A[i] == 1) {
					A[i - 1] = 0;
					counter++;
				}
				else {
					A[i - 1] = 1;
					counter++;
				}
			}
		}
	}
	// Now flip to the right of our max subarray
	if (index + subCtr != size) {
		for (i = index + subCtr; i < size - 1; i++) {
			if (A[i] == A[i + 1]) {
				if (A[i] == 1) {
					A[i + 1] = 0;
					counter++;
				}
				else {
					A[i + 1] = 1;
					counter++;
				}
			}
		}
	}
	cout << counter << endl;
	
	return 0;
}