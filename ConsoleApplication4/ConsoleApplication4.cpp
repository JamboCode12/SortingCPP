#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Sort
{
public:
	int swapCount = 0;
	int iterationwapCount = 0;

	void getArray(vector<int>& userArrayElements, int& userArrayLength)
	{
		cout << "What is the size of your array? ";
		cin >> userArrayLength;
		cout << "Enter your array" << endl;
		for (int i = 0; i < userArrayLength; ++i)
		{
			int element;
			cout << "Element " << i + 1 << ": ";
			cin >> element;
			userArrayElements.push_back(element);
		}
	}

	void BubbleSortAscending(int arrayLength, int arrayElements[])
	{
		int iteration = 0;
		int totalSwaps = 0; // Counter for total swaps

		for (int i = 0; i < arrayLength; i++)
		{
			bool swapped = false;

			for (int j = 0; j < arrayLength - 1; j++)
			{
				if (arrayElements[j] > arrayElements[j + 1])
				{
					// Swap algo for arrayElements[j] and arrayElements[j+1]
					int temp = arrayElements[j];
					arrayElements[j] = arrayElements[j + 1];
					arrayElements[j + 1] = temp;

					swapped = true;
					totalSwaps++; // Increment the counter each time a swap occurs

					// Print the array after a swap
					cout << "Swap " << totalSwaps << " in iteration " << iteration + 1 << ": ";
					for (int k = 0; k < arrayLength; k++)
					{
						cout << arrayElements[k] << " ";
					}
					cout << endl;
				}
			}

			iteration++;

			// If no swaps occurred, the array is already sorted
			if (!swapped)
			{
				cout << "Array is already sorted. Exiting early." << endl;
				break;
			}
		}
		cout << "Total iteration: " << iteration << endl;
		cout << "Total swaps (steps): " << totalSwaps << endl; // Print the total number of swaps
	}
	void BubbleSortDescending(int arrayLength, int arrayElements[])
	{
		int iteration = 0;
		int totalSwaps = 0; // Counter for total swaps

		for (int i = 0; i < arrayLength; i++)
		{
			bool swapped = false;

			for (int j = 0; j < arrayLength - 1; j++)
			{
				if (arrayElements[j] < arrayElements[j + 1])
				{
					// Swap algo for arrayElements[j] and arrayElements[j+1]
					int temp = arrayElements[j];
					arrayElements[j] = arrayElements[j + 1];
					arrayElements[j + 1] = temp;

					swapped = true;
					totalSwaps++; // Increment the counter each time a swap occurs

					// Print the array after a swap
					cout << "Swap " << totalSwaps << " in iteration " << iteration + 1 << ": ";
					for (int k = 0; k < arrayLength; k++)
					{
						cout << arrayElements[k] << " ";
					}
					cout << endl;
				}
			}

			iteration++;

			// If no swaps occurred, the array is already sorted
			if (!swapped)
			{
				cout << "Array is already sorted. Exiting early." << endl;
				break;
			}
		}
		cout << "Total iteration: " << iteration << endl;
		cout << "Total swaps (steps): " << totalSwaps << endl; // Print the total number of swaps
	}

	void SelectionSortAscending(int arrayLength, int arrayElements[])
	{
		int iteration = 0;
		int totalSwaps = 0;		 // Counter for total swaps
		int minIndexChanges = 0; // Counter for minimum index changes

		for (int i = 0; i < arrayLength - 1; i++)
		{
			int minPosition = i;
			for (int j = i + 1; j < arrayLength; j++)
			{
				if (arrayElements[j] < arrayElements[minPosition])
				{
					minPosition = j;
					minIndexChanges++; // Increment the counter each time the minimum index changes
				}
			}

			if (minPosition != i)
			{
				int temp = arrayElements[i];
				arrayElements[i] = arrayElements[minPosition];
				arrayElements[minPosition] = temp;

				totalSwaps++; // Increment the counter each time a swap occurs

				// Print the array after a swap
				cout << "Swap " << totalSwaps << " in iteration " << iteration + 1 << ": ";
				for (int k = 0; k < arrayLength; k++)
				{
					cout << arrayElements[k] << " ";
				}
				cout << endl;
			}

			iteration++;
		}
		cout << "Total iteration: " << iteration << endl;
		cout << "Total swaps (steps): " << totalSwaps << endl;				// Print the total number of swaps
		cout << "Total minimum index changes: " << minIndexChanges << endl; // Print the total number of minimum index changes
	}
	void SelectionSortDescending(int arrayLength, int arrayElements[])
	{
		int iteration = 0;
		int totalSwaps = 0;		 // Counter for total swaps
		int maxIndexChanges = 0; // Counter for maximum index changes

		for (int i = 0; i < arrayLength - 1; i++)
		{
			int maxPosition = i;
			for (int j = i + 1; j < arrayLength; j++)
			{
				if (arrayElements[j] > arrayElements[maxPosition])
				{
					maxPosition = j;
					maxIndexChanges++; // Increment the counter each time the maximum index changes
				}
			}

			if (maxPosition != i)
			{
				int temp = arrayElements[i];
				arrayElements[i] = arrayElements[maxPosition];
				arrayElements[maxPosition] = temp;

				totalSwaps++; // Increment the counter each time a swap occurs

				// Print the array after a swap
				cout << "Swap " << totalSwaps << " in iteration " << iteration + 1 << ": ";
				for (int k = 0; k < arrayLength; k++)
				{
					cout << arrayElements[k] << " ";
				}
				cout << endl;
			}

			iteration++;
		}
		cout << "Total iteration: " << iteration << endl;
		cout << "Total swaps (steps): " << totalSwaps << endl;				// Print the total number of swaps
		cout << "Total maximum index changes: " << maxIndexChanges << endl; // Print the total number of maximum index changes
	}

	void heapify(int arr[], int n, int i, int& iteration, int& steps) {
		int largest = i; // Initialize largest as root
		int left = 2 * i + 1; // Left child
		int right = 2 * i + 2; // Right child

		// If left child is larger than root
		if (left < n && arr[left] > arr[largest]) {
			largest = left;
		}

		// If right child is larger than largest so far
		if (right < n && arr[right] > arr[largest]) {
			largest = right;
		}

		// If largest is not root
		if (largest != i) {
			swap(arr[i], arr[largest]);
			steps++;
			iteration++;

			// Recursively heapify the affected sub-tree
			heapify(arr, n, largest, iteration, steps);
		}
	}


	// Main function to perform heap sort
	void HeapSortDescending(int n, int arr[]) {
		int iteration = 0;
		int steps = 0;

		// Build heap (rearrange array)
		for (int i = n / 2 - 1; i >= 0; i--) {
			heapify(arr, n, i, iteration, steps);
		}

		// One by one extract an element from heap
		for (int i = n - 1; i > 0; i--) {
			// Move current root to end
			swap(arr[0], arr[i]);
			steps++;
			iteration++;

			// call max heapify on the reduced heap
			heapify(arr, i, 0, iteration, steps);
		}

		// Print the sorted array in descending order
		cout << "Sorted array in descending order: ";
		for (int i = n - 1; i >= 0; i--) {
			cout << arr[i] << " ";
		}
		cout << endl;

		cout << "Total iteration: " << n - 1 << endl;
		cout << "Total steps: " << steps << endl;
	}


};

