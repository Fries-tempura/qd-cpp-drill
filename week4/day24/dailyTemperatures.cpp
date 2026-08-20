#include <vector>
#include <string>
#include <stack>
#include <iostream>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        std::vector<int> answer(n,0);
        std::stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty()&&temperatures[i]>temperatures[stk.top()]){
                int top_index=stk.top();
                answer[top_index]=i-top_index;
                stk.pop();
            }
            stk.push(i);
        }
        return answer;
    }
};