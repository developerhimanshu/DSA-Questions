 vector<int> mergeThree(vector<int>& a, vector<int>& b, vector<int>& c) 
    { 
        //Your code here
       vector<int>v;
       int i=0;
       int j=0;
       int n1=a.size();
       int n2 = b.size();
       int n3 = c.size();
       while(i<n1 && j<n2)
       {
           if(a[i]<b[j])
                v.push_back(a[i++]);
            else
                v.push_back(b[j++]);
            
       }
       while(i<n1)
       {
           v.push_back(a[i++]);
       }
       while(j<n2)
       {
           v.push_back(b[j++]);
       }
       i=0; j=0;
       vector<int>ans;
       while(i<(n1+n2) && j<n3)
       {
           if(v[i]<c[j])
           {
               ans.push_back(v[i++]);
           }
           else
                ans.push_back(c[j++]);
       }
       while(i<n1+n2)
       {
           ans.push_back(v[i++]);
       }
       while(j<n3)
       {
           ans.push_back(c[j++]);
       }
       return ans;
    } 
