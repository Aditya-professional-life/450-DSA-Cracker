#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long AbTak = INT_MIN;
	    long long Currentwala = 1;
	    
	    for(int i=0; i<n; i++){
	        Currentwala = Currentwala * arr[i];
	        
	        if(Currentwala>AbTak){
	            AbTak = Currentwala;
	        }
	        
	        if(Currentwala==0){
	            Currentwala = 1;
	        }
	    }
	    Currentwala = 1;
	    for(int i=n-1; i>=0; i--){
	        Currentwala = Currentwala * arr[i];
	        
	        if(Currentwala>AbTak){
	            AbTak = Currentwala;
	        }
	        
	        if(Currentwala==0){
	            Currentwala = 1;
	        }
	    }
	    return AbTak;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}