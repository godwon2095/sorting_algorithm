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
    
    int insertion_sort(int n); //Insertion sort, compare»Ωºˆ π›»Ø
    int quick_sort(int left, int right); //quick sort, compare»Ωºˆ π›»Ø
    int merge_sort(int left, int right); //merge sort, compare»Ωºˆ π›»Ø
    
    void copy_list(LE newList[], int n, int compare); //list∏¶ ∫πªÁ, compare ∫Øºˆ¥¬ «◊ªÛ 0¿∏∑Œ √ ±‚»≠
    void print_list(int left, int right); //list∏¶ leftø°º≠ right±Ó¡ˆ∏∏ √‚∑¬
    
private:
    void merge(LE keyList[], int left, int mid, int right); //merge
    int quickPartition(LE keyList[], int left, int right); //quick sort partition
    
    LE *list; //¡§∑ƒ«“ µ•¿Ã≈Õ list
    int num_compare; //≈∞ ∞™ ∫Ò±≥»∏ºˆ ƒ´øÓ∆Æ∏¶ ¿ß«— ∫Øºˆ
};

#endif /* sorting_hpp */
