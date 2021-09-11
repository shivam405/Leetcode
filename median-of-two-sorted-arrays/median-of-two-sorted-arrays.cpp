class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=n-1;
        int j=0;
        
        while(i>=0 && j<m)
        {
            if(nums1[i]>nums2[j])
            {
                swap(nums1[i],nums2[j]);
                i--;
            }
            else{
                j++;
            }
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int len=m+n;
        int mid=0;
        double sum=0;
        if(len%2==0)
        {
            mid=(len/2)-1;
            if(mid==n-1)
            {
                sum=nums1[mid]+nums2[0];
            }
            else if(mid<(n-1))
            {
                sum=nums1[mid]+nums1[mid+1];
            }
            else
            {
                sum=nums2[mid-n]+nums2[mid+1-n];
            }
            sum=sum/2;
        }
        else
        {
            mid=len/2;
            if(mid<=n-1)
            {
                sum=nums1[mid];
            }
            else
            {
                sum=nums2[mid-n];
            }
        }
        return sum;
        
    }
};