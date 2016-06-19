/*
Longest increasing subsequence can be solved using dynamic programming....
we can create an array of same size as that of a sequence
Minimum Longest increasing subsequence will have a length of size 1
initialize each element of array with 1
Now to use two pointers i and j to solve the problem:

The final answer is the maximum value in arr

time complexity of this solution in o(n^2)....

There exists a O(n*logn) solution also;
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> sequence;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        sequence.push_back(num);
    }
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
      arr.push_back(1);
    }
    //int i=1;
    //int j=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(sequence[i]>sequence[j])
            {
                arr[i]=max(arr[i],arr[j]+1);
            }
        }
    }

    int m=-1000000;
    for(int i=0;i<n;i++)
    {
        m=max(m,arr[i]);
    }
    cout<<m<<" ";
    return 0;

}
