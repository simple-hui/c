// 1、输入一个圆半径r，当r>＝0时，计算并输出圆的面积和周长，否则，输出提示信息。
#include<stdio.h>
int main()
{
	double PI=3.14;
	printf("请输入圆半径：");
	float f;
	scanf("%f",&f);
	if ( f > 0 ){
	  printf("圆面积：%7.2f",PI*f*f);
		printf("圆周长：%7.2f",2*PI*f);
	} else {
		printf("请输入大于0的数（圆半径");
	}
	return 0;
}

// 2、编一程序每个月根据每个月上网时间计算上网费用，计算方法如下，要求当输入每月上网小时数,显示该月总的上网费用。
#include <stdio.h>
int main()
{
	int a = 0;
	printf("输入小时数：");
	scanf("%d",&a);
	if( a <= 10){
		printf("费用为：%d\n",30);
	}else if( a >= 50){
		printf("费用为：%.2f\n",a* 2.5);
	}else{
		printf("费用为: %d\n",a*3);
	}
	return 0;
}

// 3、从键盘输入5个整数，统计其中正数、负数和零的个数，并在屏幕上输出。
#include <stdio.h>
int main()
{
	int i,a,sum1,sum2,sum3;
	sum1=0;
	sum2=0;
	sum3=0;
	for (i=1;i<=5;i++)
	{
		printf("请输入第%d个数：",i);
		scanf("%d",&a);
		printf("\n");
		if(a==0) sum1=sum1+1;
		else if(a>0) sum2=sum2+1;
		else if(a<0) sum3=sum3+1;
	}
	printf("0：%d\n",sum1);
	printf("+：%d\n",sum2);
	printf("-：%d\n",sum3);
	return 0;
}
// 4、编程序实现从键盘上输入5个数，输出累加和以及平均值并输出
#include <stdio.h>
int main()
{
	float a=0,b,c,d,e;
	scanf("%f,%f,%f,%f,%f",&a,&b,&c,&d,&e);
	printf("%f\n",a);
	printf("和为：%7.2f",(a+b+c+d+e));
	printf("平均值：%7.2f",((a+b+c+d+e)/5.0));
	return 0;

}
// 5、编程序实现从键盘上输入5个数，求所有数的乘积并输出。
#include <stdio.h>
int main()
{
	float result=1;
	for(int i=1;i<6;i++){
		float a;
		printf("请输入第%d个数",i);
		scanf("%f",&a);
		result=result*a;
	}
	printf("结果为:%f",result);
	return 0;
}
// 6、输入三个数，把这三个数由小到大输出。
#include <stdio.h>

