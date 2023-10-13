// Bài 2: Cho kiểu cấu trúc thời gian gồm ba trường: giờ, phút, giây. 
// (a) Viết hàm tạo cấu trúc thời gian như trên (1 điểm)
// (b) Viết hàm in một cấu trúc thời gian theo dạng: giờ: phút : giây (1 điểm)
// (c) Viết hàm so sánh hai cấu trúc thời gian (1 điểm)

#include <stdio.h>
// khai báo kiểu cấu trúc thời gian
// Ví dụ 10h25'30'' + 2h30'30'' = 12h56'00''
//Sinh viên: Name: Nguyễn Văn A, MSSV: 1234567
typedef struct {  //0.25 điểm 
    int hour;  //số nguyên
    int minute; //số nguyên
    int second; //số nguyên
} time;

// (a) hàm tạo cấu trúc thời gian (0.5 điểm)
time createTime(int hour, int minute, int second){
    time t;  // khai báo biến cấu trúc thời gian
    t.hour = hour;
    t.minute = minute;
    t.second = second;
    return t; // Return 1 cấu trúc thời gian
}
//(b) Hàm in một cấu trúc thời gian theo dạng: giờ: phút : giây (0.5 điểm)
void printTime(time t){
    printf("Thời gian: %d:%d:%d", t.hour, t.minute, t.second);
}

//(c) Viết hàm so sánh hai cấu trúc thời gian (0.5 điểm)
//11:01:30 > 11:01:59
int compareTime(time t1, time t2){
    if (t1.hour > t2.hour) return 1; //Thời gian t1 lớn hơn t2
    else if (t1.hour < t2.hour) return -1; //Thời gian t1 nhỏ hơn t2
    else if (t1.minute > t2.minute) return 1;
    else if (t1.minute < t2.minute) return -1;
    else if (t1.second > t2.second) return 1;
    else if (t1.second < t2.second) return -1;
    else return 0;
}

void main(){
    //được 0.25 điểm => tổng là 1 điểm
    time t = createTime(10, 20, 30);    
    // printf("Thoi gian: %d:%d:%d\n", t.hour, t.minute, t.second);
    //0.5 điểm
    printTime(t);

    //0.5 điểm
    time t1 = createTime(10, 00, 30);
    time t2 = createTime(9, 59, 30);
    int result = compareTime(t1, t2);
    if (result == 1) printf("\nThoi gian t1 lon hon t2");
    else if (result == -1) printf("\nThoi gian t1 nho hon t2");
    else printf("\nThoi gian t1 bang t2");
}
