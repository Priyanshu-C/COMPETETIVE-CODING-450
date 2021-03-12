class Solution {
public:
    
    bool check(int a,int b)
    {
        vector<int> ar(10,0);
        while(a)
        {
            ar[a%10]++;
            a/=10;
        }
        while(b)
        {
            ar[b%10]--;
            b/=10;
        }
        for(int i:ar)
        {
            if(i!=0)
                return false;
        }
        return true;
    }
    #define d(x) cout<<#x<<" "<<x<<endl; 
    bool reorderedPowerOf2(int N) {
        vector<int> ar;
        int sum = 1;
        int digitN = floor(log10(N)) + 1;
        int X = pow(10,digitN)-1;
        while(sum<X)
        {
         

            int digit = floor(log10(sum)) + 1;
            if(digit == digitN)
                ar.push_back(sum);
            sum=sum*2;
            // d(digit);
            // d(sum);
        }
        for(int i:ar)
        {
            // cout<<i;
            if(check(i,N))
                return true;
        }
        
        
        return false;
    }
};



// 1
// 2
// 4
// 8
// 16
// 32
// 64
// 128
// 256
// 512
// 1024
// 2048
// 4096
// 8192
// 16384
// 32768
// 65536
// 131072
// 262144
// 524288
