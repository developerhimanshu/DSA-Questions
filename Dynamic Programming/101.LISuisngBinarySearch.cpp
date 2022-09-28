  int lengthOfLIS(vector<int>&arr){
        vector<int>temp;
        temp.push_back(arr[0]);
        for(int i = 1; i<arr.size(); i++){
            if(arr[i]>temp.back())temp.push_back(arr[i]);
            else
            {
                int ind = lower_bound(temp.begin(), temp.end(),arr[i])-temp.begin(); // this will return the index of just greater or equal element in the temp array
                temp[ind]=arr[i];
            }
        }
        return temp.size();
    }
    