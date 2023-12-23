// C++ program to find number of operations
// to make an array palindrome
#include <bits/stdc++.h>
using namespace std;

// Returns minimum number of count operations
// required to make arr[] palindrome
int findMinOps(int arr[], int n)
{
	int count = 0;
	int i=0;
	int j=n-1;

	while(i<=j){
		if(arr[i]==arr[j]){
			i++;
			j--;
		}
		else if(arr[i]<arr[j]){
			arr[i+1] = arr[i] + arr[i+1];
			count++;
			i++;
		}
		else{
			arr[j-1] += arr[j];
			count++;
			j--;
		}
	}
	return count;
}

// Driver program to test above
int main()
{
	int arr[] = {1, 4, 5, 9, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Count of minimum operations is "
		<< findMinOps(arr, n) << endl;
	return 0;
}
