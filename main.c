#define swap(t ,a , b) {t temp ; temp = a ; a=b ;b=temp ; }
#include<stdio.h>
int power(int n , int c ) {
    int r = 1 ;
    while (c>0)
    {
        r*=n;
        c--; 
    }
    return r;
}
int strlen (char * arr )
{
    char * temp = arr ;
    while (*temp!='\0')
        temp++;
    return temp-arr ;
}
int partion (char  * arr , int low , int high )
{
    int pivot = arr[high];
    int j = low -1 ;
    for (int  i = low; i < high ; i++)
    {
        if (arr[i]<pivot)
        {
            j++ ;
            swap(int , arr[i], arr[j]);
        }
    }
    if (j+1!=high)
    {
        swap(int,arr[j+1], arr[high]) ;
    }
    return j+1;
}
void q_sort(char * arr , int low , int high )  // dam my mistak 
{
    if (low<high)
    {
        int pivot = partion(arr, low , high);
        q_sort(arr , low , pivot-1);
        q_sort(arr , pivot+1 , high);
    }
}

void crunch(char * arr , int min , int max ) // not cool but base
{
    const int len = strlen(arr);
    int j  , lines ; 
    ///FILE * sync = fopen("result.txt","w+" );
    ///sort the arr for a patr find so
    q_sort(arr , 0 , len-1); 
    //char stop = arr[len-1]; 
    char * stop = arr + len -1 ; /// try this is better 
    int gen_number =0 ; // just for test 
    while (min<=max)
    {
        char * word[min];
        for (int i = 0; i < min; i++)
            word[i] = arr;
        lines = power(len , min);
        gen_number +=lines;
        while (lines>0)
        {
            /// output i have to change this make it faster 
            for (int i = 0; i < min; i++)
            {
                putc(*word[i], stdout);
            }
            putc(' ',stdout);


            j = min - 1 ;
            while (j>=0)
            {
                if (word[j]!=stop)
                {
                    (*(word+j))++;
                    j=-1;
                }
                else
                {
                    *(word+j) = arr ;
                    j--;
                }
            }
            lines--;
        }
        min++;
    }
    //fclose(sync); 
    printf("\nnumber of gen patr : %d\n", gen_number );
}
int main () // one sec wow
{  
    char arr [] = "01"; 
    crunch(arr , 4,4); 
    return 0 ;
}
