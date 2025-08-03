class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size()==0) return 0;
        int count=0;
        stack<char> st;
        for(const auto i:s){
            if(i=='(') st.push('(');
            if(i==')') {
                if(!st.empty() && st.top()=='(') st.pop();
                else count++;
            }
        }
        while(!st.empty()){
            count++;
            st.pop();
        }
        return count;
    }
};

/*
- st push brackets
- agar ek pair mila, to usko pop kardo
- agar st.empty and ')' then count++;
- agar s khatam & !st.empty count++;
- ((())
(((
st = [ '(' '(' '(' ]
*/


/*
WONT WORK : "()))(("
- jitney opening bracket hai, utne hi closing  bracket hone chaiye
- count the num of opening brackets
- count the num of closing brackets
- cout there diff

int count=0;
for(const auto i:s){
    if(i=='(') count++;
    if(i==')') count--;
}
return abs(count);

*/