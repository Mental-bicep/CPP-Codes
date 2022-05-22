class Solution {
    public int splitArray(int[] A, int m) {
        int n=A.length;
        if(m>n) return -1;
        int mnn=0,mxx=0;
        for(int i=0;i<n;++i) {
            mnn=Math.max(mnn,A[i]);
            // mxx=Math.max(mxx,A[i]);
            mxx+=A[i];
        }
        int s=mnn,e=mxx;
        // System.out.println("s and e "+s+" "+e);
        int ans=-1;
        while(s<=e)
        {
            
            int mid=s+(e-s)/2;
            // System.out.println("mid = "+mid);
            if(isValid(A,mid,m)){
                // System.out.println("valid for mid");
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
    public  boolean isValid(int []arr,int val,int m)
    {
        int sum=0,cnt=0;
        for(int i=0;i<arr.length;)
        {
            if((sum+arr[i])<=val) {sum+=arr[i];++i;}
            else {
                ++cnt;
                sum=0;
            }
            if(cnt>=m) return false;
        }
        // if(cnt>m) return false;
        return true;
    }
}
