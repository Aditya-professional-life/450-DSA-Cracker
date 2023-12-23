#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
  public:
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int, bool> isThere;
        int sum = 0;
        
        for(int i=0; i<n; i++){
            sum = sum + arr[i];
            
            if(isThere[sum]==true || sum==0){
                return true;
            }
            isThere[sum]=true;
           
        }
        return false;
    }

};


//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}