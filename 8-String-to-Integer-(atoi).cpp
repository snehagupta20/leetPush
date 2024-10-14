class Solution {
public:
    void pureNum(string s, string &ans, bool &neg, bool &sign){
        if(s.size()==0){
            cout<<endl<<"s: "<<s<<endl;
            return;
        }

        cout<<endl<<"s: "<<s<<endl;
        // whitespace
        if(s[0]==' '){
            cout<<"whitespace encountered"<<endl;

            if(sign) return;

            int i=0;
            while(s[i]==' '){
                cout<<"s["<<i<<"] = "<<s[i]<<endl;
                i++;
            }

            if(i==s.size()) return;

            string temp = s.substr(i,s.size()-i);
            cout<<"temp: "<<temp<<endl;
            pureNum(s.substr(i,s.size()-i), ans, neg, sign);
        }
        // alpha
        if(isalpha(s[0])){
            return;
        }
        // negative sign
        else if(s[0]=='-'){
            cout<<endl<<"s[0]=='-'"<<endl;

            if(sign) return;

            neg = true;
            sign = true;
            
            string temp = s.substr(1,s.size()-1);
            cout<<"temp: "<<temp<<endl;
            pureNum(s.substr(1,s.size()-1), ans, neg, sign);
        }
        // positive sign
        else if(s[0]=='+'){
            cout<<endl<<"s[0]=='+'"<<endl;

            if(sign) return;

            sign = true;

            string temp = s.substr(1,s.size()-1);
            cout<<"temp: "<<temp<<endl;
            pureNum(s.substr(1,s.size()-1), ans, neg, sign);
        }
        // digit 
        else if(isdigit(s[0])){
            cout<<endl<<"digit encountered"<<endl;
            // cout<<"s[0]= "<<s[0]<<endl;
            
            int i=0;
            while(isdigit(s[i])){
                cout<<"s["<<i<<"] = "<<s[i]<<endl;
                ans+=s[i];
                i++;
                // if(i>10) return;
            }
            cout<<"ans = "<<ans<<endl;
            cout<<"i = "<<i<<endl;
            return;

            string temp = s.substr(i,s.size()-1-i);
            cout<<"temp: "<<temp<<endl;
            pureNum(s.substr(i,s.size()-1-i), ans, neg, sign);
        }

        return;
    }

    int myAtoi(string s) {
        string ans="";
        bool neg = false;
        bool sign = false;

        pureNum(s, ans, neg, sign);

        cout<<"came back to main func"<<endl;
        cout<<"ans= "<<ans<<endl;

        // removing starting 0s
        int i=0;
        while(ans[i]=='0'){
            i++;
        }
        ans = ans.substr(i,ans.size()-i);

        //checking lenght of str
        if(ans.size()<=0) return 0; 
        if(ans.size()>10){
            if (neg) return INT_MIN;
            return INT_MAX;
        }

        long long num = stoll(ans);
        if(neg) num= -num;
        
        if (num < INT_MIN) return INT_MIN;
        if (num > INT_MAX) return INT_MAX;

        return num;
    }
};
