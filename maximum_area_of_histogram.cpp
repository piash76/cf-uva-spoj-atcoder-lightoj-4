///Bismillahir Rahmanir Rahim
///ALLAHU AKBAR
#include<bits/stdc++.h>

#define ll                      long long


using namespace std;

///https://www.youtube.com/watch?v=MhQPpAoZbMc
///O(N)


ll max_area(ll a[],ll n)
{
    ll idx=0,ans=-1;
    stack<ll> st;
    while(idx<=n)
    {
        if(st.empty() or a[st.top()]<=a[idx])
        {
            st.push(idx++);
        }
        else
        {
            ll x=st.top();
            st.pop();
            ll area;
            if(st.empty())
            {
                area=a[x]*idx;
                ans=max(ans,area);
            }
            else
            {
                area=a[x]*(idx-st.top()-1);
                ans=max(ans,area);
            }
        }
    }

    while(!st.empty())
    {
        ll x=st.top();
        st.pop();

        ll area;
            if(st.empty())
            {
                area=a[x]*idx;
                ans=max(ans,area);
            }
            else
            {
                area=a[x]*(idx-st.top()-1);
                ans=max(ans,area);
            }

    }

    return ans;

}



int main()
{

    ll i,j,t,cas=0,k;
    ll n;cin>>n;
    ll a[n+5];
    for(i=0;i<n;i++) cin>>a[i];

    ll ans=max_area(a,n);

    cout<<ans<<endl;




}



