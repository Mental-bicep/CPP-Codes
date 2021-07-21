bool fun(vector<int>&v1,vector<int>&v2)
{
    return v1[0]<v2[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        if(intervals.size()<=1)
            return intervals;
            sort(intervals.begin(),intervals.end(),fun);
            vector<int> temp(2);
            int i,flag;
            temp[0]=intervals[0][0];
            temp[1]=intervals[0][1];
            for( i=1;i<intervals.size();i++)
            {
                if(temp[1]>=intervals[i][0])
                {   flag=1;
                    temp[0]=min(temp[0],intervals[i][0]);
                    temp[1]=max(temp[1],intervals[i][1]);
                }
                else
                {   
                    flag=0;        
                    v.push_back(temp);
                    //temp.clear();
                    temp[0]=intervals[i][0];
                    temp[1]=intervals[i][1];
                    //index=index+i;
                    
                }   
                
            }
        if(flag)
        v.push_back(temp);
        else
        {
            temp[0]=intervals[i-1][0];
            temp[1]=intervals[i-1][1];
            v.push_back(temp);
        }
            return v;
    }
};
