
///Bismillahir Rahmanir Rahim
///ALLAHU AKBAR
#include<bits/stdc++.h>

using namespace std;

#define ll long long

///https://www.youtube.com/watch?v=7undZLA3_rU&list=PL2q4fbVm1Ik7Ds5cuaoOmExjOQG31kM-p&index=2




///returns how many unique numbers in the range of L to R

const int maxn = 500005;  ///5e5
int n,block_size;

struct query
{
    int left;
    int right;
    int idx;
};

query Q[maxn];
int a[maxn],freq[maxn],ans[maxn];
int cnt;


bool comp(query a,query b)
{
    if(a.left/block_size!=b.left/block_size) return a.left/block_size<b.left/block_size;
    else return a.right<b.right;
}

bool cmp(query a,query b) ///parity ordering
{
    return (a.left/block_size)^(b.left/block_size)?a.left<b.left:(((a.left/block_size)&1)?a.right<b.right:a.right>b.right);
}



int main()
{
    int i,j;
    scanf("%d",&n);
    int q;scanf("%d",&q);

    for(i=0;i<n;i++) scanf("%d",&a[i]);

    block_size=sqrt(n)+1;


    for(i=0;i<q;i++)
    {
        int l,r;scanf("%d %d",&l,&r);
        l--;r--;
        Q[i].left=l;
        Q[i].right=r;
        Q[i].idx=i;
    }

    sort(Q,Q+q,comp);

    int pl=0,pr=-1;
    for(i=0;i<q;i++)
    {
        int lft=Q[i].left;
        int rt=Q[i].right;
        int indx=Q[i].idx;


        ///L <-(add) PL (remove)->L
        ///R <- (remove) PR (add) -> R

        while(pl>lft)
        {
            pl--;
            if(freq[a[pl]]==0) cnt++;
            freq[a[pl]]++;
            //ADD(pl);
        }
        while(pr<rt)
        {
            pr++;
            if(freq[a[pr]]==0) cnt++;
            freq[a[pr]]++;
            //ADD(pr);

        }

        while(pl<lft)
        {
            //REMOVE(pl);
            freq[a[pl]]--;
            if(freq[a[pl]]==0) cnt--;
            pl++;
        }

        while(pr>rt)
        {
            ///REMOVE(pr);
             freq[a[pr]]--;
            if (freq[a[pr]] == 0) cnt--;
            pr--;
        }


        ans[indx]=cnt;

    }


    for(i=0;i<q;i++)
    {
        printf("%d\n",ans[i]);
    }

}

