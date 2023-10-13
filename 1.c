/* Bài 1: Sử dụng con trỏ để viết 1 chương trình NHẬP vào từ bàn phím 10 số nguyên, 
 sau đó tính trung bình cộng của 10 số vừa nhập */ 
 //sum để tỉnh tổng các số đã nhập, tính trung bình sum/10

#include <stdio.h>
void main(){
    int a[10]; // Đây là một con trỏ => a = &a[0] . Ví dụ: a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] => 1 = *p, 2 = *(p+1), 3 = *(p+2), ... 10 = *(p+9)
    int *p; // khai báo con trỏ 
    p = a; // p = &a[0], p+1 = &a[1], p+2 = &a[2], ... p+i = &a[i]. Vì vậy, *(p+i) = = *(&a[i]) = a[i]
    int sum = 0; // khai báo biến tổng
    // Nhập 10 số nguyên từ bàn phím: nhập lần 1: 3, nhập lần 2: 4, nhập lần 3: 5, ... (lặp đi lặp lại 10 lần)
    for (int i = 0; i < 10; i++)
    {
        printf("Nhap vao so thu %d: ", i+1); //i = 0 => nhập vào số thứ 1
        scanf("%d", p+i); // nhập giá trị cho từng phần tử của mảng sử dụng con trỏ
        sum += *(p+i);  // sum = 0+a[0]+a[1]+...+a[9] = *p + *(p+1) + ... + *(p+9)
    }
    printf("Trung binh cong cua 10 so vua nhap la: %f", (float)sum/10);
}