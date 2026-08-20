class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int i = 0;

        if(n % 2 == 0){
            while(i < n){
                mp[nums[i]]++;
                i++;
            }

            i = 0;

            for(auto it : mp){
                if(it.second % 2 != 0){
                    return false;
                }
            }
        }

        return true;
    }
};