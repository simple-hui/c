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
/*输出打印：
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
/*输出打印：
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



