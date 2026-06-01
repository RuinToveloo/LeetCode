class Solution {
public:

    int removeFront(vector<int> &arr) {
        int n = arr.size();
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                return i + 1;
            }
        }
        return 0;
    }

    int removeBack(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i + 1 < n; i++) {
            if (arr[i] > arr[i + 1]) {
                return n - i - 1;
            }
        }
        return 0;
    }

    int removeMid(vector<int> &arr) {
        int n = arr.size();

        // 找右边最长非递减后缀的起点
        int j = n - 1;
        while (j > 0 && arr[j - 1] <= arr[j]) {
            j--;
        }

        int i = 0;
        int ans = INT_MAX;

        // i 只在左边非递减前缀里面走
        while (i == 0 || (i < n && arr[i] >= arr[i - 1])) {

            // 找到第一个可以和 arr[i] 接上的右边位置
            while (j < n && arr[i] > arr[j]) {
                j++;
            }

            // 如果 j < n，说明 arr[i] <= arr[j]，可以拼接
            if (j < n) {
                ans = min(ans, j - i - 1);
            }

            i++;

            // 防止 i 越界
            if (i >= n) break;
        }

        return ans;
    }

    int findLengthOfShortestSubarray(vector<int>& arr) {
        if (arr.size() == 1) return 0;

        bool sorted = true;
        int n = arr.size();

        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                sorted = false;
                break;
            }
        }

        if (sorted) return 0;

        int num1 = removeFront(arr); // 删除前面
        int num3 = removeBack(arr);  // 删除后面
        int num2 = removeMid(arr);   // 删除中间

        return min(num1, min(num2, num3));
    }
};