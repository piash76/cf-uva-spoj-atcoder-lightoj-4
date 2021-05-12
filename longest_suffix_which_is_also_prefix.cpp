#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;

char txt[maxn],pattern[maxn];
int n,m;
int lps[maxn];



void prefix()
{
    for(int i=0;i<=m;i++) lps[i]=0;

    int index=0;
    for(int i=1;i<=m;)
    {
        if(pattern[index]==pattern[i])
        {
        lps[i]=index+1;
        index++;i++;
        }
        else
        {
            if(index!=0) index=lps[index-1];
            else { lps[i]=index;i++; }
        }
    }

}

int main()
{
    scanf("%s",&pattern);
    m=strlen(pattern);
    suffix();
    //for(int i=0;i<=m;i++) cout<<lps[i]<<" ";
    //cout<<endl;
    string ans="";
    int l=lps[m-1];
    cout<<l<<endl;

    for(int i=0;i<l;i++) ans+=pattern[i];
    cout<<ans<<endl;

}

