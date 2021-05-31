/**
 * @author ling
 * @date 2021/5/31
 * @brief easy 4的幂
 * 
 * 1. 位运算
 * 当n是4的幂次方时，那么n一定是正整数，并且n的二进制表示中，有且仅有一个1，其余位都是0。
 * 并且这个1是在总左往右数  的偶数位置上。
 * 所以可以先判断n的正负，然后判断二进制表示中1的个数。最后判断是否在偶数位置上。
 * 
 * 假设 n 的二进制表示为 (a1000..)其中a表示若干个高位，1表示最低位的那个 1。
 * 000..表示后面的若干个0，那么 n−1 的二进制表示为：(a0111..)
 * 将 n和n-1 进行按位与运算，高位 a 不变，在这之后的所有位都会变为 0，这样我们就将最低位的那个 1 移除了。
 * 如果结果等于0就说明这个数二进制表示只有这一个1。
 * 
 * 判断1的位置是否在偶数位。可以构造一个32数（10101010 10101010 10101010 10101010）也就是0xaaaaaaaa
 * 只要和这个数进行按位与得到的是0，那就表示1的位置在偶数位
 * 时间复杂度：O(1)            空间复杂度：O(1)
 */

#include <iostream>
using namespace std;

/**
 * @brief 判断n是否是4的幂次方
 */
bool isPowerOfFour(int n)
{
    return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
}

int main()
{
    cout << isPowerOfFour(14) << endl;
    cout << isPowerOfFour(16) << endl;
    return 0;
}