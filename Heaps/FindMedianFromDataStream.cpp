// Approach 

// Create two heaps, one to store both half
// insert into max heap then pop it to insert into min heap
// if size differs simply remove from min heap and push to max heap 
// THINK THINK THINK this way max heap will always contain the lower half and min heap will get the upper half

class MedianFinder {
public:
    /** initialize your data structure here. */ 
    priority_queue<int> lo;
    priority_queue<int,vector<int>,greater<int>> hi;
    MedianFinder() {
       
        
    }
    
    void addNum(int num) {
        lo.push(num);
        
        hi.push(lo.top());
        lo.pop();
        
        if(lo.size()<hi.size())
        {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        return lo.size()>hi.size() ? lo.top() : (double) (lo.top() + hi.top())*1/2; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */