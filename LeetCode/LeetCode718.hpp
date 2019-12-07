class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
        vector<vector<int>> tmp(A.size()+1, vector<int>(B.size()+1, 0));
        for(int i=A.size()-1;i>=0;i--)
            for(int j=B.size()-1;j>=0;j--) {
                if(A[i]==B[j]) tmp[i][j]=tmp[i+1][j+1]+1;
                dp[i][j] = max(tmp[i][j], max(dp[i+1][j], dp[i][j+1]));
            }
        return dp[0][0];
    }
};