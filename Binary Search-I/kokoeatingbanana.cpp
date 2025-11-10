class Solution {
public:
    bool check1(int mid, vector<int>& arr, int time) {
        long long t = 0;  // use long long to avoid overflow
        for (int bananas : arr) {
            t += (bananas + mid - 1) / mid;  // ceil division
            if (t > time) return false;      // early stop
        }
        return t <= time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin(), piles.end());
        int f = 1, l = mx, ans = mx;

        while (f <= l) {
            int mid = f + (l - f) / 2;
            if (check1(mid, piles, h)) {
                ans = mid;
                l = mid - 1;  // try smaller speed
            } else {
                f = mid + 1;  // need larger speed
            }
        }
        return ans;
    }
};