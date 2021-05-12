class Solution {
public:
    int findPeakElement(vector<int>& nums) {


    int n=nums.size();
    if(n==1) return 0;

    int l=0,h=n-1,ans=-1;

     while(l<=h)
    {


        int mid=(l+h)/2;

        int prev_num;

        if(mid-1>=0) prev_num=nums[mid-1];

        int mid_num=nums[mid];

        int next_num;

        if(mid+1<n) next_num=nums[mid+1];


        if( (mid_num>prev_num or mid-1<0) and (mid_num>next_num or mid+1>=n) )
        {
            ans=mid;

            return ans;
        }

        if(mid_num<next_num) l=mid+1;
        else if(mid_num<prev_num) h=mid-1;
    }

    return -1;

    }
};
