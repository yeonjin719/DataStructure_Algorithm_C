#include <stdio.h>

#define MAX_N 6
#define MAX_M 100

int P[MAX_N] = {40, 35, 18, 4, 10, 2};
int W[MAX_N] = {100, 50, 45, 20, 10, 5};

int dp[MAX_N + 1][MAX_M + 1]; // -1이면 아직 계산 안 됨

int max(int a, int b) { return a > b ? a : b; }

int KNAP_memo(int i, int n, int capacity) {
  // 더 볼 물건이 없거나, 용량이 0이면 얻을 수 있는 이득은 0
  if (i == n || capacity == 0)
    return 0;

  // 이미 계산된 값이면 그대로 리턴
  if (dp[i][capacity] != -1)
    return dp[i][capacity];

  int best = 0;

  // i번째 물건을 안 넣는 경우
  best = KNAP_memo(i + 1, n, capacity);

  // i번째 물건을 넣을 수 있다면, 넣는 경우도 고려
  if (capacity >= W[i]) {
    int with_i = KNAP_memo(i + 1, n, capacity - W[i]) + P[i];
    best = max(best, with_i);
  }

  dp[i][capacity] = best;
  return best;
}

int main(void) {
  int n = MAX_N;
  int M = 100; // 최대 용량 예시

  // dp 초기화: -1 → 아직 계산 안 됨 표시
  for (int i = 0; i <= n; i++) {
    for (int c = 0; c <= M; c++) {
      dp[i][c] = -1;
    }
  }

  int ans = KNAP_memo(0, n, M);
  printf("최대 가치 = %d\n", ans);
  return 0;
}