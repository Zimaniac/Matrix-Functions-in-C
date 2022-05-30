#include<stdio.h>
#include <stdlib.h>
#include<math.h>


int r1 , c1;
int r2 , c2;
int x,y; 

void printm(float (*metrix), int row , int col){

    int nor = row ; 
    int noc = col ;  

    for(int i=0 ; i < nor ; i++) 
   {
        for(int j=0 ; j < noc ; j++) 
        {
            printf("%0.3f \t", *metrix);
            if(j==(col-1))
            {
                printf("\n");
            }
            metrix++ ; 
        }
   }
   printf("\n\n") ; 

}

int det(float B[x][y],int n) {
    int row_size = x;
    int column_size = y;

    if (row_size == 1)
        return (B[0][0]);

    else if (row_size == 2)
        return (B[0][0]*B[1][1] - B[1][0]*B[0][1]);

    else {
        float minor[row_size-1][column_size-1];
        int row_minor, column_minor;
        int firstrow_columnindex;
        float sum = 0;

        register int row,column;

        for(firstrow_columnindex = 0; firstrow_columnindex < row_size;
                firstrow_columnindex++) {

            row_minor = 0;

            for(row = 1; row < row_size; row++) {

                column_minor = 0;

                for(column = 0; column < column_size; column++) {
                    if (column == firstrow_columnindex)
                        continue;
                    else
                        minor[row_minor][column_minor] = B[row][column];

                    column_minor++;
                }

                row_minor++;
            }

            x = row_minor;
            y = column_minor;

            if (firstrow_columnindex % 2 == 0)
                sum += B[0][firstrow_columnindex] * det(minor,row_minor);
            else
                sum -= B[0][firstrow_columnindex] * det(minor,column_minor);

        }

        return sum;

    }
}  


int main(){

    printf("This program will first ask you to input values of metrix 1 and metrix 2 and then ask you what action do you want to perform in it (i.e. subtraction, multiplication, determinent or addition) \n\n") ; 
    

    restart :
    printf("Start \n") ; 
 
    printf("enter no of row for 1 -->\n");
    scanf("%d",&r1);
    printf("enter no of coloumn for 1 -->\n");
    scanf("%d",&c1);

    printf("\nNOTE --> coloumn of metrix 1 should be equal to row of metrix 2 for metrix multiplication \n");
    printf("NOTE --> coloumn and row of metrix 1 should be equal to that of  metrix 2 for metrix substraction and addition \n");
    printf("\n");
    printf("enter no of row for 2 -->\n");
    scanf("%d",&r2);
    printf("enter no of coloumn for 2 -->\n");
    scanf("%d",&c2);
    
    printf("enter values of metrix 1 \n\n")  ; 
   float metrix1[r1][c1];
   int i, j;
   for(i=0; i<r1; i++)
   {
        for(j=0;j<c1;j++)
       {
        printf("Enter value for metrix1[%d][%d] -> ", i+1, j+1);
        scanf("%f", &metrix1[i][j]);
       } 
   }

    printf("\n\n");

    printf("enter values of metrix 2 \n\n")  ; 
   float metrix2[r2][c2];
   for(i=0; i<r2; i++)
   {
        for(j=0;j<c2;j++)
       {
        printf("Enter value for metrix2[%d][%d] -> ", i+1, j+1);
        scanf("%f", &metrix2[i][j]);
       } 
   }

   restart2 : 
   printf("\n");
   printf("1st metrix elements:\n");
    printm(&metrix1[0][0] , r1 , c1);

    printf("second metrix elements :\n");
    printm(&metrix2[0][0] , r2 , c2);

    float multimetrix[r1][c2] ;
    float addmetrix[r1][c1] ; 
    float submetrix[r1][c1] ; 
    float determinant; 


    again :
    printf("\n") ; 
    printf("press 1 for metrix multiplication\n") ; 
    printf("press 2 for metrix addition\n") ; 
    printf("press 3 for metrix substraction\n"); 
    printf("press 4 for determinent\n");
    printf("press 5 for quit\n");

    int key = 0 ;
    scanf("%d",&key) ; 
 
    


    if (key == 1)
    {
        
        int x = 0 ;

        for(i = 0 ; i < r1 ; i++ )
        {
            for(j = 0 ; j < c2 ; j++ )
            {
                for(int k = 0 ; k < c1 ; k++)
                {
                    x += metrix1[i][k] * metrix2[k][j]  ; 
                }
                multimetrix[i][j] = x ;
                x = 0 ;
            }
        }

        printf("Multi array elements:\n");
        printm(&multimetrix[0][0] , r1 , c1);
        
    }

    else if (key ==2)
    {  
        

        for(i = 0 ; i < r1 ; i++ )
        {
            for(j = 0 ; j < c1 ; j++)
            {
                addmetrix[i][j] = metrix1[i][j] + metrix2[i][j] ; 
            }
        }

        printf("Addition array elements:\n");
        printm(&addmetrix[0][0] , r1 , c1);
       

    }
    else if ( key == 3)
    {
        

        for(i = 0 ; i < r1 ; i++ )
        {
            for(j = 0 ; j < c1 ; j++ )
            {
                submetrix[i][j] = metrix1[i][j] - metrix2[i][j] ; 
            }
        }

        printf("Substraction array elements:\n");
        printm(&submetrix[0][0] , r1 , c1);
    }
    
    else if (key == 4 )
    {
        nom :
        printf("\nwhich metrix's determinent do you want to find ? \npress 1 for metrix 1 \npress 2 for metrix 2 \n") ; 
        int dm ; 
        scanf("%d",&dm);

        if (dm == 1)
        {
            int row = sizeof(metrix1) / sizeof(metrix1[0]);
            int column = sizeof(metrix1[0]) / 4  ;
            if(row != column)
            {
                printf("row and column must be same to find determinent of the metrix");
                goto again ;
            }
            x= r1;
            y=c1;
            determinant = det(metrix1 , r1) ;
            printf("your determinent is --> %0.3f", determinant) ; 

        }
        else if ( dm == 2 )
        {
            int row = sizeof(metrix2) / sizeof(metrix2[0]);
            int column = sizeof(metrix2[0]) / 4  ;
            if(row != column)
            {
                printf("row and column must be same to find determinent of the metrix");
                goto again ;
            }
            x= r2;
            y=c2;
            determinant = det(metrix2 , r2) ;
            printf("your determinent is --> %0.3f", determinant) ;  
        }

        else 
        {
            printf("press 1 and 2 only !!! \n") ; 
            goto nom ; 
        }
    }
    else if (key == 5)
    {
        goto end ; 
    }
    else
    {
        printf("\n enter 1, 2, 3, 4 and 5 only !\n\n") ;
        goto again ;
    }

    printf("\n\ndo you want to run this program again ? \n");
    printf("press y for yes and n for no \n");

    char res ;
    scanf("%s",&res);

    if( res == 'y')
    {
        char ques ;
        printf("do you want to change elements of metrix ? \n") ; 
        printf("press y for yes and n for no \n") ;
        scanf("%s",&ques);

        if (ques == 'y')
        {
            goto restart ;
        }

        else 
        {
            goto restart2 ; 
        }
    }

    else
    {   
        end :
        printf("\n\nProgram ended ,  Thank you \n\n") ; 
    }

    return 0;

}
