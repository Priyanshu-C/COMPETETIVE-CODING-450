// ****Just Do it Bottom-Up

// If you look close, there is pattern.

// [17].
// [13,17]. // take 17 and append at start then add 13 at start
// [11,17,13]. // take 13 and append at start then add 11 at start
// [7,13,11,17]. // take 17 and append at start then add 7 at start
// [5,17,7,13,11]. // take 11 and append at start then add 5 at start
// [3,11,5,17,7,13]. // take 13 and append at start then add 3 at start
// [2,13,3,11,5,17,7]. // take 7 and append at start then add 2 at start

// ** See the pattern every new array is basically the
// old array's last element on top with new number appended to it.**

class Solution {
public:

    #define d(x) cout<<#x<<" "<<x<<endl;
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int> Q;
        int n = deck.size();
        
        for(int i=n-1;i>=0;i--)
        {
            if(Q.empty())
            {
                Q.push(deck[i]);
                continue;
            }
            Q.push(Q.front());
            Q.pop();
            Q.push(deck[i]);
            // debstack(Q);
        }
        int i=n-1;
        while(!Q.empty())
        {
            deck[i--]=Q.front();
            Q.pop();
        }
        return deck;
    }
};