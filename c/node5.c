	#include <stdio.h>  
	  
	void countingSort(int arr[], int size) {  
	    int max = arr[0];  
	    int min = arr[0];  
	  
	    // Find the maximum and minimum values in the input array  
	    for (int i = 1; i < size; i++) {  
	        if (arr[i] > max) max = arr[i];  
	        if (arr[i] < min) min = arr[i];  
	    }  
	  
	    int range = max - min + 1;  
	  
	    // Create and initialize the counting array  
	    int countingArray[range];  
	    for (int i = 0; i < range; i++) {  
	        countingArray[i] = 0;  
	    }  
	  
	    // Count occurrences of each element in the input array  
	    for (int i = 0; i < size; i++) {  
	        countingArray[arr[i] - min]++;  
	    }  
	  
	    // Update the counting array to store cumulative counts  
	    for (int i = 1; i < range; i++) {  
	        countingArray[i] += countingArray[i - 1];  
	    }  
	  
	    // Create the output array  
	    int output[size];  
	  
	    // Reconstruct the sorted output  
	    for (int i = size - 1; i >= 0; i--) {  
	        output[countingArray[arr[i] - min] - 1] = arr[i];  
	        countingArray[arr[i] - min]--;  
	    }  
	  
	    // Copy the sorted output back to the original array  
	    for (int i = 0; i < size; i++) {  
	        arr[i] = output[i];  
	    }  
	}  
	  
	int main() {  
	    int arr[] = {4, 2, 2, 8, 3, 3, 1};  
	    int size = sizeof(arr) / sizeof(arr[0]);  
	  
	    countingSort(arr, size);  
	  
	    printf("Sorted array: ");  
	    for (int i = 0; i < size; i++) {  
	        printf("%d ", arr[i]);  
	    }  
	  
	    return 0;  
	} 
