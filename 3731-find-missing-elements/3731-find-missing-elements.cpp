class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        int start = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            while (start < nums[i]) {
                ans.push_back(start);
                start++;
            }
            start = nums[i] + 1;
        }

        return ans;
    }
};