
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;

char txt[maxn],pattern[maxn];
int n,m;
int lps[maxn];

void suffix()
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

int kmp()
{
    int j=0;


    for(int i=0;i<n;i++)
    {
        if(txt[i]==pattern[j])
        {

            j++;
        }
        else
        {
            while(j!=0)
            {
                j=lps[j-1];

                if(txt[i]==pattern[j])
                {
                    j++;
                    break;
                }
            }
        }
    }
    return j;
}




int main()
{
    int T,a;
    scanf("%d",&T);
    for(a=1;a<=T;a++)
    {
      scanf("%s",&txt);
      n=m=strlen(txt);
      strcpy(pattern,txt);
      reverse(pattern,pattern+n);
      int s=kmp();


    printf("Case %d: %d\n",a,n+n-s);
     }
return 0;
}



#include<bits/stdc++.h>

using namespace std;

int f[1000002];

void kmp_preprocess(string pattern)
{
    int m=pattern.size();
    f[0]=0;

    int j=0;

    for(int i=1;i<m;i++)
    {
        if(pattern[i]==pattern[j])
        {
            f[i]=j+1;
            j++;
        }
        else
        {
            while(j!=0)
            {
                j=f[j-1];
                if(pattern[i]==pattern[j])
                {
                    f[i]=j+1;
                    j++;
                    break;
                }
            }
        }
    }
}

int kmp(string text,string pattern)
{
    int j=0;

    int n=text.size();
    int m=pattern.size();

    for(int i=0;i<n;i++)
    {
        if(text[i]==pattern[j])
        {

            j++;
        }
        else
        {
            while(j!=0)
            {
                j=f[j-1];

                if(text[i]==pattern[j])
                {
                    j++;
                    break;
                }
            }
        }
    }
    return j;
}


int main()
{

string text,pattern;

 int n,p,q;
 scanf("%d",&n);

 for(int ca=1;ca<=n;ca++)
 {
     cin>>text;

     pattern=text;
     reverse(pattern.begin(),pattern.end());
     memset(f,0,sizeof(f));
    kmp_preprocess(pattern);

     p=kmp(text,pattern);
     q=pattern.size();
     q=2*q - p ;
     printf("Case %d: %d\n",ca,q);
 }


}