int main()
{
	int userResponseForSortType;
	int userResponseForOperationRepeat;
	int userArrayLength;
	int userResponseForPattern;
	vector<int> userArrayElements;
	bool invalidInput = false;
	bool invalidInputForPattern = false;
	Sort sorter;
	do
	{
		invalidInput = false;
		cout << "Menu!" << endl;
		cout << "[1] Merge Sort" << endl;
		cout << "[2] Bubble Sort" << endl;
		cout << "[3] Selection Sort" << endl;
		cout << "[4] Heap Sort\n" << endl;
		cout << "What type of sorting would you use?" << endl;

		do
		{
			invalidInputForPattern = false;
			cin >> userResponseForSortType;
			switch (userResponseForSortType)
			{
			case 1:
				cout << "You have selected Merge Sort." << endl;
				sorter.getArray(userArrayElements, userArrayLength);
				do
				{
					cout << "[1] Ascending Pattern" << endl;
					cout << "[2] Descending Patter" << endl;
					cout << "Select Sorting Arrangement:";
					cin >> userResponseForPattern;

					switch (userResponseForPattern)
					{
					case 1:
						break;

					case 2:
						break;

					default:
						cout << "Invalid Input. Try Again" << endl;
						invalidInputForPattern = true;
						break;
					}
				} while (invalidInputForPattern);
				break;

			case 2:
				cout << "You have selected Bubble Sort." << endl;
				sorter.getArray(userArrayElements, userArrayLength);
				do
				{
					cout << "[1] Ascending Pattern" << endl;
					cout << "[2] Descending Patter" << endl;
					cout << "Select Sorting Arrangement:";
					cin >> userResponseForPattern;

					switch (userResponseForPattern)
					{
					case 1:
						sorter.BubbleSortAscending(userArrayLength, userArrayElements.data());
						break;

					case 2:
						sorter.BubbleSortDescending(userArrayLength, userArrayElements.data());
						break;

					default:
						cout << "Invalid Input. Try Again" << endl;
						invalidInputForPattern = true;
						break;
					}
				} while (invalidInputForPattern);
				break;

			case 3:
				cout << "You have selected Selection Sort." << endl;
				sorter.getArray(userArrayElements, userArrayLength);
				do
				{
					cout << "[1] Ascending Pattern" << endl;
					cout << "[2] Descending Patter" << endl;
					cout << "Select Sorting Arrangement:";
					cin >> userResponseForPattern;

					switch (userResponseForPattern)
					{
					case 1:
						sorter.SelectionSortAscending(userArrayLength, userArrayElements.data());
						break;

					case 2:
						sorter.SelectionSortDescending(userArrayLength, userArrayElements.data());
						break;

					default:
						cout << "Invalid Input. Try Again" << endl;
						invalidInputForPattern = true;
						break;
					}
				} while (invalidInputForPattern);
				break;

			case 4:
				cout << "You have selected Heap Sort." << endl;
				sorter.getArray(userArrayElements, userArrayLength);
				do
				{
					cout << "[1] Ascending Pattern" << endl;
					cout << "[2] Descending Patter" << endl;
					cout << "Select Sorting Arrangement:";
					cin >> userResponseForPattern;

					switch (userResponseForPattern)
					{
					case 1:

						break;

					case 2:
						sorter.HeapSortDescending(userArrayLength, userArrayElements.data());
						break;

					default:
						cout << "Invalid Input. Try Again" << endl;
						invalidInputForPattern = true;
						break;
					}
				} while (invalidInputForPattern);
				break;

			default:
				cout << "Input Error. Try Again" << endl;
				invalidInput = true;
				break;
			}
		} while (invalidInput);
		if (!invalidInput)
		{
			cout << "Do you want to try again? (1 for Yes, 0 for No)" << endl;
			cin >> userResponseForOperationRepeat;
		}
	} while (userResponseForOperationRepeat == 1);
	return 0;
}