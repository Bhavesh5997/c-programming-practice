#include<stdio.h>

struct student
{
	int rollno;
	char name[20];
	float m1,m2,m3,m4,m5;
	float percent;
};

void getdetail(struct student *, int);
void merit(struct student *, int);

int main(void)
{
	int n;
	printf("Enter number of students\n");
	scanf("%d", &n);

	struct student s[n];
	getdetail(s,n);
	merit(s,n);
	return 0;
}

void getdetail(struct student *ptr, int n)
{
	int i,j;

	for(i=0;i<n;i++)
	{
		printf("\nEnter Student %d details\n", i + 1);
		printf(" enter the roll no\n");
		scanf("%d",&ptr->rollno);
		printf("\n enter the name \n");
		scanf("%s",ptr->name);
		printf("\n enter the sub1 mark=");
		scanf("%f",&ptr->m1);
		printf("\n enter the sub2 mark=");
		scanf("%f",&ptr->m2);
		printf("\n enter the sub3 mark=");
		scanf("%f",&ptr->m3);
		printf("\n enter the sub4 mark=");
		scanf("%f",&ptr->m4);
		printf("\n enter the sub5 mark=");
		scanf("%f",&ptr->m5);
		ptr->percent=(ptr->m1+ptr->m2+ptr->m3+ptr->m4+ptr->m5)/5;
		ptr++;
	}
}
void merit(struct student *ptr, int n)
{
	int i,j;
	struct student t;

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((ptr+i)->percent<(ptr+j)->percent)
			{
				t=*(ptr+i);
				*(ptr+i)=*(ptr+j);
				*(ptr+j)=t;
			}
		}

	}

	printf("\n display in desending order\n");

	for(i=0;i<n;i++)
	{
		printf("\n rollno=%d",(ptr+i)->rollno);
		printf("\n name=%s",(ptr+i)->name);
		printf("\n sub1 mark=%f",(ptr+i)->m1);
		printf("\n sub2 mark=%f",(ptr+i)->m2);
		printf("\n sub3 mark=%f",(ptr+i)->m3);
		printf("\n sub4 mark=%f",(ptr+i)->m4);
		printf("\n sub5 mark=%f",(ptr+i)->m5);
		printf("\n percent=%f\n",(ptr+i)->percent);
	}
}
