#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    vector<long long> a;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    long long getMin() {
        return a[0];
    }

    void insert(long long k) {
        a.push_back(k);
        int ind = a.size() - 1;

        while (ind > 0 && a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        if (left(i) > (int)a.size() - 1){
            return;
        }
        int j = left(i);
        if (right(i) < (int)a.size() && a[right(i)] < a[left(i)]){
            j = right(i);
        }
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    long long extractMin() {
        long long root_value = getMin();

        swap(a[0], a[a.size() - 1]);
        a.pop_back();

        if (!a.empty())
            heapify(0);

        return root_value;
    }
    long long Return(long long m){
        long long sumn = 0;
        while(a.size()>m){
            extractMin();
        }
        for(int i = 0; i<a.size(); i++){
            sumn+=a[i];
        }
        return sumn;
    }

};

int main() {
    long long n,m;
    cin >> n  >> m;
    MinHeap *heap = new MinHeap();

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s=="print"){
            cout << heap->Return(m) << endl;
        }
        if(s=="insert"){
            long x;
            cin >> x;
            heap->insert(x);
        }
    }

    return 0;
}