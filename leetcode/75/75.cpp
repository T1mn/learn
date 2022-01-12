// 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

// 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

//  

// 示例 1：

// 输入：nums = [2,0,2,1,1,0]
// 输出：[0,0,1,1,2,2]
// 示例 2：

// 输入：nums = [2,0,1]
// 输出：[0,1,2]
// 示例 3：

// 输入：nums = [0]
// 输出：[0]
// 示例 4：

// 输入：nums = [1]
// 输出：[1]
//  

// 提示：

// n == nums.length
// 1 <= n <= 300
// nums[i] 为 0、1 或 2
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (1 == nums.size())
            return ;
        int nums1 = 0;
        int nums2 = 0;
        int nums3 = 0;

        for (auto &i:nums)
        {
            if (0 == i)
                ++nums1;
            else if ( 1== i)
                ++nums2;
            else
                ++nums3;
        }
        nums.clear();
        while (nums1--)
            nums.push_back(0);
        while (nums2--)
            nums.push_back(1);
        while (nums3--)
            nums.push_back(2);
    }
};