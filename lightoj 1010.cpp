
   #include<bits/stdc++.h>
   #define godspeed() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   #define ll long long
    using namespace std;

    int main()
    {

    godspeed()
    int r,c,t,i,ans,x;

    cin>>t;

    for(i=1;i<=t;i++)
        {
       cin>>r>>c;

        cout << "Case " << i << ": " ;

         ans =r*c;
        if(r == 1 || c== 1){
            cout << max(r,c) << endl;
        }
        else if(r == 2 || c == 2)
            {
             x= max(r, c);
            ans = x;
            if(x % 4 == 1 || x % 4 == 3) ans++;
            if(x % 4 == 2 ) ans+=2;
            cout << ans << endl;
        }
        else if(ans%2)
        {
            cout << ans/2 + 1 << endl;
        }
        else
            cout << ans/2 << endl;
    }
        return 0;
    }
