#include <stdio.h>
#include <stdlib.h>
//先声明后实现，为了在第一页打印主要函数内容
int Add(int a, int b);//加法
int Sub(int a, int b);//减法
int Mul(int a, int b);//乘法
int Div(int a, int b);//除法
void menu();//菜单1展示
void menu2(int ret);//菜单2展示

int main(){
	int input = 1;
	int x,y,ret = 0;
	//函数数组 固定写法
	int(*p[5])(int, int) = { 0, Add, Sub, Mul, Div };  
	while (input){
		//有计算结果，进入复用分支
		if (ret != 0) {
			menu2(ret);
			scanf("%d", &input);
			if (input < 2){
				if (input > 0){
					system("clear");
					x = ret;//复用上次计算结果
					menu();
					if (!scanf("%d", &input)) {
						system("clear");
						printf("\n请输入有效的数字\n");
						while (getchar() != '\n');
						continue;
					}
					if (input < 5 && input > 0){
						printf("输入一个数：");
						if (!scanf("%d", &y)) {
							system("clear");
							printf("\n请输入有效的数字\n");
							while (getchar() != '\n');
							continue;
						}
						ret = p[input](x, y);
					}
					system("clear");
					continue;
				}
				system("clear");
				printf("\n请输入有效的数字\n");
				return 0;
			}
		}
		//默认新分支，使用2个数字进行运算
		menu();		
		if (!scanf("%d", &input)) {
			system("clear");
			printf("\n请输入有效的数字\n");
			while (getchar() != '\n');
			continue;
		}
		if (input < 5 && input > 0){
			printf("输入两个数(x,y)：");
			if (!scanf("%d,%d", &x,&y)) {
				system("clear");
				printf("\n请输入有效的数字\n");
				while (getchar() != '\n');
				continue;
			}
			ret = p[input](x, y);
			system("clear");
			continue;
		}
		if (input != 0 ) {
			system("clear");
			printf("\n请输入有效的数字\n");
		}
	}
	return 0;
}

//工具函数，放在后面实现 不能挡住main
int Add(int a, int b){
	return a + b;
}
int Sub(int a, int b){
	return a - b;
}
int Mul(int a, int b){
	return a * b;
}
int Div(int a, int b){
	if ( b == 0 ){
		printf("除数不能为0 \n");
		return 0;
	}
	return a / b;
}

void menu(){
	printf("*************************************\n");
	printf("***** 1.add      2.sub **************\n");
	printf("***** 3.mul      4.div **************\n");
	printf("******     0.exit      **************\n");
	printf("*************************************\n");
	printf("请选择：");
}

void menu2(int ret){
	printf("*************************************\n");
	printf("******** exec result (%d) ***********\n",ret);
	printf("***** 1 continue with result  *******\n");
	printf("***** 2 new Number ******************\n");
	printf("******     0.exit      **************\n");
	printf("*************************************\n");
	printf("请选择：");
}