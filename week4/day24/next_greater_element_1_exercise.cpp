#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <iostream>
class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int,int> next_greater;
        std::stack<int> stk;
        for(int i=0;i<nums2.size();++i){
            while(!stk.empty()&&stk.top()<nums2[i]){
                int t=stk.top();
                next_greater.insert({t,nums2[i]});
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        std::vector<int> answer;
        for(int x:nums1){
            if(next_greater.count(x)){
                answer.push_back(next_greater[x]);
            }
            else{
                answer.push_back(-1);
            }
        }
        return answer;
    }
};