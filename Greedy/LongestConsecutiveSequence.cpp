class Solution {
public:
    #define d(x) cout<<#x<<" "<<x<<endl;
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        set<int> st;
        for(int i:nums)
            st.insert(i);
        
        int temp = *st.begin();
        int count =1;
        int m = 1;
        for(int i:st)
        {
                
            //d(i);
           // d(temp);
            if(i == temp + 1)
            {
                temp = i;
                count++;
            }
            else
            {
                m = max(count,m);
                temp = i;
                count =1;
            }
        }
        m = max(m,count);
        return m;
    }
};