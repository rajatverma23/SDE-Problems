class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        
        result[0] = result[rowIndex] = 1;
        
        if(rowIndex > 1)
        {
            result[1] = rowIndex;
            int mul = rowIndex - 1;
        
            for(int i = 2; i < rowIndex; i++, mul--)
            {   
                double res = (double)result[i-1] * (double)mul;
                result[i] = int(res/i);
            }
        }
        
        return result;
    }
};
