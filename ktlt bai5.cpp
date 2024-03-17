#include <stdio.h>
#include <stdlib.h>

typedef struct DT {
    int bac;
    int *heso;
} dt;

void input_dt(dt &p) {
    printf("Nhap bac da thuc: ");
    scanf("%d", &p.bac);

    p.heso = (int *)malloc((p.bac + 1) * sizeof(int));
    
    printf("Nhap cac he so: ");
    for (int i = p.bac; i >= 0; i--) {
        scanf("%d", &p.heso[i]);
    }
}

void output_dt(dt p) {
    int so_don_thuc_da_in = 0;  // Biến này để xác định đã in ra được bao nhiêu đơn thức

    // Kt điều kiện để in dấu
    for (int i = p.bac; i >= 0; i--) {
        if (p.heso[i] != 0) {
            if (so_don_thuc_da_in > 0) {
                if (p.heso[i] > 0)
                    printf(" + ");
                else
                    printf(" - ");
            } else {                //có đơn thức rồi
                if (p.heso[i] < 0)  //nếu hệ số âm thì in dấu, dương thì khỏi
                    printf("-");
            }
    //kt điều kiện để in hệ số
            // Hệ số chỉ in ra khi : khác 1 và -1 hoặc số mủ bằng 0
            if ((p.heso[i] != 1 && p.heso[i] != -1) || i == 0)
                printf("%d", p.heso[i] > 0 ? p.heso[i] : -p.heso[i]);
    //kt điều kiện để in ra số mũ
            if (i > 0) {
                printf("x");
                if (i != 1)
                    printf("^%d", i);
            }
            so_don_thuc_da_in++;
        }
    }
    printf("\n");
}

//cộng đa thức
void cong_dt(dt &p, dt &q, dt &r){
    //tìm bậc lớn nhất
    r.bac = (p.bac > q.bac) ? p.bac : q.bac;
    //cấp phát bộ nhớ có r
    r.heso = (int*)malloc((r.bac+1)*sizeof(int));

    //khởi tạo hệ số của r, loại bỏ giá trị rác
    for(int i = 0; i <= r.bac; i++){
        r.heso[i] = 0;
    }
    //copy hệ số của p vào r
    for(int i = 0; i <= p.bac; i++){
        r.heso[i] = p.heso[i];
    }
    //cộng hệ số
    for(int i = 0; i <= q.bac; i++){
        r.heso[i] += q.heso[i];
    }
    printf("Da thuc sau khi cong:\n");
    output_dt(r);
}

void huy_dt(dt &p){
    free(p.heso);
}

int main() {
    dt p,q,r;
    input_dt(p);
    input_dt(q);
    output_dt(p);
    output_dt(q);
    cong_dt(p,q,r);

    huy_dt(p);
    return 0;
}
