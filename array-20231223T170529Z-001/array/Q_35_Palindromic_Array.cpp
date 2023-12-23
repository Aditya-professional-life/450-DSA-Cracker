#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:

    int isPallindrom(int a){
        int b=a;
        int c=0;
        while(b!=0){
            c = c*10;
            c = c+(b%10);
            b = b/10;
        }
        if(c==a){
            return 1;
        }
        else{
            return 0;
        }
    }
    int PalinArray(int a[], int n)
    {
    	// code here
    	int count =0;
    	for(int i=0; i<n; i++){
    	    int m = isPallindrom(a[i]);
    	    if(m==1){
    	        count++;
    	    }
    	}
    	if(count == n){
    	    return 1;
    	}
    	else{
    	    return 0;
    	}
    	
    	
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}