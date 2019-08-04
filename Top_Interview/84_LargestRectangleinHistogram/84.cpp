class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> mystack;
        int i = 0;
        int res = 0;
        
        while(i<heights.size()){
            if(mystack.empty() || heights[i]>heights[mystack.top()]){
                mystack.push(i);
                i ++;
            }
            else{
                int tmp = mystack.top();
                mystack.pop();
                int width = mystack.empty()? i : (i-mystack.top()-1);
                res = max(res, heights[tmp]*width);
            }
        }
        
        while(mystack.size()){
            int tmp = mystack.top();
            mystack.pop();
            int width = mystack.empty()? i : (i-mystack.top()-1);
            res = max(res, heights[tmp]*width);
        }
        return res;
    }
};
