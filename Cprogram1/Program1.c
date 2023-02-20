#include <stdio.h>
#define MONTHS 12
const char *months[] = {"January","February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
void sales_reports(float sales[12]){
	int i;
	printf("Monthly Sales Report for 2022:\n");
	printf("Month     Sales \n");
	for(i=0; i<12;i++)
		{
		printf("%9s $%5.2f",months[i], sales[i]);
		printf("\n");
	}
}
void sales_summary(float sales[12]){
	int i;
	int position;
	int position_2;
	float j;
	float n;
	float min;
	float max;
	position = 0;
	position_2=0;
	min=max=sales[0];
	for(i=1; i < 12; i++){
		if(min>sales[i]){
		 min=sales[i];
		 position=i;
		}
		if(max<sales[i]){
		 max=sales[i];
		 position_2=i;
		}
	}
	for(i=0; i<12; i++){
			n += sales[i];
		}
	j=n/12;




	printf("Minimum sales:	$%5.2f (%s) \n", min, months[position]);
	printf("Maximum sales:	$%5.2f (%s) \n", max, months[position_2]);
	printf("Average sales:	$%5.2f \n", j);
}
void high_to_low(float sales[12]){
	printf("Sales Report (Highest to Lowest) \n");
	printf("Month       Sales \n");
	int A[]={0,1,2,3,4,5,6,7,8,9,10,11};
	int i;
	int j;
	float temp;
	int temp2;
	for(i=0; i < 12; ++i)
	{
		for(j=i+1; j < 12; ++j)
		{
			if(sales[i] < sales[j])
			{
				temp = sales[i];
				temp2= A[i];
				sales[i]=sales[j];
				A[i]=A[j];
				sales[j] = temp;
				A[j]=temp2;
			}
		}


	}
	for (i=0; i < 12; i++){
		printf("%9s $%5.2f \n",months[A[i]],sales[i]);
	}
}
void moving_averages(float sales[12]){
	int i;
	int k;
	float j;
	float n;
	for(i=0;i<7; i++){
		n=0;
		for(k=0; k < 6; k++){
		n += sales[i+k];}
		j=n/6;
		printf("%9s  --  %9s $%5.2f \n", months[i], months[i+k-1], j);
	}

}

int main() {
	float sales[MONTHS];
	FILE *fp;
	int i;
	fp=fopen("input.txt", "r");
	if (fp==NULL) {
		printf("Error opening file\n");
		return 1;
	}
	for(i=0; i < MONTHS; i++) {
		fscanf(fp, "%f", &sales[i]);
	}
	fclose(fp);
	sales_reports(sales);
	printf("\n");
	sales_summary(sales);
	printf("\n");
	moving_averages(sales);
	printf("\n");
	high_to_low(sales);
	return 0;
}

