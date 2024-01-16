//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here   
        int min_num = INT_MAX;
        int max_num = INT_MIN;
        int mid;
        
        int expected = (R*C+1)/2;
        
        for(int i=0; i<R; i++){
            if(matrix[i][C-1]>max_num){
                max_num = matrix[i][C-1];
            }
            if(matrix[i][0]<min_num){
                min_num = matrix[i][0];
            }
        }
        
        while(max_num>min_num){
            mid = min_num + (max_num-min_num)/2;
            int count = 0;
            for(int i=0; i<R; i++){
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            
            if(count<expected){
                min_num = mid+1;
            }
            else{
                max_num = mid;
            }
        }
        return min_num;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends