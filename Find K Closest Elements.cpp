class Solution {
public:
    
    
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int cnt=1;
        int idx=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int left=idx-1,right=idx;
        // cout<<"idx= "<<idx<<"\n";
        vector<int> ans;
        while(cnt<=k)
        {
            if(left<0) break;
            if(right>=arr.size()) break;
            if(abs(arr[left]-x)<abs(arr[right]-x)) ans.push_back(arr[left--]);
            else if(abs(arr[left]-x)>abs(arr[right]-x)) ans.push_back(arr[right++]);
            else if(arr[left]<arr[right])ans.push_back(arr[left--]);
            else ans.push_back(arr[right++]);
            ++cnt;
        }
        while(left>=0 and cnt<=k)  ans.push_back(arr[left--]),++cnt;
        while(right<arr.size() and cnt<=k) 
                ans.push_back(arr[right++]),++cnt;
        sort(ans.begin(),ans.end());
        return ans;
    }
};
