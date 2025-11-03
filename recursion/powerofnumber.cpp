class Solution {
  public:
  int reverseno(int n)
  {
      int ans=0;
        while(n>0)
        {
            int k=n%10;
            ans=ans*10+k;
            n=n/10;
        }
        return ans;
  }
  
  int powerfun(int n1,int n2)
  {
      if(n2==0)
      return 1;
      return n1 *powerfun(n1,n2-1);
  }
  
    int reverseExponentiation(int n) {
        // code here
       int n2=reverseno(n);
       return powerfun(n,n2);
    }
};