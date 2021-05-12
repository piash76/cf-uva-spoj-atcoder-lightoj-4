#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,n,b,t;
    cin>>t;
    while(t--)
    {
        queue<int> q1,q2;
        string s;
        cin>>s;
        for(i=0;i<s.size();i++)
        {
            int d=s[i]-'0';
            if(d%2==0) q1.push(d);
            else q2.push(d);
        }
        while(!q1.empty()&& !q2.empty())
    		{
    			if(q1.front()>q2.front())
    			{
    				cout << q2.front();
    				q2.pop();
    			}
    			else
    			{
    				cout << q1.front();
    				q1.pop();
    			}

    		}
    		while(!q1.empty())
            {
                cout<<q1.front();
                q1.pop();
            }
            while(!q2.empty())
            {
                cout<<q2.front();
                q2.pop();
            }



        cout<<endl;

    }

}
