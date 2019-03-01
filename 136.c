/*
   异或运算
   1. 满足交换律：A^B = B^A
   2. 满足结合律：(A^B)^C = A^(B^C)
   3. 0^A = A
   4. A^A = 0
   异或运算是按位运算的只有对应的位不同的时候结果为1 否则为0 这样的话 
   对于这个数组进行按位运算的话一样的数都为0了（符合交换律）剩下的那个就是唯一1个数了
 */


int singleNumber(int* nums, int numsSize) {
    int a = 0;
    for (int i =0;i<numsSize;i++){
        a ^= nums[i]; 
    }
    return a;
}
