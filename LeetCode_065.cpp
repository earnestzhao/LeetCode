class Solution
{
public:
    enum STATE
    {
        ACCEPT_SIGN_POINT_AND_DIGIT,
        ACCEPT_DIGIT_AND_POINT,
        ACCEPT_DIGIT_POINT_AND_E,
        ACCEPT_DIGIT_AND_E,
        ACCEPT_DIGIT_ONCE,
        ACCEPT_SIGN_AND_DIGIT,
        ACCEPT_DIGIT_ONCE_AFTER_E,
        ACCEPT_DIGIT
    };

    bool isNumber(string s)
    {
        int iContentStart = 0;
        for (; iContentStart < s.length(); iContentStart ++)
        {
            if (s[iContentStart] != ' ')
            {
                break;
            }
        }

        int iContentEnd = s.length() - 1;
        for (; iContentEnd >= 0; iContentEnd --)
        {
            if (s[iContentEnd] != ' ')
            {
                break;
            }
        }

        if (iContentEnd < iContentStart)
        {
            return false;
        }

        s = s.substr(iContentStart, iContentEnd - iContentStart + 1);
        STATE state = ACCEPT_SIGN_POINT_AND_DIGIT;
        for (int i = 0; i < s.length(); i++)
        {
            switch (state)
            {
                case ACCEPT_SIGN_POINT_AND_DIGIT:
                {
                    if (s[i] == '+' || s[i] == '-')
                    {
                        state = ACCEPT_DIGIT_AND_POINT;
                    }
                    else if (s[i] == '.')
                    {
                        state = ACCEPT_DIGIT_ONCE;
                    }
                    else if (s[i] >= '0' && s[i] <= '9')
                    {
                        state = ACCEPT_DIGIT_POINT_AND_E;
                    }
                    else
                    {
                        return false;
                    }

                    break;
                }

                case ACCEPT_DIGIT_AND_POINT:
                {
                    if (s[i] >= '0' && s[i] <= '9')
                    {
                        state = ACCEPT_DIGIT_POINT_AND_E;
                    }
                    else if (s[i] == '.')
                    {
                        state = ACCEPT_DIGIT_ONCE;
                    }
                    else
                    {
                        return false;
                    }

                    break;
                }

                case ACCEPT_DIGIT_ONCE:
                {
                    if (s[i] >= '0' && s[i] <= '9')
                    {
                        if (s[i-1] == '+' || s[i-1] == '-')
                        {
                            state = ACCEPT_DIGIT_POINT_AND_E;
                        }
                        else if (s[i-1] == '.')
                        {
                            state = ACCEPT_DIGIT_AND_E;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }

                    break;
                }

                case ACCEPT_DIGIT_POINT_AND_E:
                {
                    if (s[i] >= '0' && s[i] <= '9')
                    {
                        state = ACCEPT_DIGIT_POINT_AND_E;
                    }
                    else if (s[i] == '.')
                    {
                        state = ACCEPT_DIGIT_AND_E;
                    }
                    else if (s[i] == 'e')
                    {
                        state = ACCEPT_SIGN_AND_DIGIT;
                    }
                    else
                    {
                        return false;
                    }

                    break;
                }

                case ACCEPT_DIGIT_AND_E:
                {
                    if (s[i] >= '0' && s[i] <= '9')
                    {
                        state = ACCEPT_DIGIT_AND_E;
                    }
                    else if (s[i] == 'e')
                    {
                        state = ACCEPT_SIGN_AND_DIGIT;
                    }
                    else
                    {
                        return false;
                    }

                    break;
                }

                case ACCEPT_SIGN_AND_DIGIT:
                {
                    if (s[i] >= '0' && s[i] <= '9')
                    {
                        state = ACCEPT_DIGIT;
                    }
                    else if (s[i] == '+' || s[i] == '-')
                    {
                        state = ACCEPT_DIGIT_ONCE_AFTER_E;
                    }
                    else
                    {
                        return false;
                    }

                    break;
                }

                case ACCEPT_DIGIT_ONCE_AFTER_E:
                {
                    if (s[i] >= '0' && s[i] <= '9')
                    {
                        state = ACCEPT_DIGIT;
                    }
                    else
                    {
                        return false;
                    }

                    break;
                }

                case ACCEPT_DIGIT:
                {
                    if (s[i] >= '0' && s[i] <= '9')
                    {
                        state = ACCEPT_DIGIT;
                    }
                    else
                    {
                        return false;
                    }

                    break;
                }
            }
        }

        return state != ACCEPT_SIGN_POINT_AND_DIGIT && state != ACCEPT_DIGIT_AND_POINT && state != ACCEPT_DIGIT_ONCE && state != ACCEPT_SIGN_AND_DIGIT && state != ACCEPT_DIGIT_ONCE_AFTER_E;
    }
};

