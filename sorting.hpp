#ifndef sorting_hpp
#define sorting_hpp

#define MAX_SIZE 10
#define true 1
#define false 0

template <class LE>
class Sorting {
public:
    
    Sorting(LE *original); //Constructor
    ~Sorting();
    
    int insertion_sort(int n); //Insertion sort
    int quick_sort(int left, int right); //quick sort
    int merge_sort(int left, int right); //merge sort
    
    void copy_list(LE newList[], int n, int compare);
    void print_list(int left, int right);
    
private:
    void merge(LE keyList[], int left, int mid, int right); //merge
    int quickPartition(LE keyList[], int left, int right); //quick sort partition
    
    LE *list;
    int num_compare;
};

#endif /* sorting_hpp */
