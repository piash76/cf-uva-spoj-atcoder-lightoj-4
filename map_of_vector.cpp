


    map<ll, vector< pair<ll,ll> > >v;
    for(i=0;i<n;i++)
    {
       ll sum=0;
       for(j=i;j<n;j++)
       {
           sum+=a[j];
           v[sum].pb({i,j});   ///m[4]={ (0,0),(2,4) }

       }
    }

