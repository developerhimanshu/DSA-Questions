/*
Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings

Example 1:

Input:
S = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C
These are the possible combination of "ABC".
*/
class Solution{
  public:
    vector<string>result;
    vector<string> permutation(string S){
        solve(S, "", 0, S.length()-1);
        return result;
        
    }
    void solve(string str, string t, int i, int e)
    {
        if(s==e)
        {
            t+=str[i];
            result.push_back(t);
            return;
        }
        else{
            t+=str[s];
            solve(str, t+' ', i+1, e);
            solve(str, t, i+1, e);
            return;
        }
    }
};
