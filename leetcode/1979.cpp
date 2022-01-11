// ; 1979. 找出数组的最大公约数
// ; 给你一个整数数组 nums ，返回数组中最大数和最小数的 最大公约数 。

// ; 两个数的 最大公约数 是能够被两个数整除的最大正整数。

//  https://leetcode-cn.com/problems/find-greatest-common-divisor-of-array/

// ; 示例 1：

// ; 输入：nums = [2,5,6,9,10]
// ; 输出：2
// ; 解释：
// ; nums 中最小的数是 2
// ; nums 中最大的数是 10
// ; 2 和 10 的最大公约数是 2
// ; 示例 2：

// ; 输入：nums = [7,5,6,8,3]
// ; 输出：1
// ; 解释：
// ; nums 中最小的数是 3
// ; nums 中最大的数是 8
// ; 3 和 8 的最大公约数是 1
// ; 示例 3：

// ; 输入：nums = [3,3]
// ; 输出：3
// ; 解释：
// ; nums 中最小的数是 3
// ; nums 中最大的数是 3
// ; 3 和 3 的最大公约数是 3

#include <vector>
#include <algorithm>

// class Solution {
// public:
//     int findGCD(std::vector<int>& nums) {
//         // 从小到大对数组进行排序
//         std::sort(nums.begin(),nums.end());
//         // 判断较小的数为0，则直接返回0
//         if (nums[0] == 0)
//         {
//             return 0;
//         }
//         else if (nums[0] == 1)
//         {
//             return 1;
//         }
//         int temp = 0;
//         int bigger = nums[nums.size()-1];
//         int smaller = nums[0];
//         while (bigger % smaller != 0)
//         {
//             temp = bigger % smaller;
//             bigger = smaller ;
//             smaller = temp;
//         }
//         return smaller;
//     }
// };

// 15. 三数之和
// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

 

// 示例 1：

// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// 示例 2：

// 输入：nums = []
// 输出：[]
// 示例 3：

// 输入：nums = [0]
// 输出：[]
 

// 提示：

// 0 <= nums.length <= 3000
// -105 <= nums[i] <= 105
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        if (nums.size() < 3)
            return {};
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        int left = 0;
        int right = 0;
        int examp = 0;
        for (int i = 0 ; i != nums.size(); ++i)
        {
            examp = nums[i];
            left = i + 1;
            right = nums.size() - 1;
            while (left < right)
            {
                if (examp + nums[left] + nums[right] < 0)
                    ++left;
                else if (examp + nums[left] + nums[right] > 0)
                    --right;
                else
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while(left < right)
                    {
                        if (nums[left] == nums[++left])
                        {
                            ;
                        }
                        if (nums[right] == nums[--right])
                        {
                            ;
                        }
                    }
                }
            }
        }
        return res;
    }

};

int main()
{
    Solution s;
    std::vector<int>input{-1,0,1,2,-1,-4};
    s.threeSum(input);
}