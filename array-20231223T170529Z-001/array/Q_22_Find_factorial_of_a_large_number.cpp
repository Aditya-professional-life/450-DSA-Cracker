#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
    private:
    void multiplyArr(int arr[], int& size, int i){
        int carry=0;
        int mul=1;
        
        for(int j=0; j<size; j++){
            mul = arr[j]*i + carry;
            arr[j] = mul%10;
            carry = mul/10;
        }
        while(carry){
            arr[size]=carry%10;
            carry=carry/10;
            size++;
        }
    }
public:
    vector<int> factorial(int N){
        // code here
        vector<int> ans;
        int anss[3000]={0};
        int size = 1;
        anss[0]=1;
        
        for(int i=2;i<=N;i++){
            multiplyArr(anss, size, i);
        }
        
        for(int i=size-1; i>=0; i--){
            ans.push_back(anss[i]);
        }
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}