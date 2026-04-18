#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define   SIZE   10
//*******************************************************************************************************
// FUNCTION FOR 5 BASIC OPERATORS [Sum, multiplication, subtraction, division, modulo] :

int basic_cal()
{
    float a, b, c;
    int num, d;

    start:

    printf("Select basic operation : \n\t 1. Summation\n\t 2. Subtraction \n\t 3. Multiplication\n\t 4. Division\n\t 5. Modulo\n");
    scanf("%d", &num);

    if (num < 1 || num > 5)
    {
        printf("### Enter appropriate number for operation ###\n");
        goto start;
    }

    printf("Enter value of a : ");
    scanf("%f", &a);

    printf("Enter value of b : ");
    scanf("%f", &b);

    switch(num)
    {
    case 1:
        c = a+b;
        printf("\n>>> Summation of a and b is %f\n", c);
        break;

    case 2:
        c =a-b;
        printf("\n>>> Subtraction of a and b is %f\n", c);
        break;

    case 3:
        c =a*b;
        printf("\n>>> Multiplication of a and b is %f\n", c);
        break;

    case 4:

        if (b == 0)
        {
            printf("\n<ERROR>\n");
            break;
        }

        c = a / b;
        printf("\n>>> Division of a and b is %f\n", c);
        break;

    case 5:

        if (b == 0)
        {
            printf("\n<UNDEFINE>\n");
            break;
        }

        c = (int)a % (int)b;
        printf("\n>>> a modulo b is %.2f\n", c);
        break;
    }

    return 0;
}

//*******************************************************************************************************
// FUNCTION FOR MATRIX MULTIPLICATION :

int matrix_multiplication()
{
    int i, j, k, m, n, x, y;

    start1:

    for(i=0; i<80; i++)
        printf("-");

    printf("\nEnter no. of rows for matrix 1 : ");
    scanf("%d", &m);
    printf("Enter no. of column for matrix 1 : ");
    scanf("%d", &n);
    printf("Enter no. of rows for matrix 2 : ");
    scanf("%d", &x);
    printf("Enter no. of column for matrix 2 : ");
    scanf("%d", &y);

    if(n != x)
    {
        printf("\n<< Enter appropriate order of matrix >>\n");
        printf("Hint : [column of matrix 1 and rows of matrix 2 should be same]");
        goto start1;
    }

    int arr1[m][n], arr2[x][y], arr3[m][y];

    printf("\n\nEnter elements of matrix 1 : \n");

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("[%d][%d] = ", i+1, j+1);
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter elements of matrix 2 : \n");

    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            printf("[%d][%d] = ", i+1, j+1);
            scanf("%d", &arr2[i][j]);
        }
    }

    for(i=0; i<m; i++)
    {
        for(j=0; j<y; j++)
        {
            arr3[i][j]= 0;
            for(k=0; k<n; k++)
            {
                arr3[i][j] += arr1[i][k]*arr2[k][j];
            }
        }
    }

    printf("\n");
    printf("The multiplication matrix of matrix 1 and matrix 2 is : \n");

    for(i=0; i<m; i++)
    {
        for(j=0; j<y; j++)
        {
            printf("%d\t", arr3[i][j]);
        }
        printf("\n");
    }

    return 0;
}

//*******************************************************************************************************
// FUNCTION FOR DETERMINNT OF MATRIX :
//
int det_matrix()
{
	 float a[SIZE][SIZE], x[SIZE], ratio, det=1;
	 int i,j,k,n;

	 /* Inputs */
    /* 1. Reading number of unknowns */
	 printf("Enter Order of Matrix: ");
	 scanf("%d", &n);

	 /* 2. Reading Matrix */
	 printf("\nEnter Coefficients of Matrix: \n");
	 for(i=0;i< n;i++)
	 {
		  for(j=0;j< n;j++)
		  {
			   printf("a[%d][%d]=",i,j);
			   scanf("%f", &a[i][j]);
		  }
	 }

	 for(i=0;i< n;i++)
	 {
		  if(a[i][i] == 0.0)
		  {
			   printf("Mathematical Error!");
			   exit(0);
		  }
		  for(j=i+1;j< n;j++)
		  {
			   ratio = a[j][i]/a[i][i];

			   for(k=0;k< n;k++)
			   {
			  		a[j][k] = a[j][k] - ratio*a[i][k];
			   }
		  }
	 }

	 printf("\nUpper Triangular Matrix: \n");
	 for(i=0;i< n;i++)
	 {
		  for(j=0;j< n;j++)
		  {
			   printf("%0.2f\t",a[i][j]);
		  }
		  printf("\n");
	 }

	 for(i=0;i< n;i++)
     {
         det = det * a[i][i];
     }

	 printf("\n\nDeterminant of given matrix is: %0.3f", det);

	 return 0;
}

