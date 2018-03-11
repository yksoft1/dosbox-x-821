#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

int main(int argc, char** argv)
{
	unsigned  char far * pt;
	pt=MK_FP(0,0x500);
	printf("mem 0x500 %x\n", *pt);
	pt=MK_FP(0,0x501);
	printf("mem 0x501 %x\n", *pt);
}
