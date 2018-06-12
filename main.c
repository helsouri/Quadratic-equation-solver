#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    //we want to create a quadratic equation solver

    float a, b, c, d,x1,x2,real,imaginary;
    char answer; //A character to introduce more user interaction through a yes/no answer
    FILE *fo;

    fo=fopen("data.txt","w");
    printf("This is a program to solve quadratic equations of the form ax^2 + bx + c .\n");
    fprintf(fo,"This is a program to solve quadratic equations of the form ax^2 + bx + c .\n");
    //----Introduction----//

    printf("Would you like to start the program?(Type y for yes or n for no):");
    scanf("%c",&answer);
    fprintf(fo,"Would you like to start the program?(Type y for yes or n for no): %c",answer);
    //---User input and interaction----//

    while(answer == 'y') //a loop to keep program running as long as user wishes//
    {
        printf("-----------------------------------------------------------------------\n");
        printf("\nPlease enter the value of a:");
        scanf("%f",&a);
        fprintf(fo,"\n-----------------------------------------------------------------------\n");
        fprintf(fo,"\nPlease enter the value of a: %.2f",a);
        //----      ----//

        printf("\nPlease enter the value of b:");
        scanf("%f",&b);
        fprintf(fo,"\nPlease enter the value of b: %.2f",b);
        //----      ----//
        printf("\nPlease enter the value of c:");
        scanf("%f",&c);
        fprintf(fo,"\nPlease enter the value of c: %.2f",c);
        //----      -----/
        d= pow(b,2) - 4*a*c; //calculating the discriminant d//
        x1= (-b-sqrt(d))/(2*a);//calculating first root//
        x2= (-b+sqrt(d))/(2*a);//calculating second root//

        //----For complex roots we have to split real part from complex part----//
        real= -b/(2*a);//calculating real part//
        imaginary= sqrt(fabs(d));//calculating imaginary part//
        printf("\nThe value of the discriminant is: %.2f\n",d);
        fprintf(fo,"\nThe value of the discriminant is: %.2f\n",d);
        if(d==0)
        {
            printf("\nTherefore we have one real repeated root x1 = x2 = %.2f." ,x1);
            printf("\nThe factor is [ x - (%.2f) ][ x - (%.2f) ]\n",x1,x2);
            printf("\n-----------------------------------------------------------------------");
            fprintf(fo,"\nTherefore we have one real repeated root x1 = x2 = %.2f and our factor is x1 + %.2f \n" ,x1,-1*x1);
            fprintf(fo,"\nThe factor is [ x - (%.2f) ][ x - (%.2f) ]\n",x1,x2);
            fprintf(fo,"\n-----------------------------------------------------------------------");
        }

        else if (d>0)
            {
                printf("\nTherefore we have two real unique solutions which are x1= %.2f and x2 = %.2f" ,x1 ,x2);
                printf("\nThe factors are [x - (%.2f)][x -(%.2f)]\n",x1 ,x2);
                printf("\n-----------------------------------------------------------------------");
                fprintf(fo,"\nTherefore we have two real unique solutions which are x1= %.2f and x2 = %.2f" ,x1 ,x2);
                fprintf(fo,"\nThe factors are [x - (%.2f)][x -(%.2f)]\n",x1 ,x2);
                fprintf(fo,"\n-----------------------------------------------------------------------");
            }
            else
            {
                printf("\nTherefore we have two unique complex solutions which are x1= %.2f + %.2fi and x2 = %.2f - %.2fi\n",real ,imaginary ,real, imaginary);
                printf("\nThe factors are [x - (%.2f + %.2fi)][x -  (%.2f - %.2fi)]\n",real ,imaginary ,real, imaginary);
                printf("\n-----------------------------------------------------------------------");
                fprintf(fo,"\nTherefore we have two unique complex solutions which are x1= %.2f + %.2fi and x2 = %.2f - %.2fi\n",real ,imaginary ,real, imaginary);
                fprintf(fo,"\nThe factors are [x - (%.2f + %.2fi)][x -  (%.2f - %.2fi)]\n",real ,imaginary ,real, imaginary);
                fprintf(fo,"\n-----------------------------------------------------------------------");
            }
            printf("\nWould you like to try again?(type y for yes or n for no):");
            scanf(" %c", &answer);
            fprintf(fo,"\nWould you like to try again?(type y for yes or n for no): %c\n",answer);
        }
    printf("-----------------------------------------------------------------------");
    printf("\n\t\t\t---OK have a nice day :)----");
    printf("\n-----------------------------------------------------------------------");
    fprintf(fo,"-----------------------------------------------------------------------");
    fprintf(fo,"\n\t\t\t---OK have a nice day :)----");
    fprintf(fo,"\n-----------------------------------------------------------------------");
    fclose(fo);
}