//*******************************************************************************************************
// FUNCTION FOR ADDITION OF MATRIX :

int add_matrix()
{
    int i, j, k, m, n, x, y;

    start1:

    printf("Enter no. of rows for matrix 1 : ");
    scanf("%d", &m);
    printf("Enter no. of column for matrix 1 : ");
    scanf("%d", &n);
    printf("Enter no. of rows for matrix 2 : ");
    scanf("%d", &x);
    printf("Enter no. of column for matrix 2 : ");
    scanf("%d", &y);

    if(m != x || n != y)
    {
        printf("\n<< Enter appropriate order of matrix >>\n");
        printf("Hint : [Order of matrix 1 and order of matrix 2 should be same]");
        goto start1;
    }

    int arr1[m][n], arr2[x][y], arr3[m][y];

    printf("\n\nEnter elements of matrix 1 : \n");

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("[%d][%d] = ", i+1, j+1);
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter elements of matrix 2 : \n");

    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            printf("[%d][%d] = ", i+1, j+1);
            scanf("%d", &arr2[i][j]);
        }
    }

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            arr3[i][j] = 0;
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printf("\nAddition of matrix 1 and matrix 2 is : \n");

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t", arr3[i][j]);
        }
        printf("\n");
    }
}

//*******************************************************************************************************
// FUNTION FOR TRIGONOMETRY :

int trigo()
{
    int i, j, k, n;
    float angle, radian;

    printf("Select Trigonometric operation :\n\t 1. sin\n\t 2. cos\n\t 3. tan\n\t 4. cosec\n\t 5. sec\n\t 6. cot\n");
    scanf("%d", &n);

    int angle1()
    {
        printf("Enter angle in degree : ");
        scanf("%f", &angle);
        radian = (3.141592653589793238/180) * angle;
    }
    switch(n)
    {
    case 1:
        angle1();
        printf("\n>>> sin(%f) = %.4f\n", angle, sin(radian));
        break;

    case 2:
        angle1();
        printf("\n>>> cos(%f) = %.4f\n", angle, cos(radian));
        break;

    case 3:
        angle1();
        printf("\n>>> tan(%f) = %.4f\n", angle, tan(radian));
        break;

    case 4:
        angle1();
        printf("\n>>> cosec(%f) = %.4f\n", angle, 1/sin(radian));
        break;

    case 5:
        angle1();
        printf("\n>>> sec(%f) = %.4f\n", angle, 1/cos(radian));
        break;

    case 6:
        angle1();
        printf("\n>>> cot(%f) = %.4f\n", angle, 1/tan(radian));
        break;
    }
}

//*******************************************************************************************************
// FUNCTION FOR LOGARITHM AND ANTILOGARITHM :
// LOGARITHM :

