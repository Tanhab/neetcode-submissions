class MedianFinder {
public:
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int> > rightHeap;
    int cnt;
    double median;
    MedianFinder() {
        cnt = 0, median = 0;
    }
    
    void addNum(int num) {
        cnt++;
        // 3 2 1
        if(leftHeap.size() == rightHeap.size()){
            if(cnt==1 || num <= leftHeap.top())
                leftHeap.push(num);
            else rightHeap.push(num);
        }else if(leftHeap.size() > rightHeap.size()){
            // num >= left max
            if(num >= leftHeap.top())
                rightHeap.push(num);
            else{ // num < left max
                int lmax = leftHeap.top();
                leftHeap.pop();
                leftHeap.push(num);
                rightHeap.push(lmax);
            }
        }else{
            // num <= right min
            if(num <= rightHeap.top()){
                leftHeap.push(num);
            }else{ // num > right min
                int rmin = rightHeap.top();
                rightHeap.pop();
                rightHeap.push(num);
                leftHeap.push(rmin);
            }
        }
        
    }
    
    double findMedian() {
        if( cnt == 0) return 0;
        if(leftHeap.size() == rightHeap.size() ){
            return (leftHeap.top() + rightHeap.top())/2.0;
        }else if(leftHeap.size() > rightHeap.size())
            return leftHeap.top();
        else return rightHeap.top();
    }
};
