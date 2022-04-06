#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    s.insert(10);
    s.insert(23);
    s.insert(45);


    // => Traversing through the elements of the set
    for(auto it = s.begin(); it != s.end();  it++)
    {
        cout<<*(it)<<endl;
    }

    //finding the element
    /*
    auto it = s.find(10);
    if(s.find()!= s.end())
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;
    */


    // => Lower bound
    /*
    auto it = s.lower_bound(46);
    if (it != s.end())
        cout << (*it) << endl;
    else
        cout << "Given element is greater than the largest" << endl;
    */

   // => Upper bound
   /*
    auto it = s.upper_bound(10);
    if(it!=s.end())
    {
        cout<<(*it)<<endl;
    }
    else
        cout<<"Given element is greater than the largest"<<endl;

    s.erase(10);
    s.clear(); // it removes all the elements from the set
*/
    auto it = s.find(45);
    s.erase(it, s.end()); // it removes the element from iterator it
    cout<<s.size()<<endl;
    s.clear();
    cout<<s.size()<<endl;
    return 0;
}
