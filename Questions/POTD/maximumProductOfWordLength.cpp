/*
Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

Example 1:

Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".

*/


class Solution {
public:
    int maxProduct(vector<string>& words) {
  int n = words.size(), i, j, max = 0;
  vector<int> bits(n, 0);      
   for(i=0;i<n;i++){
      for(auto c: words[i]){
    bits[i] |= 1 << (c-'a');
      }
   }
    for(i=0;i<n;i++){
  for(j=i+1;j<n;j++){
      if((bits[i]&bits[j]) == 0){
          if(words[i].length()*words[j].length() > max){
              max = words[i].length()*words[j].length();
          }
      }
  }      
    }
        return max;
    }
};
