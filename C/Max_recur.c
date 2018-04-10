#include <stdio.h>


int max(int *arr, int n) {
    if(n==0)
        return arr[0];

    int m = max(arr, n-1);
    //printf("%d\n", m);
    return (arr[n] > m)?arr[n]:m;
}


int main() {
    int len;
    scanf("%d", &len);

    int arr[len];
    for(int i=0; i<len; ++i)
        scanf("%d", &arr[i]);

    printf("%d\n", max(arr, len-1));

    return 0;
}
