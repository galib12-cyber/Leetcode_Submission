class Solution {
public:
    int xorOperation(int n, int start) {
        int r = start;
        for (int i = 1; i < n; i++) {
            start += 2;
            r = (r ^ start);
        }

        return r;
    }
};