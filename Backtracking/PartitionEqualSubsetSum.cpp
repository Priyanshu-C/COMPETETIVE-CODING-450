class Solution {
public:
    
    //Vector
    #define fo(i,n) for(int i=0;i<n;i++)
    void debvec(vector<int> &ar)
    {
      int R=ar.size();
      int i;
      cout<<endl<<"////////////"<<endl;
      fo(i,R)
      {
        cout<<ar[i]<<"  ";
      }
      cout<<endl<<"////////////"<<endl;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums)
            sum+=i;
        if(sum%2!=0)
            return false;
        
        vector<int> DP((sum/2) +1,0);
        DP[0] = 1;
        
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<=nums.size();i++)
        {
           // debvec(DP);
            for(int j=sum/2;j>=0;j--)
            {
                if (j >= nums[i-1]) {
                    DP[j] = DP[j] || DP[j-nums[i-1]];
                } else {
                    DP[j] = DP[j];
                }
            }
        }
       // debvec(DP);
        return DP[sum/2];
    }
};