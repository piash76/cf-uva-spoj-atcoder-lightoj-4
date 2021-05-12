// C++ program to find the smallest
// positive missing number

#include <bits/stdc++.h>
using namespace std;

// Function to find the smallest positive
// missing number
int missingNumber(int a[], int n)
{
	// Declaring an unordered_map
	unordered_map<int, int> mp;

	// if array value is positive
	// store it in map
	for (int i = 0; i < n; i++) {
		if (a[i] > 0)
			mp[a[i]]++;
	}

	// index value set to 1
	int index = 1;

	// Return the first value starting
	// from 1 which does not exists in map
	while (1) {
		if (mp.find(index) == mp.end()) {
			return index;
		}

		index++;
	}
}

// Driver code
int main()
{
	int a[] = { 1, 1, 1, 0, -1, -2 };
	int size = sizeof(a) / sizeof(a[0]);

	cout << "Smallest positive missing number is : "
		<< missingNumber(a, size) << endl;

	return 0;
}

