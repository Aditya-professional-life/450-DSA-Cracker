#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int i=0;
        int j=0;
        int curr = 0, min_length = n;
        
        int temp=0;
        for(int i=0; i<n; i++){
            temp = temp+arr[i];
        }
        if(temp<=x){
            return 0;
        }
        
        while(j<n){
            if(arr[i]>x){
                return 1;
            }
            while(curr <= x && j<n){
                curr = curr + arr[j++];
            }

            min_length = min(j-i, min_length);
            curr = curr - arr[i++];

        }
        
        while(i<n && curr>x){
            min_length = min(j-i, min_length);
            curr = curr - arr[i++];
        }
        return min_length;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}