class Solution {
public:
    int ans(vector<int>& coins, int amt, vector<int>& mem) {
        if(amt == 0)
            return 0;
        if(amt < 0)
            return 10001; // just more than max amount
        if(mem[amt] != -1)
            return mem[amt];

        int mini = 10001;
        for(int x : coins)
            mini = min(mini, 1 + ans(coins, amt - x, mem));

        mem[amt] = mini;
        return mem[amt];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> mem(amount + 1, -1);
        int res = ans(coins, amount, mem);
        if(res > amount)
            return -1;
        return res;
    }
};
