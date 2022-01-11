#include <string>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

class Solution {
public:
    int myAtoi(std::string s) {
        bool startFlag = false;
        bool negative = false;
        std::string temp = "";
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <='9')
            {
                startFlag = true;
                temp.push_back(s[i]);
            }
            else {
                if (!startFlag)
                {
                    if(s[i] == '-')
                        negative = true;
                }
                else
                {
                    break;
                }
            }
        }
        float j = 0.1;
        float res = 0;
        std::cout << temp << std::endl;
        for (unsigned int i = 0; i != temp.size(); ++i)
        {   
            res = res + j * temp[i];
            j *= 10;
            std::cout << res << std::endl;
            if(!negative && res < INT32_MAX)
                continue;
            else
                return INT32_MAX;
            if (negative && res < abs(INT32_MIN))
                continue;
            else
                return INT32_MIN;
        }
        return res * 10;
    }
};

int main()
{
    Solution s;
    std::cout << s.myAtoi("42");
}