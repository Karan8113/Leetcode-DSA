class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> openSt;
        stack<int> openCloseSt;

        int n=s.length();

        if(n%2!=0)return false;

        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                openCloseSt.push(i);
            }
            else{
                if(s[i]=='('){
                    openSt.push(i);
                }
                else{
                    if(!openSt.empty()){
                        openSt.pop();
                    }
                    else if(!openCloseSt.empty()){
                        openCloseSt.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        while(!openSt.empty()&&!openCloseSt.empty() && openSt.top()<openCloseSt.top()){
            openSt.pop();
            openCloseSt.pop();
        }

        return openSt.empty();
        
    }
};