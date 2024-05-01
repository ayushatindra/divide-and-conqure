#include <iostream>
using namespace std;
void merge(int arr[], int s, int e){
  int mid =(s+e)/2;
  // length of left array=mid-start+1
  int LengthLeft=mid-s+1;
  // legth of right array=end-mid 
  int LengthRight=e-mid;

  // creating the dynamic array
  int *left=new int[LengthLeft];
  int *right =new int[LengthRight];
   // copy karo value from original array to left array
  int k=s;
  for(int i=0;i<LengthLeft;i++){
    left[i]=arr[k];
    k++;
  }
  // right array copy karo

  k=mid+1; 
  for(int i=0;i<LengthRight;i++){
    right[i]=arr[k];
    k++;
  }
  // for (int i = 0; i < LengthLeft; i++){
  //   left[i] = arr[s + i];
  // }

  // // Copy values from the original array to the right array
  // for (int i = 0; i < LengthRight; i++){
  //   right[i] = arr[mid + 1 + i];
  // }
  // merge logic
  // left array is already sorted
  // right array is already sorted
  int leftIndex=0;
  int rightIndex=0;
  int arrayindex=s;
  while(leftIndex < LengthLeft && rightIndex < LengthRight){
    
    if(left[leftIndex]<right[rightIndex]){
      arr[arrayindex]=left[leftIndex];
      leftIndex++;
      arrayindex++;
    }
    else{
      right[arrayindex]=right[rightIndex];
      rightIndex++;
      arrayindex++;
    }
    
  }
  // 2 more cases.
  // case 1 . if right array is exehusted
  while(rightIndex<LengthRight){
    arr[arrayindex]=right[rightIndex];
    rightIndex++;
    arrayindex++;
    
  }
  // case 2 if left array is exehusted
  while(leftIndex<LengthLeft){
    arr[arrayindex]=left[leftIndex];
    leftIndex++;
    arrayindex++;
    
  } 
  // last  step ki heap memory ko free karo
  delete []left;
  delete []right;
  
  
  
}
void mergeSort(int arr[], int s, int e){
  // solving from recursion
  // base case
   if(s>=e){
     return;
   }
  // break 
  int mid =s+(e-s)/2;
  // recursion in left part
  mergeSort(arr,s,mid);
  // rightpart
  mergeSort(arr,mid+1,e);
  // merge two sorted array
  merge(arr,s,e);

  
}

int main() {
  // Divide And conqure 
  // merge sort
  int arr[] = {1,2,3,4,5,6};
  int size = 6;
  int s = 0;
  int e = size - 1;

  cout << "Before merge sort: " << endl;
  for(int i=0; i<size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  mergeSort(arr,s,e);

  cout << "After merge sort: " << endl;
  for(int i=0; i<size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
 //  int arr[]={6,5,4,3,2,1};
 //  int size=6;
 //  for(int i=0;i<size;i++){
 //    cout<<arr[i]<<" ";
 //  }
 //  cout<<endl;
 //  mergeSort(arr,0,size-1);
 // // after merge sort 
 //  // printing the array 
 //  for(int i=0;i<size;i++){
 //    cout<<arr[i]<<" ";
 //  }


  // merge two sorted array
  // int arr[]={1,2,3};
  // int size=3;
  // int arr1[]={1,3,5};
  // int size1=3;
  
  
}
