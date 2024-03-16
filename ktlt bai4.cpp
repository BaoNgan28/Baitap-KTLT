#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

typedef struct CONTACT {
    char hoten[41];
    char sdt[12];
    char email[61];
}contact;

void cho_phim(){
    printf("Press any key to continue...");
    getch();
}

#define MAX 2000 //danh bạ tối đa 2000 contact
contact *danhsach_ct = (contact*)malloc(MAX * sizeof(contact)); //mảng contact lưu danh bạ
int sl = 0; //sl contact thực tế

//nhập contact
void input_ct(contact *a) {
    fflush(stdin); // Xoá dữ liệu trong bộ nhớ đệm
    printf("Nhap thong tin contact:\n");
    printf("- Ho va ten: "); gets(a->hoten);
    printf("- So dien thoai: "); gets(a->sdt); 
    // Kiểm tra và yêu cầu nhập lại nếu phần đuôi của email không phải là "@gmail.com"
    do {
        printf("- Email: "); 
        gets(a->email);
        if (strstr(a->email, "@gmail.com") == NULL) {
            printf("Sai cu phap.\nVui long nhap lai email ket thuc bang @gmail.com!\n");
        }
    } while (strstr(a->email, "@gmail.com") == NULL);
}

const char header[] = 
"---------------------------------------- ----------- ----------------------------------------\n"
"HO VA TEN                                 SO DT      EMAIL NGUOI DUNG\n"
"---------------------------------------- ----------- ----------------------------------------\n";


//xuất contact
void output_ct (contact a){
    printf("%-37s %-11s %-60s", a.hoten, a.sdt, a.email);
}

//thêm contact vào cuối danh bạ
void add_contact (){
    contact temp;
    char ask;
    int cnt = 0;
    do{
        if(sl < MAX){
            input_ct(&temp);
            danhsach_ct[sl] = temp;
            sl++;
            cnt++;
            fflush(stdin); //xoá dữ liệu bộ nhớ
        printf("Da them contact vao danh ba. Tiep tuc (y/n)...");
        scanf("%c", &ask);
        }
        else {
            printf("Danh ba dien thoai da day\n");
            break;
        }
        printf("Da them %d contact vao danh ba\n", cnt);
    }while(ask == 'y' || ask == 'Y');
}

//tìm kiếm contact theo họ tên, sdt, email
    //tìm kiếm theo họ tên
void find_name() {
    char name[41];
    int cnt = 0;
    fflush(stdin);
    printf("Nhap ho ten can tim: ");
    gets(name);
    printf(header);
    // Tạo bản sao chữ thường cho biến name
    char copy_name[41];
    strcpy(copy_name, name);
    for (int i = 0; copy_name[i] != '\0'; i++) {
        copy_name[i] = tolower(copy_name[i]);
    }

    for (int i = 0; i < sl; i++) {
        // Tạo bản sao chữ thường cho phần tử thứ i trong danh sách
        char copy_danhsach[41];
        strcpy(copy_danhsach, danhsach_ct[i].hoten);
        for (int j = 0; copy_danhsach[j] != '\0'; j++) {
            copy_danhsach[j] = tolower(copy_danhsach[j]);
        }
        // So sánh 2 chuỗi
        if (strstr(copy_danhsach, copy_name) != NULL) {
            output_ct(danhsach_ct[i]);
            cnt++;
            printf("\n");
        }
    }
    if (cnt == 0)
        printf("Khong co contact nao trung khop voi thong tin vua nhap.\n");
    else
        printf("\nTim thay %d contact thoa dieu kien.\n", cnt);
}

    //tìm kiếm theo số điện thoại
void find_Num (){
    char number[12];
    int cnt = 0;
    fflush(stdin);
    printf("So dien thoai can tim: "); gets(number);
    printf(header);
    for(int i = 0; i < sl; i++){
        if(strcmp(danhsach_ct[i].sdt, number) == 0){
            output_ct(danhsach_ct[i]);
            cnt++;
        }
    }
    if(cnt == 0)
        printf("\nKhong co contact nao trung khop voi thong tin vua nhap");
    else   
        printf("\nTim thay %d contact thoa dieu kien\n", cnt);
}

    //tìm kiếm theo email
