class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<long long, int> preSumMap;
        int n = nums.size();
        int sum = 0;
        int count = 0;

        preSumMap[0] = 1; 
        // ✅ Important: handles subarrays starting from index 0

        for(int i = 0; i < n; i++){
            sum += nums[i];

            int remainder = sum - k;

            // ❌ earlier: count++
            // ✅ FIX: add frequency of remainder
            if(preSumMap.find(remainder) != preSumMap.end()){
                count += preSumMap[remainder]; 
            }

            // ❌ earlier: used condition + stored index (+= i)
            // ✅ FIX: always increment frequency of current sum
            preSumMap[sum]++; 
        }

        return count;
    }
};