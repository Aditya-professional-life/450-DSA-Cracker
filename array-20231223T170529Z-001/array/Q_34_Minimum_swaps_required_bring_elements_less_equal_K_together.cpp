#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int i=0;
        int j;
        int count = 0;
       
        
        int countinghowmany = 0;
        for(int a=0; a<n; a++){
            if(arr[a]<=k){
                countinghowmany++;
            }
        }

        j = countinghowmany-1;

        
        for(int a=0; a<countinghowmany; a++){
            if(arr[a]>k){
                count++;
            }
        }
        int abtkkaMIN = count;
        while(j<n){
            if(arr[i]>k){
                count--;
            }
            
            // cout<<i<<j<<endl;
            i++;
            j++;
            if(arr[j]>k && j<n){
                count++;
            }
            
            if(j<n){
            abtkkaMIN = min(count,abtkkaMIN);}
        }
        return abtkkaMIN;
    
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
