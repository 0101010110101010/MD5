/*
二、MD5计算步骤   
   MD5以512位分组来处理输入的信息，且每一分组又被划分为16个32位子分组，经过了一系列的处理后，算法的输出由四个32位分组组成，将这四个32位分组级联后将生成一个128位散列值。
第一步、填充
      如果输入信息的长度(bit)对512求余的结果不等于448，就需要填充使得对512求余的结果等于448。填充的方法是填充一个1和n个0。填充完后，信息的长度就为N*512+448(bit)；
第二步、记录信息长度
     用64位来存储填充前信息长度。这64位加在第一步结果的后面，这样信息长度就变为N*512+448+64=(N+1)*512位。
第三步、装入标准的幻数（四个整数）
     标准的幻数（物理顺序）是（A=(01234567)16，B=(89ABCDEF)16，C=(FEDCBA98)16，D=(76543210)16）。如果在程序中定义应该是（A=0X67452301L，B=0XEFCDAB89L，C=0X98BADCFEL，D=0X10325476L）。有点晕哈，其实想一想就明白了。
第四步、四轮循环运算
     循环的次数是分组的个数（N+1） 

   1）将每一512字节细分成16个小组，每个小组64位（8个字节）    
   2）先认识四个线性函数(&是与,|是或,~是非,^是异或)    
	F(X,Y,Z)=(X&Y)|((~X)&Z)   
	G(X,Y,Z)=(X&Z)|(Y&(~Z))   
	H(X,Y,Z)=X^Y^Z   
	I(X,Y,Z)=Y^(X|(~Z))
    3）设Mj表示消息的第j个子分组（从0到15），<<<s表示循环左移s位，则四种操作为：    FF(a,b,c,d,Mj,s,ti)表示a=b+((a+F(b,c,d)+Mj+ti)<<<s)   GG(a,b,c,d,Mj,s,ti)表示a=b+((a+G(b,c,d)+Mj+ti)<<<s)   HH(a,b,c,d,Mj,s,ti)表示a=b+((a+H(b,c,d)+Mj+ti)<<<s)   II(a,b,c,d,Mj,s,ti)表示a=b+((a+I(b,c,d)+Mj+ti)<<<s)    4）四轮运算 

第一轮
a=FF(a,b,c,d,M0,7,0xd76aa478) 
b=FF(d,a,b,c,M1,12,0xe8c7b756) 
c=FF(c,d,a,b,M2,17,0x242070db) 
d=FF(b,c,d,a,M3,22,0xc1bdceee) 
a=FF(a,b,c,d,M4,7,0xf57c0faf) 
b=FF(d,a,b,c,M5,12,0x4787c62a) 
c=FF(c,d,a,b,M6,17,0xa8304613) 
d=FF(b,c,d,a,M7,22,0xfd469501) 
a=FF(a,b,c,d,M8,7,0x698098d8) 
b=FF(d,a,b,c,M9,12,0x8b44f7af) 
c=FF(c,d,a,b,M10,17,0xffff5bb1) 
d=FF(b,c,d,a,M11,22,0x895cd7be) 
a=FF(a,b,c,d,M12,7,0x6b901122) 
b=FF(d,a,b,c,M13,12,0xfd987193) 
c=FF(c,d,a,b,M14,17,0xa679438e) 
d=FF(b,c,d,a,M15,22,0x49b40821) 
第二轮
a=GG(a,b,c,d,M1,5,0xf61e2562) 
b=GG(d,a,b,c,M6,9,0xc040b340) 
c=GG(c,d,a,b,M11,14,0x265e5a51) 
d=GG(b,c,d,a,M0,20,0xe9b6c7aa) 
a=GG(a,b,c,d,M5,5,0xd62f105d) 
b=GG(d,a,b,c,M10,9,0x02441453) 
c=GG(c,d,a,b,M15,14,0xd8a1e681) 
d=GG(b,c,d,a,M4,20,0xe7d3fbc8) 
a=GG(a,b,c,d,M9,5,0x21e1cde6) 
b=GG(d,a,b,c,M14,9,0xc33707d6) 
c=GG(c,d,a,b,M3,14,0xf4d50d87) 
d=GG(b,c,d,a,M8,20,0x455a14ed) 
a=GG(a,b,c,d,M13,5,0xa9e3e905) 
b=GG(d,a,b,c,M2,9,0xfcefa3f8)
c=GG(c,d,a,b,M7,14,0x676f02d9) 
d=GG(b,c,d,a,M12,20,0x8d2a4c8a) 
第三轮
a=HH(a,b,c,d,M5,4,0xfffa3942) 
b=HH(d,a,b,c,M8,11,0x8771f681) 
c=HH(c,d,a,b,M11,16,0x6d9d6122) 
d=HH(b,c,d,a,M14,23,0xfde5380c) 
a=HH(a,b,c,d,M1,4,0xa4beea44) 
b=HH(d,a,b,c,M4,11,0x4bdecfa9) 
c=HH(c,d,a,b,M7,16,0xf6bb4b60) 
d=HH(b,c,d,a,M10,23,0xbebfbc70) 
a=HH(a,b,c,d,M13,4,0x289b7ec6) 
b=HH(d,a,b,c,M0,11,0xeaa127fa) 
c=HH(c,d,a,b,M3,16,0xd4ef3085) 
d=HH(b,c,d,a,M6,23,0x04881d05) 
a=HH(a,b,c,d,M9,4,0xd9d4d039) 
b=HH(d,a,b,c,M12,11,0xe6db99e5) 
c=HH(c,d,a,b,M15,16,0x1fa27cf8) 
d=HH(b,c,d,a,M2,23,0xc4ac5665) 
第四轮
a=II(a,b,c,d,M0,6,0xf4292244) 
b=II(d,a,b,c,M7,10,0x432aff97) 
c=II(c,d,a,b,M14,15,0xab9423a7) 
d=II(b,c,d,a,M5,21,0xfc93a039) 
a=II(a,b,c,d,M12,6,0x655b59c3) 
b=II(d,a,b,c,M3,10,0x8f0ccc92) 
c=II(c,d,a,b,M10,15,0xffeff47d) 
d=II(b,c,d,a,M1,21,0x85845dd1) 
a=II(a,b,c,d,M8,6,0x6fa87e4f) 
b=II(d,a,b,c,M15,10,0xfe2ce6e0) 
c=II(c,d,a,b,M6,15,0xa3014314) 
d=II(b,c,d,a,M13,21,0x4e0811a1) 
a=II(a,b,c,d,M4,6,0xf7537e82) 
b=II(d,a,b,c,M11,10,0xbd3af235) 
c=II(c,d,a,b,M2,15,0x2ad7d2bb) 
d=II(b,c,d,a,M9,21,0xeb86d391) 
*/
#include <memory.h>
#include "md5.h" 

