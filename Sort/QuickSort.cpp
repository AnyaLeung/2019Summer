void QuickSort(vector<int> arr, int left, int right){
    int start = 0;
    int end = 0;
    if(left<right){
        start = left;
        end = right;
        int pivot = arr[right];

        while(left<right){
            while(left<right && arr[left]<pivot){
                left ++;
            }
            while(left<right && arr[right]>=pivot){
                right --;
            }
            swap(arr[left], arr[right]);
        }
        s[left] = pivot;
        QuickSort(arr, start, left-1);
        QuickSort(arr, left+1, end);
    }
}
