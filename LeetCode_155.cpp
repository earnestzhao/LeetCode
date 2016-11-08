class MinStack
{
public:

    /** initialize your data structure here. */
    MinStack()
    {
        
    }
    
    void push(int x)
    {
        m_stackContainer.push(x);
        m_msetContainer.insert(x);
    }
    
    void pop()
    {
        int iTopValue = m_stackContainer.top();
        m_stackContainer.pop();
        m_msetContainer.erase(m_msetContainer.find(iTopValue));
    }
    
    int top()
    {
        return m_stackContainer.top();
    }
    
    int getMin()
    {
        return *m_msetContainer.begin();
    }
    
private:

    // Stack
    stack<int> m_stackContainer;
    
    // Multiset
    multiset<int> m_msetContainer;
};
