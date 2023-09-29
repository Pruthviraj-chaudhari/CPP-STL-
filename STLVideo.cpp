#include<bits/stdc++.h>
using namespace std;

// C++ STL
// 1. Algorithms
// 2. Containers
// 3. Functions
// 4. Iterators


// Pairs
void learnPairs(){
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;     // 1, 3

    pair<int , pair<int, int>> p1 = {1, {20, 30}};
    cout<< p1.first << endl;    // 1
    cout<< p1.second.first << endl;     // 20
    cout<< p1.second.second << endl;    // 30

    pair<int, int> arr[] = {{1,2}, {2,5}, {5,1}};

    cout<< arr[1].first << endl;    // 2
    cout<< arr[1].second << endl;   // 5
}


void learnVector(){

    // It is a Dynamic Array with contiguous memory

    vector<int> v;      // {}
    v.push_back(3);     // {3}
    v.emplace_back(4);  // {3,4}  faster one

    vector<pair<int, int>> vec;
    vec.push_back({2,4});
    vec.emplace_back(3,6);  // see the difference

    vector<int> temp(4);   // {0, 0, 0, 0}
    vector<int> nums(4, 100);   // {100, 100, 100, 100}
    vector<int> nums1(nums);   // {100, 100, 100, 100}  copy vectors
    
    // iterators

    v = {1,2,3,4,5,6};

    vector<int>::iterator it = v.begin();   // v.begin() stores the memory address of first element
    cout<< *(it) <<endl;    //1  *(it) to print value of address

    it++;
    cout<< *(it) <<endl;    //2

    it = it + 2;
    cout<< *(it) <<endl;    //4

    vector<int>::iterator it2 = v.end();    // points at last+1, need to do it2--
    vector<int>::iterator it3 = v.rbegin();     // points at last element and works in reverse way

    cout<< v.back() << endl;     // 6 --> print last element


    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout<< *(it) << " ";
    }

    for(auto it = v.begin(); it != v.end(); it++){
        cout<< *(it) << " ";
    }

    for(int nums: temp){
        cout << nums << " ";
    }

    v = {10,20,12,23,35};

    // Delete
    v.erase(v.begin());     // {20, 12, 23 35}
    v.erase(v.begin(), v.begin()+2);    // {23, 35}  (start, end+1)

    // Insert (position, value)
    v.insert(v.begin(), 300);   // {300, 23, 35}

    // Insert (position, NoOfTimes, value)
    v.insert(v.begin(), 3, 400);    // {400, 400, 400, 300, 23, 35}

    // Insert vector into another vector
    vector<int> temp = {1,2};
    temp.insert(temp.begin(), v.begin(), v.end());  // {400, 400, 400, 300, 23, 35, 1, 2}


    temp.pop_back();   // {400, 400, 400, 300, 23, 35, 1}
    temp.pop_back();   // {400, 400, 400, 300, 23, 35}

    temp.size();  // --> size
    temp.empty(); // --> True or False
    temp.clear(); // --> clear all elements and empty the vector.
}


void learnList(){
    list<int> ls;

    ls.push_back(2);        // {2}
    ls.emplace_back(3);     // {2,3}

    ls.push_front(1);       // {1,2,3}
    ls.emplace_front(0);    // {0,1,2,3}

    // All functions same as vector
    // begin, end, ebegin, rend, clear, insert, size, swap
    for(auto i: ls){
        cout<< i << endl;
    }
}


void learnDeque() {
    deque<int> dq;

    dq.push_back(1);
    dq.emplace_back(3);
    dq.push_front(2);
    dq.emplace_front(4);

    dq.pop_back();
    dq.pop_front();

    dq.back();
    dq.front();
}


void learnStack() {
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.emplace(5);

    cout<< st.top() << endl;

    st.pop();

    cout << st.top() << endl;

    cout << st.size() << endl;

    cout << st.empty() << endl;

    stack<int> st1, st2;
    st1.swap(st2);
}


void learnQueue() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(4);

    q.back() += 5;  // 4 + 5 = 9 (new back)

    // [1, 2, 9]
    cout<< q.back() << endl;
    cout<< q.front() << endl;

    q.pop();  // [2, 9]
    cout<< q.front() << endl;

}

// Priority_queue --> Largest element stays at the Top (largest char, int or String lexicographically)
void learnPriorityQueue() {

    // Max Heap
    priority_queue<int> pq;
    pq.push(1);     // [1]
    pq.push(4);     // [1,4]
    pq.push(7);     // [1,4,7]
    pq.push(9);     // [1,4,7,9]
    pq.push(2);     // [1,2,4,7,9]
    cout<< pq.top() << endl;

    // Min Heap --> minimum element at top
    priority_queue<int, vector<int>, greater<int>> mpq;
    mpq.push(1);     // [1]
    mpq.push(4);     // [4,1]
    mpq.push(7);     // [7,4,1]
    mpq.push(9);     // [9,7,4,1]
    mpq.push(2);     // [9,7,4,2,1]
    cout<< mpq.top() << endl;

    // Time complexity
    // push --> log(n)
    // top  --> O(1)
    // pop  --> log(n)
}


// SET --> Sorted & Unique
void learnSet() {
    set<int> st;

    st.insert(1);
    st.insert(4);
    st.insert(4);
    st.emplace(3);
    st.emplace(5);

    // if present returns Iterator pointing to location
    auto it1 = st.find(3);

    // if not present returns Iterator pointing to st.end()
    auto it2 = st.find(10);

    st.erase(5);    // delete 5

    int count = st.count(3);    // present 1 or not O

    // Time Complexity  --> log(n) for all operations


    // unordered_set() ust;
    // Time Complexity  --> O(1) for all operations
    // Once in worst case --> O(n)
}


void learnMap() {
    map<int, int> mpp;

    map<int, pair<int, int>> mpp1;

    map<pair<int,int>, int> mpp2;

    mpp[1] = 2;             // {1,2}
    mpp.insert({3,6});      // {3,6}
    mpp.emplace(2,4);       // {2,4}   
    // Map stores unique keys in sorted order


    for(auto it: mpp){
        cout<< it.first << " " << it.second << endl;
    }

    // cout<< mpp[0] <<endl;  // 0 not present
    // cout<< mpp[1] <<endl;  // 2 
    // cout<< mpp[5] <<endl;  // 0 not present


    // find value in map
    auto it = mpp.find(6);
    cout<< (*(it)).second << endl;
}


bool descComparator(int a, int b){
    if(a>b) return true;
    if(a<b) return false;
}

bool myComp(pair<int,int> p1, pair<int,int> p2) {
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;

    // if they same
    if(p1.first > p2.first) return true;
    return false;
}

void learnAlgorithms() {
    int arr[] = {5,6,3,4,1};

    // Sort Asscending
    sort(arr, arr + 5);     // [1,3,4,5,6]

    // Sort Descending
    sort(arr, arr+5, descComparator);   // [6,5,4,3,1]

    // Sort in given range
    sort(arr+2, arr+5);     // [5,6,1,3,4]

    vector<int> v = {5,6,3,4,1};
    sort(v.begin(), v.end());


    pair<int, int> a[] = {{1,2}, {2,1}, {4,1}};
    // Make Own Way to Sort
    // sort it according to second element
    // if second elements are same, then
    // sort it according to first element but in descending
    sort(a, a+4, myComp);


    int num = 7;
    int count = __builtin_popcount(num);    // count number of 1 in binary i.e. setBits
    cout << count << endl;

    int max = *max_element(arr, arr+5);     // max element in array
    cout<< max << endl;
}

int main() {
    learnAlgorithms();
}

