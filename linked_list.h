#ifndef DS_LIB_List
#define DS_LIB_List

// List: Generic implementation of a doubly linked list.
// Made for learning purposes
// Author: Caio Guedes de Azevedo Mota

// List Node
// Contains data and pointers to previous and next nodes in list.
template <typename T>
class ListNode {
    private:
    T *_prev;
    T *_next;
    T _data;
    public:
    ListNode(T data);
    ~ListNode();

    // Getters
    T GetData();
    T *GetPrev();
    T *GetNext();
    // Setters
    void SetData(T data);
    void SetPrev(T *prev);
    void SetNext(T *next);
};

// Default constructor
template <typename T> ListNode<T>::ListNode(T data): _data(data), _prev(nullptr), _next(nullptr) {}
// Default destructor (this might not work as intended, check later)
template <typename T> ListNode<T>::~ListNode() {
    if(_prev != nullptr) delete _prev;
    if(_next != nullptr) delete _next;
}

// Getter definitions
template <typename T> T ListNode<T>::GetData() { return _data; }
template <typename T> T *ListNode<T>::GetPrev() { return _prev; }
template <typename T> T *ListNode<T>::GetNext() { return _next; }
// Setter definitions
template <typename T> void ListNode<T>::SetData(T data) { _data = data; }
template <typename T> void ListNode<T>::SetPrev(T *prev) { _prev = prev; }
template <typename T> void ListNode<T>::SetNext(T *next) { _next = next; }


// List
// Contains size, pointers to start and end of list as well as
// Insertion, access and search methods.
template <typename T>
class List {
    private:
    ListNode<T> *_start;
    ListNode<T> *_end;
    int _size;
    public:
    List();
    ~List();

    // Getters
    ListNode<T> *Start();
    ListNode<T> *End();
    int Size();
    // Setters
    void SetStart(ListNode<T> *start);
    void SetEnd(ListNode<T> *end);
    void SetSize(int size);

    // Methods to insert/remove elements
    // Insertion at beginning/end of list
    void PushBack(T data);
    void PushFront(T data);
    // Removal at beginning/end of list
    void PopBack();
    void PopFront();
    // Regular indexed insertion/deletion
    void Insert(T data, int index);
    void Remove(int index);
    // Checking if list is empty
    bool IsEmpty();
    // Clearing list
    void Clear();
    // Access operator
    T& operator[] (int i);
    // Search method (maybe it should be T*? check later)
    ListNode<T> *Search(T data);
};

// Default constructor
template <typename T> List<T>::List() : _start(nullptr), _end(nullptr), _size(0) {}
// Default destructor (this might not work as intended, check later)
template <typename T> List<T>::~List() { delete _start; }

// Getter definitions
template <typename T> ListNode<T> *List<T>::Start() { return _start; }
template <typename T> ListNode<T> *List<T>::End() { return _end; }
template <typename T> int List<T>::Size() { return _size; }
// Setter definitions
template <typename T> void List<T>::SetStart(ListNode<T> *start) { _start = start; }
template <typename T> void List<T>::SetEnd(ListNode<T> *end) { _end = end; }
template <typename T> void List<T>::SetSize(int size) { _size = size; }

// Insertion methods
// PushBack: inserts element at the end of the list
template <typename T> void List<T>::PushBack(T data) {
    ListNode<T> *node = new ListNode<T>(data);

    // If list is empty, simply set as end
    if(_end == nullptr) {
        _end = node;
    }
    // Else, set as next to end, then replace end for inserted node
    else {
        _end->SetNext(node);
        _end = node;
    }

    // In case this is the start of the list, set start as well
    if(_start == nullptr) {
        _start = node;
    }

    _size++;
}
// PushFront: inserts element at the start of the list
template <typename T> void List<T>::PushFront(T data) {
    ListNode<T> *node = new ListNode<T>(data);
    
    // If list is empty, simply set as start
    if(_start == nullptr) {
        _start = node;
    }
    // Else, set as previous to start, then replace start for inserted node
    else {
        _start->SetPrev(node);
        _start = node;
    }

    // In case this is the start of the list, set start as well
    if(_end == nullptr) {
        _end = node;
    }

    _size++;
}

template <typename T> void List<T>::PopBack() {
    // If there is only one element before removal, set new end to null and delete past end
    if(_end->GetPrev() == nullptr) {
        delete _end;
        _end = nullptr; // Do I really need this? Maybe delete does the job?
    }
    // Else, set new end to second to last element and delete past end
    else {
        ListNode<T> *end_prev = _end->GetPrev();
        delete _end;
        _end = end_prev;
    }

    _size--;
}

template <typename T> void List<T>::PopFront() {

    if(_start->GetNext() == nullptr) {
        delete _start;
        _start = nullptr; // Do I really need this? Maybe delete does the job?
    }
    else {
        ListNode<T> *start_next = _start->GetNext();
        delete _start;
        _start = start_next;
    }

    _size--;
}

#endif