bool fun(string a,string b)
{
    string  c,d;
    c=a.append(b);
    d=b.append(a);
   if( c.compare(d)>0)
       return true;
    return false;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
       
        vector<string>str;
        string s;
        if(nums.size()<=0)
            return s;
        int flag=0,i;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                flag=1;
                break;
            }
        }
        if (flag==0)
            return(s.append("0"));
        int end=nums.size();
            for(i=0;i!=end;i++)
                str.push_back(to_string(nums[i]));
        sort(str.begin(),str.end(),fun);
        
        for(i=0;i<end;i++)
            s.append(str[i]);
        return s;
    }
};
