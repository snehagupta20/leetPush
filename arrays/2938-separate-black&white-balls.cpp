class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps=0;
        int one=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                one++;
            }
            else if(s[i]=='0'){
                swaps+=one;
            }
        }

        return swaps;
    }
};

// number of 1 (before 0) * number of 0 (after 1)
// 01234567
// 11010111
// i=3
// one=2
// zero=1

// 2+1=3

// 4+1 (total number of 0)

// figure out how many 1 before 0 

// - convert s to integer string
// - convert integer to vector
// - sort the vector (swap method) - sort of like bubble sort, but u can only swap adjacent nums
// - figure out how many swaps to completely sort the vector


/*
    while(i<s.size()){

        int one=0;
        int zero=0;

        while(s[i]=='1'){
            one++;
            i++;
        }

        j=i;

        while(j<s.size()){
            if(s[j]=='0'){
                // i++;
                zero++;
            }
            j++;
        }

        while(s[i]=='0'){
            i++;
        }

        swaps += (one*zero);

    }
*/