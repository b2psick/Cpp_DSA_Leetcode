class Solution {
public:
    bool winner(vector<int>& nums, int i, int j, int player1, int player2, bool turn) {
        if(i>j) {
            if(player1 >= player2) {
                return true;
            } else return false;
        }

        if(turn) {
            return winner(nums, i + 1, j, player1 + nums[i], player2, !turn) || winner(nums, i, j - 1, player1 + nums[j], player2, !turn);
        } else {
            return winner(nums, i + 1, j, player1, player2 + nums[i], !turn) && winner(nums, i, j - 1, player1, player2 + nums[j], !turn);
        }

        return false;
    }
    bool predictTheWinner(vector<int>& nums) {
        return winner(nums, 0, nums.size() - 1, 0, 0, true);
    }
};