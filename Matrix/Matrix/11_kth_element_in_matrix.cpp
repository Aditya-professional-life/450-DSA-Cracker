//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



int rankk(int mat[MAX][MAX], int n, int mid){
    int i=0;
    int j=n-1;
    int anss=0;
    while(i<n){
        if(mat[i][j]>mid){
            j--;
        }
        else{
           anss+=j+1; //barabar wale bhi count
           i++;
        }
    }
    return anss;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int i = mat[0][0];
  int j= mat[n-1][n-1];
  int ans=0;
  while(i<=j){ // =nhi lagaya tha
    // cout<< "i " << i << " j "<< j<<endl;
      int mid = (i+j)/2;
    //   cout<< "mid "<< mid<< endl;
    //   cout<<"rank of "<< mid<< " "<<rankk(mat, n, mid)<<endl;
      if(rankk(mat, n, mid)<k){
          i = mid+1;
      }
      else{
          ans = mid;
        //   cout<<"ans "<< ans<<endl;
          j=mid-1;
      }
  }
  return ans;
}
/*
i 16 j 94
mid 55
rank of 55 7
ans 55
i 16 j 54
mid 35
rank of 35 4
ans 35
i 16 j 34
mid 25
rank of 25 2
i 26 j 34
mid 30
rank of 30 4
ans 30
i 26 j 29
mid 27
rank of 27 3
ans 27
i 26 j 26
mid 26
rank of 26 2
27

rankk function calculate karega ki less than and equal to kitne function hai








*/
