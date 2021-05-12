    #include <bits/stdc++.h>
    using namespace std;


    int main()
    {
       int n,i,j,x;
       cin>>n;
       int a[n][n];
       x=1;
       for(i=0;i<n;i++)
       {

           if(i%2==0)
           {
               for(j=0;j<n;j++)
               {
                   a[j][i]=x;
                   x++;
               }
           }
           else
           {
               for(j=n-1;j>=0;j--)
               {
                   a[j][i]=x;
                   x++;
               }
           }
       }

       for(i=0;i<n;i++)
       {
           for(j=0;j<n;j++)
           {
               cout<<a[i][j]<<" ";
           }
           cout<<endl;
       }



    }
