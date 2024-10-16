class Solution {
public:
    vector<int> NGE(vector<int> arr){
        stack<int> st;
        vector<int> nge(arr.size());

        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                nge[st.top()] = i-1;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            nge[st.top()] = arr.size()-1;
            st.pop();
        }

        return nge;
    }

    vector<int> PGE(vector<int> arr){
        stack<int> st;
        vector<int> pge(arr.size());

        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                pge[st.top()] = i+1;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            pge[st.top()] = 0;
            st.pop();
        }

        return pge;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int MOD = (1e9+7);

        vector<int> nge = NGE(arr);
        vector<int> pge = PGE(arr);

        long long sum=0;

        for(int i=0;i<arr.size();i++){
            long long left = i - pge[i] + 1;
            long long right = nge[i] - i + 1;
            long long contribution = (left * right) % MOD;
            contribution = (contribution * arr[i]) % MOD;
            sum = (sum + contribution) % MOD;
        }

        return sum;
    }
};

// - traverse the arr
// - find next greater element
// - prev greater element (index form)
// - calculae the distcance
// - find num of subarrays it will be min for.


// 0 1 2 3
// 3 1 2 4
// 1-4 : 3-1 = 2+1 = 3 elements
// 1-0 = 1+1 = 2 elements

















// - Modulo keeps numbers within a specified range (to avoid overflow).
// - 1e9+7 is a common choice because it is a prime number and is near the upper limit of typical integer sizes.
// - You perform the modulo operation during the sum to ensure intermediate values do not overflow and cause incorrect results.

/*
    long long ans=0;
    long long mod = 1e9+7;
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr.size();j++){
            int min=INT_MAX;
            for(int k=i;k<=j;k++){
                if(min>arr[k]) min=arr[k];
            }
            ans=(ans+min)%mod;
        }
    }
    return ans;
*/


/*
    long long sum=0;
    long long mod=1e9+7;
    for(int i=0;i<arr.size();i++){
        int right=1;
        int left=1;
        cout<<"arr[i] = "<<arr[i]<<endl;
        for(int j=i+1;j<arr.size();j++){
            cout<<"right arr[j] = "<<arr[j]<<endl;
            if(arr[j]>arr[i]){
                right++;
                cout<<"right = "<<right<<endl;
            }
            else if(arr[j]<=arr[i]){
                break;
            }
        }
        // cout<<endl;
        for(int j=i-1;j>=0;j--){
            cout<<"left arr[j] = "<<arr[j]<<endl;
            if(arr[j]>arr[i]){
                cout<<"left = "<<right<<endl;
                left++;
            }
            else if(arr[j]<=arr[i]){
                break;
            }
        }
        sum = (sum + ((left*right)*arr[i])) % mod;
        cout<<"sum = "<<sum<<endl<<endl;
    }
    return sum;
*/



/*
    int count=0;
    long long sum=0;
    long long mod=1e9+7;

    for(int i=0;i<arr.size();i++){

        int right=1;
        int left=0;

        // counts right
        cout<<"arr[i] = "<<arr[i]<<endl;
        for(int j=i;j<arr.size();j++){
            cout<<"right arr[j] = "<<arr[j]<<endl;
            if(arr[j]>arr[i]){
                right++;
                cout<<"right = "<<right<<endl;
            }
            else if(arr[j]<arr[i]){
                break;
            }
        }

        // counts left
        // cout<<endl;
        for(int j=i;j>=0;j--){
            cout<<"left arr[j] = "<<arr[j]<<endl;
            if(arr[j]>=arr[i]){
                cout<<"left = "<<right<<endl;
                left++;
            }
            else if(arr[j]<arr[i]){
                break;
            }
        }

        sum = (sum + ((left*right)*arr[i])) % mod;
        cout<<"sum = "<<sum<<endl<<endl;
    }

    return sum;

*/


/*

vector<int> getlsl(vector<int> arr){

        stack<int> st;
        vector<int> lsl;

        for(int i=0;i<arr.size();i++){

            if(st.empty()){
                st.push(i);
                lsl.push_back(-1);
            }
            else{

                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }

                st.empty() ? lsl.push_back(-1) : lsl.push_back(st.top());
                
                st.push(i);

            }

        }

        return lsl;

    }

    vector<int> getlsr(vector<int> arr){

        int n = arr.size();
        stack<int> st;
        vector<int> lsr;

        for(int i=n-1;i>=0;i--){

            if(st.empty()){
                st.push(i);
                lsr.push_back(n);
            }
            else{

                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }

                st.empty() ? lsr.push_back(n) : lsr.push_back(st.top());

                st.push(i);

            }

        }

        reverse(lsr.begin(),lsr.end());

        return lsr;

    }

    int sumSubarrayMins(vector<int>& arr) {

        int MOD = 1e9+7;
        long long sum=0;

        vector<int> lsl = getlsl(arr);
        vector<int> lsr = getlsr(arr);

        for(long long i=0;i<arr.size();i++){
            sum = (sum + ((i-lsl[i])*(lsr[i]-i))*arr[i]) % MOD;
        }

        return sum;

    }

*/