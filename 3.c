// Bài 3: 
// (a) Viết một hàm tính n giai thừa (1 điểm) 
// (b) Viết hàm để tính tổ hợp chập k của n:  C(k,n). (1 điểm) 
// (c) Cho một tệp văn bản, mỗi dòng chứa 2 số k và n. Viết 1 chương trình tính C(k,n), với k và n được đọc ra từ tệp trên. 
// Kết quả đưa vào một tệp văn bản khác, trong đó mỗi dòng gồm: k  n  C(k,n). (2 điểm)

#include <stdio.h>
// (a) Viết một hàm tính n giai thừa (0.5 điểm)
int factorial(int n){ // n! = n*(n-1)*(n-2)*...*1, ví dụ: 5! = 5*4*3*2*1 = 120
    if (n == 0) return 1;
    else return n*factorial(n-1); 
    // Đệ quy: n! = n*(n-1)! => factorial(n) = n*factorial(n-1) = n*(n-1)*factorial(n-2) = ... = n*(n-1)*...*1
}

// (b) Viết hàm để tính tổ hợp chập k của n:  C(k,n). (0.5 điểm)
int C(int k, int n){
    return factorial(n)/(factorial(k)*factorial(n-k)); // C(k,n) = n!/(k!*(n-k)!)
}

int main (){
    //0.5 điểm cho một ví dụ cụ thể
    printf("%d\n", factorial(5));
    //0.5 điểm
    printf("%d\n", C(3, 7));
    // int n, k;
    // printf("Nhap vao n: ");
    // scanf("%d", &n);
    // printf("Nhap vao k: ");
    // scanf("%d", &k);
    // printf("Giai thua cua %d la: %d\n", n, factorial(n));
    // printf("To hop chap %d cua %d la: %d", k, n, C(k, n));

    // (c) Cho một tệp văn bản, mỗi dòng chứa 2 số k và n. 
    // Viết 1 chương trình tính C(k,n), với k và n được đọc ra từ tệp trên.
    // Kết quả đưa vào một tệp văn bản khác, trong đó mỗi dòng gồm: k  n  C(k,n). (2 điểm)
    
    FILE *fptr1, *fptr2; //Để xử lý 2 file input.txt và output.txt
    
    // tạo file input.txt => 1 điểm
    fptr1 = fopen("input.txt", "w"); // Viết các cặp số k, n vào file input.txt theo từng dòng
    int k, n;
    while (1)
    {
        printf("\nNhap vao k: ");
        scanf("%d", &k);
        printf("Nhap vao n: ");
        scanf("%d", &n);
        fprintf(fptr1, "%d %d\n", k, n); // ghi kết quả vào file input.txt
        printf("Ban co muon tiep tuc khong? (1: tiep tuc, 0: dung): ");
        int choice;
        scanf("%d", &choice); // nhập lựa chọn
        if (choice == 0) break; // nếu lựa chọn là 0 thì dừng vòng lặp
    }
    fclose(fptr1);
    
    // đọc file input.txt và ghi kết quả vào file output.txt => 1 điểm
    fptr1 = fopen("input.txt", "r");
    fptr2 = fopen("output.txt", "w");
    while (!feof(fptr1))  // kiểm tra xem đã đọc hết file chưa
    {
        fscanf(fptr1, "%d %d", &k, &n); // đọc từng dòng của file input.txt
        fprintf(fptr2, "%d %d %d\n", k, n, C(k, n)); // ghi kết quả vào file output.txt
    }
    return 0;
}