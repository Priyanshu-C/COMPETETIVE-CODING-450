
//https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

class Solution{
public:
#define ll long long 
	// Function to find maximum product subarray
	
	static bool compMin(ll a, ll b) 
        { 
            return (a < b); 
        }
    static bool compMax(ll a, ll b) 
        { 
            return (a > b); 
        }
	
	long long maxProduct(int *A, int n) {
	    // code here
	   
	   ll mi = *A;
	   ll ma = *A;
	   ll res = *A;
	   A++;
	   for(int i=1;i<n;i++)
	   {
	    
	       ll num = *A;   
	       if(res<ma)
	       res=ma;
	       
	       if(num < 0)
	       swap(mi,ma);
	        
	       mi = min(num,mi*num);
	       ma = max(num,ma*num);
	       
	       cout<<mi<<" "<<ma<<endl;
            	       
	       if(res<ma)
	       res=ma;
	       
	    A++;
	       
	   }
	   return res;
	   
	}
};