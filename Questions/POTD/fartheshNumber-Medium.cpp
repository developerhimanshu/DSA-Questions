/*
Given an array Arr[] of size N. For every element in the array, the task is to find the index of the farthest element in the array to the right which is smaller than the current element. If no such number exists then print -1.
Note: 0 based indexing.

Input: 
N=5
Arr[] = {3, 1, 5, 2, 4}
Output: 
3 -1 4 -1 -1


*/

 vector<int> farNumber(int N,vector<int> arr){
        //code here
        vector<int>v;
        for(int i=0; i<N; i++)
        {
           int j=N-1;
            while(i<j && arr[i]<=arr[j])
            {
                j--;
            }
            if(i>=j)
                v.push_back(-1);
            else
                v.push_back(j);
        }
        return v;
    }
