class Solution {
public:
     bool outOfOrder(vector<int> arr,int i) {
	        int x=arr[i];
	        if(i==0)
	        return x>arr[1];
	        if(i==arr.size()-1)
	        return x<arr[i-1];
	        return x>arr[i+1] or x<arr[i-1];
	    }
    int findUnsortedSubarray(vector<int>& arr) {
        int smallest=INT_MAX,largest=INT_MIN;
	    for(int i=0;i<arr.size();i++)
	    {
            if(arr.size()<2)
                return (0);
	        if(outOfOrder(arr,i))
	        {
	            smallest=min(smallest,arr[i]);
	            largest=max(largest,arr[i]);
	        }
	    }
	    if(smallest==INT_MAX)
	     return (0);
	    
	    int left=0;
	    while(arr[left]<=smallest)
	    left++;
	    int right=arr.size()-1;
	    while(arr[right]>=largest)
	    right--;
	    return (right-left+1);
        
    }
};