class Solution {
public:
    int add(int num) {
        if (num == 0)
            return 0;

        return (num % 10) + add(num / 10);
    }

    int addDigits(int num) {
        if (num < 10)
            return num;

        return addDigits(add(num));
    }
};