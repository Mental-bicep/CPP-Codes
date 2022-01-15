class Solution {
    public int findMin(int[] arr) {
        
        int s=0,e=arr.length-1;
    while(s<e)
    {
        int mid=(s+e)/2;
        if(arr[mid]<arr[e]) e=mid;
        else s=mid+1;
    }
    return arr[s];
    }
}