/*
用于bits填充的缓冲区，为什么要64个字节呢？因为当欲加密的信息的bits数被512除其余数为448时，
需要填充的bits的最大值为512=64*8 。
*/

unsigned char PADDING[]={
                0x80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void MD5Init(MD5_CTX *context)
{     
     /*将当前的有效信息的长度设成0,这个很简单,还没有有效信息,长度当然是0了*/
     context->count[0] = 0;
     context->count[1] = 0;
     context->state[0] = 0x67452301;
     context->state[1] = 0xEFCDAB89;
     context->state[2] = 0x98BADCFE;
     context->state[3] = 0x10325476;
}

/* MD5 block update operation. Continues an MD5 message-digest
   operation, processing another message block, and updating the
   context. */
/*将与加密的信息传递给md5结构，可以多次调用
context：初始化过了的md5结构
input：欲加密的信息，可以任意长
inputLen：指定input的长度
*/
void MD5Update(MD5_CTX *context,unsigned char *input,unsigned int inputlen)
{
    unsigned int i = 0,index = 0,partlen = 0;

    /* Compute number of bytes mod 64 */
    /*计算已有信息的bits长度的字节数的模64, 64bytes=512bits。
    用于判断已有信息加上当前传过来的信息的总长度能不能达到512bits，
    如果能够达到则对凑够的512bits进行一次处理*/
    index = (context->count[0] >> 3) & 0x3F;

    /*计算已有的字节数长度还差多少字节可以 凑成64的整倍数*/
    partlen = 64 - index;

    /* Update number of bits *//*更新已有信息的bits长度*/
    context->count[0] += inputlen << 3;
    if(context->count[0] < (inputlen << 3))
       context->count[1]++;
    context->count[1] += inputlen >> 29;

    /* Transform as many times as possible.*/
    /*如果当前输入的字节数 大于 已有字节数长度补足64字节整倍数所差的字节数*/
    if(inputlen >= partlen)
    {
        /*用当前输入的内容把context->buffer的内容补足512bits*/
       memcpy(&context->buffer[index],input,partlen);

       /*用基本函数对填充满的512bits（已经保存到context->buffer中） 做一次转换，转换结果保存到context->state中*/
       MD5Transform(context->state,context->buffer);

       /*
        对当前输入的剩余字节做转换（如果剩余的字节<在输入的input缓冲区中>大于512bits的话 ），
        转换结果保存到context->state中
        */
       for(i = partlen;i+64 <= inputlen;i+=64)
           MD5Transform(context->state,&input[i]);
       index = 0;
    }
    else
    {
        i = 0;
    }

    /* Buffer remaining input */
    /*将输入缓冲区中的不足填充满512bits的剩余内容填充到context->buffer中，留待以后再作处理*/
    memcpy(&context->buffer[index],&input[i],inputlen-i);
}

/* MD5 finalization. Ends an MD5 message-digest operation, writing the
   the message digest and zeroizing the context. */
/*获取加密 的最终结果
digest：保存最终的加密串
context：你前面初始化并填入了信息的md5结构
*/
void MD5Final(MD5_CTX *context,unsigned char digest[16])
{
    unsigned int index = 0,padlen = 0;
    unsigned char bits[8];

    /* Pad out to 56 mod 64. */
    /* 计算所有的bits长度的字节数的模64, 64bytes=512bits*/
    index = (context->count[0] >> 3) & 0x3F;

    /*计算需要填充的字节数，padLen的取值范围在1-64之间*/
    padlen = (index < 56)?(56-index):(120-index);

    /* Save number of bits */
    /*将要被转换的信息(所有的)的bits长度拷贝到bits中*/
    MD5Encode(bits,context->count,8);

    /*这一次函数调用绝对不会再导致MD5Transform的被调用，因为这一次不会填满512bits*/
    MD5Update(context,PADDING,padlen);

    /* Append length (before padding) */
    /*补上原始信息的bits长度（bits长度固定的用64bits表示），这一次能够恰巧凑够512bits，不会多也不会少*/
    MD5Update(context,bits,8);

    /* Store state in digest */
    /*将最终的结果保存到digest中。ok，终于大功告成了*/
    MD5Encode(digest,context->state,16);

    /* Zeroize sensitive information. 
    R_memset((POINTER)context, 0, sizeof(*context));*/
}

/* Encodes input (UINT4) into output (unsigned char). Assumes len is
   a multiple of 4. */
/*将4字节的整数copy到字符形式的缓冲区中
output：用于输出的字符缓冲区
input：欲转换的四字节的整数形式的数组
len：output缓冲区的长度，要求是4的整数倍
*/
void MD5Encode(unsigned char *output,unsigned int *input,unsigned int len)
{
    unsigned int i = 0,j = 0;
    while(j < len)
    {
         output[j] = input[i] & 0xFF;
         output[j+1] = (input[i] >> 8) & 0xFF;
         output[j+2] = (input[i] >> 16) & 0xFF;
         output[j+3] = (input[i] >> 24) & 0xFF;
         i++;
         j+=4;
    }
}

/* Decodes input (unsigned char) into output (UINT4). Assumes len is
   a multiple of 4. */
/*与上面的函数正好相反，这一个把字符形式的缓冲区中的数据copy到4字节的整数中（即以整数形式保存）
output：保存转换出的整数
input：欲转换的字符缓冲区
len：输入的字符缓冲区的长度，要求是4的整数倍
*/
void MD5Decode(unsigned int *output,unsigned char *input,unsigned int len)
{
     unsigned int i = 0,j = 0;
     while(j < len)
     {
           output[i] = (input[j]) | (input[j+1] << 8) | (input[j+2] << 16) | (input[j+3] << 24);
           i++;
           j+=4;
      }
}

/* MD5 basic transformation. Transforms state based on block. */
/*
对512bits信息(即block缓冲区)进行一次处理，每次处理包括四轮
state[4]：md5结构中的state[4]，用于保存对512bits信息加密的中间结果或者最终结果
block[64]：欲加密的512bits信息
*/
void MD5Transform(unsigned int state[4],unsigned char block[64])
{
     unsigned int a = state[0];
     unsigned int b = state[1];
     unsigned int c = state[2];
     unsigned int d = state[3];
     unsigned int x[64];
     MD5Decode(x,block,64);
     FF(a, b, c, d, x[ 0], 7, 0xd76aa478); /* 1 */ 
     FF(d, a, b, c, x[ 1], 12, 0xe8c7b756); /* 2 */
     FF(c, d, a, b, x[ 2], 17, 0x242070db); /* 3 */ 
     FF(b, c, d, a, x[ 3], 22, 0xc1bdceee); /* 4 */ 
     FF(a, b, c, d, x[ 4], 7, 0xf57c0faf); /* 5 */ 
     FF(d, a, b, c, x[ 5], 12, 0x4787c62a); /* 6 */ 
     FF(c, d, a, b, x[ 6], 17, 0xa8304613); /* 7 */ 
     FF(b, c, d, a, x[ 7], 22, 0xfd469501); /* 8 */ 
     FF(a, b, c, d, x[ 8], 7, 0x698098d8); /* 9 */ 
     FF(d, a, b, c, x[ 9], 12, 0x8b44f7af); /* 10 */ 
     FF(c, d, a, b, x[10], 17, 0xffff5bb1); /* 11 */ 
     FF(b, c, d, a, x[11], 22, 0x895cd7be); /* 12 */ 
     FF(a, b, c, d, x[12], 7, 0x6b901122); /* 13 */ 
     FF(d, a, b, c, x[13], 12, 0xfd987193); /* 14 */ 
     FF(c, d, a, b, x[14], 17, 0xa679438e); /* 15 */ 
     FF(b, c, d, a, x[15], 22, 0x49b40821); /* 16 */  
     /* Round 2 */ 
     GG(a, b, c, d, x[ 1], 5, 0xf61e2562); /* 17 */ 
     GG(d, a, b, c, x[ 6], 9, 0xc040b340); /* 18 */ 
     GG(c, d, a, b, x[11], 14, 0x265e5a51); /* 19 */ 
     GG(b, c, d, a, x[ 0], 20, 0xe9b6c7aa); /* 20 */ 
     GG(a, b, c, d, x[ 5], 5, 0xd62f105d); /* 21 */ 
     GG(d, a, b, c, x[10], 9,  0x2441453); /* 22 */ 
     GG(c, d, a, b, x[15], 14, 0xd8a1e681); /* 23 */ 
     GG(b, c, d, a, x[ 4], 20, 0xe7d3fbc8); /* 24 */ 
     GG(a, b, c, d, x[ 9], 5, 0x21e1cde6); /* 25 */ 
     GG(d, a, b, c, x[14], 9, 0xc33707d6); /* 26 */ 
     GG(c, d, a, b, x[ 3], 14, 0xf4d50d87); /* 27 */ 
     GG(b, c, d, a, x[ 8], 20, 0x455a14ed); /* 28 */ 
     GG(a, b, c, d, x[13], 5, 0xa9e3e905); /* 29 */ 
     GG(d, a, b, c, x[ 2], 9, 0xfcefa3f8); /* 30 */ 
     GG(c, d, a, b, x[ 7], 14, 0x676f02d9); /* 31 */ 
     GG(b, c, d, a, x[12], 20, 0x8d2a4c8a); /* 32 */  
     /* Round 3 */ 
     HH(a, b, c, d, x[ 5], 4, 0xfffa3942); /* 33 */ 
     HH(d, a, b, c, x[ 8], 11, 0x8771f681); /* 34 */ 
     HH(c, d, a, b, x[11], 16, 0x6d9d6122); /* 35 */ 
     HH(b, c, d, a, x[14], 23, 0xfde5380c); /* 36 */ 
     HH(a, b, c, d, x[ 1], 4, 0xa4beea44); /* 37 */ 
     HH(d, a, b, c, x[ 4], 11, 0x4bdecfa9); /* 38 */ 
     HH(c, d, a, b, x[ 7], 16, 0xf6bb4b60); /* 39 */ 
     HH(b, c, d, a, x[10], 23, 0xbebfbc70); /* 40 */ 
     HH(a, b, c, d, x[13], 4, 0x289b7ec6); /* 41 */ 
     HH(d, a, b, c, x[ 0], 11, 0xeaa127fa); /* 42 */ 
     HH(c, d, a, b, x[ 3], 16, 0xd4ef3085); /* 43 */ 
     HH(b, c, d, a, x[ 6], 23,  0x4881d05); /* 44 */ 
     HH(a, b, c, d, x[ 9], 4, 0xd9d4d039); /* 45 */ 
     HH(d, a, b, c, x[12], 11, 0xe6db99e5); /* 46 */ 
     HH(c, d, a, b, x[15], 16, 0x1fa27cf8); /* 47 */ 
     HH(b, c, d, a, x[ 2], 23, 0xc4ac5665); /* 48 */  
     /* Round 4 */ 
     II(a, b, c, d, x[ 0], 6, 0xf4292244); /* 49 */ 
     II(d, a, b, c, x[ 7], 10, 0x432aff97); /* 50 */ 
     II(c, d, a, b, x[14], 15, 0xab9423a7); /* 51 */ 
     II(b, c, d, a, x[ 5], 21, 0xfc93a039); /* 52 */ 
     II(a, b, c, d, x[12], 6, 0x655b59c3); /* 53 */ 
     II(d, a, b, c, x[ 3], 10, 0x8f0ccc92); /* 54 */ 
     II(c, d, a, b, x[10], 15, 0xffeff47d); /* 55 */ 
     II(b, c, d, a, x[ 1], 21, 0x85845dd1); /* 56 */ 
     II(a, b, c, d, x[ 8], 6, 0x6fa87e4f); /* 57 */ 
     II(d, a, b, c, x[15], 10, 0xfe2ce6e0); /* 58 */ 
     II(c, d, a, b, x[ 6], 15, 0xa3014314); /* 59 */
     II(b, c, d, a, x[13], 21, 0x4e0811a1); /* 60 */
     II(a, b, c, d, x[ 4], 6, 0xf7537e82); /* 61 */ 
     II(d, a, b, c, x[11], 10, 0xbd3af235); /* 62 */ 
     II(c, d, a, b, x[ 2], 15, 0x2ad7d2bb); /* 63 */ 
     II(b, c, d, a, x[ 9], 21, 0xeb86d391); /* 64 */     
     state[0] += a;     
     state[1] += b;     
     state[2] += c;     
     state[3] += d;
}
