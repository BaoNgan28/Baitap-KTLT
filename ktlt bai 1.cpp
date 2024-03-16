#include <stdio.h>
#include <stdlib.h> //con trỏ phải có

//cách sử dụng ifndef - else

void nhapmang (int a[], int n){
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}


void xuatmang (int a[], int n){
    for(int i = 0;i < n; i++)
        printf("%d ", a[i]);
}
//cach su dung con tro
// void nhapmang (int *a, int n){
//     for(int i = 0; i < n; i++)
//         printf("%d ", *(a+i));
// }
// void nhapmang (int *a, int n){
//     for(int i = 0; i < n; i++)
//         scanf("%d", (a+i));
// }

void dao_nguoc (int a[], int n){
    int l = 0, r = n-1;
    while(l < r){
        int t = a[l];
        a[l] = a[r];
        a[r] = t;
        l++; r--;
    }
}
// void dao_nguocPointer (int *a, int n){
//     int *l = a, *r = a+n-1;
//     while (l < r){
//         int t = *l;
//         *l = *r;
//         *r = t;
//         l++;r--
//     }

// }

int sum (int a[], int n){
    int tong = 0;
    for(int i = 0; i < n; i ++){
        tong += a[i];
    }
    return tong;
}
/*int sum (int *a, int n){
    int s = 0;
    while (n != 0){
        s+= *a++;
        n--;
    }
    return s;
}
*/

float tbc(int *a, int n){
    return (float)sum(a,n)/n;
}

int find_min (int *a, int n){
    int m = *a;
    while (n){
        if(m > *a)
            m = *a;
        a++;
        n--;
    }
    return m;
}

int find_max(int *a, int n) {
    int m = *a;
    while (n > 0) {
        if (*a > m)
            m = *a;
        a++;
        n--;
    }
    return m;
}
void sap_xep(int a[], int n){
    for(int step = 0; step < n-1; step++){
        for(int i = 0; i < n - step - 1; i++){
            if(a[i] > a[i+1]){
                int t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
            }
        }
    }
}

int main (){
    int n;
    printf("N = "); scanf("%d", &n); //nhap so phan tu
    int *a = (int *)malloc(n * sizeof(int));; //cap phat bo nho cho n phan tu la so nguyen
    nhapmang(a,n);
    printf("Mang da nhap la:\n");
    xuatmang(a,n);
    dao_nguoc(a,n);
    printf("\nMang dao nguoc la:\n");
    xuatmang(a,n);
    printf("\nSum = %d", sum(a,n));
    printf("\nTrung binh cong = %.2f", tbc(a,n));
    printf("\nMin = %d, Max = %d", find_min(a,n), find_max(a,n));
    sap_xep(a,n);
    printf("\nMang sau khi sap xep la: "); xuatmang(a,n);

    free(a); //thu hoi bo nho
    return 0;
}