class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int time;
public:
    Twitter() {
        time = 0;
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        auto& ownTweets = tweets[userId];
        for (int i = (int)ownTweets.size() - 1;
             i >= 0 && i >= (int)ownTweets.size() - 10; i--) {
            pq.push(ownTweets[i]);
        }
        for (int followee : following[userId]) {
            auto& userTweets = tweets[followee];
            for (int i = (int)userTweets.size() - 1;
                 i >= 0 && i >= (int)userTweets.size() - 10; i--) {
                pq.push(userTweets[i]);
            }
        }
        vector<int> feed;
        while (!pq.empty() && feed.size() < 10) {
            feed.push_back(pq.top().second);
            pq.pop();
        }
        return feed;
    }
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};