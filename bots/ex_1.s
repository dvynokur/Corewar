.name "aaaaaaaaa"
.comment "HAHAHAaaa"

# haha:	live %10

# ------------------- 1-я функц
# грузим функцию st в 2-й регистр
	# ld %224257,r2		#ошибочная  функция
# грузим будущие аргументы st в 3-й регистр
	# ld %200,r3

# ------------------- 2-я функц
# грузим live ld в 4-й регистр
	# ld %57671936,r4		#good  функция
	# ld %200,r5




	# st r2, 190
	# st r4, 193


							# cmd		byte	 1 arg
# 225281	0x037001	= 0000 0011 0111 0000 0000 0001	work
# 226049	0x037301	= 0000 0011 0111 0011 0000 0001	work
# 228353	0x037C01	= 0000 0011 0111 1100 0000 0001	work
# 224257	0x036C01	= 0000 0011 0110 1100 0000 0001	dont'work



# РАБОЧАЯ
# # грузим функцию st в 2-й регистр
# 	ld %72614153,r2		#рабочая	  функция	0x04 54 01 09
# # грузим будущие аргументы st в 3-й регистр
# 	ld %117440512,r3	#аргументы				0x70 00 00 00

# # ------------------- 2-я функц
# # грузим live ld в 4-й регистр
# 	ld %58459904,r4		#good  функция			0x03 7C 07 00
# 	# ld %200,r5
	
# 	st r2, 190
# 	st r3, 189
# 	st r4, 185


# # РАБОЧАЯ
# # грузим функцию st в 2-й регистр
# 	ld %72614399,r2		#рабочая	  функция	0x04 54 01 09
# # грузим будущие аргументы st в 3-й регистр
# 	ld %117440512,r3	#аргументы				0x70 00 00 00

# # ------------------- 2-я функц
# # грузим live ld в 4-й регистр
# 	ld %58459904,r4		#good  функция			0x03 7C 07 00
# 	# ld %200,r5
	
# 	st r2, 190
# 	st r3, 189
# 	st r4, 185


# # НЕ РАБОЧАЯ
# # грузим функцию st в 2-й регистр
# 	ld %74711551,r2		#рабочая	  функция	0x04 54 01 09
# # грузим будущие аргументы st в 3-й регистр
# 	ld %117440512,r3	#аргументы				0x70 00 00 00

# # ------------------- 2-я функц
# # грузим live ld в 4-й регистр
# 	ld %58459904,r4		#good  функция			0x03 7C 07 00
# 	# ld %200,r5
	
# 	st r2, 190
# 	st r3, 189
# 	st r4, 185


# грузим функцию st в 2-й регистр
	# ld %57671681,r2		#рабочая	  функция	0x04 54 01 09
# грузим будущие аргументы st в 3-й регистр
	# ld %117440512,r3	#аргументы				0x70 00 00 00

# ------------------- 2-я функц
# грузим live ld в 4-й регистр
	# ld %58459904,r4		#good  функция			0x03 7C 07 00
	# ld %200,r5
	
	# st r2, 190
	# st r3, 189
	# st r4, 185


	# ld	%-2147483648,r2
	# or		r2, r11, r2
	live	%-1
	fork %-100
	# l2:	sti	r1,%:live,%0
	# l2:	sti	r1,%:live,%0
	# l2:	sti	r1,%:live,%0
	# l2:	sti	r1,%:live,%0
	# 	and	r1,%0,r1
	# live:	
	# 	zjmp	%:live

	# st 		r10, 5