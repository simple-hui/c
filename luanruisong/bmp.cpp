#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    //unsigned short int bfType;       //位图文件的类型，必须为BM
    unsigned int bfSize;            //文件大小，以字节为单位
    unsigned short bfReserverd1; //位图文件保留字，必须为0
    unsigned short bfReserverd2; //位图文件保留字，必须为0
    unsigned int bfOffBits;       //位图文件头到数据的偏移量，以字节为单位
} BitMapFileHeader;
typedef struct {
    unsigned int biSize;             //该结构大小，字节为单位
    unsigned int biWidth;            //图形宽度以象素为单位
    unsigned int biHeight;           //图形高度以象素为单位
    unsigned short biPlanes;      //目标设备的级别，必须为1
    unsigned short biBitcount;    //颜色深度，每个象素所需要的位数
    unsigned int biCompression; //位图的压缩类型
    unsigned int biSizeImage;        //位图的大小，以字节为单位
    unsigned int biXPelsPermeter;    //位图水平分辨率，每米像素数
    unsigned int biYPelsPermeter;    //位图垂直分辨率，每米像素数
    unsigned int biClrUsed;          //位图实际使用的颜色表中的颜色数
    unsigned int biClrImportant;     //位图显示过程中重要的颜色数
} BitMapInfoHeader;
typedef struct {  
	unsigned char rgbBlue; //该颜色的蓝色分量 
	unsigned char rgbGreen; //该颜色的绿色分量 
	unsigned char rgbRed; //该颜色的红色分量 
	unsigned char rgbReserved; //保留值 
} Point;

void Rotate180(unsigned char * pSrc,unsigned int width,unsigned int biBitcount,unsigned int imgSize)  {  
    unsigned int pointSize = sizeof(Point);
    unsigned int rowSize = pointSize * (biBitcount*width/32);
    unsigned int cloSize = imgSize / rowSize;
    printf("-------------%s-------------------\n","start rotate 180");
    printf("rowSize   %u\n",rowSize);
    printf("cloSize   %u\n",cloSize);
    printf("pointSize %u\n",pointSize);
    printf("imgSize   %u\n",imgSize);
    //把image data 按照像素点 排列进入二维数组
    Point clo[cloSize][width];
    for(int i=0;i<cloSize;i++){
        int p = i*rowSize;
        for(int j=0;j<width;j++){
            int pp = p+j*4;
            Point c;
            c.rgbBlue = pSrc[pp];
            c.rgbGreen = pSrc[pp+1];
            c.rgbRed = pSrc[pp+2];
            c.rgbReserved = pSrc[pp+3];
            clo[i][j] = c;
        }
    }
    //二位数组 下角标转换
    Point clo2[cloSize][width];
    for(int i=0;i<cloSize;i++){
        for(int j=0;j<width;j++){
            clo2[i][j] = clo[cloSize-i-1][width-j-1];
        }
    }
    //按字节重新写入原数组
    for(int i=0;i<cloSize;i++){
        int p = i*rowSize;
        for(int j=0;j<width;j++){
            int pp = p+j*4;
            pSrc[pp] = clo2[i][j].rgbBlue;
            pSrc[pp+1] = clo2[i][j].rgbGreen;
            pSrc[pp+2] = clo2[i][j].rgbRed;
            pSrc[pp+3] = clo2[i][j].rgbReserved;
        }
    }   
}  

int main(){
    FILE *imgFile;
    FILE *tagImgFile;
    BitMapFileHeader bfh;
    BitMapInfoHeader bih;
    if ((imgFile = fopen("timg.bmp", "r")) == NULL){
        printf("can't open the bmp imgae.\n ");
        exit(0);
    }
    if ((tagImgFile = fopen("1.bak.bmp", "w+")) == NULL){
        printf("can't open the bmp imgae.\n ");
        exit(0);
    }
    //先读取类型 不是bitmap的话 不进行处理
    unsigned short fileType;
    
    fread(&fileType, sizeof(unsigned short), 1, imgFile);  
    if (fileType == 0x4D42)  {
        fread(&bfh, sizeof(BitMapFileHeader), 1, imgFile);  
        fread(&bih, sizeof(BitMapInfoHeader), 1, imgFile);  
        // fread(&clr, sizeof(ClRgbQuad), 1, imgFile);  
        printf("-------------%s-------------------\n","file header");
        printf("bfSize       %u\n",bfh.bfSize);
        printf("bfReserverd1 %u\n",bfh.bfReserverd1);
        printf("bfReserverd2 %u\n",bfh.bfReserverd2);
        printf("bfOffBits    %u\n",bfh.bfOffBits);
        printf("biSize       %u\n",bih.biSize);
        printf("biWidth      %u\n",bih.biWidth);
        printf("biHeight     %u\n",bih.biHeight);
        printf("biBitcount   %u\n",bih.biBitcount);
        unsigned int tmpSize = bih.biSize-sizeof(bih);
        unsigned int imgSize = bfh.bfSize - bfh.bfOffBits;
        //读取超出54字节外的未知信息
        unsigned char tmp[tmpSize];
        fread(&tmp, tmpSize,1, imgFile);
        unsigned char src[imgSize];
        //读取位图的image data
        fread(&src, sizeof(src),1, imgFile);
        //旋转180
        Rotate180(src,bih.biWidth,bih.biBitcount,imgSize);

        printf("-------------%s-------------------\n","bitmap Rotate 180 overr write to file");
        //因为旋转的180 所以头文件信息不用修改 直接写回去即可
        fwrite(&fileType,sizeof(unsigned short), 1, tagImgFile);
        fwrite(&bfh, sizeof(BitMapFileHeader), 1, tagImgFile);  
        // bih.biWidth = tempLength;
        // bih.biHeight = tempLength;
        fwrite(&bih, sizeof(BitMapInfoHeader), 1, tagImgFile);  
        fwrite(&tmp, tmpSize,1, tagImgFile);  
        fwrite(&src, imgSize,1, tagImgFile);  
        printf("-------------%s-------------------\n","write to file overr");
    } else {
        printf("is not bitmap file");
    } 

}