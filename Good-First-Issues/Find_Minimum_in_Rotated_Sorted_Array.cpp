#include <iostream>
#include <vector>

using namespace std;

int find_minimum_element(vector<int>& numbers) {
    // If the list empty return error
	if (numbers.empty()) return -1;

    // If the list has just one element then return that element.
	if (numbers.size() == 1) return numbers[0];

    // initializing left and right pointers.
	int left = 0, right = numbers.size()-1;

	// Binary search way
	while (left < right) {
        // Find the mid element
		int mid = (left + right) / 2;

        // If numbers[0] is greater than the mid value then this means the smallest value is somewhere to
        // the left
		if (numbers[0] > numbers[mid])
			right = mid;
		else
            // If the mid elements value is greater than the 0th element this means
            // the least value is still somewhere to the right as we are still dealing with elements
            // greater than numbers[0]
			left = mid + 1;
	}

    // If numbers[0] is the smallest element then the result of binary will wrong,
    // so we must check with the numbers[0]
	if (numbers[0] < numbers[left]) return numbers[0];

	return numbers[left];
}

// Test and print result function
int test(vector<int>& numbers) {
    cout << "Input: nums = [";
    for (auto index = 0; index < numbers.size(); ++index) {
        if (index < numbers.size() - 1) cout << numbers[index] << ", ";
        else cout << numbers[index];
    }
    cout << "]\nOutput: ";
    cout << find_minimum_element(numbers) << endl;
    cout << endl;
}

int main() {
    vector<int> testing_array;

    // Test 01
    testing_array = {1, 2, 3, 4, 5};
    test(testing_array);

    // Test 02
    testing_array = {3, 4, 5, 1, 2};
    test(testing_array);

    // Test 03
    testing_array = {4, 5, 6, 7, 0, 1, 2};
    test(testing_array);

    return 0;
}
