class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int i = 0;

        while(i < n){
            mp[nums[i]]++;
            i++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if(mp[a] != mp[b]) {
                return mp[a] < mp[b];  
            }

            return a > b;
        });

        return nums;
    }
};