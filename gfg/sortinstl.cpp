#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int comp(int a,int b)
{

    return a>b;
}
int main()
{
    vector<int> arr={5,1,3,20,0,7,-1};
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<"\n";

    sort(arr.begin(),arr.end(),comp);
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<"\n";


}
