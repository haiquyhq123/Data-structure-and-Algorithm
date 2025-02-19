#include <bits/stdc++.h>
using namespace std;




void copysubmtom(int m[], vector<int> subm, int l, int r) {
    for (int i = l; i <= r; i++) {
        m[i] = subm[i - l];
    }
}


void merge(int m[], int l, int mid, int r) {
    if (l > mid || mid >= r) {
        return;
    }
    int i = l;
    int j = mid + 1;
    vector<int> subm;
    
    while (i <= mid && j <= r) {
        if (m[i] <= m[j]) {
            subm.push_back(m[i]);
            i++;
        } else {
            subm.push_back(m[j]);
            j++;
        }
    }
    
    while (i <= mid) {  
        subm.push_back(m[i]);
        i++;
    }
    
    while (j <= r) {  
        subm.push_back(m[j]);
        j++;
    }

    copysubmtom(m, subm, l, r);
}

void mergesort(int m[], int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) / 2;
    mergesort(m, l, mid);
    mergesort(m, mid + 1, r);
    merge(m, l, mid, r);  
}


int main() {
    int m[] = {5, 4, 1, 7, 2, 12, 6, 35, 34, 33};
    int n = sizeof(m) / sizeof(m[0]);
    mergesort(m, 0, n - 1);  
    for (auto i : m) {
        cout << i << " ";
    }
    return 0;
}
