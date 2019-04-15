#ifndef MD5_H
#define MD5_H 
typedef struct{    
    /* number of bits, modulo 2^64 (lsb first) */   
    /*存储原始信息的bits数长度,不包括填充的bits，最长为 2^64 bits，因为2^64是一个64位数的最大值*/
    unsigned int count[2];    

     /* state (ABCD) */  
    /*四个32bits数，用于存放最终计算得到的消息摘要。当消息长度〉512bits时，也用于存放每个512bits的中间结果*/
    unsigned int state[4];    

    /* input buffer */
    /*存放输入的信息的缓冲区，512bits*/
	unsigned char buffer[64];   
}MD5_CTX;

#define F(x,y,z) ((x & y) | (~x & z))
#define G(x,y,z) ((x & z) | (y & ~z))
#define H(x,y,z) (x^y^z)
#define I(x,y,z) (y ^ (x | ~z))
#define ROTATE_LEFT(x,n) ((x << n) | (x >> (32-n)))
#define FF(a,b,c,d,x,s,ac) \          
	{ \          
		a += F(b,c,d) + x + ac; \          
		a = ROTATE_LEFT(a,s); \          
		a += b; \          
	}
#define GG(a,b,c,d,x,s,ac) \          
	{ \          
		a += G(b,c,d) + x + ac; \          
		a = ROTATE_LEFT(a,s); \          
		a += b; \          
	}
#define HH(a,b,c,d,x,s,ac) \          
	{ \          
		a += H(b,c,d) + x + ac; \          
		a = ROTATE_LEFT(a,s); \          
		a += b; \          
	}
#define II(a,b,c,d,x,s,ac) \          
	{ \          
		a += I(b,c,d) + x + ac; \          
		a = ROTATE_LEFT(a,s); \          		
		a += b; \          
	}                                            
void MD5Init(MD5_CTX *context);
void MD5Update(MD5_CTX *context,unsigned char *input,unsigned int inputlen);
void MD5Final(MD5_CTX *context,unsigned char digest[16]);
void MD5Transform(unsigned int state[4],unsigned char block[64]);
void MD5Encode(unsigned char *output,unsigned int *input,unsigned int len);
void MD5Decode(unsigned int *output,unsigned char *input,unsigned int len); 
#endif
