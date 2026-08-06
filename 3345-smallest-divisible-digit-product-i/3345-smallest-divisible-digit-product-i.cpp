class Solution {
public:
    int smallestNumber(int n, int t) {
        int digit = 0;
        int product = 1;
        int x = n;

        while(x > 0){
            digit = x % 10;
            product = product * digit;
            x /= 10;
        }

        if(product % t == 0){
            return n;
        }

        if(product % t != 0){
            return smallestNumber(n + 1, t);
        }

        return -1;
    }
};