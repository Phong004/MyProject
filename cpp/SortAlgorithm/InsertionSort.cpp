#include "./BubbleSort.cpp"
using namespace std;

void InsertSort(vector<int>& a, int a_start, int a_end) {
    for (int i = a_start+1; i < a_end; i++) {
        int j = i;
        int key = a[i];
        while (j > 0 && a[j-1] > key) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = key;
    }
}

int main() {
    openFile();
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    InsertSort(a, 0, n);
    outputSort(a);
}