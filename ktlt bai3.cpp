#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct  POINT {
    int x;
    int y;
}point;

//phát sinh ngẫu nhiên
void generate_array (point *a, int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        a[i].x = (rand() % 10) + 1;
        a[i].y = (rand() % 10) + 1;
    }
}

//xuất mảng các điểm 
void output_Point (point *a, int n){
    for(int i = 0; i < n; i++){
        printf("(%d,%d) ", a[i].x, a[i].y);
    }
}

//tìm kiếm toạ độ (u,v)

//xuất tất cả vị trí có toạ độ u,v
void position (point *a, int n, int u, int v){
    for(int i = 0; i < n; i++){
        if(a[i].x == u && a[i].y == v)
            printf("%d ", i);
    }
    printf("\n");
}
void find_cordinate (point *a, int n, int u, int v){
    int find = 0;
    for(int i = 0; i < n; i++){
        if(a[i].x == u && a[i].y == v){
            printf("Diem co toa do (%d,%d) duoc tim thay o vi tri: ", u,v);
            position(a,n,u,v);
            find = 1;
            return;
        }
    }
    if(!find)
        printf("Diem (%d, %d) khong ton tai trong mang\n", u, v);
}

void array_rev (point*a, int n){
    int l = 0, r = n-1;
    while (l<r){
        point t = a[l];
        a[l] = a[r];
        a[r] = t;
        l++;r--;
    }
}
void huy_mang (point *a){
    free(a);
}

int main ()
{
    int n,u,v;
    printf("Nhap n: "); scanf("%d", &n);
    point *a = (point*) malloc (n*sizeof(point));
    generate_array(a,n);
    printf("Cac diem da nhap:\n");
    output_Point(a,n);
    printf("\nToa do (u,v) can tim: ");
    scanf("%d%d", &u, &v);  
    find_cordinate(a,n,u,v);
    array_rev(a,n);
    printf("Mang sau khi dao nguoc:\n");
    output_Point(a,n);
    huy_mang(a);

    return 0;
}