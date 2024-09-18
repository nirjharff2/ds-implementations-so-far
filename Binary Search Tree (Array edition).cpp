//Binary Search Tree

bool search(int arr[], int node, int value) {
    if (arr[node] == -1)
        return false;
    if (value > arr[node])
        return search(arr, 2 * node + 1, value);
    else if (value < arr[node])
        return search(arr, 2 * node, value);
    else
        return true;
}
void insert(int arr[], int node, int value) {
    if (arr[node] == -1) {
        arr[node] = value;
        return;
    }
    if (value > arr[node])
        insert(arr, 2 * node + 1, value);
    else if (value < arr[node])
        insert(arr, 2 * node, value);
}
int miniNode(int arr[], int node) {
    int i = node;
    while (arr[i] != -1) {
        i = 2 * i;
    }
    return i / 2;
}

void remove(int arr[], int node, int value) {
    if (arr[node] == -1) {
        cout << "Error!";
        return;
    }
    if (value > arr[node])
        remove(arr, 2 * node + 1, value);
    else if (value < arr[node])
        remove(arr, 2 * node, value);
    else {
        if (arr[2 * node] == -1) {
            arr[node] = arr[2 * node + 1];
            arr[2 * node + 1] = -1;
        }
        else if (arr[2 * node + 1] == -1) {
            arr[node] = arr[2 * node];
            arr[2 * node] = -1;
        }
        else {
            int minNode = miniNode(arr, 2 * node + 1);
            //cout << arr[minNode] << "**" << endl;
            arr[node] = arr[minNode];
            arr[minNode] = -1;
        }
    }
}

void inOrder(int arr[], int node) {
    if (arr[node] == -1)
        return;
    inOrder(arr, 2 * node);
    cout << arr[node] << " ";
    inOrder(arr, 2 * node + 1);

}

void preOrder(int arr[], int node) {
    if (arr[node] == -1)
        return;
    cout << arr[node] << " ";
    preOrder(arr, 2 * node);
    preOrder(arr, 2 * node + 1);
}