class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int i = 0, j = height.size() - 1;

        while(i < j){

            int maxi = min(height[i], height[j]) * (j - i);
            ans = max(ans, maxi);

            if(height[i] < height[j]){
                i++;
            }
            else if(height[i] > height[j]){
                j--;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};