#include "sorting.hpp"
#include <iostream>

using namespace std;

template<class LE>
Sorting<LE>::Sorting(LE *original) {
    list = original;
    
    num_compare = 0;
}

template<class LE>
Sorting<LE>::~Sorting() {
    
}

template<class LE>
int Sorting<LE>::insertion_sort(int n) {
    for (int i = 1; i < MAX_SIZE; i++)
    {
        int tmp = list[i];

        for (int j = i - 1; j >= 0; j--)
        {
            if (tmp <= list[j])
            {
                list[j+1] = list[j];
                list[j] = tmp;
                num_compare++;
            }
            else
            {
                num_compare++;
                break;
            }
        }
    }
    
    return num_compare;
}


template<class LE>
int Sorting<LE>::quick_sort(int left, int right) {
    if (left < right) {
        int q = quickPartition(list,left, right);
        quick_sort(left, q - 1);
        quick_sort(q + 1, right);
    }
    
    return num_compare;
}


template<class LE>
int Sorting<LE>::merge_sort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(list, left, mid, right);
    }
    return num_compare;
}

template<class LE>
void Sorting<LE>::copy_list(LE newList[], int n, int compare) {
    num_compare = compare;
    
    for (int i = 0; i < MAX_SIZE; i++)
        list[i] = newList[i];
    
}

template<class LE>
void Sorting<LE>::print_list(int left, int right) {
    for (int i = left; i < right+1 ; i++)
        cout << "|" << list[i] << "|";
    cout << endl;
}

template<class LE>
void Sorting<LE>::merge(LE keyList[], int left, int mid, int right) {
    int i, j, k = left, l;
    
    static LE sorted[MAX_SIZE];

    for (i = left, j = mid + 1; i <= mid && j <= right; ) {
        sorted[k++] = (keyList[i] <= keyList[j]) ? keyList[i++] : keyList[j++];
        num_compare++;
    }

    if (i > mid)
        for (l = j; l <= right; l++, k++) {
            sorted[k] = keyList[l];
        }
    else
        for (l = i; l <= mid; l++, k++) {
            sorted[k] = keyList[l];
        }

    for (l = left; l <= right; l++) {
        keyList[l] = sorted[l];
    }
}

template<class LE>
int Sorting<LE>::quickPartition(LE keyList[], int left, int right) {
    int low = left;
    int high = right + 1;
    int pivot = keyList[left];
    do {
        
        do {
            low++;
            num_compare++;
        } while (low <= right && keyList[low] < pivot);
        do {
            num_compare++;
            high--;
        } while (high >= left && keyList[high] > pivot);
        if (low < high) {
            LE tmp = keyList[low];
            keyList[low] = keyList[high];
            keyList[high] = tmp;
        }
    } while (low < high);
    
    LE tmp = keyList[left];
    keyList[left] = keyList[high];
    keyList[high] = tmp;
    
    return high;
}
