#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int count = 0;
        int x, ub, lb;
        
        for(int i=0; i<n-1; i++){
            x = k - arr[i];
            ub = upper_bound(arr+i+1,arr+n,x) - arr;
            lb = lower_bound(arr+i+1,arr+n,x) - arr;
            count = count + (ub - lb);
            
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}