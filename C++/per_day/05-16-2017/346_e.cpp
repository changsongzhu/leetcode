/**
346[E]. Moving Average from Data Stream
 
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
**/

class MovingAverage {
public:
    MovingAverage(int size) {
        this->size=size;
        sum=0;
    }

    double next(int val) 
    {
      if(dq.size()<this->size)
      {
          sum+=val;
          q.push(val);
          return sum/q.size();
      }
      else
      {
          sum-=q.front();
          sum+=val;
          dq.pop();
          dq.push(val);
          return sum/this->size;
      }
    }
private:
    queue<int> q;
    int size;
    double sum;
};
