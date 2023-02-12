int binary_search(int* a, int n, int target)
{
    int low=0,high=n,middle=0;
    while(low<high) {
        middle=(low+high)/2;
        if (target==a[middle]) return middle;
        else if (target<a[middle]) high=middle;
        else if (target>a[middle]) low=middle+1;
    }
    return -1;
}
bool bFind(int a[], int left, int right, int tag)
{
    for (; left <= right; ) {
        int mid = (left + right) >> 1;
        if (a[mid] == tag)
            return true;
        else
            a[mid] < tag ? left = mid + 1 : right = mid - 1;
    }
    return false;
}


// 非等值查找，例如平时所说的二分求上界，二分求下界之类的。
