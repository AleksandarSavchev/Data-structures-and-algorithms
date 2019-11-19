#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long int br = 0;
void merge(int arr[], int start, int mid, int end)
{
    int i, j, k=start;
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int* arr1 = new int[n1];
    int* arr2 = new int[n2];
    for (i = 0; i < n1; i++)
        arr1[i] = arr[start + i];
    for (j = 0; j < n2; j++)
        arr2[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;  
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
            br+=n1-i;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
    delete[] arr1;
    delete[] arr2;
}

void mergesort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int n, a[600000];
    long long int br1[1024];
    int q;
    cin >> q;
    for (int j = 0; j<q; j++)
    {
        cin >> n;
        for (int i = 0; i<n; i++)
        {
            cin >> a[i];
        }
        mergesort(a, 0, n - 1);
        br1[j] = br;
        br = 0;
    }
    for (int i = 0; i < q; i++)
        cout << br1[i] << endl;
    return 0;
}