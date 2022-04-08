
vector<int> leftCeling(int arr[], int n)
{
    vector<int>v;
    v.push_back(-1);
    for(int i=1; i<n; i++)
    {
        int diff = INT_MAX;
        for(int j=0; j<i; j++)
        {
            if(arr[j]>=arr[i])
            {
                diff = min(diff, arr[j]-arr[i]);
            }
        }
        if(diff==INT_MAX)
            v.push_back(-1);
        else
            v.push_back(diff+arr[i]);
    }
    return v;
}
