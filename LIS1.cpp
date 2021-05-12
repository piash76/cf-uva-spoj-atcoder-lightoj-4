#include<bits/stdc++.h>
using namespace std;


int n; // the number of items in the sequence

int Sequence[32]; // the sequence of integers

int L[32]; // L[] as described in the algorithm



void takeInput() {

    scanf("%d", &n); // how many numbers in the sequence ?



    // take the sequence

    for( int i = 0; i < n; i++ )

        scanf("%d", &Sequence[i]);

}



int LIS() { // which runs the LIS algorithm and returns the result

    int i, j; // auxilary variables for iteration



    // initialize L[] with 1

    for( i = 0; i < n; i++ )

        L[i] = 1;



    // start from the left most item and itetare right

    for( i = 0; i < n; i++ ) {

        // for the ith item item find all items that are in right

        for( j = i + 1; j < n; j++ ) {



            if( Sequence[j] > Sequence[i] ) {

                // the item is greater than the ith item



                // so, L[j] = L[i] + 1, since jth item can be added after ith

                // item. if L[j] is already greater than or equal to L[i] + 1

                // then ignore it

                if( L[j] < L[i] + 1 )

                    L[j] = L[i] + 1;

            }

        }

    }

    // now find the item whose L[] value is maximum

    int maxLength = 0;

    for( i = 0; i < n; i++ ) {

        if( maxLength < L[i]  )

            maxLength = L[i];

    }

    // return the result

    return maxLength;

}
int LisSequence[32]; // for storing the sequence



void findSequence( int maxLength ) { // finds a valid sequence

    int i, j; // variable used for iteration



    // at first find the position of the item whose L[] is maximum

    i = 0;

    for( j = 1; j < n; j++ ) {

        if( L[j] > L[i] )

            i = j;

    }



    // initialize the position in LisSequence where the items can be added.

    // observe that the data are saving from right to left!

    int top = L[i] - 1;



    // insert the item in i-th position to LisSequence

    LisSequence[top] = Sequence[i];

    top--; // is decreasing such that a new item can be added in a new place



    // now find the other valid numbers to form the sequence

    for( j = i - 1; j >= 0; j-- ) {

        if( Sequence[j] < Sequence[i] && L[j] == L[i] - 1 ) {

            // we have found a valid item so, we will save it

            i = j; // as in our algorithm

            LisSequence[top] = Sequence[i]; // stored

            top--; // decreased for new items

        }

    }



    // so, we have got the sequence, now we want to print it

    printf("LIS is");

    for( i = 0; i < maxLength; i++ ) {

        printf(" %d", LisSequence[i]);

    }

    puts("");

}



int main() {

    takeInput();

    int result = LIS();

    printf("The LIS length is %d\n", result);

    findSequence( result );

    return 0;

}








///PROBLEM DESCRIPTION:


#include<bits/stdc++.h>

#define speed() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



#define ll long long
#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;




const int mod = 1000000007;


const int mx =5005;///1e6
ll a[mx],I[mx];
double b[mx];
ll dp[mx];

int main()
{


    speed()

    ll t,i,j,cas=0;

    for(i=0;i<n;i++) cin>>a[i];

    ll lis=0;


    dp[0]=1;
    for(i=1;i<n;i++)
    {
       dp[i]=1;
       for(j=0;j<i;j++)
       {
           if(a[j]<=a[i])
           {
               dp[i]=max(dp[i],dp[j]+1);
           }
       }
    }

    for(i=0;i<n;i++) lis=max(lis,dp[i]);

    cout<<lis<<endl;

    //cout<<n-lis<<endl;




    return 0;

}








