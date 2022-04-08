vector<int> leftCeiling(int arr[], int n)
{
    vector<int>v;
    v.push_back(-1);
    set<int>s;
    s.insert(arr[0]);
    for(int i=1; i<n; i++)
    {
        auto it = s.lower_bound(arr[i]);
        if(it != s.end())
            v.push_back(*(it));
        else
            v.push_back(-1);
        s.insert(arr[i]);
    }
    return v;
}
