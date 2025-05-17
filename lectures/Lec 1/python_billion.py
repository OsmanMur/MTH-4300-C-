from timeit import default_timer as timer

start = timer()


N = 10**9   # 10**9 = billion
running_sum = 0
for i in range(N + 1):
    running_sum += i
print(running_sum)


end = timer()
print('Total elapsed time:', end-start, 'seconds')
