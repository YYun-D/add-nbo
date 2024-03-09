#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){

    FILE* File1 = fopen(argv[1], "r");
    FILE* File2 = fopen(argv[2], "r");

    if(File1 == NULL || File2 == NULL){
        printf("파일이 없습니다.");
        return 0;
    }

    uint32_t a;
    uint32_t b;
    uint32_t c;

    fread(&a, sizeof(a), 1, File1);
    fread(&b, sizeof(b), 1, File2);

    a = htonl(a);
    b = htonl(b);
    c = a + b;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, c, c);
}