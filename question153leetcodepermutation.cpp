#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return nums[low];
}

int main()
{
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements of the rotated sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int minimum = findMin(nums);

    cout << "Minimum element is: " << minimum << endl;

    return 0;
}