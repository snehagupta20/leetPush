class Solution {
    public:
      void bitManipulation(int num, int i) {
          
          i--;
          
          // get ith bit
          if(num & (1<<i)) cout<<1<<" ";
          else cout<<0<<" ";
          
          //set ith bit
          num |= (1<<i);
          cout<<num<<" ";
  
          // clear ith bit
          num &= ~(1<<i);
          cout<<num;
          
          return ;
          
      }
  };