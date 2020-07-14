#include<bits/stdc++.h>
using namespace std;
int cnt;
void insertionSort(int *A,int n,int g){
    for (int i=g; i<n; i++){
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v){
            A[j+g] = A[j];
            j -= g;
            cnt ++;
        }
        A[j+g] = v;
    }
}
void shellSort(int *A,int n){
    cnt = 0;
    int r = 1;
    vector<int> G;
    while (r <= n){
        G.push_back(r);
        r *= 2;
    }
    int m = G.size();
    reverse(G.begin(), G.end());
    cout << m << endl;
    for (int i=0; i<m; i++){
        if (i == m-1){
            cout << G[i] << endl;
        } else {
            cout << G[i] << " ";
        }
    }
    for (int i=0; i<m; i++){
        insertionSort(A,n,G[i]);
    }
    cout << cnt << endl;
}
int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin >> A[i];
    }
    shellSort(A,n);
    for (int i=0; i<n; i++){
        cout << A[i] << endl;
    }
    return 0;
}