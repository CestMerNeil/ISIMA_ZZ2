#include <stdio.h>
#include <stdlib.h>

/**
 * @param start
 * @param finsih
 * @param num[int] number of this pair
*/
void Question_One(double start, double finish, int times){
    int num = 2;
    double arr[num] = {start, finish};
    printf("%lf\t%lf\t", start, finish);
    for(int i=0; i<times; i++){
        num += (num - 1);
        for(int j=0; j<num; j++){
            double arrNew[num];
            
        }
        
    }
}

int main(void){


    return EXIT_SUCCESS;
}