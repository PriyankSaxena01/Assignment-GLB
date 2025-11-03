// User function template for C++
class Solution {
  public:
    int answer(vector<int>& arr,int index)
    {
        if(index==arr.size()-1)
        return arr[index];
        return arr[index]+answer(arr,index+1);
    }
    // Function to return sum of elements
    int arraySum(vector<int>& arr) {
        // code here
        return answer(arr,0);
       
    }
};
