#include <iostream>
#include <list>

using namespace std;

/*
 * implemented as doubly linked list
 * slower traversal then vector, but faster insertion and deletion
 */

void print(list<int>& lst) {
    auto it = lst.begin();
    for (; it != lst.end(); ++it)
        cout << *it << ' ';
    cout << endl;
}

// predicate:
bool is_even(const int& val) { return val % 2 == 0; }

int main()
{
    list<int> lst;
    for (int i = 1; i <= 5; ++i) {
        lst.push_back(2*i);
        lst.push_front(i);

        // we can add to both sides
    }

    cout << lst.front() << ' ' << lst.back() << endl; // 5 10

    lst.pop_back();
    lst.pop_front();
    // also we can pop from both sides

    list<int>::iterator it = lst.begin();
    advance(it, 2); // now it points to 3rd item
    lst.insert(it, 7);
    print(lst);

    it = lst.erase(it); // removes a single value
    print(lst);
    lst.erase(lst.begin(), it); // removes a range of values
    print(lst);

    lst.remove_if(is_even);
    print(lst);

    lst.insert(lst.begin(), 5);
    lst.insert(lst.begin(), 7);
    lst.insert(lst.begin(), 8);
    lst.reverse();

    cout << lst.max_size() << endl; // max number that list can hold // 384307168202282325

    lst.unique(); // removes all duplicate consecutive elements

    // clear() => to clear the list :)
    // swap() => swap the contents of 2 lists


    return 0;
}