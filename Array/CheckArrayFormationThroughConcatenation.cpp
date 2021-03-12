Basically take a pointer and itertate checking first value in each row, if they match continue on that row.
if nothing maches simply return false.

Do upvote if you like the solution.

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size();
        int i=0;
        int pn = pieces.size();
        while(i<n)
        {
            int flag = 0;
            for(int j=0;j<pn;j++)
            {
				// Checking first value of every row in pieces 
                if(i<n)
                if(pieces[j][0]==arr[i])
                {
					// Iterate over the row and check if they match the sequence or not.
                    for(int l:pieces[j])
                    {
                        if(l!=arr[i++])
                            return false;
                    }
                    flag = 1;
                }
            }
            if(!flag)
                return false;
        }
        return true;
    }
};