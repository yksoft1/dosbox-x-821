#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <bios98.h>

main()
{
	unsigned char *row;
	unsigned int x,y,r,o;
	FILE *fp;
	unsigned char sw2;
	
	sw2=inportb(0x31);
	printf("%x\n", sw2);
	
	row=malloc(0x10*256);
	if(!row)
		exit(1);
	fp=fopen("anex86.bmp","wb");
	if(!fp)
	{
		printf("Cannot open anex86.bmp\n");
		exit(1);
	}
	memset(row, 0, 62);
	
	/* bmp header */
	*(row)='B';
	*(row+1)='M';
	
	*((unsigned long *)(row+2)) = 14+40+8+(2048UL/8UL)*2048UL; /*file size*/
	*((unsigned short *)(row+6)) = 0;
	*((unsigned short *)(row+8)) = 0;
	*((unsigned long *)(row+10)) = 14+40+8;
	
	*((unsigned long *)(row+14)) = 40;
	*((unsigned long *)(row+18)) = 2048;
	*((unsigned long *)(row+22)) = 2048;
	*((unsigned short *)(row+26)) = 1;
	*((unsigned short *)(row+28)) = 1;   /*1-bit*/
	*((unsigned long *)(row+30)) = 0;
	*((unsigned long *)(row+34)) = (2048UL/8UL)*2048UL; /*data size*/
	
	*((unsigned long *)(row+54)) = 0;
	*((unsigned long *)(row+58)) = 0x00FFFFFFUL;
	
	fwrite(row, 62, 1, fp);
	
	/* read kanjis */
	for(y=127;y>0;y--)
	{
		for(x=0;x<128;x++)
		{
			outportb(0xa3, x);
			outportb(0xa1, y);
			
			for(r=0;r<16;r++)
			{
				outportb(0xa5,r+0x20);
				row[2*x+((15-r)<<8U)]=inportb(0xa9) ^ 0xff;

				outportb(0xa5,r+0x00);
				row[2*x+((15-r)<<8U)+1]=inportb(0xa9) ^ 0xff;				
			}
		}
		fwrite(row, 16*256, 1, fp);
	}
	
	/* read half-wide chars */
	for(x=0;x<256;x++)
	{
		outportb(0xa3, x);
		outportb(0xa1, 0);
		
		for(r=0;r<16;r++)
		{
			outportb(0xa5,r+0x20);
			row[x+((15-r)<<8U)]=inportb(0xa9) ^ 0xff;
		}
	}
	fwrite(row, 16*256, 1, fp);
	fclose(fp);
}

