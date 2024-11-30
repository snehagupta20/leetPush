
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]]++;
        }

        priority_queue<int> pq;

        for(auto f : freq){
            pq.push(f.second);
        }

        int time = 0;

        while(!pq.empty()){
            vector<int> temp;
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    int f = pq.top();
                    pq.pop();
                    f--;
                    temp.push_back(f);
                }
            }

            for(int i=0; i<temp.size(); i++){
                if(temp[i]>0){
                    pq.push(temp[i]);
                }
            }

            if(pq.empty()){
                time += temp.size();
            } else {
                time += n+1;
            }
        }

        return time;
    }
};


























// jabtak pura pq pop na ho jaye, tabtak vo usme se 1-1 hata dega
// and time += n+1


/*
ONE OF THE SOLS 

int freq[26] = {0};
for(char task : tasks){
    freq[task - 'A']++;
}
sort(begin(freq) , end(freq));
int chunk = freq[25] - 1;
int idel = chunk * n;

for(int i=24; i>=0; i--){
    idel -= min(chunk,freq[i]);
}

return idel < 0 ? tasks.size() : tasks.size() + idel;
*/

/*
A A A B B B
A B X A B X A B X

FREQ 

A B X A B X A X X A X X 

A C A B D B
A C A B D B

A A A B B B
A B X X A B X X A B X X
*/



/*
MY SOL - 1ST TRY

map<char,int> freq;
for(int i=0;i<tasks.size();i++){
    freq[tasks[i]]++;
}

// cout
for(const auto f : freq){
    cout<<f.first<<" : "<<f.second<<endl;
}cout<<endl;

int count = 0;
n++;
int interval = n;

while(freq.size()>0){
    n = interval;
    // for(auto &f : freq){
    for(auto it = freq.begin(); it != freq.end();){
        cout<<endl<<"LOOP ITERATION"<<endl;
        // cout<<f.first<<" : "<<f.second<<endl;
        cout<<it->first<<" : "<<it->second<<endl;
        count++;
        cout<<"count = "<<count<<endl;
        // f.second--;
        it->second--;
        // cout<<f.first<<" : "<<f.second<<endl;
        cout<<it->first<<" : "<<it->second<<endl;
        if(n>0) n--;
        cout<<"intervals left (n) = "<<n<<endl;
        // if(f.second == 0){
        if(it->second == 0){
            // cout<<"since, the freq of "<<f.first<<" is now 0, we have erased it."<<endl;
            cout<<"since, the freq of "<<it->first<<" is now 0, we have erased it."<<endl;
            it = freq.erase(it);
        } else {
            it++;
        }

        if(n==0) {
            cout<<"n has gone 0, so we will  break."<<endl;
            break;
        }
        cout<<endl;
    }
    cout<<"LOOP HAS ENDED "<<endl;
    while(freq.size()>0 && n!=0){
        cout<<"frequency ended, but n did not"<<endl;
        count++;
        n--;
        cout<<"count = "<<count<<endl;
        cout<<"n = "<<n<<endl;
    }
}

return count;
*/


/*
map<char,int> freq;

for(int i=0;i<tasks.size();i++){
    freq[tasks[i]]++; 
}

int time = 0;

priority_queue<int> pq; // max heap

for(const auto f : freq){
    pq.push(f.second);
}

while(!pq.empty()){
    vector<int> temp;

    for(int i=1;i<=n+1;i++){
        if(!pq.empty()){
            int f = pq.top();
            pq.pop();
            f--;
            temp.push_back(f);
        }
    }

    for(int &f : temp){
        if(f>0){
            pq.push(f);
        }
    }

    if(pq.empty()){
        time += temp.size();
    } else {
        time += n+1;
    }
}

return time;
*/