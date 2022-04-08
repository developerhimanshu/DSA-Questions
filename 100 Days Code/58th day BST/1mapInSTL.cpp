#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, string>m;
    m.insert({5, "geeks"});
    m.insert({20, "hustlers"});
    m.insert({10, "money minded"});

    //Traversing in a map
    /*
    for(auto it = m.begin(); it != m.end(); it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<" ";
    }
    */

   //Traversing in a map from a specific key
   for(auto it = m.find(10); it!=m.end(); it++)
   {
       cout<<(*it).first<<" "<<(*it).second<<" ";
   }
   cout<<endl;

   //Check weather an element is present using count function
    if(m.count(10)==1)
    {
        cout<<"Found"<<endl;
    }
    else
        cout<<"Not found"<<endl;

    //Lower Bound Of a key:- It returns an iterator for key if key is presnet otherwise it returns just greater than the given key
    auto lb = m.lower_bound(1);
    if(lb != m.end())
        cout<<(*lb).first<<" "<<(*lb).second<<endl;
    else
        cout<<"No equal or greater value than the given value"<<endl;

    //Upper bound of a key:- It returns a key just greater than given value
    auto ub = m.upper_bound(10  );
    if(ub != m.end())
        cout<<(*ub).first<<" "<<(*ub).second<<endl;
    else
        cout<<"No greter value than the given value"<<endl; 

    cout<<"Size: "<<m.size()<<endl;

    //Erase function:- we can pass value, iterator to the erase function:-
    // m.erase(5);
    // m.erase(m.find(5));
    m.erase(m.find(10), m.end());
    cout<<"After Deleting"<<endl;  
    cout<<"Size: "<<m.size()<<endl;
    
   return 0;
}  
