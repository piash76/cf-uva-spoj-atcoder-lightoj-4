class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();

        int i,j;

        int dp[n+5][m+5];

        memset(dp,0,sizeof(dp));

        for(i=0;i<m;i++)
        {
            if(matrix[0][i]==1) dp[0][i]=1;
        }


         for(i=0;i<n;i++)
         {
            if(matrix[i][0]==1) dp[i][0]=1;

         }

         for(i=0;i<n;i++)
         {
             for(j=0;j<m;j++)
             {
                 if(i==0 or j==0) continue;

                 if(matrix[i][j]==1)
                 {
                     //cout<<"I "<<i<<" J "<<j<<endl;

                     dp[i][j]=min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1;
                 }
                 else  dp[i][j]=0;
             }
         }


         int sum=0;
         for(i=0;i<n;i++)
         {
             for(j=0;j<m;j++)
             {
              // cout<<dp[i][j]<<" ";
               sum+=dp[i][j];
             }

             //cout<<endl;
         }

        return sum;
    }
};
