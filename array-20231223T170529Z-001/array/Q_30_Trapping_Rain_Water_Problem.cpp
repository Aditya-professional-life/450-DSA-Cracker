#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        long long ans =0;
        
        int picche[n] = {0};
        int aage[n] = {0};
        int maxi=arr[0];
        picche[0]=arr[0];
        
        for(int i=1; i<n; i++){
            if(maxi<arr[i]){
                maxi=arr[i];
            }
            picche[i] = maxi;
        }
        
        maxi = arr[n-1];
        aage[n-1] = arr[n-1];
        
        for(int i=n-1; i>=0; i--){
            if(maxi<arr[i]){
                maxi = arr[i];
            }
            aage[i] = maxi;
        }
        
        for(int i=0; i<n; i++){
            ans = ans + (min(aage[i],picche[i]) - arr[i]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}