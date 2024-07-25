class Solution {
public:
    void merge(vector<int>& nums, int s,int e){
        int mid=s+(e-s)/2;
        int n1=mid-s+1;
        int n2=e-mid;
        int *first= new int[n1];
        int *second= new int[n2];
        for(int i=0;i<n1;i++){
            first[i]=nums[s+i];
        }
        for(int i=0;i<n2;i++){
            second[i]=nums[mid+i+1];
        }
        int i=0,j=0,k=s;
        while(i<n1 && j<n2){
            if(first[i]<second[j]){
                nums[k]=first[i];
                i++;
            }else{
                nums[k]=second[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            nums[k]=first[i];
            k++;i++;
        }
        while(j<n2){
            nums[k]=second[j];
            k++;j++;
        }
    }
    void mergeSort(vector<int>& nums, int s, int e)
    {
        if( s>=e) return;
        int mid=s+(e-s)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums, mid+1, e);
        merge(nums,s,e);
    }
    vector<int> sortArray(vector<int>& nums) {

        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};