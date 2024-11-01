/*
2. Nhập vào Danh sách sinh viên ListSV, và in ra Danh sách sinh viên được sắp xếp tăng dần theo mã sinh viên. Hãy viết hàm thêm một sinh viên mới vào danh sách ListSV đã sắp xếp và SV được sắp xếp theo đúng thứ tự ở DS mới.

3. In ra các sinh viên có cùng ngày sinh, nếu không tìm thấy sinh viên có cùng ngày sinh thì in thông báo “không tìm thấy sinh viên cùng ngày sinh”

4. Loại bỏ các sinh viên có cùng ngày sinh ra khỏi danh sách ListSV
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct {
    int ngay;
    int thang;
    int nam;
} Ngay; //Tạo struct Ngay

typedef struct {
    char maSV[8]; 
    char hoTen[50]; 
    int gioiTinh; 
    Ngay ngaySinh; 
    char diaChi[100]; 
    char lop[12]; 
    char khoa[7];
} SinhVien; //Struct Sinh vien

typedef struct {
    SinhVien data; 
    Node *link;
} Node; //Tao node moi

typedef struct {
    Node *first; 
    Node *last;
} List; //Tao list moi

void init(List *list) { //Khởi tạo List sinh viên
    list->first = 0;    //NULL
    list->last = 0;   //NULL
}

Node* taoNode(SinhVien sv) { //Tạo 1 Node mang thông tin của struct sinh viên, chưa có link 
    Node *p = (Node*)malloc(sizeof(Node)); // cap phat bo nho cho node
    if (p != NULL) {
        p->data = sv;
        p->link = NULL;
    }
    else {
        printf("Khong cap phat duoc bo nho cho node");
    }
    return p;
} 

void List_Add(List *list, SinhVien sv) { //Add Note vào List sinh viên
    Node *p = taoNode(sv); //Đầu tiên phải tạo 1 Node mang thông tin Sinh vien trước
    if (p == NULL) return;
    
    if (list->first == NULL) {   //Nếu danh sách rỗng, thêm Node này làm Node đầu tiên
        list->first = list->last = p;
    } else {                     // Thêm vào cuối danh sách
        list->last->link = p;
        list->last = p;
    }
}

// Hàm nhập thông tin cho một sinh viên
SinhVien nhapSinhVien() {
    SinhVien sv;
    
    printf("Nhap ma SV: ");
    scanf("%s", sv.maSV);
    
    printf("Nhap ho ten: ");
    getchar();  // Xóa bộ đệm
    fgets(sv.hoTen, sizeof(sv.hoTen), stdin);
    sv.hoTen[strlen(sv.hoTen) - 1] = '\0';  // Bỏ ký tự xuống dòng
    
    printf("Nhap gioi tinh (1: Nam, 0: Nu): ");
    scanf("%d", &sv.gioiTinh);
    
    printf("Nhap ngay sinh (ngay thang nam): ");
    scanf("%d %d %d", &sv.ngaySinh.ngay, &sv.ngaySinh.thang, &sv.ngaySinh.nam);
    
    printf("Nhap dia chi: ");
    getchar();  // Xóa bộ đệm
    fgets(sv.diaChi, sizeof(sv.diaChi), stdin);
    sv.diaChi[strlen(sv.diaChi) - 1] = '\0';  // Bỏ ký tự xuống dòng
    
    printf("Nhap lop: ");
    scanf("%s", sv.lop);
    
    printf("Nhap khoa: ");
    scanf("%s", sv.khoa);
    
    return sv;
}

// Hàm nhập danh sách sinh viên
void nhapDanhSachSinhVien(List &l) {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        SinhVien sv = nhapSinhVien();
        List_Add(l, sv);
    }
}

// Hàm in danh sách sinh viên
void inDanhSachSinhVien(List l) {
    Node *p = l.first;
    while (p != NULL) {
        printf("\nMa SV: %s", p->data.maSV);
        printf("\nHo ten: %s", p->data.hoTen);
        printf("\nGioi tinh: %s", p->data.gioiTinh == 1 ? "Nam" : "Nu");
        printf("\nNgay sinh: %02d/%02d/%d", p->data.ngaySinh.ngay, p->data.ngaySinh.thang, p->data.ngaySinh.nam);
        printf("\nDia chi: %s", p->data.diaChi);
        printf("\nLop: %s", p->data.lop);
        printf("\nKhoa: %s\n", p->data.khoa);
        
        p = p->link;
    }
}

int main() {
    List l;
    init(&l);
    
    nhapDanhSachSinhVien(&l);  // Nhập danh sách sinh viên và tự động sắp xếp
    
    printf("\nDanh sach sinh vien (da sap xep theo ma SV):\n");
    inDanhSachSinhVien(&l);  // In danh sách sinh viên
    return 0;
}