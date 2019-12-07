class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
    	// 查找R棋子的位置
        int i, j;
        bool is_find = false;
        for(i=0;i<board.size();i++){ 
        	for(j=0;j<board[0].size();j++)
        		if(board[i][j]=='R'){
        			is_find = true;
        			break;
        		}
        	if(is_find) break;
    	}
    	// 探索
    	int ans = 0;
    	// 左
    	for(int l=i-1;l>=0;l--) {
    		if(board[l][j]=='B') break;
    		if(board[l][j]=='p') {
    			ans++;
    			break;
    		}
    	}
    	// 右
    	for(int r=i+1;r<board.size();r++) {
    		if(board[r][j]=='B') break;
    		if(board[r][j]=='p') {
    			ans++;
    			break;
    		}
    	}
    	// 上
    	for(int d=j+1;d<board[0].size();d++) {
    		if(board[i][d]=='B') break;
    		if(board[i][d]=='p') {
    			ans++;
    			break;
    		}
    	}
    	// 下
    	for(int u=j-1;u>=0;u--) {
    		if(board[i][u]=='B') break;
    		if(board[i][u]=='p') {
    			ans++;
    			break;
    		}
    	}
    	return ans;
    }
};