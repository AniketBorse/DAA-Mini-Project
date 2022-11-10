#include<iostream>
using namespace std;

void merge(int arr[], int a, int mid, int b){
	int m = mid-a+1;
	int n = b-mid;
	
	int arr1[m];
	int arr2[n];
	
	for(int i = 0; i<m; i++){
		arr1[i] = arr[a+i];
	}
	
	for(int i = 0; i<n; i++){
		arr2[i] = arr[mid+1+i];
	}
	
	int i = 0;
	int j = 0;
	int k = a;
	while(i<m && j<n){
		if(arr1[i]<arr2[j]){
			arr[k] = arr1[i];
			k++;
			i++;
		}
		else{
			arr[k] = arr2[j];
			k++;
			j++;
		}
	}
	
	while(i<m){
		arr[k] = arr1[i];
		k++;
		i++;
	}
	
	while(i<n){
		arr[k] = arr2[j];
		k++;
		j++;
	}
}

void mergeSort(int arr[], int a, int b){
	if(a<b){
		int mid = (a+b)/2;
		mergeSort(arr, a, mid);
		mergeSort(arr, mid+1, b);
		
		merge(arr, a, mid, b);
	}
}

int main(){
	
	int arr[] = {13, 17, 12, 24, 14, 10, 18, 20};
	mergeSort(arr, 0, 7);
	cout<<"Sorted Array:";
	for(int i = 0; i<8; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
