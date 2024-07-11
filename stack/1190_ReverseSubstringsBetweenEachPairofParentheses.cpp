#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {

        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=')') // pushing all element except ')'
            {
                st.push(s[i]);
            }
            else
            {
                string str = "";
                while(!st.empty() && st.top()!='(') // jab tak '(' ye nahi aa jata stack me hm sare element ko str me add karenge 
                {
                    str+=st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop(); // we also have to pop '(' ..q ki reh gya tha ...

                for(int j=0;j<str.size();j++) // ab sare element str k stack me push kar denge q ki reverse karna tha sara n 
                {
                    st.push(str[j]);
                }
            }
        }

       string str = "";
       while(!st.empty())  // last me sare ko nikal lenge reverse odere me agar str+st.top() karte to reverse b karna padata lekin hm st.top + str kiye so reverse nhi karna pda.
       {
         str = st.top() +str;
         st.pop(); 
           
       }

        return str;
        
    }
};
