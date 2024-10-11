/*продублювати усі прості числа масиву після цього масиву*/
#include <iostream>
using namespace std;

void input(int *temparr, int leng);

void print(int *arr, int real_leng);

void work(int *arr, int *temparr, int *counter, int leng);

int simple(int n);

int main() {
    int leng;
    cout << "Enter the length of the array" << endl;
    cin >> leng;

    int real_leng = 0;
    int* counter;
    int* temparr = new int[leng];
    int* arr = new int[2*leng];
    *counter = 0;

    input(temparr, leng);
    work(arr, temparr, counter, leng);
    real_leng = leng + *counter;
    print(arr, real_leng);

    delete(temparr);
    delete(arr);

    return 0;
}

int simple(int n) {
    if (n <= 1) {
        return 0;
    }

    for (int j = 2; j * j <= n; j++) {
        if (n % j == 0) {
            return 0;
        }
    }

    return 1;
}

void input(int *temparr, int leng) {
    cout << "Enter the array elements: " << endl;
    int n = 0;
    for (int i = 0; i < leng; i++) {
        cin >> n;
        temparr[i] = n;
    }
}

void print(int *arr, int real_length) {
    cout << "A new array: ";
    for (int i = 0; i < real_length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void work(int* arr, int* temparr, int* counter, int leng) {
    for (int i = 0; i < leng; i++) {
        arr[i] = temparr[i];

        if (simple(arr[i]) == 1) {
            arr[*counter + leng] = temparr[i];
            (*counter)++;
        }
    }
}