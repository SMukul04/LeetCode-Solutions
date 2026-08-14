class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i, j;
        int result = 0;

        for(i = 0; i < s.length(); i++){
            unordered_map<char, int> mp;
            for(j = i; j < s.length(); j++){

                if(mp[s[j]] < 2){
                    mp[s[j]]++;
                    result = max(result, j - i + 1);
                }

                else{
                    break;
                }
            }
        }

        return result;
    }
};