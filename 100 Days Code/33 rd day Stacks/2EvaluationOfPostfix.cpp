#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string str)
{
    stack <int>st;

    for(int i=0; i<str.length(); i++)
    {
        if(str[i]==' ')continue;

        else if(isdigit(str[i]))
        {
            int num = 0;
            while(isdigit(str[i]))
            {
                num = num*10+(int)(str[i]-'0');
                i++;
            }
            i--;
         st.push(num);   
        }
        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch(str[i])
            {
                case '+': st.push(val2+val1);break;
                case '-': st.push(val2-val1);break;
                case '*': st.push(val2 * val1); break;
                case '/': st.push(val2/val1); break;
            }
        }
    }
    return st.top();
}
int main()
{
    char exp[] = "100 200 + 2 / 5 * 7 +";
    cout << evaluatePostfix(exp);
    return 0;
}
