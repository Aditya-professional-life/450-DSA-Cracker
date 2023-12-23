#include <bits/stdc++.h>
using namespace std;

void rightrotate(int arr[], int n,int i, int outofplace)
{
int temp = arr[i];
for(int j=i; j>outofplace; j--){
    arr[j] = arr[j-1];
}
arr[outofplace] = temp;
}

void rearrange(int arr[], int n)
{
	int outofplace = -1;

    for(int i=0;i<n;i++){

        if(outofplace>=0){
            if(((arr[i]>=0) && (arr[outofplace]<0))|| ((arr[i]<0) && (arr[outofplace]>=0))){
                rightrotate(arr,n,i,outofplace);
            
            if(i-outofplace>=2){
                outofplace = outofplace+2;
            }
            else{
                outofplace= -1;
            }
            }
        }

        if(outofplace == -1){
            if(((i & 0x01) && (arr[i]<0)) || ((!(i & 0x01)) && (arr[i]>=0))){
                outofplace = i;
            }
            
        }
    }
}

// A utility function to print an array 'arr[]' of size 'n'
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{

	int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, n);
	
// Function Call
	rearrange(arr, n);

	cout << "Rearranged array is \n";
	printArray(arr, n);

	return 0;
}
