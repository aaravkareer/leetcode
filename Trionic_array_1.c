#include<stdio.h>
int isTrionic(int* nums, int numsSize) {
    //Important thing before you read it
    //Instead of using multiple flags, only one phase variable should be used which will make it more cleaner
    int p=-1;
    int q=-1;
    int flag=0;
    int flag1=3;
    int flag2=0;
    if(numsSize<4){
        printf("invalid input size");
        flag=0;
        goto skip;
    }
  for(int i=0;i<numsSize-1;i++){
    if(nums[i+1]>nums[i]&&flag1!=2&&flag2!=10){
        printf("inc done");
        p=i+1;
        flag2=1;
        

    }
    else if(nums[i+1]<nums[i]&&flag2==1){
        printf("dec");
        q=i+1;
        flag1=2;
        flag=0;
    }
    else if(nums[i+1]>nums[i]&&flag1==2){
        printf("sec inc");
        flag=1;
        flag2=10;
    }
    else if(nums[i+1]==nums[i]){
        printf("failed");
        flag=0;
        break;
    }
    else{
        printf("failed");
        flag=0;
        break;
    }
    
    

  }
  skip:
  if(0<p&&p<q&&q<numsSize-1&&flag){
        printf("The array is Trionic");
    }
    else{
        printf("The array is not Trionic");
        
    }
  printf("%d %d",p,q);
  return flag;
  
}
int main(){
    int numsSize;
    printf("Enter array size");
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++){
        printf("Enter number");
        scanf("%d",&nums[i]);
    }

    isTrionic(nums,numsSize);
    return 0;
}