//Sum the two number last digit and then append it to the string from right to left

class Solution{   
public:
    string solve(int arr[], int n) {
        sort(arr,arr+n);
        bool T = true;
        int rem = 0;
        string s = "";
        for(int i=n-1;i>=0;i=i-2)
        {
            int sum = arr[i] + arr[i-1] + rem;
            rem = sum/10;
            sum=sum%10;
            //cout<<sum<<endl;
            s = char(sum+48) + s; 
        }
        if(rem!=0)
        s = char(rem+48) + s; 
        
        while(s[0]=='0')
        s=s.substr(1);
        return s;
    }
};