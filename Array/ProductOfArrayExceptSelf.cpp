class Solution {
public:
    
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
    
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int c0 = 0;
        int len = nums.size();
        vector<int> R(len,0);
        vector<int> L(len,0);
        
        L[0]= nums[0];
        for(int i=1;i<len;i++)
        {
            if(nums[i])
            L[i]=L[i-1]*nums[i];
            else
                c0++;
        }
        
        R[len-1]=nums[len-1];
        for(int i=len-2;i>=0;i--)
        {
            if(nums[i])
            R[i]=R[i+1]*nums[i];
        }

        if(c0>1)
            return vector<int> (len,0);
        else if(c0==1)
        {
            if(nums[0]==0)
            nums[0]=R[1];
            else
                nums[0]=0;
            
            if(!nums[len-1])
            nums[len-1]=L[len-2];
            else
                nums[len-1]=0;
            
            for(int i=1;i<len-1;i++)
            {
                if(!nums[i])
                {
                    nums[i]= L[i-1]*R[i+1];    
                }
                else
                {
                    nums[i]=0;
                }
            }
        }
        else
        {
            nums[0]=R[1];
            nums[len-1]=L[len-2];
            for(int i=1;i<len-1;i++)
            {
                cout<<nums[i];
                nums[i] = L[i-1]*R[i+1]; 
            }
        }
         
        return nums;
        
    }
};