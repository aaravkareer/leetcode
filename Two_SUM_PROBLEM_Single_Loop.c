int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int flag=0;
    int j=0;
    int i=0;
    nested_loop_prevention:
    
    for(i=0;i<numsSize;i++){
        if(nums[i]+nums[j]==target){
            flag=1;
            break;
        }
    }
   
    if(flag==0||i==j){
        flag=0;
        j=j+1;
        goto nested_loop_prevention;
    }
    int* ret=malloc(2*sizeof(int));
    *returnSize=2;
    printf("%d %d",i,j);
    if(j>i){
        ret[0]=i;
        ret[1]=j;
    }
    else{
        ret[0]=j;
        ret[1]=i;
    }/
    return ret;
}