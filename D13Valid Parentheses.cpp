// Problem Link
//https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
	    int i;
	    char ch,temp;
        stack<char>st;
	    for(i=0;s[i]!='\0';i++)
	    {
		    ch=s[i];
		    if(ch=='('||ch=='{'||ch=='[')
		    {
			    st.push(ch);
		    }
		    else if(ch==')'||ch=='}'||ch==']')
		    {
			    if(st.empty())
			    {
				return false;
			    }
			    else
			    {   
				    temp=st.top();
                    st.pop();                                        
				    if(temp!=getMatchingSymbol(ch))
				    {
					    return false;
				    }
			    }
		    }
	    }
	    if(!st.empty())
	    {
            return false;
	    }
	    else
	    return true;
    }
    
    
    char getMatchingSymbol(char ch)
    {
	    char t;
	    switch(ch)
	    {
		    case '(':
			    t=')';
			    break;
		    case ')':
		        t='(';
			    break;
		    case ']':
		        t='[';
			    break;
		    case '[':
		        t=']';
			    break;
		    case '{':
			    t='}';
			    break;
		    case '}':
		        t='{';
		        break;
	    }
	    return t;
    }

};
