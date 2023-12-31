#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++
#include <set>
class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        set<int> myset;
        int i;
        int j;
        for(i = 0; i<n; i++){
            myset.insert(a[i]);
        }
        for(j = 0; j<m; j++){
            myset.insert(b[j]);
        }
        return myset.size();
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}