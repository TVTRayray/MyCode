def is_prime( number):
	if (number == 1):
		return 0
	
	for x in range(2,number):
		if ( number%x == 0):
			return False
			
	return True




if __name__=="__main__":
	n = int(input("please input a number:"))
	if ( is_prime(n) ):
		print("是一个素数")
	else :
		print("不是素数")