void find_mail (){
    char mail[61];
    int cnt = 0;
    fflush(stdin);
    printf("Nhap email can tim: "); 
    gets(mail);
    printf(header);
    // Tạo bản sao chữ thường cho mail
    char copy_mail[61];
    strcpy(copy_mail, mail);
    for(int i = 0; copy_mail[i] != '\0'; i++){
        copy_mail[i] = tolower(copy_mail[i]);
    }
    for(int i = 0; i < sl; i++){
        // Tạo bản sao chữ thường cho phần tử thứ i trong danh sách
        char copy_danhsach[61];
        strcpy(copy_danhsach, danhsach_ct[i].email);
        for(int j = 0; copy_danhsach[j] != '\0'; j++){
            copy_danhsach[j] = tolower(copy_danhsach[j]);
        }
        // So sánh 2 chuỗi
        if(strstr(copy_danhsach, copy_mail) != NULL){
            output_ct(danhsach_ct[i]);
            cnt++;
        }
    }
    if(cnt == 0)
        printf("\nKhong co contact nao trung khop voi thong tin vua nhap");
    else
        printf("\nTim thay %d contact thoa dieu kien\n", cnt);
}

void find_ct() {
    bool check;
    int choose;
    printf("\nTim kiem contact theo:\n    Nhap 1: tim kiem theo ho ten\n  Nhap 2: tim kiem theo sdt\n Nhap 3: Tim kiem theo email\n");
   do {
    scanf("%d", &choose);
    check = (choose == 1 || choose == 2 || choose == 3);
    if (!check)
        printf("Nhap lai: ");
   } while (!check);
   switch (choose) {
        case 1:
            find_name();
            break;
        case 2:
            find_Num();
            break;
        case 3:
            find_mail();
            break;
   }
}

//xoá một contact khỏi danh bạ
void delete_contact(){
    // Xuất danh sách cho người dùng xem
    printf("Danh sach contact hien co:\n");
    printf(header);
    for(int i = 0; i < sl; i++){
        printf("%d. ", i+1);
        output_ct(danhsach_ct[i]);
        printf("\n");
    }
    // Yêu cầu nhập dòng contact cần xoá
    int stt;
    do{
        printf("\nBan muon xoa contact thu: "); 
        scanf("%d", &stt);
        if(stt < 1 || stt > sl)
            printf("Nhap sai\n");
    }while(stt < 1 || stt > sl);
    // Xoá dòng contact theo yêu cầu
    for(int i = stt - 1; i < sl - 1; i++){
        danhsach_ct[i] = danhsach_ct[i+1];
    }
    sl--;
    printf("Da xoa dong contact thu %d.\n", stt);
    printf("Danh sach sau khi xoa:\n");
    for(int i = 0; i < sl; i++){
        printf("%d. ", i + 1);
        output_ct(danhsach_ct[i]);
        printf("\n");
    }
}

//sắp xếp thứ tự theo họ tên tăng dần
#define min(n1,n2) ((n1) < (n2) ? (n1) : (n2))
    //so sánh 2 từ
int cmp (char test1[], char test2[], int i, int j){
    int n1 = strlen(test1) - i;
    int n2 = strlen(test2) - j;
    int m;
    for( m = 0; m < min(n1,n2); m++){
        if(test1[i] != test2[j]){
            if(test1[i] > test2[j]){
                return -1; //trả về -1 để hoán đổi
            }
            else 
                return 1; //nghĩa là test1 < test2, đúng yêu cầu và không cần đổi
        }
    }
    if(m == min(n1,n2))
        return 0; //2 từ hoàn toàn giống nhau
    return 0;
}

