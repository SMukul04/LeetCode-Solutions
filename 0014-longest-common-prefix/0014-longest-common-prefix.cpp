class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int i = 0;
        string ans = "";

        while(i < strs[0].length() && strs[0][i] == strs[strs.size() - 1][i]){
            ans += strs[0][i];
            i++;
        }

        return ans;
    }
};