#include <bits/stdc++.h> 
using namespace std; 
  
bool checkRedundancy(string& str) 
{ 
stack<char> stack;
for(char i:str)
{
  if(i==')')
  {
    char top = stack.top();
    stack.pop();
    bool flag=true;

    while(top!='(')
    {
      if (top == '+' || top == '-' || top == '*' || top == '/') flag =  false;
      top=stack.top();
      stack.pop();          
    }

if (flag == true) 
                return true; 
  }
 else
            stack.push(i); 
}
return false;
} 
  
// Function to check redundant brackets 
void findRedundant(string& str) 
{ 
    bool ans = checkRedundancy(str); 
    if (ans == true) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
} 
  
// Driver code 
int main() 
{ 
    string str = "((a+b))"; 
    findRedundant(str); 
  
    str = "(a+(b)/c)"; 
    findRedundant(str); 
  
    str = "(a+b*(c-d))"; 
    findRedundant(str); 
  
    return 0; 
} 