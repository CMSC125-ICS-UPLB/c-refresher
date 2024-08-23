#include <stdio.h>
#include <stdlib.h>




// Assumes little endian
//https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
void print_bits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
            if ((j % 4) == 0)
               printf(" ");
        }
    }
    puts("");
}


int main(){

   unsigned int n=0x12345678;

   printf("%d %x\n",n,n);



   print_bits(sizeof(n),&n);

   //get the topmost 16 bits
   unsigned int top16 = n >> 16;
   print_bits(sizeof(n),&top16);
   printf("%x\n",top16);

   //get the lowest 16 bits
   unsigned int bottom16 = n & 0x0000FFFF;
   print_bits(sizeof(n),&bottom16);
   printf("%x\n",bottom16);


   printf("%d\n", 32>>2);
   printf("%d\n", 32<<2);

}
