class MedianFinder {
private: 
    priority_queue<int> left ;
    priority_queue<int, vector<int>, greater<int> > right ;
    double currentMedian ;
public:
    
    MedianFinder() {
        currentMedian = 0 ;
    }
    
    void addNum(int num) {
        if(currentMedian > num) {
            if(left.size() > right.size()) {
                right.push(left.top()) ;
                left.pop() ;
                
            }
            left.push(num) ;
                
        } else {
            if(right.size() > left.size()) {
                left.push(right.top()) ;
                right.pop() ;
            }
            right.push(num) ;
        }
        
        currentMedian = findMedian() ; //this is an imp step
    }
    
    double findMedian() {
        currentMedian ;
        if(left.size() == right.size()) {
            currentMedian = ((left.top()*1.0) + (right.top()*1.0))/2 ;
        } else if(left.size() > right.size()) {
            currentMedian = left.top() ;
        } else {
            currentMedian = right.top() ;
        }
        
        return currentMedian ;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
