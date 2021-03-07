N, M = map(int, input().split())

s1 = list(input())
s2 = list(input())




















# N, M = map(int, input().split())
#
# s1 = list(input())
# s2 = list(input())
#
# dp = [[0] * (M + 1) for _ in range(N + 1)]
#
# for m in range(1, N + 1):
#     for n in range(1, M + 1):
#         if s1[m - 1] == s2[n - 1]:
#             dp[m][n] = dp[m - 1][n - 1] + 1
#         else:
#             dp[m][n] = max(dp[m - 1][n], dp[m][n - 1])
#
# print(dp[N])
#
# ans = 0
#
# if N < M:
#     check_arr = dp[N]
# else:
#     check_arr = []
#     for row in dp:
#         check_arr.append(row[-1])
#
# print(check_arr)
#
# # for i, elem in enumerate(dp[N]):
# #     if elem == dp[i + 1] == dp[i + 2]:
# #         ans += 1
#
# # i = 1
# # while i < len(dp[N]):
# #     if dp[i] == dp[i + 1] == dp[i + 2]:
# #         ans += 1
# #         i += 3
# #
# #     i += 1
#
#
# print(dp[N][M])
