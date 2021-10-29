class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // if()
        if(rooms.size()==0) return true;
        stack<int> stk;
        unordered_map<int,bool> mp1;
        for(int i=0;i<rooms.size();++i) mp1[i];
        stk.push(0);
        while(!stk.empty()){
            auto ele=stk.top();
            stk.pop();
            if(mp1[ele]==false)
                for(auto itms:rooms[ele]) stk.push(itms);
            mp1[ele]=true;
        }
        for(auto ele:mp1) if(ele.second==false) return false;
        return true;
    }
};
