/* 0/1 knapsack problem is a problem that can be solved using dynamic programming.
given a max weight of sack and the value and weights of various items we have to choose
items such that their total weight is less than or equal to max weight and
their total value of items in sack is maximum.
This problem is different from fractional knapsack, which can be solved using greedy approach
in that case we find val/weight ratios of all items and sort them in non increasing order and then greedily
fill the knapsack and when the last item cannot be taken as full we take the quantity according to weight left and calculate
the value using the val/weight ratio....


concept used is:
if we are ith item ..we can either choose it or neglect it;

if(wt[i]>j)
t[i][j]=t[i-1][j];
else
t[i][j]=max(val[i]+t[i-1][j-wt[i]],t[i-1][j])
*/


#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int sackWeight;
    int n;
    cin>>sackWeight;
    cin>>n;
    int value[n];
    int weight[n];
    //value[0]=weight[0]=0;
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
        cin>>weight[i];
    }
    int t[n][sackWeight+1];
    for(int i=0;i<n;i++)
    {
        t[i][0]=0;
    }
    for(int j=1;j<=sackWeight;j++)
    {
        if(weight[0]>j)
            t[0][j]=0;
        else
            t[0][j]=value[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sackWeight;j++)
        {
            if(weight[i]>j)
            {
                t[i][j]=t[i-1][j];
            }
            else
            {
                t[i][j]=max(value[i]+t[i-1][j-weight[i]],t[i-1][j]);
            }
        }
    }

    cout<<"MAX value possible is: "<<t[n-1][sackWeight]<<" ";
    return 0;



}
