class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target == 0)
            return true;
        if (target > x + y)
            return false;
        return target % gcd(x, y) == 0;
    }
};