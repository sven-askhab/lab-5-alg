include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#include <iostream>

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
void ReverseBubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    srand(time(0));

    const int sizes[] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000 };

    cout << "Arr size\ttime (average)\t        time (worst)\n";

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        const int size = sizes[i];
        int arr[100001];
        for (int a = 0; a < 30; a++) {
            for (int j = 0; j < size; j++) {
                arr[j] = rand() % 1000;
            }
            clock_t start = clock();
            for (int j = 0; j < 1; j++) {
                BubbleSort(arr, size);
            }
            clock_t end = clock();
            double Time = double(end - start) / CLOCKS_PER_SEC;
            start = clock();
            for (int j = 0; j < 1; j++) {
                ReverseBubbleSort(arr, size);
            }
            end = clock();
            double worstTime = double(end - start) / CLOCKS_PER_SEC;
            cout << size << "\t\t" << Time << " sec\t\t" << worstTime << " sec\n";
        }
    }


    return 0;
}

//cout << "Sorting time: " << Time << " sec\n";
//cout << "Sorted array (" << size << "):\n";
//for (int k = 0; k < size; k++) {
//  cout << arr[k] << " ";
//}