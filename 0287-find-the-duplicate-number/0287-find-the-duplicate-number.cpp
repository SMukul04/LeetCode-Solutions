class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        int x = nums[0];
        while (x != fast) {
            x = nums[x];
            fast = nums[fast];
        }

        return x;
    }
};