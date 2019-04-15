#include <stdio.h>
#include <stdlib.h>
#include "md5.h" 
int main(int argc, char *argv[])
{
    int i;	
    unsigned char encrypt[100];
    unsigned char decrypt[16];
    while(1)
    {
        scanf("%s",encrypt);
        MD5_CTX md5;	
        MD5Init(&md5);
        MD5Update(&md5,encrypt,strlen((char *)encrypt));	
        MD5Final(&md5,decrypt);        	
        printf("加密前:%s\n加密后:",encrypt);	
        for(i=0;i<16;i++)	
        {
            printf("%02x",decrypt[i]);	
        }
        printf("\n",decrypt[i]);	
    }
	return 0;
}
