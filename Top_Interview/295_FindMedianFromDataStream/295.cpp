class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap; //left
    priority_queue<int, vector<int>, greater<int>> minHeap; //right
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxHeap.empty()){ //first time, put into maxHeap
            maxHeap.push(num);
            return ;
        }
        if(num>maxHeap.top()){
            minHeap.push(num);
        }
        else{
            maxHeap.push(num);
        }
        
        //balance two heap
        if(maxHeap.size()-minHeap.size()==2){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size()-maxHeap.size()==2){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if((maxHeap.size()+minHeap.size())%2==1){ //奇数个
            return (maxHeap.size()>minHeap.size())? maxHeap.top() : minHeap.top();
        }
        return ((double)maxHeap.top()+(double)minHeap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
