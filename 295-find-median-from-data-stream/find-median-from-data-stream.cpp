class MedianFinder {
public:
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxi.size()>mini.size()){
            maxi.push(num);
            int n = maxi.top();
            maxi.pop();
            mini.push(n);
        }
        else {
            mini.push(num);
            int n = mini.top();
            mini.pop();
            maxi.push(n);
        }
    }
    
    double findMedian() {
        if (maxi.size()<mini.size()) return mini.top();
        else if (maxi.size()>mini.size()){
            return maxi.top();
        }
        else return (1.0*maxi.top()+1.0*mini.top())/2;;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */