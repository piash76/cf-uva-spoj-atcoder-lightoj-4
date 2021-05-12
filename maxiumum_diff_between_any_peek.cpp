


 ll mxd=-1,mx1;
           int f=0;
            for(i=1;i<n;i++)
            {
                if(a[i]<a[i-1] and f==0)
                {
                    f=1;
                    mx1=a[i-1];
                    mxd=max(mxd,abs(a[i]-mx1));

                   // cout<<1<<endl;
                   // cout<<"MX1 "<<mx1<<" mxd "<<mxd<<endl;


                }
                else if(f==1 and a[i]<a[i-1] )
                {
                    mxd=max(mxd,abs(a[i]-mx1));
                   // cout<<2<<endl;
                   // cout<<"MX1 "<<mx1<<" mxd "<<mxd<<endl;
                }
                else if(a[i]>a[i-1] and f==1 and a[i]<mx1)
                {
                    mxd=max(mxd,abs(a[i]-mx1));
                    //cout<<3<<endl;
                   // cout<<"MX1 "<<mx1<<" mxd "<<mxd<<endl;
                }
                else if(a[i]>a[i-1] and f==1 and a[i]>=mx1)
                {
                   // cout<<4<<endl;

                    f=0;
                }

                //cout<<"F "<<f<<endl;
            }



        int val = 0;
    int mx = (int) -2e9;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      mx = max(mx, a);
      val = max(val, mx - a);
    }
