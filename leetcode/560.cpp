// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的连续子数组的个数。

//  

// 示例 1：

// 输入：nums = [1,1,1], k = 2
// 输出：2
// 示例 2：

// 输入：nums = [1,2,3], k = 3
// 输出：2

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/subarray-sum-equals-k
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <vector>
#include <map>
#include <string>

// class Solution {
// public:
//     int subarraySum(std::vector<int>& nums, int k) {
//         if (nums.empty())
//             return 0;
//         int cnt = 0;
//         int sum = 0;
//         // int firstNum = 1;
//         // for (auto i = 0; i != nums.size(); ++i)
//         // {
//         //     if (firstNum != nums[i])
//         //     {
//         //         firstNum = 0;
//         //         break;
//         //     }
//         // }
//         // if (firstNum && k >= 1)
//         // {
//         //     cnt = nums.size() - k + 1;   
//         // }
//         // else
//         // {
//             for (auto i = 0; i != nums.size(); ++i)
//             {
//                 for (auto j = i; j != nums.size(); ++j)
//                 {
//                     sum += nums[j];
//                     if (sum == k)
//                         ++cnt;
//                 }
//                 sum = 0;
//             }
//         // }
//         return cnt;
//     }
// };

// class Solution {
// public:
//     int subarraySum(std::vector<int>& nums, int k) {
//         if (nums.empty()) return 0;
//         std::map<int, int> sumMap;
//         int sum = 0;
//         int res = 0;
//         for (auto i = 0; i != nums.size(); ++i)
//         {
//             sum += nums[i];
//             if (sum == k)
//                 ++res;
//             res += sumMap[sum - k];
//             if (sumMap.find(sum) != sumMap.end())
//                 ++sumMap[sum];
//             else
//                 sumMap[sum] = 1;
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     int subarraySum(std::vector<int>& nums, int k) {
//         if(nums.empclass Solution {
// public:
//     int subarraySum(std::vector<int>& nums, int k) {
//         if(nums.empty())
//             return 0;
//         int sum = 0;
//         int cnt = 0;
//         std::vector<int> sumVec;
//         for (int i = 0; i != nums.size(); ++i)
//         {
//             sum += nums[i];
//             sumVec.push_back(sum);
//         }
//         for (int i = sumVec.size() - 1; i != -1; --i)
//         {
//             if (sumVec[i] == k)
//                 ++cnt;
//             if (sumVec.size() > 1)
//             {
//                 for (int j = i - 1; j != -1; --j)
//                 {
//                     if((sumVec[i] - sumVec[j])==k)
//                         ++cnt;
//                 }
//             }
//         }
//         return cnt;
//     }
// };
// ty())
//             return 0;
//         int sum = 0;
//         int cnt = 0;
//         std::vector<int> sumVec;
//         for (int i = 0; i != nums.size(); ++i)
//         {
//             sum += nums[i];
//             sumVec.push_back(sum);
//         }
//         for (int i = sumVec.size() - 1; i != -1; --i)
//         {
//             if (sumVec[i] == k)
//                 ++cnt;
//             if (sumVec.size() > 1)
//             {
//                 for (int j = i - 1; j != -1; --j)
//                 {
//                     if((sumVec[i] - sumVec[j])==k)
//                         ++cnt;
//                 }
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty())
            return "";
        else if (strs.size() == 1)
            return strs[0];
        
        for (auto i = 1; i != strs.size() ; ++i)
        {
            for (auto j = 0; j != strs[0].size(); ++j)
            {
                if (strs[0][j] != strs[i][j])
                {
                    strs[0].erase(j, strs[0].size() - j + 1);
                    break;
                }
            }
        }
        return strs[0];
    }
};

int main()
{
    // std::vector<int> nums {0,0,0,0,0,0,0,0,0,0};
    // int k = 0;
    std::vector<std::string> strs{"flower","flow","flight"};
    Solution s;
    s.longestCommonPrefix(strs);
}