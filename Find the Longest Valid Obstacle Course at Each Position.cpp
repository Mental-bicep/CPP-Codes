#define rn return
#define v vector
#define umap unordered_map
#define ll long long 
#define ins insert
#define mp make_pair
#define p pair
#define s second
#define f first
#define pb push_back
class compare{
  public:
    bool operator () (p<ll,ll>a,p<ll,ll>b)
    {
        if(a.f==b.f) rn a.s>b.s;
        rn a.f>b.f;
    }
};

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& v1) {
        
        
        v<int> res(v1.size(),0);
        res[0]=1;
        v<int> v2; v2.pb(v1[0]);
        for(ll i=1;i<v1.size();++i)
        {
            if(v2.back()<=v1[i])
            {
                v2.pb(v1[i]);
                res[i]=v2.size();
            }
            else
            {
                auto idx=upper_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
                v2[idx]=v1[i];
                res[i]=idx+1;
            }
        }
        rn res;
    }
};
