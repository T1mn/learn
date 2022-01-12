// 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

//  

// 示例 1：

// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// 输出：true
// 示例 2：

// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// 输出：true
// 示例 3：

// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// 输出：false
//  

// 提示：

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board 和 word 仅由大小写英文字母组成

#include <vector>
#include <string>
using namespace std;

// 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

//  

// 示例 1：

// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// 输出：true
// 示例 2：

// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// 输出：true
// 示例 3：

// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// 输出：false
//  

// 提示：

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board 和 word 仅由大小写英文字母组成

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i != board.size(); ++i)
        {
            for (int j = 0; j != board[0].size(); ++j)
            {
                if (dfs(i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }
    bool dfs(int &i, int &j, int wordIndex, vector<vector<char>> &board, string &word)
    {
        if (board[i][j] != word[wordIndex])
            return false;
        else if (wordIndex == word.size() - 1)
            return true;
        board[i][j] += 128;
        vector<pair<int, int>> pairs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        bool res = false;
        for (int k = 0; k != pairs.size(); ++k)
        {
            int newI = i + pairs[k].first;
            int newJ = j + pairs[k].second;
            if (newI >= 0 && newI < board.size() && newJ >= 0 && newJ < board[0].size())
            {
                res = dfs(newI, newJ, wordIndex + 1, board, word);
                if (res)
                    break;
            }
        }
        board[i][j] -= 128;
        return res;
    }
};

int main()
{
    vector<vector<char>> input{{'G','B'}, {'G', 'a'}};
    Solution s;
    s.exist(input, "GBGaa");
}