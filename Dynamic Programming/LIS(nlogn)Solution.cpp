/*
Let A be the array for the sequence..
1.If A[i] is smallest among all end candidates of active lists,
we will start new active list of lenght 1.

2.if A[i] is largest among all end candidates of active lists,we
will clone the largest active list and extend it by A[i].

3. if A[i] is in between,we will find a list with largest end element that is
smaller than A[i].clone and extend this list by A[i]

Algorithm:
Querying length of longest is fairly easy.
Note that we are dealing with end elements only.
We need not to maintain all the lists.
We can store the end elements in an array.
Discarding operation can be simulated with replacement,
and extending a list is analogous to adding more elements to array.

We will use an auxiliary array to keep end elements.
The maximum length of this array is that of input.
In the worst case the array divided into N lists of size one (note that it does’t lead to worst case complexity).
To discard an element, we will trace ceil value of A[i] in auxiliary array (again observe the end elements in your rough work),
and replace ceil value with A[i].
We extend a list by adding element to auxiliary array.
We also maintain a counter to keep track of auxiliary array length.
*/
#include<iostream>
#include<vector>
using namespace std;
int ceil(vector<int> &a,int l,int r,int value)
{
    while(r-l>1)
    {
        int m=l+(r-1)/2;
        if(a[m]>=value)
        {
            r=m;
        }
        else
        {
            l=m;
        }

    }
    return r;
}
int main()
{

    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        a.push_back(k);
    }
    int len=1;
    vector<int> ans;
    ans.push_back(a[0]);
    for(int i=1;i<n;i++)
    {
        if(a[i]<ans[0])
        {
            ans[0]=a[i];
        }
        else if(a[i]>ans[len-1])
        {
            len++;
            ans.push_back(a[i]);
        }
        else
        {
            ans[ceil(ans,-1,len-1,a[i])]=a[i];
        }

    }
    cout<<"LIS length is: "<<len;
    return 0;
}

