#include <stdio.h>
#include <math.h>
void input_int(int *input) //Проверка на целое число
{
    float pr;
    do {
        printf("Целое число: ");
        scanf("%f", &pr);
        *input=pr;
       }   while ((*input-pr)!=0);
}
int nechet_arr(int *arr, int lenght)
{
    int flag=0;
    int i;
    for(i=0;i<lenght;i++)
    {
        if(arr[i]%2!=0)
        {
            arr[i]=arr[i]*2;
            flag=1;
        }
    }
    return flag;
}
int calcSquareEq(int a, int b, int c, double* x1, double* x2) //Вычисление корней
{

    int d;//Дискриминант
    d=b*b-4*a*c;
    if (d<0) return -1;
    if (d==0)
    {
        *x1=-1*b/(2*a); return 0;
    }
    *x1=(sqrt(d)-b)/(2*a);
    *x2=(-b-sqrt(d))/(2*a);
    return 1;
}
void first()
{
    int a, b, c, flag;
    double x1, x2;
    printf("Используя заголовочный файл <math.h>, описать функцию: int calcSquareEq(int a, int b, int c, double* x1, double* x2); Которая будет решать квадратное уравнение вида a * x ** 2 + b * x + c = 0\n");
    printf("Введите целое a:\n");
    input_int(&a);
    printf("Введите целое b:\n");
    input_int(&b);
    printf("Введите целое c:\n");
    input_int(&c);
    flag=calcSquareEq (a,b,c,&x1,&x2);
    if(flag<0) printf("Уравнение %dx^2+%dx+%d=0 не имеет решений\n",a,b,c);
    else
    {
        if(flag==0) printf("Уравнение %dx^2+%dx+%d=0 имеет одно решение x = %.2lf\n",a,b,c, x1);
        else printf("Уравнение %dx^2+%dx+%d=0 имеет два решения x1 = %.2lf\n  x2 = %.2lf\n",a,b,c, x1,x2);
    }
}
void second()
{
    const int lenght_arr=10;
    int i;
    int arr[lenght_arr];
    printf("Функция должна вернуть ноль, если в массиве нет нечётных чисел, в противном случае удвоить все нечётные числа в массиве и вернуть единицу.\n");
    for(i=0;i<lenght_arr;i++)
    {
        printf("Введите целый элемент a[%d] массива\n",i);
        input_int(&arr[i]);
    }
    if(nechet_arr(&arr,lenght_arr))
    {
        printf("Массив был изменен:\n");
        for(i=0;i<lenght_arr;i++)
            printf("%d  ",arr[i]);
        printf("\n");
    }
    else printf("Массив не изменен\n");
}
int main()
{
    int choise;
    while(1)
    {
        printf("Выберете задание\n1. Первое\n2. Второе\n0. Выход\n");
        input_int(&choise);
        switch(choise)
        {
            case(1): {first(); break;}
            case(2): {second(); break;}
            case(0): return 0;
        }


    }
    return 0;
}
