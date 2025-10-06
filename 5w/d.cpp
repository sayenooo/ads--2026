#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    vector<long long> a;
    long long sumn = 0;

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
        if (left(i) > (int)a.size() - 1)
            return;

        int j = left(i);
        if (right(i) < (int)a.size() && a[right(i)] < a[left(i)])
            j = right(i);

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

    long long extractSumn(int count) {
        int sumn = 0;
        while(a[0]<count){
            if(a.size()<2){
                return -1;
            }
            long long x = extractMin();
            long long y = extractMin();
            long long s = x + 2*y;
            insert(s);
            sumn++;
        }
        return sumn;
    }
};

int main() {
    int n,m;
    cin >> n >> m;
    MinHeap *heap = new MinHeap();

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        heap->insert(x);
    }

    cout << heap->extractSumn(m);

    return 0;
}
