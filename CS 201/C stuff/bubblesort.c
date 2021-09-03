#include <stdio.h>

void SortArray(int sortingList[], int numVals){
   int t, n, swapped;
   n = numVals;
   for (int i = 0; i < n-1; i++) {
      swapped = 0;
      for (int j = 0; j < n - i - 1; j++) {
         if (sortingList[j] > sortingList[j + 1]) {
            t = sortingList[j];
            sortingList[j] = sortingList[j + 1];
            sortingList[j + 1] = t;
            swapped = 1;
         }
      }
      if (swapped == 0){
         break;
      }
   }

}

int main(void) {
   int numnum, nums[20];
   
   scanf("%d", &numnum);
   for (int i = 0; i < numnum; ++i){
      scanf("%d", &nums[i]);
   }
   SortArray(nums, numnum);
   
   for (int i = 0; i < numnum; ++i){
      printf("%d ", nums[i]);
   }

   return 0;
}