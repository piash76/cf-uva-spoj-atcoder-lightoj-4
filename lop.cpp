

//The code below works perfectly but I would like someone to explain to me the mathematics behind it. Basically, how does it work?
#include<bits/stdc++.h>
using namespace std;

int main()
{

   int n,i,j,p,c,noz,k,base;
   cin>>n>>base;


   noz = n;
   j = base;
   /* Why do we start from 2 */
   for (i=2; i <= base; i++)
   {
      if (j % i == 0)
      {
         p = 0;  /* What is p? */
         while (j % i== 0)
         {
            p++;
            j /= i;
         }
         c = 0;
         k = n;
         /* What is the maths behind this while loop? */
         while (k/i > 0)
         {
            c += k/i;
            k /= i;
         }
         noz = min(noz, c/p);
      }
   }
   printf("%d! has %d trailing zeros\n", n, noz);

   return 0;
}

