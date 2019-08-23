class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        size_t max_gap_overlap_time = 0;

        unordered_map<size_t, size_t> gap_times;

        for (size_t i = 0; i < wall.size(); i++)
        {
            size_t gap = 0;

            for (size_t j = 0; j < wall[i].size() - 1; j++)
            {
                gap += wall[i][j];

                size_t times = (++ gap_times[gap]);

                if (max_gap_overlap_time < times)
                {
                    max_gap_overlap_time = times;
                }
            }
        }

        return wall.size() - max_gap_overlap_time;
    }
};
