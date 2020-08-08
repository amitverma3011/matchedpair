#include <bits/stdc++.h>
using namespace std;

bool ismatched(string bracket)
{
  stack<char> stk;
  char top;
  for(int i=0;i<bracket.length();i++)
  {
      if(bracket[i]=='{' || bracket[i]=='(' || bracket[i]=='[')
         stk.push(bracket[i]);
      else
      {
          if(bracket[i]=='}')
          {
              top=stk.top();
              stk.pop();   
              if(top=='(' || top=='[')
                return false;
                continue;
          }
          else if(bracket[i]==')')
           {
               top=stk.top();
               stk.pop();   
               if(top=='{' || top=='[')
                return false;
                continue;
           }
           else if(bracket[i]==']')
           {
               top=stk.top();
               stk.pop();   
               if(top=='{' || top=='(')
                return false;
                continue;
           } 
           
      }
      if(stk.empty())                      // if stack is empty then it means all have matched pair
       return true;
  }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int number;                   // number of test cases
    cin>>number;
    while(number--)
    {
        string bracket;                    // taking string of bracket as input
        cin>>bracket;
        if(ismatched(bracket))
         cout<<"YES\n";
        else
         cout<<"NO\n"; 

    }
       
    return 0;
}