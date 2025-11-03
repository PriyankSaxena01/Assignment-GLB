class Solution {
public:
    int countDigits(int num) {
       int n2=num;
       int ans=0;
       while(n2>0)
       {
        int k=n2%10;
        if(num%k==0)
        ans++;
        n2=n2/10;
       }
       return ans;
    }
};