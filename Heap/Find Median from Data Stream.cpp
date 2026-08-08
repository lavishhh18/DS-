class MedianFinder {
public:
    priority_queue<int> l_max_heap;
    priority_queue<int, vector<int>, greater<int>> r_min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(l_max_heap.size() == 0 || num < l_max_heap.top()){
            l_max_heap.push(num);
        } else {
            r_min_heap.push(num);
        }

        if(abs((int)l_max_heap.size() - (int)r_min_heap.size()) > 1){
            r_min_heap.push(l_max_heap.top());
            l_max_heap.pop();
        } 
        else if(r_min_heap.size() > l_max_heap.size()){
            l_max_heap.push(r_min_heap.top());
            r_min_heap.pop();
        }
    }
    
    double findMedian() {
        if(l_max_heap.size() == r_min_heap.size()){
            double l = l_max_heap.top();
            double r = r_min_heap.top();
            return (l + r)/2.0;
        }
        else {
            return (double)l_max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */