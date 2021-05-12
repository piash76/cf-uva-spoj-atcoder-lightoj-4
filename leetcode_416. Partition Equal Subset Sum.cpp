


class Solution {
public:

    int a[205];
    int dp[205][20005];

    int solve(int idx,int sum) ///subset sum
    {
     if(sum==0) return 1;

    if(idx<0 or sum<0) return 0;

    if(dp[idx][sum]!=-1) return dp[idx][sum];

    int ans=solve(idx-1,sum-a[idx]) || solve(idx-1,sum);

    return dp[idx][sum]=ans;

    }


    bool canPartition(vector<int>& nums)
    {

    memset(dp,-1,sizeof(dp));

    int n=nums.size();
    int i,j;


    int sm=0;
    for(i=0;i<n;i++) {a[i]=nums[i]; sm+=nums[i]; }

    if(sm%2) return false;

    sm/=2;


    if(solve(n-1,sm)) return true;
    else return false;




    }
};
