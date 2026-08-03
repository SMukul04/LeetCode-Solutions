class Solution {
public:
    void combi(vector<string>& v, int n, int oc, int cc, string s){
        if(oc == n && cc == n){
            v.push_back(s);
            return;
        }

        if(oc < n){
            combi(v, n, oc + 1, cc, s + "(");
        }

        if(cc < oc){
            combi(v, n, oc, cc + 1, s + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int oc = 0, cc = 0;

        combi(v, n, oc, cc, "");
        return v;
    }
};