class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>stk;
        stack<char>temp;
        if(k>=num.size()) return "0";

        for(int i=0; i<num.size(); i++){
            while(stk.size() && num[i] < stk.top() &&k){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
            if(stk.size()==1 && stk.top() =='0') stk.pop();
        }

        while(k>0 && stk.size()>0){
            stk.pop();
            k--;
        }

        num = "";

        while(!stk.empty()){
            temp.push(stk.top());
            stk.pop();
        }

        while(!temp.empty()){
            num += temp.top();
            temp.pop();
        }

        if(num.size() ==0) num="0";

        return num;
    }
};