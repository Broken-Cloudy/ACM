#include<bits/stdc++.h>
using namespace std;
int n,i,k,arr[10009],dp[10009];
int calculateXORSum(){
    // ������arr[i]��β������������
    for (int i=0;i<n;i++) {
        dp[i]=arr[i];
        for (int j=i-1;j>=0;j--) {
            dp[i]^=arr[j]^dp[j];
        }
    }

    // ������������������
    int result = 0;
    for (int i = 0; i < n; ++i) {
        result ^= arr[i] ^ dp[i];
    }

    return result;
}

int main() {
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
    int result = calculateXORSum();
    cout<<result<<endl;
	fclose(stdin);fclose(stdout);
    return 0;
}

