#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
public:
    vector<long long> a;
    long long sumn = 0;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    long long getMax() { return a[0]; }

    void insert(long long k) {
        a.push_back(k);
        int ind = a.size() - 1;
        // Bubble up if GREATER than parent
        while (ind > 0 && a[ind] > a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        int n = a.size();
        int largest = i;
        int l = left(i), r = right(i);
        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;
        if (largest != i) {
            swap(a[i], a[largest]);
            heapify(largest);
        }
    }

    long long extractMax() {
        long long root_value = getMax();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (!a.empty())
            heapify(0);
        return root_value;
    }

    long long MaxSumn(long long count){
        while(count > 0 && !a.empty() && a[0] > 0){
            long long x = extractMax();
            sumn += x;
            insert(x - 1);
            count--;
        }
        return sumn;    
    }
};

int main(){

    int n;
    long long m;
    cin >> n >> m;
    MaxHeap *heap = new MaxHeap();

    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        heap->insert(x);
    }

    cout << heap->MaxSumn(m);

    return 0;
}