int main()
{
	int a,b,c,i;
	printf("请输入数字，a,b,c:\n");
	scanf("%d,%d,%d",&a,&b,&c);
	if(a > b)						//a,b 的数字进行交换
	{
		i = a;
		a = b;
		b = i;
	}
	if(a > c)
	{
		i = a;
		a = c;
		c = i;
	}
	if(b > c)
	{
		i = b;
		b = c;
		c = i;
	}
	printf("数字从小到大排列为：\n");
	printf("%d,%d,%d\n",a,b,c);
	return 0;
}
// 7、输入三个字符，反向输出3个字符和他们对应的ASCII码。
#include<stdio.h>
int main()
{
	char a, b, c;
	a = getchar();
	b = getchar();
	c = getchar();
	printf("%c=%d,%c=%d,%c=%d",a,a,b,b,c,c);

	return 0;
}
// 8、输入两个数和算术运算符（+,-,*,/），根据不同的运算符输出不同的运算结果。（if语句）
#include <stdio.h>
int main(){
	double a = 0,b = 0,result = 0;
	char c;
	printf("请输入两个数：");
	scanf("%lf %lf",&a,&b);
	printf("请输入想要的运算符：");
	scanf("%c",&c);
	c = getchar();

	if(c == '+')
	{
		result = a + b;
	}
	else if(c == '-')
	{
		result = a - b;
	}
	else if(c == '*')
	{
		result = a * b;
	}
	else if(c == '/')
	{
		if(b == 0)
		{
			printf("除数不能是0，请检查输入");
			return 0;
		}
		else
		{
			result = a / b;
		}
	}
	else
	{
		printf("输入的运算符有误，请检查输入");
		return 0;
	}
	printf("最终的计算结果为：%f",result);
	return 0;
}
// 9、输入两个数和算术运算符（+,-,*,/），根据不同的运算符输出不同的运算结果。（switch语句）
#include<stdio.h>
int main()
{
	int a, b, r;
	char c;
	printf("请以加数运算符加数的形式输入，例如5+8\n");
	scanf("%d%c%d", &a, &c, &b);
	switch (c)
	{
	case '+':r = a + b; break;
	case '-':r = a - b; break;
	case '*':r = a*b; break;
	case '/':
		{
			if (b == 0)
			{
				printf("除数不能为0");
				return 0;
			}
			else r = a / b;
			break;
		}
		default:
		{
			printf("请输入正确的运算符");
			return 0;
		}
	}
	printf("%d%c%d=%d\n", a, c, b, r);
	return 0;

}
// 10、有一个分数序列：2/1，3/2，5/3，8/5，13/8，……编程求这个序列的前10项之和。（提示：分子为前一个数分子分母之和，分母为前一个数的分子）
#include<stdio.h>
int main()
{
	int i, t, n = 10;
	float a = 2, b = 1, s = 0;
	for (i = 1; i <= n; i++)
	{
		s = s + a / b;
		t = a;
		a = a + b;
		b = t;
	}
	printf("sum=%6.2f", s);
	return 0;
}
/*11、输出打印：
1   2   3   4   5
6   7   8   9   10
11  12  13  14  15
16  17  18  19  20
*/
#include<stdio.h>
int main()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			printf("%d\t", (i - 1) * 5 + j);
		}
		printf("\n");

	}
	return 0;
}
/*12、输出打印：
1    2    3    4   5
2    4    6    8   10
3    6    9    12  15
4    8    12   16  20
*/
#include<stdio.h>
int main()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			printf("%d\t", i*j);
		}
		printf("\n");

	}
	return 0;
}
// 13、在全系1000学生中，征集慈善募捐，当总数达到10万元时就结束，统计此时捐款的人数，以及平均每人捐款的数目。
#include <stdio.h>
#define SUM 100000
int main()
{
	float amount, aver, total;   
	int i;
	for (i = 1, total = 0; i <= 1000; i++)
	{
		printf("please enter amount:");
		scanf("%f", &amount);
		total = total + amount;
		if (total >= SUM) break;
	}
	aver = total / i;  
	printf("num = %d\naver = %10.2f\n", i, aver);
	return 0;
}
// 14、要求输出100～200之间的不能被3整除的数。
#include<stdio.h>
int main()
{
	for (int n=100; n <= 200; n++)
	{
		if (n % 3 == 0)
			continue;
		printf("%d  ", n);
	}
	return 0;
}
// 15、求方程的根，由键盘输入a,b,c。假设a,b,c的值任意，并不保证。需要在程序中进行判别，如果，就计算并输出方程的两个实根，否则就输出“方程无实根”的信息。
#include <stdio.h>
#include  <math.h>
int main()
{
	double a, b, c, disc, x1, x2, p, q;
	scanf("%lf%lf%lf", &a, &b, &c);
	disc = b*b - 4 * a*c;
	if (disc<0)
		printf("has not real roots\n");
	else
	{
		p = -b / (2.0*a);
		q = sqrt(disc) / (2.0*a);
		x1 = p + q;
		x2 = p - q;
		printf("real roots : \nx1 = %7.2f\nx2 = %7.2f\n", x1, x2);
	}
	return 0;
}
// 16、输入两个实数，按代数值由小到大的顺序输出这两个数。
#include <stdio.h>
int main()
{
	float a, b, t;
	scanf("%f,%f", &a, &b);
	if (a>b)
	{
		t = a;
		a = b;
		b = t;
	}
	printf("%5.2f,%5.2f\n", a, b);
	return 0;
}

