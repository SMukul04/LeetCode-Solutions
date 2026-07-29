class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;

        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '('){
                if(depth > 0){
                    ans.push_back('(');
                }
                depth++;
            }    

            else if(s[i] == ')'){
                depth--;
                if(depth > 0){
                    ans.push_back(')');
                    }
                }
        }

        return ans;
    }
};