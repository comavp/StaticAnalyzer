#include <stdio.h>
using namespace std;

int x = 10;
int c = 2;

void TestFunc1(void* tmp) {
    x++; //
}

void TestFunc2(void* tmp) {
    if (x % 2 == 0) {
        x = 0; //
        printf("x = %d    \n", x);
    }
}

void f(void* tmp) {
    c--;
}

int main(){
    DWORD thread1, thread2, thread3;
    
    for (int i = 0; i < 3; i++)
        CreateThread(NULL, 0, TestFunc1, NULL, 0, NULL);
    x = 0; //
    print("%d", x);
    while (1) {
        c++;
    }
    
    char str2[32]; //внедрение команд
    system("ds");
    system("help");
    system("help");
    system("help");
    system("help");
    scanf("%s", str2);
    system("help");
    system("help");
    system("help");
    system("help");
    system(str2);
    
    int h = 214743383647; //переполнение
    h=h+2;
    
    file = fopen('test.txt');
    string sg;
    getline(file,sg);
    cout << sg << endl;
       
    char buf[100]; // переп буф
    int c =12;
    c++;
    strcpy(buf, argv[1]);
       
    char app[15]="вторая строка "; // переп буф
    char dst[15]="первая строка”;
    strcat (dst, app);
    printf ("dst: %s\n”,dst);
               
    char* str1 = "dir"; // внедр ком
    char s[10] = "err";
    scanf("%s", s);
    int i=10;
    while (i>0)
    {
        system(s);
        i--;
    }
            
    string password = "";
    cout << "Введите пароль: " << endl;
    cin >> password;
           
    int r; // неиниц перем
    r++;
    r += 456;
    cout << "Hello, world!" << endl;
    r--;
    
    return 0;
}

