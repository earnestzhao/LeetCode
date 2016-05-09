struct TicketDpsNode
{
	string m_strAirport;

	bool m_bTicketUsed;
	
	TicketDpsNode(const string & strAirport) : m_strAirport(strAirport), m_bTicketUsed(false) {  }
};


bool TicketDpsNodeSmaller(const TicketDpsNode & stOper1, const TicketDpsNode & stOper2)
{
	return stOper1.m_strAirport.compare(stOper2.m_strAirport) < 0;
}


class Solution
{
public:

    vector<string> findItinerary(vector<pair<string, string>> tickets)
	{
		for (int iIndex = 0; iIndex < tickets.size(); iIndex ++)
		{
			TicketDpsNode stTicketDpsNode(tickets[iIndex].second);
		
			map<string, vector<TicketDpsNode>>::iterator mapIterator = m_mapTicketFromTo.find(tickets[iIndex].first);
		
			if (mapIterator != m_mapTicketFromTo.end())
			{
				mapIterator -> second.push_back(stTicketDpsNode);
			}
			else
			{
				m_mapTicketFromTo[tickets[iIndex].first] = vector<TicketDpsNode>(1, stTicketDpsNode);
			}
		}
		
		map<string, vector<TicketDpsNode>>::iterator mapIterator = m_mapTicketFromTo.begin();
		
		for (; mapIterator != m_mapTicketFromTo.end(); mapIterator ++)
		{
			sort(mapIterator -> second.begin(), mapIterator -> second.end(), TicketDpsNodeSmaller);
		}
		
		m_bFinished = false;
		
		m_vecItineraryFinal.clear();
		
		m_iTicketNumber = tickets.size();
		
		vector<string> vecItinerary;
		
		findItineraryDps("JFK", vecItinerary);
		
		return m_vecItineraryFinal;
    }

private:

	map<string, vector<TicketDpsNode>> m_mapTicketFromTo;
	
	vector<string> m_vecItineraryFinal;
	
	int m_iTicketNumber;
	
	bool m_bFinished;
	
private:

	void findItineraryDps(const string & strStartAirport, vector<string> & vecItinerary)
	{
		if (m_bFinished)
		{
			return;
		}
	
		vecItinerary.push_back(strStartAirport);
		
		if (vecItinerary.size() >= m_iTicketNumber + 1)
		{
			m_vecItineraryFinal = vecItinerary;
			
			vecItinerary.pop_back();
			
			m_bFinished = true;
			
			return;
		}
		
		map<string, vector<TicketDpsNode>>::iterator mapIterator = m_mapTicketFromTo.find(strStartAirport);
		
		if (mapIterator != m_mapTicketFromTo.end())
		{
			for (int iIndex = 0; iIndex < mapIterator -> second.size(); iIndex ++)
			{
				if (!mapIterator -> second[iIndex].m_bTicketUsed)
				{
					mapIterator -> second[iIndex].m_bTicketUsed = true;
					
					findItineraryDps(mapIterator -> second[iIndex].m_strAirport, vecItinerary);
					
					mapIterator -> second[iIndex].m_bTicketUsed = false;
				}
			}
		}
		
		vecItinerary.pop_back();
	}
};
