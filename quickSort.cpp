#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
private:
  vector<int> nums;
public:
  Solution(vector<int> n): nums(n) {}

  void swap(int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }

  int partition(int left, int right, int pivot_index) {
    int pivot = nums[pivot_index];
    swap(right, pivot_index);
    int start_index = left;
    for (int i = left; i <= right; i++) {
      if (nums[i] < pivot) {
        swap(start_index, i);
        start_index++;
      }
    }
    swap(start_index, right);
    return start_index;
  }

  int quickSelect(int left, int right, int k) {
    if (left == right) {
      return nums[left];
    }
    int random_index = left + rand() % (right - left);
    random_index = partition(left, right, random_index);

    if (k == random_index) {
      return nums[k];
    } else if (k < random_index) {
      return quickSelect(left, random_index - 1, k);
    }
    return quickSelect(random_index + 1, right, k);
  }

  int findKthLargest(int k) {
    int len = nums.size();
    return quickSelect(0, len - 1, len - k);
  }
};

int main() {
  int n[] = {3, 2, 1, 5, 6, 4};
  vector<int> a(n, n + 6);
  Solution kLargest(a);
  int res = kLargest.findKthLargest(2);
  cout << res << endl;

  return 0;
}
