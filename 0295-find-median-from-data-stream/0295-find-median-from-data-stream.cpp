class MedianFinder {
public:
double median;
priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;
    int signum(){
        if(minheap.size()< maxheap.size()){
          return 1;  
        }
        else if(minheap.size()== maxheap.size()){
            return 0;
        }
        else{
            return -1;
        }
    }
    void calculate_median(int num){
        if(maxheap.empty()){
            maxheap.push(num);
            median = num;
        }
        else if(signum()== 0){
            if(num> maxheap.top()){
                minheap.push(num);
                median = minheap.top();
            }
            else{
                maxheap.push(num);
                median = maxheap.top();
            }
        }
        else if(signum()< 0){
           if(num> maxheap.top()){
              minheap.push(num);
              int temp = minheap.top();
              minheap.pop();
              maxheap.push(temp);
              median = (minheap.top() + maxheap.top())/2.0;
           }
           else{
            maxheap.push(num);
            median = (minheap.top() + maxheap.top())/2.0;
           }
        }
        else{
            if(num> maxheap.top()){
                minheap.push(num);
                median = (minheap.top() + maxheap.top())/2.0;
            }
            else{
                maxheap.push(num);
                int temp = maxheap.top();
                maxheap.pop();
                minheap.push(temp);
                median = (minheap.top() + maxheap.top())/2.0;
            }
        }
    }
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       calculate_median(num); 
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */