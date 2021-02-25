class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int x = 0;
        int y = 0;
        vector<string> S;
        for(int i=1;i<=n;i++)
        {
            x++;
            y++;
            if(x==3 and y==5)
            {
                S.push_back("FizzBuzz");
                x=0;
                y=0;
            }
            else if(x==3)
            {
                S.push_back("Fizz");
                x=0;
            }
            else if(y==5)
            {
                S.push_back("Buzz");
                y=0;
            }
            else
                S.push_back(to_string(i));
        }
        return S;
    }
};