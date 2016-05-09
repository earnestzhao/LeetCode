// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator
{
    struct Data;
	Data* data;
	
public:
	
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator
{
public:
	
	PeekingIterator(const vector<int>& nums) : Iterator(nums), m_objCurrentIterator(*this) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek()
	{
		Iterator objCurrentIteratorNext = m_objCurrentIterator;
		return objCurrentIteratorNext.next();
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next()
	{
		return m_objCurrentIterator.next();
	}

	bool hasNext() const
	{
		return m_objCurrentIterator.hasNext();
	}
	
private:

	Iterator m_objCurrentIterator;
};

