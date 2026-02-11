#include <iostream>
#include <vector>
using namespace std;

int peakElement(vector<int> &arr)
{
    // code here
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    if (n == 1)
        return 0;
    while (start <= end)
    {
        // [6,5,4,3,2,3,2]
        int mid = start + (end - start) / 2;
        if (mid == 0)
        {
            if (n == 1 || arr[0] > arr[1])
                return 0;
            else
                return 1;
        }
        else if (mid == n - 1)
        {
            if (arr[n - 1] > arr[n - 2])
                return n - 1;
            else
                return n - 2;
        }
        else if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else if (arr[mid] < arr[mid - 1])
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 7, 8, 3};
    cout << peakElement(arr) << endl;
}