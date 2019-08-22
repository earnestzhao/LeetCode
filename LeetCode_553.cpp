class Solution
{
public:
    string optimalDivision(vector<int> &nums)
    {
        string result;
        optimalDivision(true, nums, 0, nums.size() - 1, result);
        return result;
    }

private:
    float optimalDivision(bool maximum, const vector<int> &numbers, size_t start_index, size_t end_index, string &output)
    {
        ostringstream output_generator;
        if (start_index == end_index)
        {
            output_generator << numbers[start_index];
            output = output_generator.str();
            return static_cast<float>(numbers[start_index]);
        }

        auto iterator = cache_storage_.find(make_pair(start_index, end_index));
        if (iterator != cache_storage_.end())
        {
            output = iterator->second.second;
            return iterator->second.first;
        }

        float optimal_value = maximum ? -1.0F : 10000.0F;
        for (size_t i = start_index; i < end_index; i++)
        {
            string head_half_division = "";
            string tail_half_division = "";

            float head_half_value = optimalDivision(maximum, numbers, start_index, i, head_half_division);
            float tail_half_value = optimalDivision(!maximum, numbers, i + 1, end_index, tail_half_division);
            float current_value = head_half_value / tail_half_value;

            string left_parenthesis  = (i + 1 < end_index ? "(" : "");
            string right_parenthesis = (i + 1 < end_index ? ")" : "");

            if ((maximum && current_value > optimal_value) || (!maximum && current_value < optimal_value))
            {
                optimal_value = current_value;
                output_generator.str("");
                output_generator << head_half_division << "/" << left_parenthesis << tail_half_division << right_parenthesis;
            }
        }

        output = output_generator.str();
        cache_storage_[make_pair(start_index, end_index)] = make_pair(optimal_value, output);
        return optimal_value;
    }

    struct HashPair
    {
        size_t operator()(const pair<size_t, size_t> &pair) const
        {
            return pair.first * 100 + pair.second;
        }
    };

    unordered_map<pair<size_t, size_t>, pair<float, string>, HashPair> cache_storage_;
};
