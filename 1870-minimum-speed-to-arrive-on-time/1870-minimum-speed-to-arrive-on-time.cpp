class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 10000000;
        int n = dist.size() - 1;
        int i;
        int ans = -1;

        while(low <= high){
            int mid = (low + high) / 2;
            double k = 0;

            for(i = 0; i < n; i++){
                k += ceil((double)dist[i] / mid);
            }
            k += (double)dist[n] / mid;

            if(k <= hour){
                ans = mid;
                high = mid - 1;
            }

            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};