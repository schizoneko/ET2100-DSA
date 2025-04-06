# ASSIGNMENT 7

## 1. Quản lý tiến trình bằng danh sách móc nối đơn

Sử dụng cấu trúc **danh sách liên kết đơn (singly linked list)** để quản lý các tiến trình (process – là các chương trình đang chạy) trong một hệ điều hành.

### Cấu trúc dữ liệu của một tiến trình bao gồm:
- **ID**: Mã số tiến trình (kiểu `int`)
- **Name**: Tên tiến trình (kiểu `string`)
- **Status**: Trạng thái của tiến trình gồm 1 trong 4 trạng thái:
  - `READY`
  - `RUNNING`
  - `WAITING`
  - `TERMINATED`
- **Priority**: Độ ưu tiên (kiểu `int`, giá trị càng nhỏ thì độ ưu tiên càng cao)

### Yêu cầu các thao tác chính:
- `a.` **insertProcess**: Bổ sung một tiến trình vào danh sách
- `b.` **findReadyHighestPriority**: Tìm kiếm tiến trình có trạng thái READY và độ ưu tiên cao nhất
- `c.` **remove**: Xóa một tiến trình tại vị trí cho trước (kết quả từ `findReadyHighestPriority`)
- `d.` **removeAllTerminated**: Xóa tất cả các tiến trình có trạng thái TERMINATED
- `e.` Viết chương trình chính **sử dụng các thao tác trên**

---

## 2. Danh sách sinh viên và môn học

Tạo một danh sách liên kết đơn lưu trữ các **Sinh viên**. Thông tin của mỗi sinh viên bao gồm:
- `mssv` (kiểu `long`)
- `họ tên` (kiểu `string`)
- Danh sách các môn học mà sinh viên đã học, kèm theo:
  - `mã số học kỳ`
  - `điểm môn học`

### Cấu trúc dữ liệu của mỗi môn học:
- `mshp`: Mã số học phần
- `Tên học phần`
- `Số tín chỉ`

### Thao tác:
Thực hiện các thao tác cơ bản trên các danh sách liên kết lưu trữ:
- Danh sách sinh viên
- Danh sách các môn học của mỗi sinh viên

---
