class Solution {
public:
    vector<int> sortedSquares(vector<int>& v) {
        int pos=0;
        for( pos=0;pos<v.size();pos++) if(v[pos]>=0) break;
        
        for(int i=0;i<v.size();i++) v[i]*=v[i];
        int i=pos-1,k=0;
        vector<int > res(v.size());
        while(i>=0 and pos<v.size())
        { 
          
         if(v[i]>v[pos])
            { 
                res[k++]=v[pos++];
            }
            else res[k++]=v[i--];
        }
        while(i>=0)
        { 
            res[k++] =v[i--];
        }
        while(pos<v.size())
        {   
            res[k++]=v[pos++];
        }
        return res;
        
    }
};
