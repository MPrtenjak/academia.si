#include "constants.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#endif

using namespace std;

#ifdef RESITEV_SRECANJE_4_NALOGA_5

void insert(vector<int>& v, int e)
{
	if (v.empty()) {
		v.push_back(e);
		return;
	}

    int left = 0;
    int right = v.size() - 1;
    int insertPos = v.size();

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (v[mid] == e) {
            insertPos = mid;
            break;
        }
        else if (v[mid] < e) {
            left = mid + 1;
        }
        else { // v[mid] > e
            insertPos = mid;
            right = mid - 1;
        }
    }

    v.insert(v.begin() + insertPos, e);
}

void printOut(vector<int>& v)
{
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
        cout << *i << ", ";

    cout << endl;
}

int main()
{
    vector<int> numbers = { 44, 80, 10, 10, 82, 86, 32, 44, 66, 36, 5, 9, 98, 41, 91, 73, 53, 96, 48 };
    vector<int> sort;

    for (vector<int>::iterator i = numbers.begin(); i != numbers.end(); ++i)
    {
        cout << "Dodajam element: " << *i << endl;
        insert(sort, *i);
        cout << "Trenuten izgled vektorja ";
        printOut(sort);
        cout << endl << endl;
    }
}


#endif

#ifdef RESITEV_SRECANJE_4_NALOGA_6

void InsertionSort(std::vector<int>& v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int key = v[i];
        int j = i - 1;
        
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = key;
    }
}

void printOut(vector<int>& v)
{
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
        cout << *i << ", ";

    cout << endl;
}
int main()
{
    vector<int> numbers = { 44, 80, 10, 10, 82, 86, 32, 44, 66, 36, 5, 9, 98, 41, 91, 73, 53, 96, 48 };
    printOut(numbers);

    InsertionSort(numbers);
    printOut(numbers);
}
#endif

#ifdef RESITEV_SRECANJE_4_NALOGA_7

class MergeSorter
{
private:
    void merge(std::vector<int>& v, int left, int mid, int right)
    {
        std::vector<int> leftHalf;
        std::vector<int> rightHalf;
        
        for (int i = left; i <= mid; i++)
        {
            leftHalf.push_back(v[i]);
        }
        
        for (int i = mid + 1; i <= right; i++)
        {
            rightHalf.push_back(v[i]);
        }
        
        int indexLeft = 0;
        int indexRight = 0; 
        int indexMerged = left; 
        
        while (indexLeft < leftHalf.size() && indexRight < rightHalf.size())
        {
            if (leftHalf[indexLeft] <= rightHalf[indexRight])
            {
                v[indexMerged] = leftHalf[indexLeft];
                indexLeft++;
            }
            else
            {
                v[indexMerged] = rightHalf[indexRight];
                indexRight++;
            }
            indexMerged++;
        }
        
        // Copy remaining elements from leftHalf (if any)
        while (indexLeft < leftHalf.size())
        {
            v[indexMerged] = leftHalf[indexLeft];
            indexLeft++;
            indexMerged++;
        }
        
        // Copy remaining elements from rightHalf (if any)
        while (indexRight < rightHalf.size())
        {
            v[indexMerged] = rightHalf[indexRight];
            indexRight++;
            indexMerged++;
        }
    }
    
    void mergeSortHelper(std::vector<int>& v, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
           
            mergeSortHelper(v, left, mid);
            mergeSortHelper(v, mid + 1, right);
            
            merge(v, left, mid, right);
        }
    }

public:
    void MergeSort(std::vector<int>& v)
    {
        if (v.size() <= 1)
            return;
        
        mergeSortHelper(v, 0, v.size() - 1);
    }
};

// Hybrid MergeSort with InsertionSort for small subarrays
class HybridMergeSorter
{
private:
    int threshold;
    
    // InsertionSort for small subarrays
    void insertionSort(std::vector<int>& v, int left, int right)
    {
        for (int i = left + 1; i <= right; i++)
        {
            int key = v[i];
            int j = i - 1;
            
            while (j >= left && v[j] > key)
            {
                v[j + 1] = v[j];
                j--;
            }
            
            v[j + 1] = key;
        }
    }
    
    // Helper function to merge two sorted halves
    void merge(std::vector<int>& v, int left, int mid, int right)
    {
        // Create temporary vectors for left and right halves
        std::vector<int> leftHalf;
        std::vector<int> rightHalf;
        
        // Copy data to temporary left half
        for (int i = left; i <= mid; i++)
        {
            leftHalf.push_back(v[i]);
        }
        
        // Copy data to temporary right half
        for (int i = mid + 1; i <= right; i++)
        {
            rightHalf.push_back(v[i]);
        }
        
        // Merge the temporary vectors back into v[left..right]
        int i = 0; // Index for leftHalf
        int j = 0; // Index for rightHalf
        int k = left; // Index for merged vector
        
        while (i < leftHalf.size() && j < rightHalf.size())
        {
            if (leftHalf[i] <= rightHalf[j])
            {
                v[k] = leftHalf[i];
                i++;
            }
            else
            {
                v[k] = rightHalf[j];
                j++;
            }
            k++;
        }
        
        // Copy remaining elements from leftHalf (if any)
        while (i < leftHalf.size())
        {
            v[k] = leftHalf[i];
            i++;
            k++;
        }
        
        // Copy remaining elements from rightHalf (if any)
        while (j < rightHalf.size())
        {
            v[k] = rightHalf[j];
            j++;
            k++;
        }
    }
    
    // Helper function to recursively divide and sort
    void mergeSortHelper(std::vector<int>& v, int left, int right)
    {
        if (left < right)
        {
            // If the subarray size is below threshold, use InsertionSort
            int size = right - left + 1;
            if (size <= threshold)
            {
                insertionSort(v, left, right);
                return;
            }
            
            // Find the middle point
            int mid = left + (right - left) / 2;
            
            // Sort first half
            mergeSortHelper(v, left, mid);
            
            // Sort second half
            mergeSortHelper(v, mid + 1, right);
            
            // Merge the sorted halves
            merge(v, left, mid, right);
        }
    }

public:
    // Constructor with threshold parameter (default is 10)
    HybridMergeSorter(int thresh = 10) : threshold(thresh) {}
    
    // Public function to sort the vector
    void MergeSort(std::vector<int>& v)
    {
        if (v.size() <= 1)
        {
            return; // Already sorted
        }
        
        mergeSortHelper(v, 0, v.size() - 1);
    }
};

void printOut(vector<int>& v)
{
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
        cout << *i << ", ";

    cout << endl;
}

int main()
{
    vector<int> numbers = { 44, 80, 10, 10, 82, 86, 32, 44, 66, 36, 5, 9, 98, 41, 91, 73, 53, 96, 48 };
    
    cout << "Original: ";
    printOut(numbers);
    
    // Test basic MergeSort
    MergeSorter sorter1;
    vector<int> copy1 = numbers;
    sorter1.MergeSort(copy1);
    cout << "Basic MergeSort: ";
    printOut(copy1);
    
    // Test hybrid MergeSort with threshold of 5
    HybridMergeSorter sorter2(5);
    vector<int> copy2 = numbers;
    sorter2.MergeSort(copy2);
    cout << "Hybrid MergeSort (threshold=5): ";
    printOut(copy2);
}

#endif