class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        int low=0,high=matrix.size(), mid;
        while(high>low+1){
            mid=(high+low)/2;
            if(matrix[mid][0]==target) return true;
            else if(matrix[mid][0]>target) high=mid;
            else low=mid;
        }
        if(high<low+1)return false;
        else{
            int low1=0;
            high=matrix[low].size();
            while(high>=low1){
                mid=(high+low1)/2;
                if(matrix[low][mid]==target) return true;
                else if(matrix[low][mid]>target) high=mid-1;
                else low1=mid+1;
            }
            return false;
        }
    }
};
