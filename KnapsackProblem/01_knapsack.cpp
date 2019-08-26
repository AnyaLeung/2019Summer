#include <iostream>
#include <string>
#include <vector>

using namespace std;

void knapsack(int product_count, int capacity, vector<int> weight, vector<int> value, vector<vector<int>>& dp){
    for(int i=1; i<=product_count; i++){
        for(int j=1; j<=product_count; j++){
            if(weight[i]>j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);
            }
        }
    }
}

int main(void){
    int product_count = 0;
    int capacity = 0;
    vector<int> weight(1, 0);
    vector<int> value(1, 0);

    cin >> product_count >> capacity;
    for(int i=0; i<product_count; i++){
        cin >> weight[i];
    }
    for(int i=0; i<product_count; i++){
        cin >> value[i];
    }

    vector<vector<int>> dp(product_count+1, vector<int>(capacity+1, 0));
    knapsack(product_count, capacity, weight, value, dp);
    cout << dp[product_count][capacity] << endl;
    return 0;
}
