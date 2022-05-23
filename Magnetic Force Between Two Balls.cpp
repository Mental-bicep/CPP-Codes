class Solution {
public:
    bool isValid(vector<int> pos,int cows,int dis)
    {
        int cnt=1;
        int prev=pos[0];
        for(int i=1;i<pos.size();++i)
            if((pos[i]-prev)>=dis){
                ++cnt;
                prev=pos[i];
            }
        return cnt>=cows;
    }
    
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        if(m==2) return pos.back()-pos[0];
        int s=1;
        int e=pos.back()-pos[0];
        int ans;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isValid(pos,m,mid))
            {
                s=mid+1;
                ans=mid;
            }
            else e=mid-1;
        }
        return ans;
    }
};
