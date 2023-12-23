#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A, A+n);
        for(int i=0; i<n; i++){
            //yha 1 element fix kiya, ab aage ke array me X - A[i] dhundenge
            int p=i+1;
            int q=n-1;
            while(p<q){
                if(A[p] + A[q] == X - A[i]){
                    return 1;
                                    }
                else if(A[p] + A[q] < X - A[i]){
                    p++;
                }
                else{
                    q--;
                }
            }
        }
        return 0;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}