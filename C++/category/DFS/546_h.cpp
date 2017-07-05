/**
546[H]. Remove Boxes
Given several boxes with different colors represented by different positive numbers. 
You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), remove them and get k*k points.
Find the maximum points you can get.
Example 1:
Input:
[1, 3, 2, 2, 2, 3, 4, 3, 1]
Output:
23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1]
----> [1, 3, 3, 4, 3, 1] (3*3=9 points)
----> [1, 3, 3, 3, 1] (1*1=1 points)
----> [1, 1] (3*3=9 points)
----> [] (2*2=4 points)
Note: The number of boxes n would not exceed 100.
**/

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int res=0;
        if(boxes.size()==0) return 0;
        for(int i=0;i<boxes.size();i++)
        {
            int j=i;
            int val=boxes[i];
            while(boxes[j]==boxes[i])j++;
            for(int k=0;k<j-i;k++)
            {
                boxes.erase(boxes.begin()+i, boxes.begin()+i+k);
                int t=removeBoxes(boxes);
                res=max(res, t+(k+1)*(k+1));
                boxes.insert(boxes.begin()+i, k+1, val);
            }
        }
        return res;
    }
};

