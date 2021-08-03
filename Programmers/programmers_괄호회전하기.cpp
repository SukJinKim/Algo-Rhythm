#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    int n = s.size();
    
    stack<char> _stack;
    
    for(int i = 0; i < n; i++)
    {   
        bool isRight = true;
        
        for(int j = i, k = 0; k < n; j++, k++)
        {
            char ch = s[j % n];
            
            if(ch == '(' || ch == '{' || ch == '[')
                _stack.push(ch);
            else if(ch == ')' && _stack.empty() ||
                    ch == ')' && _stack.top() != '(')
            {
                isRight = false;
                break;
            }
            else if(ch == '}' && _stack.empty() ||
                    ch == '}' && _stack.top() != '{')
            {
                isRight = false;
                break;
            }
            else if(ch == ']' && _stack.empty() ||
                    ch == ']' && _stack.top() != '[')
            {
                isRight = false;
                break;
            }
            else
                _stack.pop();
        }
    
        if(isRight && _stack.empty()) 
            answer++;
        
        while(!_stack.empty())
            _stack.pop();
    }
    
    return answer;
}