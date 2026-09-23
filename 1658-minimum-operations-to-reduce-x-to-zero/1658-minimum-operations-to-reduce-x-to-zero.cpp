class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i;
        mp[0] = -1;
        int sum = 0;

        for(i = 0; i < n; i++){
            sum += nums[i];
            mp[sum] = i;
        }
        if(sum < x){
            return -1;
        }
        
        int remainSum = sum - x;
        int longSubArray = INT_MIN;
        sum = 0;

        for(i = 0; i < n; i++){
            sum += nums[i];

            int findSum = sum - remainSum;
            if(mp.find(findSum) != mp.end()){
                int idx = mp[findSum];
                longSubArray = max(longSubArray, i - idx);
            }
        }

        return longSubArray == INT_MIN ? -1 : (n - longSubArray);
    }
};