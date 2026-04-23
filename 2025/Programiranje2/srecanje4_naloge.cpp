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
#include <random>
#include <chrono>

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

class HybridMergeSorter
{
private:
    int threshold;
    
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

        while (indexLeft < leftHalf.size())
        {
            v[indexMerged] = leftHalf[indexLeft];
            indexLeft++;
            indexMerged++;
        }

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
            int size = right - left + 1;
            if (size <= threshold)
            {
                insertionSort(v, left, right);
                return;
            }
            
            int mid = left + (right - left) / 2;
            
            mergeSortHelper(v, left, mid);
            mergeSortHelper(v, mid + 1, right);
            
            merge(v, left, mid, right);
        }
    }

public:
    HybridMergeSorter(int thresh = 10) : threshold(thresh) {}
    
    void MergeSort(std::vector<int>& v)
    {
        if (v.size() <= 1)
            return; 
        
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
    /*
    vector<int> numbers = { 44, 80, 10, 10, 82, 86, 32, 44, 66, 36, 5, 9, 98, 41, 91, 73, 53, 96, 48 };
    
    cout << "Original: ";
    printOut(numbers);
    
    HybridMergeSorter sorter1(-1);
    vector<int> copy1 = numbers;
    sorter1.MergeSort(copy1);
    cout << "Sortirano I  : ";
    printOut(copy1);
    
    HybridMergeSorter sorter2(5);
    vector<int> copy2 = numbers;
    sorter2.MergeSort(copy2);
    cout << "Sortirano II : ";
    printOut(copy2);
    */

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100000);

    std::vector<int> vector_size = { 1000, 10000, 100000, 1000000 };
    std::vector<int> threshold_size = { -1, 50, 100, 200, 300, 500 };


    for (size_t i = 0; i < vector_size.size(); i++)
    {
        int n = vector_size[i];
        vector<int> numbers(n);
        for (int i = 0; i < n; ++i) {
            int randomNumber = dis(gen);
            numbers[i] = randomNumber;
        }

        for (size_t j = 0; j < threshold_size.size(); j++)
        {
			int threshold = threshold_size[j];

            auto chronoStart = std::chrono::high_resolution_clock::now();
            HybridMergeSorter sorter1(threshold);
            vector<int> copy1 = numbers;
            sorter1.MergeSort(copy1);
            auto chronoEnd = std::chrono::high_resolution_clock::now();

            auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(chronoEnd - chronoStart).count();
            cout << "Sort z velikostjo [" << n << "] in mejo sortiranja [" << threshold << "] se izvaja [" << ms << "] ms" << endl;
        }
    }
}

#endif