#include<stdio.h>
#include<math.h>
int findN(int x);
void getSig(int sig[]);
void getExp(int exp[],int n);
int main(){

    int x ;
    printf("Please input an integer number: ");
    scanf("%d",&x);
    int n = findN(x);
    int exp[1000],sig[1000];
    int i=0;
    for(;;i++){
        n = findN(x);
        exp[i]=n;
        if(x>(pow(3,n)/2) && x<(pow(3,n))){
            sig[i] = -1;
            x= pow(3,n) - x;
        }
        else if(x == pow(3,n)){
            sig[i] = 0;
            break;
        }
        else{
            sig[i] = 1;
            x= x - pow(3,n);
        }
    }

    getSig(sig);
    getExp(exp,i+1);
    for(int k=0;k<i+1;k++){
        if(k==0){
            printf("L : %.0lf\n",pow(3,exp[0]));
        }
        else if(sig[k-1] == 1){
            printf("L : %.0lf\n",pow(3,exp[k]));
        }
        else if(sig[k-1] == -1){
            printf("R : %.0lf\n",pow(3,exp[k]));
        }
    }


    return 0;
}

int findN(int x){

    for(int i=0;;i++){
        if(x>(pow(3,i)/2) && x<(pow(3,i+1)/2)){
            return i;
        }
    }
}
void getSig(int sig[]){
    int len = 0;
    for(;sig[len]!=0;len++);
    for(int k =len-1;k>0;k--){
        int temp = 1;
        for(int i=0;i<=k;i++){
            temp *= sig[i];
        }
        sig[k] = temp;
    }
    // for(int s=0;s<len;s++){
    //     printf("%d ",sig[s]);
    // }

}

void getExp(int exp[],int n){
    // for(int s=0;s<n;s++){
    //     printf("%d ",exp[s]);
    // }
}