/*用冒泡法对10个整数排序*/
#include<stdio.h>
int main(){
	int a[10] = { 1, 2, 5, 6, 12, 56, 3, 64, 78, 10 };
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9 - i; j++){
			if (a[j] > a[j + 1]){
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}	
	for (int i = 0; i < 10; i++){
		printf("%d ", a[i]);
	}	
	return 0;
}

/*写一个冒泡排序的函数*/
#include<stdio.h>
int main(){
	int sort1(int a[]);
	int b[10] = { 1, 2, 5, 6, 12, 56, 3, 64, 78, 10 };
	sort1(b);
	for (int i = 0; i < 10; i++){
		printf("%d ", b[i]);
	}	
	return 0;
}
int sort1(int a[]){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9 - i; j++){
			if (a[j] > a[j + 1]){
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	return 0;
}

/*选择法对10个整数从小到大排序*/
#include<stdio.h>
int main(){
	int a[10] = { 1, 2, 5, 6, 12, 56, 3, 64, 78, 10 };
	for (int i = 0; i < 9; i++){
		int pos = i, min = a[pos];
		for (int j = i + 1; j < 10; j++){
			if (min > a[j]){
				pos = j;
				min = a[j];
			}
		}
		int t = a[pos];
		a[pos] = a[i];
		a[i] = t; 
	}
	for (int i = 0; i < 10; i++){
		printf("%d ", a[i]);
	}
	return 0;
}


/*写一个选择排序的函数在主函数调用对10个整数从小到大进行排序*/
#include<stdio.h>
int main(){
	int sort2(int a[]);
	int b[10] = { 1, 2, 5, 6, 12, 56, 3, 64, 78, 10 };
	sort2(b);
	for (int i = 0; i < 10; i++){
		printf("%d ", b[i]);
	}	
	return 0;
}
int sort2(int a[]){
	for (int i = 0; i < 9; i++){
		int pos = i, min = a[pos];
		for (int j = i + 1; j < 10; j++){
			if (min > a[j]){
				pos = j;
				min = a[j];
			}
		}
		int t = a[pos];
		a[pos] = a[i];
		a[i] = t;
	}
	return 0;
}

/*将两个字符串连接起来，不使用strcat函数*/
#include <stdio.h>
int main(){
	char s1[80], s2[40];
	int i = 0, j = 0;
	printf("input string1:");
	scanf("%s", s1);
	printf("input string2:");
	scanf("%s", s2);
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		s1[i++] = s2[j++];
	s1[i] = '\0';
	printf("\nThe new string is:%s\n", s1);
	return 0;
}

/*写一个函数，将两个字符串连接，在主函数中输出连接后的字符串*/
#include <stdio.h>
int main(){
	void connect(char s1[],char s2[]);
	char c1[80], c2[40];	
	printf("input string1:");
	scanf("%s", c1);
	printf("input string2:");
	scanf("%s", c2);
	connect(c1,c2);
	printf("\nThe new string is:%s\n", c1);
	return 0;
}
void connect(char s1[],char s2[]){
	int i = 0, j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		s1[i++] = s2[j++];
	s1[i] = '\0';
}

/*利用函数递归调用输出Fibonacci数列前20项*/
#include<stdio.h>
//递归
int Fabio1(int n){
	if(n == 1||n ==2){
		return 1;
	}else{
		return Fabio(n-1) + Fabio(n-2);
	}
} 
int main(){
	for(int i=1;i<=20;i++){
		printf("%2d",Fabio1(i));
	}
	printf("\n");
	return 0;
}

/*利用循环求n!*/
#include<stdio.h>
int main(){
	int n;  
	int y;
	printf("input an integer number:");
	scanf("%d",&n);  
	int y=1;
	for(int i=2;i<=n;i++){
		y=y*i;	
	}
	printf("%d!=%d\n",n,y);
	return 0;
}

/*利用递归方法求n!*/
#include <stdio.h>
int main(){
	int fac(int n); 
	int n;  
	int y;
	printf("input an integer number:");
	scanf("%d",&n);  
	y=fac(n);
	printf("%d!=%d\n",n,y);
	return 0;
}
int fac(int n){
     int f;
     if(n<0){
     	printf("n<0,data error!");
     }else if(n==0 | | n==1){
     	f=1;
     }else{
     	f=fac(n-1)*n; 
     }
     return(f);
 }


/*分别输出一个3*3的整形矩阵两条对角线元素之和*/
#include<stdio.h>
int main(){
	int a[3][3] = { 1, 2, 6, 4, 5, 6, 7, 8, 9 };
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < 3; i++){
		sum1 = sum1 + a[i][i];
		sum2 = sum2 + a[i][2 - i];
	}
	printf("sum1=%d ,sum2=%d ", sum1, sum2);
	return 0;
}

