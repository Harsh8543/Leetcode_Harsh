class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                p.push(ch);
            }
            else{
                if(!p.empty()){
                    char top = p.top();
                    if((ch == ')' && top =='(')||
                    (ch=='}' && top == '{') ||
                    (ch == ']'&& top=='[')){
                        p.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
       if(p.empty()){
         return true;
       }
       else
       return false; 
    }
};