//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int i=0; 
	    int j=m-1;
	    int maxRow = 0;
	    int count=0;
	    
	    int checkone = 0;
	    for(int a=0; a<n; a++){
	        if(arr[a][m-1]==1){
	            checkone=1;
	        }
	    }
	    if(checkone == 0 ){
	        return -1;
	    }
	    
	    while(i<n && j<m){
	        if(arr[i][j]==1){
	            maxRow = i;
	            j--;
	        }
	        else{
	            i++;
	        }
	    }
	    return maxRow;
	}

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends