#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct box
{
    int h,w,d;
};
int compare(box a,box b)
{
    int x=(a.w*a.d)-(b.w*b.d);
    if (x>0)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    //vector<box> x;
    vector<box> rot;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int h,w,d;
        cin>>h>>w>>d;
        box b;
        b.h=h;
        b.w=w;
        b.d=d;
        rot.push_back(b);

        box c;
        c.h=b.w;
        c.d=max(b.d,b.h);
        c.w=min(b.d,b.h);
        rot.push_back(c);

        c.h=b.d;
        c.d=max(b.w,b.h);
        c.w=min(b.w,b.h);
        rot.push_back(c);
    }

    sort(rot.begin(),rot.end(),compare);
    for(int i=0;i<rot.size();i++)
        cout<<rot[i].h<<" "<<rot[i].w<<" "<<rot[i].d<<"\n";
    n=rot.size();
    //cout<<"n:"<<n<"\n";
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        ans.push_back(rot[i].h);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            //cout<<"hey";
            if(((rot[i].w)<(rot[j].w))&&((rot[i].d)<(rot[j].d)))
            {

                ans[i]=max((rot[i].h)+ans[j],ans[i]);
                //cout<<"CANS:"<<ans[i]<<" ";
            }
        }
    }
    int m=-1000000;
    for(int i=0;i<n;i++)
    {
        //cout<<"ans[i]:"<<ans[i]<<"\n";
        m=max(ans[i],m);

    }

    cout<<m;



}
