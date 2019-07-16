#include <iostream>

using namespace std;

void Swap(int arr[], int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                Swap(arr, i, j);
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if(left<j){
          quickSort(arr, left, j);
      }
      if(i<right){
          quickSort(arr, i, right);
      }
}

int main(void){
    int arr[5] = {3, 2, 5, 4, 1};
    quickSort(arr, 0, 4);
    for(int i=0; i<5; i++){
        cout << arr[i] << " " << endl;
    }
}
