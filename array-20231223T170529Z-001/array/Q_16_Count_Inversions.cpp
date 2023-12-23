#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    private:
    void merge(long long array[], long long left, long long mid,
           long long right, long long& count
           )
{
    long long const subArrayOne = mid - left + 1;
    long long const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new long long[subArrayOne],
         *rightArray = new long long[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    long long indexOfMergedArray = left;
 
    // Merge the temp arrays back long longo array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            count = count+ subArrayOne - indexOfSubArrayOne;
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            
        }
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
        
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(long long array[], long long begin, long long end,long long& count)
{
    if (begin >= end)
        return;
 
    long long mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid, count);
    mergeSort(array, mid + 1, end, count);
    merge(array, begin, mid, end, count);
}


  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long inversionCount(long long arr[], long long N)
    {
        // Your Code Here
      long long count = 0;
      
      mergeSort(arr,0,N-1,count);
      return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
