class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minElIndex = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxElIndex = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(minElIndex, maxElIndex);
        int right = max(minElIndex, maxElIndex);

        return min({right + 1, n - left, left + 1 + n - right});
    }
};