//MinHeap

void push(vector<int> &minheap, int val) {
    minheap.pb(val);
    int i = minheap.size() - 1;

    while (i > 1 && minheap[i] < minheap[i / 2]) {
        swap(minheap[i], minheap[i / 2]);
        i /= 2;
    }
}
int pop(vector<int> &minheap) {
    if (minheap.size() == 2) {
        int res = minheap[minheap.size() - 1];
        minheap.pop_back();
        return res;
    }
    int res = minheap[1];
    minheap[1] = minheap[minheap.size() - 1];
    minheap.pop_back();
    int i = 1;
    //Percolate down
    while (2 * i < minheap.size()) {
        if (2 * i + 1 < minheap.size() && minheap[2 * i + 1] < minheap[2 * i] && minheap[i] > minheap[2 * i + 1]) {
            swap(minheap[i], minheap[2 * i + 1]);
            i = 2 * i + 1;
        } else if (minheap[i] > minheap[2 * i]) {
            swap(minheap[i], minheap[2 * i]);
            i = 2 * i;
        } else break;
    }
    return res;
}

void heapify(vector<int> &v) {
    v.pb(v[0]);
    v[0] = 0;
    int cur = (v.size() - 1) / 2;

    while (cur > 0) {
        int i = cur;
        while (2 * i < v.size()) {
            if (2 * i + 1 < v.size() && v[2 * i + 1] < v[2 * i] && v[i] > v[2 * i + 1]) {
                swap(v[i], v[2 * i + 1]);
                i = 2 * i + 1;
            } else if (v[i] > v[2 * i]) {
                swap(v[i], v[2 * i]);
                i = 2 * i;
            } else break;
        }
        cur -= 1;
    }
}