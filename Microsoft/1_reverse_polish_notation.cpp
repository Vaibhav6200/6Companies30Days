#include<bits/stdc++.h>
using namespace std;


// Approach
// Iterate over vector
// Push numbers into stack
// when we get an operator
//      pop 2 numbers from stack and perform operation on it
//      push result into stack and continue

class Solution {
public:
    int performOperation(long n1, long n2, string str){
        if(str == "+")
            return n1+n2;

        else if(str == "-")
            return n1 - n2;

        else if(str == "*")
            return n1 * n2;

        else
            return n1 / n2;
    }

    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<long> st;

        for(int i=0; i<n; i++){
            string str = tokens[i];
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                long n2 = st.top(); st.pop();
                long n1 = st.top(); st.pop();

                long result = performOperation(n1, n2, str);
                st.push(result);
            }
            else
                st.push(stoi(str));
        }
        return st.top();

        return 0;
    }
};



int main()
{

    return 0;
}