#include <iostream>
#include <stdexcept>
#include "picture_hanging.h"

#define TODO(X) cout << "[TODO] " << __FUNCTION__ << ": " << X << endl;

using std::cout, std::endl;
using std::ostream;
using std::out_of_range;

/*
make a copy of src (elements 0..len-1)
*/
int* copy(const int src[], const size_t len) {
    int* ret = new int[len];
    for (size_t i = 0; i < len; ++i) {
        ret[i] = src[i];
    }
    return ret;
}

/*
return i such that A[i] = key, or -1 if key is not in A
*/
int find(const int A[], const size_t len, const int key) {
    for (size_t i = 0; i < len; ++i) {
        if (A[i] == key) {
            return i;
        }
    }
    return -1;
}

/*
remove the specified number (cnt) of elements starting at specified index (idx)
*/
void remove(int A[], size_t& len, const size_t idx, const size_t cnt) {
    if ((idx + cnt) > len) {
        throw std::out_of_range("");
        return;
    }
    int* tempArr = new int[len - cnt];
    size_t newLen = 0;
    for (size_t i = 0; i < idx; ++i) {
        tempArr[i] = A[i];
        newLen++;
    }
    for (size_t i = idx; i < len - cnt; ++i) {
        tempArr[i] = A[i + cnt];
        newLen++;
    }
    len = newLen;
    for (size_t i = 0; i < len; ++i) {
        A[i] = tempArr[i];
    }
    delete[] tempArr;
}

/*
remove all instances of duplicate values in A (including opposites, so 1 and -1 are the same)
*/
void removeDuplicates(int A[], size_t& len) {
    for (size_t i = 0; i < len; ++i) {
        for (size_t j = i + 1; j < len; ++j) {
            if (A[j] == A[i] || A[j] == 0 - A[i]) {
                remove(A, len, j, 1);
                --j;
            }
        }
    }
}

/*
returns true if str is not reducible (no canceling neighbors)
*/
bool isStable(const int A[], const size_t len) {
    for (size_t i = 1; i < len; ++i) {
        if (A[i] == (0 - A[i - 1])) {
            return false;
        }
    }
    return true;
}

/*
remove all instances of value
*/
void removeAll(int A[], size_t& len, const int value) {
    while (find(A, len, value) != -1) {
        remove(A, len, find(A,len,value), 1);
    }
}

/*
repeatedly remove any pair of neighbors which are opposites (e.g. 1 and -1).
*/
void reduce(int A[], size_t& len) {
    for (size_t i = 1; i < len; ++i) {
        if (A[i] == (0 - A[i - 1])) {
            remove(A, len, i-1, 2);
            i -= 2;
        }
    }
}

/*
return true if removing any single value (and it's opposite, e.g. 1 and -1) reduces the sequence to empty.
*/
bool isCorrect(const int A[], const size_t len) {
    for (size_t i = 0; i < len; ++i) {
        int* copyArr = copy(A, len);
        size_t newLen = len;
        removeAll(copyArr, newLen, copyArr[i]);
        removeAll(copyArr, newLen, 0 - copyArr[i]);
        reduce(copyArr, newLen);
        if (newLen == 0) {
            delete[] copyArr;
            return true;
        }
        delete[] copyArr;
    }

    return false;
}
