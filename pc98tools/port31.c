#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

int main(int argc, char** argv)
{
	unsigned char sw2;
	unsigned char far * gdc54;
	/* load dip switch SW2*/ 
	sw2=inportb(0x31);
	printf("port 0x31 %x\n", sw2);
	/*load memory 0000:054D */
	gdc54=MK_FP(0,0x54d);
	printf("mem 0x54d %x\n", *gdc54);
}
