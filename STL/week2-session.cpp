// Created by Saeed
// at 5 Mar 2023

#include <bits/stdc++.h>
using namespace std;

/////////////////// Class & Struct ///////////////////
/*
 * public & private
 * attributes & functions (methods)
 */

class myClass {
public:
    int x, y;
    float f;
};

struct myStruct {
    int x, y;
private:
    int pr;
};

void class_test() {
    myClass s;
    s.x = 5;

    myStruct str;
    str.y = 10;
    //str.pr; // can't access private item
}

/////////////////// vector & array ///////////////////
/*
 * declaration & initialization
 *  - vector<object>
 *  - generics, what and why?
 * functions & complexities
 *
 * array => I don't recommend
 *
 * problem
 */

vector<int> global;

void print(vector<int>& vec) {
    for (auto& i : vec) // 1 2 3 4 5
        cout << i << ' ';
    cout << endl;
}
void test_vector() {
    int n = 10;
    vector<int> vec(n, 10);
    print(vec);

    vector<myStruct> structs;
    for (int i = 1; i <= 10; ++i) {
        myStruct tmp;
        tmp.x = i, tmp.y = 0;
        structs.push_back(tmp); // O(1)
    }

    cout << structs.max_size() << endl;

    sort(vec.begin(), vec.end()); // O(n logn)
    // begin => pointer to first item
    // end => pointer to last item
    // 10 10 10 10 10 end

    vector<myStruct>::iterator iter = structs.begin();
    structs.erase(iter); // O(n)
    advance(iter, 3);

    structs.erase(structs.begin(), iter);

    vector<int> vec2 = {1, 2, 3, 4, 5};
    while (!vec2.empty()) {
        cout << vec2.back() << ' '; // O(1)
        vec2.pop_back(); // O(1)
    }

    vec2.push_back(10), vec2.push_back(3);
    //cout << vec2.at(2); // exception

    int nn = vec2.size(); // O(1)

    cin >> nn;
    global.resize(nn); // O(n)

    vec2.swap(vec); // vec2 = vec
    // O(n)
}

void array_test() {
    array<int, 7> arr;
    arr[0] = 3;
    arr[1] = 2;

    cout << arr.front() << ' ' << arr.back() << endl;
}

/////////////////// stack ///////////////////
// balanced brackets example
// problem

void stack_test() {
    stack<int> stk;
    stk.push(3); // 3
    stk.push(7); // 7 3
    stk.push(-1); // -1 7 3

    cout << stk.top() << endl;

    while (!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    } // -1 7 3

    cout << stk.size() << endl; // 0
}

/////////////////// queue ///////////////////
/*
 * declaration
 * functions
 * problem
 */
// stack vs queue => reverse properity

void queue_test() {
    queue<char> q;
    q.push('a'); // a
    q.push('x'); // a x
    q.push('y'); // a x y
    q.push('z'); // a x y z

    stack<char> stk;

    while (!q.empty()) {
        stk.push(q.front()); // z y x a
        q.pop();
    }
}

/////////////////// priority_queue ///////////////////
/*
 * declare
 *  - max heap => default
 *  - min heap
 * functions
 * problem
 */

void priority_queue_test() {
    priority_queue<int> pq; // by default => max heap
    priority_queue<int, vector<int>, greater<> > pq_min; // min heap

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int tmp; cin >> tmp;
        pq.push(tmp);
    }
}

/////////////////// deque ///////////////////
/*
 * declaration
 * functions
 * problem
 */

void deque_test() {
    deque<int> deq = {5};
    deq.push_back(7);
    deq.push_front(3); // 3 5 7

    for (int i = 0; i < deq.size(); ++i) {
        cout << deq[i] << ' ';
    }
    cout << endl;

    while (!deq.empty()) {
        cout << deq.back() << ' ';
        deq.pop_back();
    }
}

/////////////////// tuple ///////////////////
/*
 * declaration
 *  - order of arguments
 * functions
 */

void tuple_test() {
    tuple<string, int, bool> t = make_tuple("saeed", 19, false);
}

int main()
{
    //test_vector();

    //stack_test();

    //queue_test();

    //priority_queue_test();

    deque_test();

    return 0;
}