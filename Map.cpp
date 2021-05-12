#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
main()
{
   int n,m,i,j;
   scanf("%d %d",&n,&m);
   int a[n+1][m+1],b[n+1][m+1];
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=m;j++)
       {
           scanf("%d",&a[i][j]);
       }
   }
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=m;j++)
       {
           scanf("%d",&b[i][j]);
       }
   }
   vector<int>vec1[n+m+1];
   vector<int>vec2[n+m+1];
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=m;j++)
       {
           vec1[i+j].push_back(a[i][j]);
       }
   }
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=m;j++)
       {
           vec2[i+j].push_back(b[i][j]);
       }
   }
   for(i=2;i<=n+m;i++)
   {
       sort(vec1[i].begin(),vec1[i].end());
       sort(vec2[i].begin(),vec2[i].end());
       if(vec1[i]!=vec2[i])
       {
           printf("NO");
           return 0;
       }
   }
   printf("YES");
}
