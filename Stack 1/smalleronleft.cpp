vector<int> Smallestonleft(int a[], int n) {
    // code here
    set<int>s;
    vector<int> finalans;
    for(int i=0;i<n;i++)
    {
        int val=a[i];
        int ans=-1;
        for(auto j: s)
        {
            if(j>ans && j<a[i]){
                ans=j;
            }
        }
        s.insert(a[i]);
        finalans.push_back(ans);
    }
    return finalans;
}