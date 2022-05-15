class Solution {
public:
    bool search2(vector<int>& arr, int tar) {
        int s=0,e=arr.size()-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(arr[mid]==tar or arr[e]==tar) return true;
            if(arr[mid]>arr[s]) 
            {
                if(tar<arr[mid] and tar>=arr[s]) e=mid-1;
                else s=mid+1;
            }
            else if(arr[mid]<arr[e]){
                if(tar>arr[mid] and tar<=arr[e]) s=mid+1;
                else e=mid-1;
            }
            else --e;
        }
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        // int s=0,e=nums.size()-1;
        return search2(nums,target);
        // if(ans==-1) return false;
        // return true;
    }
};
