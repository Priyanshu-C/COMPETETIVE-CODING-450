//https://leetcode.com/problems/minimum-window-substring/

#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fo(i,n) for(i=0;i<n;i++)
#define fok(i,k,n) for(i=k;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================


string minWindow(string str, string t) {
    vector<int> hash_str(250,0);
    vector<int> hash_pat(250,0);
    
    int len1 = str.size();
    int len2 = t.size();
    if (len1 < len2) 
    {
        return ""; 
    }
    
    for(char i:t)
    hash_str[i]++;
    int start = 0, start_index = -1, min_len = INT_MAX; 
  
    // start traversing the string 
    int count = 0; // count of characters 
    for (int j = 0; j < len1 ; j++) 
    { 
        // count occurrence of characters of string 
        hash_str[str[j]]++; 
  
        // If string's char matches with pattern's char 
        // then increment count 
        if (hash_pat[str[j]] != 0 && 
            hash_str[str[j]] <= hash_pat[str[j]] ) 
            count++; 
  
        // if all the characters are matched 
        if (count == len2) 
        { 
            // Try to minimize the window i.e., check if 
            // any character is occurring more no. of times 
            // than its occurrence in pattern, if yes 
            // then remove it from starting and also remove 
            // the useless characters. 
            while ( hash_str[str[start]] > hash_pat[str[start]] 
                || hash_pat[str[start]] == 0) 
            { 
  
                if (hash_str[str[start]] > hash_pat[str[start]]) 
                    hash_str[str[start]]--; 
                start++; 
            } 
  
            // update window size 
            int len_window = j - start + 1; 
            if (min_len > len_window) 
            { 
                min_len = len_window; 
                start_index = start; 
            } 
        } 
    } 
  
    // If no window found 
    if (start_index == -1) 
    { 
    cout << "No such window exists"; 
    return ""; 
    } 
  
    // Return substring starting from start_index 
    // and length min_len 
    return str.substr(start_index, min_len); 
} 

int main() {
    FIN
    int s;
    int i,j;
    cin>>s;
    while(s--)
    {
        string x;
        cin>>x;
        string y;
        cin>>y;
        cout<<minWindow(x,y);
        cout<<endl;
    }

    return 0;
}
