class Solution {
public:
    int find(int x,vector<int> &par)
    {
        if(x==par[x]) return x;
        return par[x]=find(par[x],par);
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> par(10005),rank(10005,1);
        for(int i=0;i<par.size();++i) par[i]=i;
        int uid=0;
        unordered_map<string,int> mp1;   // email,uid
        unordered_map<string,string> mp2; // email,name
        for(vector<string> account:accounts)
        {
            string name="";
            for(string email:account)
            {
                if(name=="")
                {
                    name=email;
                    continue;
                }
                if(mp1.find(email)==mp1.end()) mp1[email]=uid++;
                mp2[email]=name;
                string name1=account[1];
                int id1=mp1[name1];
                int lx=find(id1,par);
                int id2=mp1[email];
                int ly=find(id2,par);
                if(lx!=ly)
                {
                    if(rank[lx]>rank[ly]) par[ly]=lx;
                    else if(rank[ly]>rank[lx]) par[lx]=ly;
                    else{
                        par[lx]=ly;
                        ++rank[ly];
                    }
                }
            }
        }
        unordered_map<int,vector<string>> mp3;
        for(pair<string,string> ele: mp2)
        {
            int id=mp1[ele.first] ;
            int lx=find(id,par);
            mp3[lx].push_back(ele.first);
        }
        vector<vector<string>> res;
        for(auto  &ele: mp3)
        {
            string name=mp2[ele.second[0]];
            vector<string> emails;
            emails.push_back(name);
            sort(ele.second.begin(),ele.second.end());
            for(string itms:ele.second) emails.push_back(itms);
            res.push_back(emails);
        }
        return res;
    }
};
