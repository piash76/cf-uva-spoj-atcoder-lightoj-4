#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;

ll a[N];
long long sum[4 * N];
long long msum[4 * N];
long long pref[4 * N];
long long suff[4 * N];

void combine(ll node)
{
    ll left=2*node;
    ll right=(2*node)+1;
    pref[node] = max(pref[left], sum[left] + pref[right]); ///maximising prefix sum
    suff[node] = max(suff[right], suff[left] + sum[right]); ///maximising sufffix sum
    msum[node] = max(msum[left], max(msum[right], suff[left] + pref[right]));///maximising sub array
    sum[node] = sum[left] + sum[right];
}
void build(ll node,ll b,ll e)
{
    if (b == e) {
        sum[node] = a[b];
        pref[node] = a[b];
        suff[node] = a[b];
        msum[node] = a[b];
        return;
    }

    ll left=2*node;
    ll right=(2*node)+1;
    ll mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    // merge function
    combine(node);
}

/*void update(ll node,ll b,ll e,ll i,ll val)
{
    if (b == e) {
        sum[node] = val;
        pref[node] = val;
        suff[node] = val;
        msum[node] = val;
        return;
    }

    ll left=2*node;
    ll right=(2*node)+1;
    ll mid=(b+e)/2;
    update(left,b,mid,i,val);
    update(right,mid+1,e,i,val);
    // merge function
    combine(node);
}*/

void update(ll node,ll b,ll e,ll i,ll val)
{
    if(i>e or i<b) return;
    if (b>=i and e<=i) {
        msum[node] = val;
        sum[node] = val;
        pref[node] = val;
        suff[node] = val;
        return;
    }
    ll left=2*node;
    ll right=(2*node)+1;
    ll mid=(b+e)/2;
    update(left,b,mid,i,val);
    update(right,mid+1,e,i,val);

    //sum[node]=sum[left]+sum[right];

    combine(node);


   /* else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        // merge function
        combine(v);
    }*/
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <=n; i++)
        cin >> a[i];
    build(1,1,n);
   /*for(int i=1;i<=10;i++) cout<<sum[i]<<" ";
    cout<<endl;
    update(1,1,n,1,4);

    for(int i=1;i<=10;i++) cout<<sum[i]<<" ";
    cout<<endl;*/


    if (msum[1] >= 0)
        cout << msum[1] << endl;
    else
        cout << 0 << endl;
    while (m--) {
        ll ind, val;
        cin >> ind >> val;
        update(1,1,n,ind+1, val);
        if (msum[1] >= 0)
            cout << msum[1] << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}

