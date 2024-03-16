#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//cấp phát và phát sinh ngẫu nhiên mảng 
void tao_mang(int *a, int m, int n){
    srand(time(NULL));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[i*n+j] =(rand() % 50) + 1;
        }
    }

//xuất dòng r ra màn hình
}void xuat_dong(int *a, int r, int n){
    for(int j = 0; j < n; j++)
        printf("%-3d", a[r*n+j]);
}

//xuất ma trận ra màn hình
void xuat_mang(int *a, int m, int n){
    for(int i = 0; i < m; i++){
        xuat_dong(a,i,n); //xuất dòng thứ i
    printf("\n");
    }
}

//xuất đường biên
void duong_bien(int *a, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || i == m-1 || j == 0 || j == n-1)
                printf("%-3d", a[i*n+j]);// In phần tử nằm trên đường biên
            else   
                printf("   ");// In 3 khoảng trắng cho phần tử không nằm trên đường biên
        }
        printf("\n");
    }
}

//tìm vị trí giá trị k
void vitri_k (int *a, int m, int n, int k){
    int find = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i*n+j] == k){
                printf("(%d,%d)", i,j);
                find = 1;
            }
        }
    }
    if(find == 0)
        printf("Mang khong co gia tri K can tim\n");
}

//
void xuatR (int *a, int m, int n, int &r){
    do{
        printf("\nNhap dong r: ");
        scanf("%d", &r);
        if(r < 0 || r >= m)
            printf("Dong khong hop le");
    }while (r < 0 || r >= m);
    xuat_dong(a,r,n);
}

//huỷ ma trận
void huy_mt (int *a){
    free(a);
}
int main ()
{
    int m,n,k,r;
    printf("So dong: "); scanf("%d", &m);
    printf("So cot: "); scanf("%d", &n);
    //cap phap cho ma tran co mxn phan tu
    int *a = (int *)malloc (m*n*sizeof(int));
    tao_mang(a, m ,n);
    xuat_mang(a, m, n);
    printf("Cac phan tu nam tren duong bien:\n");
    duong_bien(a,m,n);
    printf("Nhap gia tri K: "); scanf("%d", &k);
    vitri_k(a,m,n,k);
    xuatR(a,m,n,r);
    huy_mt(a); //thu hồi bộ nhớ
    return 0;
}