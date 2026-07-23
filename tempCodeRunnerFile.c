
#include<stdio.h>
int main(){
        int n,arr[100];
        printf("enter no of element in array");
        scanf("%d",&n);
        printf("enter the element in the array: \n");
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        printf("array element are: \n");
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
    }
    return 0;
}