void sort_name(contact danhsach_ct[], int sl){
    printf("Danh sach contact can sap xep:\n");
    printf(header);
    for(int i = 0; i < sl; i++){
        printf("%d. ", i+1);
        output_ct(danhsach_ct[i]);
        printf("\n");
    }
    for(int step = 0; step < sl - 1; step++) {
        for(int i = 0; i < sl - step - 1; i++) {
            // Tìm chữ cái in hoa cuối cùng trong ds i
            int j,k;
            for (j = strlen(danhsach_ct[i].hoten) - 1; j >= 0; j--) {
                if (isupper(danhsach_ct[i].hoten[j]))
                    break;
            }
            // Tìm chữ cái in hoa cuối cùng trong ds i+1
            for (k = strlen(danhsach_ct[i + 1].hoten) - 1; k >= 0; k--) {
                if (isupper(danhsach_ct[i + 1].hoten[k]))
                    break;
            }

            // Lưu vị trí của chữ cái in hoa cuối cùng trong cả hai chuỗi
            int a = j, b = k;

            int check = cmp(danhsach_ct[i].hoten, danhsach_ct[i+1].hoten, a, b);
            if (check == -1) {
                // Hoán đổi
                char temp[41];
                strcpy(temp, danhsach_ct[i].hoten);
                strcpy(danhsach_ct[i].hoten, danhsach_ct[i+1].hoten);
                strcpy(danhsach_ct[i+1].hoten, temp);
            } else if (check == 0) {
                // Tiếp tục so sánh các từ tiếp theo nếu cần
                while (j >= 0 && k >= 0) {
                    // Tìm vị trí của chữ cái in hoa tiếp theo trong ds i và ds i+1
                    for (j = j - 1; j >= 0; j--) {
                        if (isupper(danhsach_ct[i].hoten[j]))
                            break;
                    }
                    for (k = k - 1; k >= 0; k--) {
                        if (isupper(danhsach_ct[i + 1].hoten[k]))
                            break;
                    }
                    // Lưu vị trí mới của chữ cái in hoa
                    a = j;
                    b = k;
                    // So sánh các từ tiếp theo
                    check = cmp(danhsach_ct[i].hoten, danhsach_ct[i + 1].hoten, a, b);
                    if (check == -1) {
                        // Hoán đổi
                        char temp[41];
                        strcpy(temp, danhsach_ct[i].hoten);
                        strcpy(danhsach_ct[i].hoten, danhsach_ct[i+1].hoten);
                        strcpy(danhsach_ct[i+1].hoten, temp);
                        // Cập nhật mảng tests
                        break;
                    } else if (check == 1) {
                        break;
                    }
                }
            }     
        }
    }
    printf("Danh sach contact sau khi sap xep:\n");
    printf(header);
    for(int i = 0; i < sl; i++){
        printf("%d. ", i+1);
        output_ct(danhsach_ct[i]);
        printf("\n");
    }
}

//menu
void menu(){
    int luachon;
    do{
        printf(" DANH BA DIEN THOAI \n"
            "--------------------------\n"
            "[So luong hien co = %d]\n"
            "1. Them contac vao danh ba\n"
            "2. Tim kiem contacct\n"
            "3. Xoa contact khoi danh ba\n"
            "4. Sap xep ho ten danh ba\n"
            "0. Thoat chuong trinh\n", sl);
        printf("Lua chon: ");
        scanf("%d", &luachon); 
        if(luachon >= 1 && luachon <= 4){
            switch(luachon){
                case 1: add_contact();              break;
                case 2: find_ct();                  break;
                case 3: delete_contact();           break;
                case 4: sort_name(danhsach_ct,sl);  break;
            }
            cho_phim();
        }   
    }while(luachon != 0);
}
contact test []=
{
    {"Nguyen Thanh Bao Ngan", "0329336782", "Baongan456789@gmail.com"},
    {"Nguyen Pham Bao Ngan", "0389612765", "nguyenphambaongan@gmail.com"},
    {"Trang Minh Y", "0369453982", "trangminhy@gmail.com"},
    {"Pham Anh Hung", "0918227563", "Phamanhhung@gmail.com"},
    {"Nguyen Khanh Hung", "0326936498", "NguyenKhanhHung@gmail.com"},
    {"Bui Bao An", "0896221753", "BuibaoAn@gmail.com"}
};

int main ()
{
    //them test vao danh sach contact
    for(size_t i = 0; i < sizeof(test)/sizeof(contact); i++){
        danhsach_ct[sl++] = test[i];
    }
    menu();
    free(danhsach_ct);
    return 0;
}