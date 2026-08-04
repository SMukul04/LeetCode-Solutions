class Solution {
public:
    void func(int ind, vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans) {
        ans.push_back(subset);

        for (int i = ind; i < nums.size(); i++) {

            // Skip duplicate elements
            if (i > ind && nums[i] == nums[i - 1])
                continue;

            subset.push_back(nums[i]);

            func(i + 1, nums, subset, ans);

            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> subset;

        func(0, nums, subset, ans);

        return ans;
    }
};