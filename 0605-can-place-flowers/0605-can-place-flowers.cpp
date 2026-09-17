class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int x = flowerbed.size();

        if (x == 1) {
            if (flowerbed[0] == 0) n--;
            return n <= 0;
        }

        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            n--;

            if (n == 0) {
                return true;
            }
        }

        // Middle positions
        for (int i = 1; i < x - 1; i++) {
            if (flowerbed[i] == 1) {
                continue;
            }

            if (flowerbed[i - 1] == 0 &&
                flowerbed[i] == 0 &&
                flowerbed[i + 1] == 0) {

                flowerbed[i] = 1;
                n--;

                if (n == 0) {
                    return true;
                }
            }
        }

        if (flowerbed[x - 1] == 0 && flowerbed[x - 2] == 0) {
            flowerbed[x - 1] = 1;
            n--;
        }

        return n <= 0;
    }
};