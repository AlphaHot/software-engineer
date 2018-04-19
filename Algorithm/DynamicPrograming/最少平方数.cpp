#include<iostream>
#include<cmath>
#include<cstdlib>
#include<memory.h>
#include<climits>
using namespace std;

//public class Solution {
//    public int numSquares(int n) {
//        int[] dp = new int[n+1];
//        // �����з�ƽ�����Ľ������󣬱�֤֮��Ƚϵ�ʱ�򲻱�ѡ��
//        Arrays.fill(dp, Integer.MAX_VALUE);
//        // ������ƽ�����Ľ����1
//        for(int i = 0; i * i <= n; i++){
//            dp[i * i] = 1;
//        }
//        // ��С������������a
//        for(int a = 0; a <= n; a++){
//            // ��С������ƽ����b��b
//            for(int b = 0; a + b * b <= n; b++){
//                // ��Ϊa+b*b���ܱ������ƽ��������������Ҫȡ�����н�С��
//                dp[a + b * b] = Math.min(dp[a] + 1, dp[a + b * b]);
//            }
//        }
//        return dp[n];
//    }
//}


int dfs(int n,int count,int* dp){
        if(n==0)
            return count;

        int c=0;
        if((c=dp[n-1])!=0){
            return count+c;
        }


        int res=INT_MAX;
        int j=(int)sqrt(n);
        for(int i=j;i>=(j/2+1);i--){
            int num=n-pow(i,2);
            int c=dfs(num,count+1,dp);
            res=min(res,c);
        }
        cout<<endl;
        dp[n-1]=res-count;
        return res;
    }

    int numSquares(int n)
    {
        int dp[n];
        memset(dp,0,n*sizeof(n));
        return dfs(n,0,dp);

    }

int main(void)
{
    int result=numSquares(18);
    cout<<result<<endl;
    return 0;
}
