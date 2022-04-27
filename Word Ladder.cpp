class Solution {
public:
    
    bool fun(string &s1,string &s2)
    {
        if(s1.size()!=s2.size()) return false;
        int cnt=0;
            for(int i=0;i<s1.size();++i) if(s1[i]!=s2[i]) ++cnt;
        return cnt==1;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // unordered_map<s>
//     queue<string> q;
//     q.push(beginWord);
//         // unordered_map<string,bool> mp1;
//         vector<bool> mp1(wordList.size());
//         int level=1;
//         while(q.size()>0)
//         {
//             int size=q.size();
//             while(size--){
//                 auto rem=q.front();q.pop();
//                 if(mp1[rem]) continue;
//                 mp1[rem]=true;
//                 if(rem==endWord) return level;
//                 for(string ele:wordList){
//                     if(ele.size()!=rem.size() or mp1[ele]) continue;
//                     int cnt=0;
//                     for(int i=0;i<ele.size();++i) if(ele[i]!=rem[i]) ++cnt;
//                     if(cnt==1){ 
//                         if(ele==endWord) return level+1;
//                         q.push(ele);
//                     }
//                 }
                
//             }
//             ++level; 
//         }
//         return 0;
    
//     }
        
        
        queue<string> q;
        q.push(beginWord);
        int level=1;
        vector<bool> mp1(wordList.size());
        while(q.size())
        {
            int size=q.size();
            while(size--){
            
                auto rem=q.front();q.pop();
                if(rem==endWord) return level;
                for(int i=0;i<wordList.size();++i)
                {
                    if(mp1[i] or !fun(wordList[i],rem)) continue;
                    mp1[i]=true;
                    if(wordList[i]==endWord) return level+1;
                    q.push(wordList[i]);
                }
                
            }
            ++level;
            
        }
        return 0;
    }
};
