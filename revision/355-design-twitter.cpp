class Twitter {
public:

    int timestamp;
    map<int, vector<pair<int,int>>> tweets;
    map<int, vector<int>> following;

    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        timestamp++;
        tweets[userId].push_back({timestamp, tweetId});
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        vector<pair<int,int>> vec = tweets[userId];
        int size = vec.size();

        for(int i=0;i<size;i++){
            pq.push(vec[i]);
        }

        vector<int> temp = following[userId];
        for(int i=0;i<temp.size();i++){
            vec = tweets[temp[i]];
            for(int i=0;i<vec.size();i++){
                pq.push(vec[i]);
            }
            
        }

        vector<int> ans;
        while(ans.size()<10 && !pq.empty()){
            pair<int,int> p = pq.top();
            ans.push_back(p.second);
            pq.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        vector<int> vec = following[followerId];
        auto it = find(vec.begin(), vec.end(), followeeId);
        if(it == vec.end()){
            following[followerId].push_back(followeeId);
        }
        return;
    }
    
    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(remove(following[followerId].begin(), following[followerId].end(), followeeId), following[followerId].end());

        return;
    }
};

/*
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
*/



/*
class Twitter {
public:

    // map<userid, num of tweets>
    map<int,int> numOfTweets;

    // map<userid, vector<pair<time stamp, tweet id>>>
    map<int, vector<pair<int,int>>> tweetsOfUser;

    int timestamp;

    // map<user id, vector<following ids> >
    map<int, vector<int>> following;
    
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {

        // incrementing number of tweets of a particular user
        numOfTweets[userId]++;

        // incrementing time stamp after adding
        timestamp++;

        // adding the tweet id to corresponding user along with timestamp
        tweetsOfUser[userId].push_back({timestamp, tweetId});

        return;
    }
    
    vector<int> getNewsFeed(int userId) {

        vector<int> temp = following[userId];

        auto it = find(temp.begin(), temp.end(), userId);
        if(it == temp.end()){
            following[userId].push_back(userId);
            temp.push_back(userId);
        }

        priority_queue<pair<int,int>> recentMostTweets;

        for(int i=0; i < temp.size(); i++){

            int user = temp[i];

            vector<pair<int,int>> helper = tweetsOfUser[user];

            for(int j=0;j<helper.size();j++){
                recentMostTweets.push(helper[j]);
            }
        }

        vector<int> ans;
        int n = 10;
        while(n>0 && !recentMostTweets.empty()){
            ans.push_back(recentMostTweets.top().second);
            recentMostTweets.pop();
            n--;
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {

        vector<int> temp = following[followerId];

        auto it = find(temp.begin(), temp.end(), followeeId);
        if(it == temp.end()){
            following[followerId].push_back(followeeId);
        }

        return;

    }
    
    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(remove(following[followerId].begin(), following[followerId].end(), followeeId), following[followerId].end());

        return;
    }

};

*/

/*
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
*/
