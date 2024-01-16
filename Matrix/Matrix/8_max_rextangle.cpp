//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
  //histogram wala code
  
  int getMaxArea(int arr[], int n)
    {
        // Your code here
        vector<int> leftSmaller(n, -1);
        vector<int> rightSmaller(n, n);
       
        stack <int> s;
        
        for(int i=0; i<n; i++){
            
                while(!s.empty() && arr[s.top()]>=arr[i]){
                    s.pop();
                }
                if(s.empty()){
                    leftSmaller[i]=-1;
                }
                else{
                    leftSmaller[i]=s.top();
                    
                } s.push(i);
            
        }
        
        while (!s.empty()) {
        s.pop(); }
    
        for(int i=n-1; i>=0; i--){
           
                while(!s.empty() && arr[s.top()]>=arr[i]){
                    s.pop();
                }
                if(s.empty()){
                    rightSmaller[i]=n;
                }
                else{
                    rightSmaller[i]=s.top();
                    
                } s.push(i);
            
        }
        
        
        int maxArea = arr[0];
        for(int i=0; i<n; i++){
             int currArea = arr[i]*(rightSmaller[i]-leftSmaller[i]-1);
             maxArea = max(maxArea, currArea);
        }
        
        return maxArea;
    }
    
    //main function
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int currRow[m];
        memcpy(currRow, M[0], sizeof(currRow));
        // memcpy use kiya pehli row copy karne k liye, #include <cstring> jarur dalna
        int maxx = getMaxArea(currRow, m);
        
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(M[i][j]==1){
                    currRow[j]++;
                }
                else{
                    currRow[j]=0;
                }
            }
            maxx = max(maxx, getMaxArea(currRow, m));
        }
        return maxx;
    }
    
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
