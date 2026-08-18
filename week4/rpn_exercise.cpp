#include <vector>
#include <string>
#include <stack>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;
        int a=0;
        int b=0;
        int sum=0;
        for (int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                b=s.top();//栈顶是右操作数
                s.pop();
                a=s.top();
                s.pop();
                if(tokens[i]=="+"){
                    sum=a+b;
                }
                else if(tokens[i]=="-"){
                    sum=a-b;
                }
                else if(tokens[i]=="*"){
                    sum=a*b;
                }
                else if(tokens[i]=="/"){
                    sum=a/b;
                }
                s.push(sum);
            }
            else{
                s.push(std::stoi(tokens[i]));//string转int
            }
        }
        return s.top();
    }
};