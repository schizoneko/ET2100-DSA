/*Định nghĩa một cấu trúc danh sách liên kết đơn để lưu trữ các file trong một 
thư mục D>Document trên máy tính. Các file được sắp xếp theo trật tự thời gian. 
Sau đó thực hiện tao tác:  

1. Khai báo cấu trúc của danh sách liên kết. Các thông tin chứa ở mỗi node sinh 
    viên tự đưa vào để đảm bảo các nội dung sau được thực hiện 
2. Copy paste một file từ thư mục khác sang thư mục trên sao do file luôn được 
    chèn vào theo trật tự thời gian  
3. Thực hiện tính toán kích thước các file trong thư mục 
4. Người ta muốn sao lưu các file trong thư mục trên vào một ổ USB có kích thước 
    32G. Hãy thực hiện loại bỏ dần nếu cần một số file có kích thước nhỏ nhất để 
    có thể thực hiện được thao tác trên.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define MAX 10000

typedef struct file { // Thiết kế thông tin file lưu trữ
    //char name[MAX]; <- Chưa có ý tưởng strcp không dùng string.h
    float size;
    float time_added;
    struct file *next;
} file;

typedef struct Folder { // Thiết kế DSLK của 1 folder để lưu trữ thông tin file
    file *first;
    file *last;
} Folder;

void init_folder(Folder *folder) { // Khởi tạo List (ở đây là Folder)
    folder->first = NULL;
    folder->last = NULL;
}

file* create_file(float size, float time_added) {
    file* newfile = (file*)malloc(sizeof(file));
    //strncpy(newfile->name, filename, MAX);  // Sao chép tên file vào cấu trúc
    newfile->size = size;                   // Gán kích thước file
    newfile->time_added = time_added;       // Gán thời gian thêm vào
    newfile->next = NULL;                   // Gán link bằng Null
    return newfile;
}

void add_file(Folder *folder, float size, float time_added) {
    file* newfile = create_file(size, time_added);

    // Trường hợp danh sách trống
    if (folder->first == NULL) {
        folder->first = newfile; // Node mới là node đầu tiên
        folder->last = newfile;  // Node mới cũng là node cuối cùng
    } 
    else {
        // Liên kết file mới vào cuối danh sách
        folder->last->next = newfile;
        folder->last = newfile; // Cập nhật con trỏ last để trỏ tới file mới
    }
}

void sort_files(Folder *folder) { //Sắp xếp file trong thư mục theo thứ tự tăng dần về dung lượng
    if (folder->first == NULL || folder->first->next == NULL) return; // Không cần sắp xếp nếu danh sách rỗng hoặc chỉ có một phần tử

    file *last = NULL;  // Đánh dấu vị trí cuối đã sắp xếp
    file *current;      // Con trỏ để duyệt qua danh sách

    while (1) {
        current = folder->first;

        // Duyệt qua danh sách để thực hiện hoán đổi nếu cần
        while (current->next != last) {
            if (current->size > current->next->size) {
                // Hoán đổi liên kết của các node mà không hoán đổi dữ liệu
                file *temp = current->next;
                current->next = temp->next;
                temp->next = current;

                // Cập nhật đầu danh sách nếu hoán đổi đầu tiên
                if (current == folder->first) {
                    folder->first = temp;
                } 
                else {
                    // Tìm node trước `current` để sửa liên kết
                    file *prev = folder->first;
                    while (prev->next != current) {
                        prev = prev->next;
                    }
                    prev->next = temp;
                }
                // Cập nhật lại `current` sau khi hoán đổi
                current = temp;
            }
            current = current->next;
        }

        last = current;  // Đánh dấu node cuối cùng đã được sắp xếp

        // Kiểm tra xem danh sách đã sắp xếp đúng chưa
        current = folder->first;
        int sorted = 1;  // Giả định danh sách đã được sắp xếp
        while (current->next != NULL) {
            if (current->size > current->next->size) {
                sorted = 0;  // Nếu phát hiện một cặp không đúng thứ tự
                break;
            }
            current = current->next;
        }
        
        // Nếu danh sách đã sắp xếp, thoát khỏi vòng lặp
        if (sorted) break;
    }
}

void display_files(Folder *folder) {
    file *current = folder->first;
    while (current != NULL) {
        printf("Kich thuoc: %.2f MB, Thoi gian them vao: %.2f\n", current->size, current->time_added);
        current = current->next;
    }
    printf("-------------------------\n");
}

/*
void delete_file() { // Xóa các file có dung lượng bé nhất & thời gian lưu trữ lâu nhất 

}
*/


int main() {
    Folder folder;
    init_folder(&folder);

    // Thêm các file vào danh sách
    add_file(&folder, 1.5, 12.30);
    add_file(&folder, 0.9, 16.30);
    add_file(&folder, 2.0, 16);
    add_file(&folder, 0.5, 69);

    printf("Danh sách trước khi sắp xếp:\n");
    display_files(&folder);

    // Sắp xếp danh sách
    sort_files(&folder);

    printf("Danh sách sau khi sắp xếp:\n");
    display_files(&folder);

    return 0;
}