class Solution {
public:
    bool isoperator(string s1){
        if(s1=="+" or s1=="-" or s1=="/" or s1=="*") return true;
        return false;
    }
    int calc(string op,string op1,string op2){
        if(op=="+") return stoll(op1)+stoll(op2);
        if(op=="-") return stoll(op1)-stoll(op2);
        if(op=="/") return stoll(op1)/stoll(op2);
        if(op=="*") return stoll(op1)*stoll(op2);
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        for(auto &ele:tokens){
            if(isoperator(ele)){
                string op2=stk.top();
                stk.pop();
                string op1=stk.top();
                stk.pop();
                int ans=calc(ele,op1,op2);
                stk.push(to_string(ans));
            }
            else stk.push(ele);
        }
        return stoll(stk.top());
    }
};
