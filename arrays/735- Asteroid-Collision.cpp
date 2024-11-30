class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int j=0;
        while(j<asteroids.size()){
            if(j==asteroids.size()-1) break;

            int first = asteroids[j];
            int right = asteroids[j+1];

            if((first<0 && right<0) || (first>0 && right>0) || (first<0 && right>0)){
                j++;
            }

            else if(abs(first) == abs(right)){
                asteroids.erase(asteroids.begin()+j);
                asteroids.erase(asteroids.begin()+j);
                if(j>0) j--;
            }

            else if((first>0 && right<0)){
                if(abs(first) < abs(right)){
                    asteroids[j]=right;
                    if(j>0) j--;
                }
                asteroids.erase(asteroids.begin()+j+1);
            }
        }

        return asteroids;
    }
};