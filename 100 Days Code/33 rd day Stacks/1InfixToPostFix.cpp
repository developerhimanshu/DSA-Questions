#include <bits/stdc++.h>
using namespace std;

int precedence(char x)
{
    int prec;
    if (x == '^' || x == '%')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return -1;
}
bool isOperator(char x)
{
    if (x == '^' || x == '%' || x == '/' || x == '*' || x == '+' || x == '-')
        return true;
    return false;
}
bool isOperand(char x)
{
    if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9'))
        return true;
    return false;
}

void infixToPostfix(string str)
{
    stack<char> st;
    string result;
    for (int i = 0; i < str.length(); i++)
    {
        if (isOperand(str[i]))
            result += str[i];
        else if (str[i] == '(')
            st.push('(');

        else if (str[i] == ')')
        {
            while (st.top() != ')')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(str[i]))
        {
            while (!st.empty() && precedence(str[i]) <= precedence(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
      while (st.empty() == false)
        {
            result+=st.top();
            st.pop();
        }
    cout<<result;
}
int main()
{
    string str = "a+b/c-d";
 infixToPostfix(str);

    return 0;
}
