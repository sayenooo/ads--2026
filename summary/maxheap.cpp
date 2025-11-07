class MaxHeap {
public:
    vector<int> a;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    int getMax() { return a[0]; }

    void insert(int k) {
        a.push_back(k);
        int ind = a.size() - 1;
        // Change: bubble up if GREATER than parent
        while (ind > 0 && a[ind] > a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;
        int j = left(i);
        // Change: find LARGEST child
        if (right(i) < a.size() && a[right(i)] > a[left(i)])
            j = right(i);
        // Change: swap if parent is SMALLER
        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMax() {
        int root_value = getMax();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root_value;
    }
};