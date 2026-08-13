class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        unordered_map<char, int> target;

        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
        }

        for(int i = 0; i < t.length(); i++){
            target[t[i]]++;
        }

        if(mp == target){
            return true;
        }

        return false;
    }
};