int logarithm()
{
    int i, j, k;
    float m, n, squrt=0;

    for(i=0; i<80; i++)
        printf("-");

    printf("\nEnter the number : ");
    scanf("%f", &n);

    if(n <= 0)
    {
        printf("\n>>> Log is defined for number which is greater than 0\n");
        exit(0);
    }

    m = n;
    for(i=0; i<15; i++)
    {
        squrt = sqrt(n);
        n = squrt;
    }

    squrt--;    // want to minus 1 from squrt

    squrt = squrt / 0.000070271;

    printf("\n>>> Log of %f is %f\n", m, squrt);

    return 0;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ANTILOGARITHM :

int antilogarithm()
{
    int i, j, k;
    float m, n, anti;

    for(i=0; i<80; i++)
        printf("-");

    printf("\nEnter the number : ");
    scanf("%f", &n);

    anti = n / 227695;

    anti++;

    for(i=0; i<19; i++)
    {
        anti = anti * anti;
    }

    printf("\n>>> Antilog of %f is %f\n", n, anti);

    return 0;
}

//*******************************************************************************************************
// FUNCTION FOR DIRTY OF NUMBER CALCULATION :

int dirty_power()
{
    int i, n, m;
    float w, x, y, z;

    for(i=0; i<120; i++)
        printf("-");

    printf("\n>>> This is to calculate a number of form (x^y), here x and y both fraction or only y is fraction number <<<\n");

    printf("\nEnter number 1 (X) : ");
    scanf("%f", &x);

    printf("Enter number 2 (Y) : ");
    scanf("%f", &y);

    w = x;
    for(i=0; i<12; i++)
    {
        z = sqrt(x);
        x = z;
    }

    x--;    // want to minus 1

    x = x*y;

    x++;    //want to add 1

    for(i=0; i<12; i++)
    {
        x = x * x;
    }

    printf("\n>>> The value of (%f)^(%f) is %f", w, y, x);
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// FUNCTION FOR X AND Y ARE BOTH INTEGERS :

int int_power()
{
   int i, x, y, n; long int m=1;

    for(i=0; i<120; i++)
        printf("-");

    printf("\t>>> This is to calculate a number of form (x^y), here x and y both are integer or x can be fraction number <<<\n");

    printf("\nEnter number 1 (X) : ");
    scanf("%d", &x);

    printf("Enter number 2 (Y) : ");
    scanf("%d", &y);

    for(i=0; i<y; i++)
    {
        m = m*x;
    }

    printf("\n>>> The value of (%d)^(%d) is %ld\n", x, y, m);
}
//*******************************************************************************************************
// FUNCTION FOR INVERSE TRIGONOMETRY :

int inverse_trigo()
{
    int i, j, n;
    float num, z, a;

    for(i=0; i<120; i++)
        printf("-");

    printf("\nSelect operation : \n\t 1. sin inverse\n\t 2. cos inverse\n\t 3. tan inverse\n\t 4. cosec inverse\n\t 5. sec inverse\n\t 6. cot inverse\n");
    scanf("%d", &n);

    switch(n)
    {
    case 1:
        printf("\nNOTE : Enter value in range[-1, 1].\n");

        printf("Enter value : ");
        scanf("%f", &num);

        z = asin(num);
        z = z*(180/3.14159265);

        printf("\nInverse of sin(%f) is %f", num, z);
        printf("\n");
        break;

    case 2:
        printf("\nNOTE : Enter value in range[-1, 1].\n");

        printf("Enter value : ");
        scanf("%f", &num);

        z = acos(num);
        z = z*(180/3.14159265);

        printf("\nInverse of cos(%f) is %f", num, z);
        printf("\n");
        break;

    case 3:
        printf("\nNOTE : Enter value in range(-infinity, infinity).\n");

        printf("Enter value : ");
        scanf("%f", &num);

        z = atan(num);
        z = z*(180/3.14159265);

        printf("\nInverse of tan(%f) is %f", num, z);
        printf("\n");
        break;

    case 4:
        printf("\nNOTE : Enter value in range[(-infinity, -1] and [1, infinity)].\n");

        printf("Enter value : ");
        scanf("%f", &num);

        a = 1/num;
        z = asin(a);
        z = z*(180/3.14159265);

        printf("\nInverse of cosec(%f) is %f", num, z);
        printf("\n");
        break;

    case 5:
        printf("\nNOTE : Enter value in range[(-infinity, -1] and [1, infinity)].\n");

        printf("Enter value : ");
        scanf("%f", &num);

        a = 1/num;
        z = acos(num);
        z = z*(180/3.14159265);

        printf("\nInverse of sec(%f) is %f", num, z);
        printf("\n");
        break;

    case 6:
        printf("\nNOTE : Enter value in range[(-infinity, -1] and [1, infinity)].\n");

        printf("Enter value : ");
        scanf("%f", &num);

        a = 1/num;
        z = atan(num);
        z = z*(180/3.14159265);

        printf("\nInverse of cot(%f) is %f", num, z);
        printf("\n");
        break;
    }


}


//*******************************************************************************************************
//      %   %   %   %   %   %   %   %   %   %   %   %   %   %   %   %   %   %   %   %   %   %   %   %   %
//*******************************************************************************************************

int main()
{
    int i, j, k, n, a, b;

    printf("\t>>> THIS IS IN PROGRASS FOR BEING SCIENTIFIC CALCULATOR <<<\n\n");

    start2:

    printf("Select operations from below : \n\t 1. Basic Operation[+, -, *, /, %%]\n\t 2. Matrix Multiplication\n\t 3. Determinant of Matrix\n\t 4. Addition of Matrix\n\t 5. Trigonometry\n\t 6. Logarithm and Antilogarithm\n\t 7. Number of form [X^Y]\n\t 8. Inverse Trigonometry\n");
    scanf("%d", &n);

    if(n<1 || n>8)
    {
        printf("### Enter appropriate number for operation ###\n\n");
        goto start2;
    }
    switch(n)
    {
    case 1:
        basic_cal();
        break;

    case 2:
        matrix_multiplication();
        break;

    case 3:
        det_matrix();
        break;

        break;

    case 4:
        add_matrix();
        break;

    case 5:
        trigo();
        break;

    case 6:
        printf("Select operation :\n\t 1. Log\n\t 2. Antilog\n");
        scanf("%d", &b);

        switch(b)
        {
        case 1:
            logarithm();
            break;
        case 2:
            antilogarithm();
            break;
        }
        break;

    case 7:
        printf("Select option :\n\t 1. X and Y both are integers\n\t 2. X and Y either one or both fraction\n");
        scanf("%d", &a);

        switch(a)
        {
        case 1:
            int_power();
            break;

        case 2:
            dirty_power();
            break;
        }
        break;

    case 8:
        inverse_trigo();
        break;
    }

    return 0;
}
