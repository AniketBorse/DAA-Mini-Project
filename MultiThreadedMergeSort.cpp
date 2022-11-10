#include <iostream>
#include <pthread.h>
#include <time.h>
#define size 20
#define thread_size 4
using namespace std;
int arr[size];
int arrval = 0;
void combine_array(int a, int mid, int b){
   int* m = new int[mid - a + 1];
   int* n = new int[b - mid];
   int arr1 = mid - a + 1;
   int arr2 = b - mid;
   int i, j;
   int k = a;
   for(i = 0; i < arr1; i++){
      m[i] = arr[i + a];
   }
   for (i = 0; i < arr2; i++){
      n[i] = arr[i + mid + 1];
   }
   i = j = 0;
   while(i < arr1 && j < arr2){
      if(m[i] <= n[j]){
         arr[k++] = m[i++];
      }
      else{
         arr[k++] = n[j++];
      }
   }
   while (i < arr1){
      arr[k++] = m[i++];
   }
   while (j < arr2){
      arr[k++] = n[j++];
   }
}
void Sorting_Threading(int a, int b){
   int mid = a + (b - a) / 2;
   if(a < b){
      Sorting_Threading(a, mid);
      Sorting_Threading(mid + 1, b);
      combine_array(a, mid, b);
   }
}
void* Sorting_Threading(void* arg){
   int set_val = arrval++;
   int a = set_val * (size / 4);
   int b = (set_val + 1) * (size / 4) - 1;
   int mid = a + (b - a) / 2;
   if (a < b){
      Sorting_Threading(a, mid);
      Sorting_Threading(mid + 1, b);
      combine_array(a, mid, b);
   }
}
int main(){
   for(int i = 0; i < size; i++){
      arr[i] = rand() % 100;
   }
   pthread_t P_TH[thread_size];
   for(int i = 0; i < thread_size; i++){
      pthread_create(&P_TH[i], NULL, Sorting_Threading, (void*)NULL);
   }
   for(int i = 0; i < 4; i++){
      pthread_join(P_TH[i], NULL);
   }
   combine_array(0, (size / 2 - 1) / 2, size / 2 - 1);
   combine_array(size / 2, size/2 + (size-1-size/2)/2, size - 1);
   combine_array(0, (size - 1)/2, size - 1);
   cout<<"Sorted Array: ";
   for (int i = 0; i < size; i++){
      cout << arr[i] << " ";
   }
   return 0;
}