/*写一个函数，在自定义函数中分别输出一个3*3的整形矩阵两条对角线元素之和*/
#include<stdio.h>
int main(){
	int diaSum(int a[][3]);
	int b[3][3] = { 1, 2, 6, 4, 5, 6, 7, 8, 9 };
	diaSum(b);
	return 0;
}
int diaSum(int a[][3]){
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < 3; i++){
		sum1 = sum1 + a[i][i];
		sum2 = sum2 + a[i][2 - i];
	}
	printf("sum1=%d ,sum2=%d ", sum1, sum2);
	return 0;
}

/*写一个函数，在main函数中分别输出一个3*3的整形矩阵两条对角线元素之和*/
#include<stdio.h>
int main(){
	int diaSum(int a[][3],int sum[2]);
	int b[3][3] = { 1, 2, 6, 4, 5, 6, 7, 8, 9 };
	int s[2] = { 0, 0 };
	diaSum(b,s);
	printf("sum1=%d ,sum2=%d ", s[0], s[1]);
	return 0;
}
int diaSum(int a[][3],int s[2]){
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < 3; i++){
		s[0] = s[0] + a[i][i];
		s[1] = s[1] + a[i][2 - i];
	}
	return 0;
}

/*输入一个四位数字，要求输出这4个数字字符*/
#include <stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	if (a / 1000 >9 || a / 1000 < 1){
		printf("请输入四位数字！");
		scanf("%d", &a);
		if (a / 1000 >9 || a / 1000 < 1 ){
			return 0;
		}	
	}
	char b[4];
	b[0] = a / 1000 + 48;
	b[1] = (a % 1000) / 100 + 48;
	b[2] = ((a % 1000) % 100) / 10 + 48;
	b[3] = ((a % 1000) % 100) % 10 + 48;
	for (int i = 0; i < 4; i++){
		printf("%c ", b[i]);
	}
	return 0;	
}


/*写一个函数，输入一个四位数字，在自定义函数中要求输出*/
#include <stdio.h>
int main(){
	void change(int num);
	int a;
	scanf("%d", &a);
	if (a / 1000 >9 || a / 1000 < 1){
		printf("请输入四位数字！");
		scanf("%d", &a);
		if (a / 1000 >9 || a / 1000 < 1){
			return 0;
		}
	}
	change(a);
	return 0;
}

void change(int num){
	char b[4];
	b[0] = num / 1000 + 48;
	b[1] = (num % 1000) / 100 + 48;
	b[2] = ((num % 1000) % 100) / 10 + 48;
	b[3] = ((num % 1000) % 100) % 10 + 48;
	for (int i = 0; i < 4; i++){
		printf("%c ", b[i]);
	}	
}


/*写一个函数，输入一个四位数字，在main函数中要求输出*/
#include <stdio.h>
int main(){
	void change(int num,char str[4]);
	int a;
	scanf("%d", &a);
	if (a / 1000 >9 || a / 1000 < 1){
		printf("请输入四位数字！");
		scanf("%d", &a);
		if (a / 1000 >9 || a / 1000 < 1){
			return 0;
		}	
	}
	char b[4];
	change(a,b);
	for (int i = 0; i < 4; i++){
		printf("%c ", b[i]);
	}	
	return 0;
}

void change(int num, char str[4]){
	str[0] = num / 1000 + 48;
	str[1] = (num % 1000) / 100 + 48;
	str[2] = ((num % 1000) % 100) / 10 + 48;
	str[3] = ((num % 1000) % 100) % 10 + 48;
}




