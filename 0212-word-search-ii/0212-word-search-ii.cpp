class Solution {
public:
    // Removed the DP array because it causes false negatives in path-dependent DFS.
    
    bool solve(int r, int c, int n, int m, vector<vector<char>>& g, string& word, int a) {
        if (a == word.size() - 1) return true;

        char curr = g[r][c];
        g[r][c] = '!'; // Mark visited
        
        int drow[] = {-1, 0, 1, 0}, dcol[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            int nr = r + drow[i], nc = c + dcol[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] == word[a + 1]) {
                if (solve(nr, nc, n, m, g, word, a + 1)) {
                    g[r][c] = curr; // Backtrack
                    return true;
                }
            }
        }
        
        g[r][c] = curr; // Backtrack
        return false;
    }

    vector<string> findWords(vector<vector<char>>& g, vector<string>& words) {
        int n = g.size(), m = g[0].size();
        vector<string> ans;
        
        // 1. Board Frequency Optimization (Crucial for TLE)
        vector<int> boardCount(26, 0);
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) boardCount[g[i][j]-'a']++;

        for (string word : words) {
            // 2. Frequency Pruning: If word has more of a letter than the board, skip.
            vector<int> wordCount(26, 0);
            bool possible = true;
            for(char c : word) {
                if(++wordCount[c-'a'] > boardCount[c-'a']) { possible = false; break; }
            }
            if(!possible) continue;

            // 3. Reversal Heuristic: Start from the rarer end of the word
            bool rev = false;
            if(boardCount[word.front()-'a'] > boardCount[word.back()-'a']) {
                reverse(word.begin(), word.end());
                rev = true;
            }

            bool found = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (g[i][j] == word[0] && solve(i, j, n, m, g, word, 0)) {
                        if(rev) reverse(word.begin(), word.end());
                        ans.push_back(word);
                        found = true; break;
                    }
                }
                if (found) break;
            }
        }
        return ans;
    }
};