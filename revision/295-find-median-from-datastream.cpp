class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);

        minheap.push(maxheap.top());
        maxheap.pop();
        
        // dono heaps mei equal number of elements daal diye
        if(maxheap.size() < minheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        } 

        return;
    }
    
    double findMedian() {
        if((maxheap.size() + minheap.size()) % 2 != 0){
            return maxheap.top();
        }

        return ( maxheap.top() + minheap.top() ) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */