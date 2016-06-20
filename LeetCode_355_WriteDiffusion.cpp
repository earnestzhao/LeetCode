class Twitter
{
public:
    
    /** Initialize your data structure here. */
    Twitter()
    {
        m_iGlobalSequence = INT_MIN;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        int iTweetSeq = AddTweet(userId, tweetId);
        
        unordered_map<int, unordered_set<int>>::iterator hmitFollower = m_hmapFollower.find(userId);
        
        if (hmitFollower != m_hmapFollower.end())
        {
            for (unordered_set<int>::iterator hsitFollower = hmitFollower -> second.begin(); hsitFollower != hmitFollower -> second.end(); hsitFollower ++)
            {
                AddFeed(*hsitFollower, tweetId, iTweetSeq, userId);
            }
        }
        
        AddFeed(userId, tweetId, iTweetSeq, userId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int> vecFeedList;
        
        unordered_map<int, TweetListNode *>::iterator hmapIterator = m_hmapUserFeeds.find(userId);
        
        if (hmapIterator != m_hmapUserFeeds.end())
        {
            for (TweetListNode * pstCollect = hmapIterator -> second -> m_pstNext; pstCollect != NULL; pstCollect = pstCollect -> m_pstNext)
            {
                vecFeedList.push_back(pstCollect -> m_iTweetId);
                
                if (vecFeedList.size() >= 10)
                {
                    break;
                }
            }
        }
        
        return vecFeedList;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        if (followerId == followeeId)
        {
            return;
        }
        
        if (!AddFollowee(followerId, followeeId))
        {
            return;
        }
        
        AddFollower(followerId, followeeId);
        
        unordered_map<int, TweetListNode *>::iterator hmitUserTweets = m_hmapUserTweets.find(followeeId);
        
        if (hmitUserTweets == m_hmapUserTweets.end())
        {
            return;
        }
        
        unordered_map<int, TweetListNode *>::iterator hmitUserFeeds = m_hmapUserFeeds.find(followerId);
        
        if (hmitUserFeeds == m_hmapUserFeeds.end())
        {
            m_hmapUserFeeds[followerId] = new TweetListNode;
            hmitUserFeeds = m_hmapUserFeeds.find(followerId);
        }
        
        int iInsertNumber = 0;
        
        for (TweetListNode * pstBeInserted = hmitUserTweets -> second -> m_pstNext, * pstInsert = hmitUserFeeds -> second; pstBeInserted != NULL;)
        {
            if (pstInsert -> m_pstNext == NULL || pstInsert -> m_pstNext -> m_iTweetSeq < pstBeInserted -> m_iTweetSeq)
            {
                TweetListNode * pstInsertNode = new TweetListNode(pstBeInserted -> m_iTweetId, pstBeInserted -> m_iTweetSeq, pstBeInserted -> m_iUserId);
                pstInsertNode -> m_pstNext    = pstInsert -> m_pstNext;
                pstInsert -> m_pstNext        = pstInsertNode;
                
                iInsertNumber ++;
                pstInsert     = pstInsertNode;
                pstBeInserted = pstBeInserted -> m_pstNext;
                
                if (iInsertNumber >= 10)
                {
                    break;
                }
            }
            else
            {
                pstInsert = pstInsert -> m_pstNext;
            }
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if (followerId == followeeId)
        {
            return;
        }
        
        if (!DelFollowee(followerId, followeeId))
        {
            return;
        }
        
        DelFollower(followerId, followeeId);
        
        unordered_map<int, TweetListNode *>::iterator hmitUserFeeds = m_hmapUserFeeds.find(followerId);
        
        if (hmitUserFeeds != m_hmapUserFeeds.end())
        {
            for (TweetListNode * pstBehind = hmitUserFeeds -> second, * pstFront = pstBehind -> m_pstNext; pstFront != NULL;)
            {
                if (pstFront -> m_iUserId == followeeId)
                {
                    TweetListNode * pstDelNode = pstFront;
                    pstFront                   = pstFront -> m_pstNext;
                    pstBehind -> m_pstNext     = pstFront;
                    
                    delete pstDelNode;
                    pstDelNode = NULL;
                }
                else
                {
                    pstBehind = pstFront;
                    pstFront  = pstFront -> m_pstNext;
                }
            }
        }
    }
    
private:

    int AddTweet(int iUserId, int iTweetId)
    {
        unordered_map<int, TweetListNode *>::iterator hmitTweets = m_hmapUserTweets.find(iUserId);
        
        if (hmitTweets == m_hmapUserTweets.end())
        {
            m_hmapUserTweets[iUserId] = new TweetListNode;
            hmitTweets = m_hmapUserTweets.find(iUserId);
        }
        
        TweetListNode * pstNewNode = new TweetListNode(iTweetId, ++ m_iGlobalSequence, iUserId);
        
        if (hmitTweets != m_hmapUserTweets.end())
        {
            pstNewNode -> m_pstNext           = hmitTweets -> second -> m_pstNext;
            hmitTweets -> second -> m_pstNext = pstNewNode;
        }
        
        return pstNewNode -> m_iTweetSeq;
    }
    
    void AddFeed(int iUserId, int iTweetId, int iTweetSeq, int iAuthorId)
    {
        unordered_map<int, TweetListNode *>::iterator hmitFeeds = m_hmapUserFeeds.find(iUserId);
        
        if (hmitFeeds == m_hmapUserFeeds.end())
        {
            m_hmapUserFeeds[iUserId] = new TweetListNode;
            hmitFeeds = m_hmapUserFeeds.find(iUserId);
        }
        
        TweetListNode * pstNewNode = new TweetListNode(iTweetId, iTweetSeq, iAuthorId);
        
        if (hmitFeeds != m_hmapUserFeeds.end())
        {
            pstNewNode -> m_pstNext          = hmitFeeds -> second -> m_pstNext;
            hmitFeeds -> second -> m_pstNext = pstNewNode;
        }
    }
    
    bool AddFollowee(int iFollowerId, int iFolloweeId)
    {
        unordered_map<int, unordered_set<int>>::iterator hmitFollowee = m_hmapFollowee.find(iFollowerId);
        
        if (hmitFollowee != m_hmapFollowee.end())
        {
            if (hmitFollowee -> second.find(iFolloweeId) != hmitFollowee -> second.end())
            {
                return false;
            }
            
            hmitFollowee -> second.insert(iFolloweeId);
        }
        else
        {
            m_hmapFollowee[iFollowerId] = unordered_set<int>( { iFolloweeId } );
        }
        
        return true;
    }
    
    void AddFollower(int iFollowerId, int iFolloweeId)
    {
        unordered_map<int, unordered_set<int>>::iterator hmitFollower = m_hmapFollower.find(iFolloweeId);
        
        if (hmitFollower != m_hmapFollowee.end())
        {
            hmitFollower -> second.insert(iFollowerId);
        }
        else
        {
            m_hmapFollower[iFolloweeId] = unordered_set<int>( { iFollowerId } );
        }
    }
    
    bool DelFollowee(int iFollowerId, int iFolloweeId)
    {
        unordered_map<int, unordered_set<int>>::iterator hmitFollowee = m_hmapFollowee.find(iFollowerId);
        
        if (hmitFollowee != m_hmapFollowee.end())
        {
            if (hmitFollowee -> second.find(iFolloweeId) == hmitFollowee -> second.end())
            {
                return false;
            }
            
            hmitFollowee -> second.erase(iFolloweeId);
        }
        else
        {
            return false;
        }
        
        return true;
    }
    
    void DelFollower(int iFollowerId, int iFolloweeId)
    {
        unordered_map<int, unordered_set<int>>::iterator hmitFollower = m_hmapFollower.find(iFolloweeId);
        
        if (hmitFollower != m_hmapFollowee.end())
        {
            hmitFollower -> second.erase(iFollowerId);
        }
    }
    
private:

    // Feed linked-list node
    struct TweetListNode
    {
        // Tweet ID
        int m_iTweetId;
        
        // Tweet Sequence
        int m_iTweetSeq;
        
        // User ID
        int m_iUserId;
        
        // Next node
        TweetListNode * m_pstNext;
        
        // Constructor
        TweetListNode(int iTweetId, int iTweetSeq, int iUserId) : m_iTweetId(iTweetId), m_iTweetSeq(iTweetSeq), m_iUserId(iUserId), m_pstNext(NULL) {}
        
        // Default constructor
        TweetListNode() : m_iTweetId(INT_MIN), m_iTweetSeq(INT_MIN), m_iUserId(INT_MIN), m_pstNext(NULL) {}
    };
    
    // Global Sequence
    int m_iGlobalSequence;
    
    // User's feeds
    unordered_map<int, TweetListNode *> m_hmapUserFeeds;
    
    // User's tweets
    unordered_map<int, TweetListNode *> m_hmapUserTweets;
    
    // User's followee
    unordered_map<int, unordered_set<int>> m_hmapFollowee;
    
    // User's follower
    unordered_map<int, unordered_set<int>> m_hmapFollower;
};

/*

A long size code...

Classic write diffusion.

I thought a long time for choosing read diffusion or write diffusion. At last, I chose write diffusion, because there are only 10 feeds' id to show, which has a low writing cost when following and unfollowing.

If using read diffusion, it maybe have low cost method with a LRU cache. I will do it later.

There must be better data structures and better solutions. I will research it later.

*/
