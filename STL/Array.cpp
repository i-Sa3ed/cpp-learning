#include <iostream>
#include <array>

using namespace std;

/*
 * size must be defined (static container)
 */

void print(array<int, 10>& arr) {
    for (int i : arr)
        cout << i << ' ';
    cout << endl;
}

int main()
{
    array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << arr.front() << ' ' << arr.back() << endl;

    array<int, 10> arr2 = {1, 2, 5, 3, 4, 6, 7, 10, 8, 9};
    arr.swap(arr2);
    print(arr);

    //cout << arr.at(10) << endl; // Exception (out of boundary)
    cout << arr.at(2) << endl; // 5

    arr.fill(13);
    print(arr);

    // size() = max_size()
    cout << sizeof(arr) << endl; // size of array in bytes

    // data() => returns pointer to the first element in the array

    return 0;
}