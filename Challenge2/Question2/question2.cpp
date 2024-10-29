#include <iostream>
#include <vector>

int findMissingNumber(const std::vector<int>& arr) {
    int n = arr.size(); // Size of the array
    int expectedSum = (n + 1) * (n + 2) / 2; // Sum from 1 to n+1
    int actualSum = 0;

    // Calculate the sum of elements in the array
    for (int num : arr) {
        actualSum += num;
    }

    // The missing number is the difference
    return expectedSum - actualSum;
}

int main() {
    std::vector<int> arr = {2,1,3,5,6,8,7}; // Example array with missing number 3
    int missingNumber = findMissingNumber(arr);
    std::cout << "The missing number is: " << missingNumber << std::endl;

    return 0;
}
