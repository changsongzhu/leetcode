/**
295[H]. Find Median from Data Stream
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
Examples: 

[2,3,4] , the median is 3
[2,3], the median is (2 + 3) / 2 = 2.5
Design a data structure that supports the following two operations:
void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2
**/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        this->count=0;
    }
    
    void addNum(int num) {
        this->count++;
        if(small.size()==large.size())
        {
            if(large.empty()||num<=*large.begin()) small.insert(num);
            else
            {
                small.insert(*large.begin());
                large.erase(large.begin());
                large.insert(num);
            }
        }
        else
        {
            if(num>=*small.rbegin()) large.insert(num);
            else
            {
                large.insert(*small.rbegin());
                small.erase(--small.end());
                small.insert(num);
            }
        }
    }
    
    double findMedian() {
        if(count%2) return *small.rbegin();
        else return(double)(*small.rbegin()+*large.begin())/2.0;
    }
private:
    multiset<int> small, large;
    int count;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

