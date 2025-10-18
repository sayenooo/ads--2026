#include <iostream>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

class MinHeap{
    public:
    vector<int>a;

    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }

    int insert(int data){
        a.push_back(data);
        int idx = a.size() - 1;
        while(idx>0 && a[idx]<a[parent(i)]){
            swap(a[idx],a[parent(i)]);
            idx = parent(i);
        }
    }
    int getmin(){
        return a[0];
    }
    int heapify(int i){
        if(left(i)>a.size()-1){
            return;
        }
        int j = left(i);
        if(right(i)<a.size() && a[left(i)]>a[right(i)]){
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
        if(!a.empty()){
            heapify(0);
        }
    }
};

int main() {
    int n, x;
    cin >> n;
    MinHeap *heap = new MinHeap();

    // Insert n elements
    for (int i = 0; i < n; i++) {
        cin >> x;
        heap->insert(x);
    }

    // Extract all elements (sorted order)
    for (int i = 0; i < n; i++)
        cout << heap->extractMin() << " ";

    return 0;
}