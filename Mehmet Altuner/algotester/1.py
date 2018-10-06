def abs_sub(i, j):
	if i < j:
		return j - i
		
	return i - j
	

if __name__ == '__main__':
	n = int(input())
	ar_n = list(map(int, input().rstrip().split()))
	a, b = input().split()
	
	a = int(a)
	b = int(b)
	
	compare_to = list(range(1, n+1))
	swaps = []   # [(i, j), ()...]
	cost = 0
	
	while compare_to != ar_n:
		for i in range(n):
			i_th = ar_n[i]
			if i != i_th - 1:
				# check if it is at correct position already
				holder = ar_n[i_th - 1]
				ar_n[i_th - 1] = i_th
				ar_n[i] = holder
				
				swaps.append((i, i_th - 1))
				cost += a * abs_sub(i, i_th - 1) + b
				
				if compare_to == ar_n:
					break
					
	print(cost)
	print(len(swaps))
	for i, j in swaps:
		print(i, j)
		
