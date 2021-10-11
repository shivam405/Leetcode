class MedianFinder {
    double med;
    priority_queue<int> maxh;
    priority_queue<int,vector<int>,greater<int>> minh;
public:
    MedianFinder() { 
       med=1e5+1; 
    }
    
    void addNum(int d) {
        if(med==1e5+1)
        {
            med=d;
            maxh.push(d);
        }
        else
        {
             if(maxh.size()>minh.size())
            {
                if(d<med)
                {
                    minh.push(maxh.top());
                    maxh.pop();
                    maxh.push(d);
                }
                else
                {
                    minh.push(d);
                }
                 med=(maxh.top()+minh.top())/2.0;
            }
            else if(maxh.size()==minh.size())
            {
                if(d<med)
                {
                    maxh.push(d);
                    med=maxh.top();
                }
                else{
                    minh.push(d);
                    med=minh.top();
                }

            }

            else
            {
                if(d>med)
                {   
                    maxh.push(minh.top());
                    minh.pop();
                    minh.push(d);
                }
                else
                {
                    maxh.push(d);
                }
                med=(maxh.top()+minh.top())/2.0;

            }
        }
    }
    
    double findMedian() {
        return med;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */