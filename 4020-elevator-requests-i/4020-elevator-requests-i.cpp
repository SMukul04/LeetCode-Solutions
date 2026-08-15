class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans = 0;
        int i = 0;
        ans += requests[i];

        for(i = 1; i < requests.size(); i++){
            ans += abs(requests[i - 1] - requests[i]);
        }

        return ans;
    }
};