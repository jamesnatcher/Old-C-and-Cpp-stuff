#include <stdio.h>

void copy(int res[], int a[], int n){
    for (int i = 0; i < n; ++i) {
        res[i] = a[i];
    }
}

void merge(int res[], int a[], int n, int b[], int m){
    int a_pos = 0;
    int b_pos = 0;
    int res_pos =0;

    while ((a_pos < n) && (b_pos < m)) {
        if (a[a_pos] <= b[b_pos]){
            res[res_pos] = a[a_pos];
            a_pos++;  
        }
        else{
            res[res_pos] = b[b_pos];
            b_pos++;
        }
        res_pos++;
    }
    while (a_pos < n){
        res[res_pos] = a[a_pos];
        a_pos++;
        res_pos++;
    }
    while (b_pos < m){
        res[res_pos] = b[b_pos];
        b_pos++;
        res_pos++;
    }
}

void sort(int array[], int n){
    int n_left, n_right;
    int * array_left, * array_right;
    int temp[n]; /* n is actually not constant and C arrays need to be of constant size
                    but in modern C (>= 2011)  this is okay, if at least n is constant for this 
                    call of the funciton and the array variable is the last variable declared in this function.
                    Otherwise us a feature later in shown in class*/
    //Base Cases
    if (n == 0) return;
    if (n == 1) return;
    
    //Cutting the array into two "halves"
    n_left = n / 2;
    n_right = n - n_left;

    array_left = array;
    array_right = &array[n_left];

    //Sort them again
    sort(array_left, n_left);
    sort(array_right, n_right);

    //Merge them
    merge(temp, array_left, n_left, array_right, n_right);

    //temp is now sorted, and we just have to copy it back into the normal array
    copy(array, temp, n);

}

void input_array(int array[], int n){
    int i;
    printf("Please enter %d integer numbers.\n", n);
    for (i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
}

void print_array(int array[], int n){
    int i;
    for (i = 0; i < n; i++){
        printf("%d", array[i]);
        if (i < n -1){
            printf(", ");
        }
    }
    printf("\n");
}

int main(int argc, char **argv){
    const int n = 10;
    int array[n];
    
    input_array(array, n);

    printf("The input array is :\n");
    print_array(array, n);

    sort(array, n);

    printf("The sorted array is :\n");
    print_array(array, n);

    return 0;
}