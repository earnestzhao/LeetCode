class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int iCows  = 0;
        int iBulls = 0;
        int aiDigitTimes[10] = { 0 };

        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                iBulls ++;
            }
            else
            {
                aiDigitTimes[secret[i] - '0'] ++;
            }
        }

        for (int i = 0; i < guess.size(); i++)
        {
            if (secret[i] != guess[i] && aiDigitTimes[guess[i] - '0'] > 0)
            {
                iCows ++;
                aiDigitTimes[guess[i] - '0'] --;
            }
        }

        ostringstream ossOutput;
        ossOutput << iBulls << 'A';
        ossOutput << iCows  << 'B';
        return ossOutput.str();
    }
};

