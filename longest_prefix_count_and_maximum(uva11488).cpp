
#include<bits/stdc++.h>

using namespace std;

const int N =1e6+5;


int nodecnt,tree[N][3],cnt[N],len[N];

void add(string s)
{
    int node=0,sz=s.size();
    for(int it=0;it<sz;it++)
    {
        int i=s[it]-'0';
        if(!tree[node][i])
        {
            tree[node][i]=++nodecnt;
        }
        node=tree[node][i];
        cnt[node]++;   ///couting prefix
        len[node]=it+1;   ///lenght of the prefix

    }


}



int main()
{

    int i,j,t,cas=0;

    cin>>t;
    while(t--)
    {
        nodecnt=0;
        memset(tree,0,sizeof(tree));
        memset(cnt,0,sizeof(cnt));
        memset(len,0,sizeof(len));

        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            add(s);
        }

        int ans=-1;
        for(int i=0;i<=nodecnt;i++)
        {
            ans=max(ans,len[i]*cnt[i]);
        }

        cout<<ans<<endl;




    }



}




