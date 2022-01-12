#include<stdio.h>
void main()
{
    int m,n,p,q,i,j,k;

    printf("Enter number of rows and columns for First matrix and Second matrix: ");
    scanf("%d %d %d %d",&m,&n,&p,&q);

    int A[m][n],B[p][q],C[m][q];

    if(n!=p)	printf("Matrix multiplication is not possible.");
    else
    {
        printf("Enter the elements of First matrix:\n");
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)	scanf("%d",&A[i][j]);
    	}
    
        printf("\nEnter the elements of Second matrix:\n");
        for(i=0;i<p;i++)
        {
            for(j=0;j<q;j++)	scanf("%d",&B[i][j]);
    	}
    

        for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)
            {   
           		int sum=0;
                for(k=0;k<p;k++)	sum=sum+A[i][k]*B[k][j];
                C[i][j]=sum;
            }
        }

        printf("Multiplication of matrices is:\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)	printf("\t%d\t",C[i][j]);
            printf("\n");
        }
 	}
}