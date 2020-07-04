int x = 10;
int c = 2;

void TestFunc1(void* tmp) {
}

void TestFunc2(void* tmp) {
    if (x % 2 == 0) {
        x = 0;
        printf("x = %d    \n", x);
    }
}

void f(void* tmp) {
    c--;
}

int main(){
    CreateThread(NULL, 0, TestFunc1, NULL, 0, NULL);
    CreateThread(NULL, 0, TestFunc2, NULL, 0, NULL);
	c++;
}