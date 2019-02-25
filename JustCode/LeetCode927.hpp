/*
 * 判断思路：
 *     1. 记录1出现的位置和个数
 *     2. 判断个数是否是3的倍数，是否为0
 *     3. 从最前面的一段开始判断相邻数字之差是否相等，不相等则说明不存在符合条件的可能
 *     4. 末尾0处理，调整位置将0前置
 */
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        vector<int> index;
        for(int i=0;i<A.size();i++)
        	if(A[i]) index.push_back(i);
        if(index.size()%3) return {-1, -1};
        if(index.empty()) return {0, 2};
        int x1=0, x2=index.size()/3, x3 = x2*2;
        for(int i=1;i<x2;i++) {
        	int diff = index[i]-index[i-1];
        	if(diff != index[x2+i]-index[x2+i-1]
        		|| diff != index[x3+i]-index[x3+i-1]) 
        		return {-1, -1};
        }
        int tail = A.size()-index.back();
        if(index[x3]-index[x3-1] < tail 
        	|| index[x2]-index[x2-1] < tail)
        	return {-1, -1};
        return {index[x2-1]+tail-1, index[x3-1]+tail};
    }
};