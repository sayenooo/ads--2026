#include <bits/stdc++.h>
using namespace std;

class MinHeap{
    public:
    vector<int>a;
    int sumn = 0;

    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i + 1;
    }
    int right(int i){
        return 2*i + 2;
    }
    int insert(int data){
        a.push_back(data);
         int idx = a.size() - 1;
        while(idx>0 && a[idx]<a[parent(idx)]){
            swap(a[idx],a[parent(idx)]);
            idx = parent(idx);
        }
    }
    int getmin(){
        return a[0];
    }
    void heapify(int i){
        if(left(i)>a.size()-1){
            return;
        }
        int j = left(i);
        if(right(i)<a.size() && a[right(i)]<a[left(i)]){
            j = right(i);
        }
        if(a[i]>a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }
    int extractMin(){
        int minm = getmin();
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        if(a.size()>0){
            heapify(0);
        }
        return minm;
    }
    int extractSumn() {
        if (a.size() < 2) return 0;
        int x = extractMin();
        int y = extractMin();
        int s = x + y;
        insert(s);
        sumn += s;
        return s;
    }

};

int main() {
    int n;
    cin >> n;
    MinHeap* heap = new MinHeap();

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        heap->insert(x);
    }

    for (int i = 0; i < n - 1; i++) {
        heap->extractSumn();
    }

    cout << heap->sumn;

    return 0;
}
