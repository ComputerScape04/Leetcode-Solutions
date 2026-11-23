/*
sequential 

so we need word[0] before we proceed to word[1] and so on

if we move to the right, search positions [up, down, right]
if we move to the left, search positions [up, down, left]
if we move to the top, search positions [up, left, right]
if we move to the bottom, search positions [down, left, right]

might need a separate var to keep track of which direction we traverse

take care of boundary positions (prevent index out of bounds)

do i directly move to position or check if the position matches a char in word??

a double for loop to find the starting position of the string 
once we find it, run the traversal algorithm starting from that position
initially direction is "", so we can traverse any direction (unless out of bounds).
if that starting position leads me to the word, return true and end the backtracking function
else, return false.
continue finding the next starting position of the string. if all options exhausted from the input board,
return false finally.

dir --> 0 = up ; 1 = down ; 2 = left ; 3 = right

*/

class Solution {
public:
    bool wordsearch_backtrack(
        const vector<vector<char>>& board, 
        string& word, 
        int idx, 
        int i, int j, int m, int n,
        vector<vector<bool>> &visited) 
    {
        if (word[idx] == board[i][j])
            idx++;
        else 
            return false;

        if (idx == word.size())
            return true;

        visited[i][j] = true;
        
        // check right
        if (j+1 < n && !visited[i][j+1]) {
            bool res = wordsearch_backtrack(board, word, idx, i, j+1, m, n, visited);
            if (res)
                return true;
        }

        // check left
        if (j-1 >= 0 && !visited[i][j-1]) {
            bool res = wordsearch_backtrack(board, word, idx, i, j-1, m, n, visited);
            if (res)
                return true;
        }

        // check bottom
        if (i+1 < m && !visited[i+1][j]) {
            bool res = wordsearch_backtrack(board, word, idx, i+1, j, m, n, visited);
            if (res)
                return true;
        }

        // check top
        if (i-1 >= 0 && !visited[i-1][j]) {
            bool res = wordsearch_backtrack(board, word, idx, i-1, j, m, n, visited);
            if (res)
                return true;
        }

        // no word matched, pop back and backtrack
        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    // perform word search
                    if (wordsearch_backtrack(board, word, 0, i, j, m, n, visited))
                        return true;
                }
            }
        }

        return false;
    }
};

/* O(1) Space Optimization */
/*
sequential 

so we need word[0] before we proceed to word[1] and so on

if we move to the right, search positions [up, down, right]
if we move to the left, search positions [up, down, left]
if we move to the top, search positions [up, left, right]
if we move to the bottom, search positions [down, left, right]

might need a separate var to keep track of which direction we traverse

take care of boundary positions (prevent index out of bounds)

do i directly move to position or check if the position matches a char in word??

a double for loop to find the starting position of the string 
once we find it, run the traversal algorithm starting from that position
initially direction is "", so we can traverse any direction (unless out of bounds).
if that starting position leads me to the word, return true and end the backtracking function
else, return false.
continue finding the next starting position of the string. if all options exhausted from the input board,
return false finally.

dir --> 0 = up ; 1 = down ; 2 = left ; 3 = right

*/

class Solution {
public:
    bool wordsearch_backtrack(
        vector<vector<char>>& board, 
        string& word, 
        int idx, 
        int i, int j, int m, int n) 
    {
        if (word[idx] == board[i][j])
            idx++;
        else 
            return false;

        if (idx == word.size())
            return true;

        char temp = board[i][j];
        board[i][j] = '#';
        
        // check right
        if (j+1 < n && board[i][j+1] != '#') {
            bool res = wordsearch_backtrack(board, word, idx, i, j+1, m, n);
            if (res)
                return true;
        }

        // check left
        if (j-1 >= 0 && board[i][j-1] != '#') {
            bool res = wordsearch_backtrack(board, word, idx, i, j-1, m, n);
            if (res)
                return true;
        }

        // check bottom
        if (i+1 < m && board[i+1][j] != '#') {
            bool res = wordsearch_backtrack(board, word, idx, i+1, j, m, n);
            if (res)
                return true;
        }

        // check top
        if (i-1 >= 0 && board[i-1][j] != '#') {
            bool res = wordsearch_backtrack(board, word, idx, i-1, j, m, n);
            if (res)
                return true;
        }

        // no word matched, pop back and backtrack
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    // perform word search
                    if (wordsearch_backtrack(board, word, 0, i, j, m, n))
                        return true;
                }
            }
        }

        return false;
    }
};
