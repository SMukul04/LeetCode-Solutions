class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> map_pattern;
        int n = s.size();
        int i = 0;
        string word = "";
        vector<string> ans;

        while(i < n){
            if(s[i] == ' ') {
                ans.push_back(word);
                word = "";
            }
            else {
                word += s[i];
            }
            i++;
        }

        ans.push_back(word);

        if(ans.size() != pattern.size()){
            return false;
        }

        unordered_map<string, int> map_ans;

        for(i = 0; i < pattern.size(); i++){
            if(map_pattern[pattern[i]] == 0 && map_ans[ans[i]] == 0) {
                map_pattern[pattern[i]] = i + 1;
                map_ans[ans[i]] = i + 1;
            }
            else if(map_pattern[pattern[i]] != map_ans[ans[i]]) {
                return false;
            }
        }

        return true;
    }
};