.data
array:		.word -2,45,67,89,23,12,-100,23,0,120,6 # array = {23,-2,45,67,89,12,-100,0,120,6}
length:		.word 10 # the length of the array is 10
numlook:	.asciiz "Enter a number to see if there is a duplicate: "
numMessage:	.asciiz "The number that we are looking for duplicates is: "
loopMessage:	.asciiz "The amout of ties that we needed to run through the loop to find the number was : "
notfoundMsg:	.asciiz "The number only had one or nun"
newLine:	.asciiz "\n"

# Algorithm being implemented to sum an array
# sum = 0 (use $t0 for sum)
# squarSum = 0 (use %t5 for squarSum)
# for i = 0 to length-1 do (use $t1 for i)
# sum = sum + array[i] (use $t2 for length-1)
# squareSum = squareSum + array[i]*array[i]
# end for (use $t3 for base addr. of array)

.text
main:

	li	$t0, 0 # load immediate 0 in register $t0 (sum)
	li	$t5, 0 # load immediate 0 in register $t0 (squarSum)
	la	$t3, array # load base addr. of array into $t3
	lw	$t2, length # load length in register $t2
	addi	$t2, $t2, -1 # $t2 = length - 1
	li	$t1, 0 # initialize i in $t1 to 0

	#promt ,essage for the user
	li	$v0, 4
	la	$a0, numlook
	syscall 

	li	$v0,  5
	syscall		# read an int
	add	$t0, $v0, $zero		# move to $t0


loop:
#make a branch statment that will go through the list and will compare the first number with all of them and then branch if this is true
# but if the number doesn't mach then the program will grab the next number in the list and comcare that to all of them except the first one

	bgt	$t1, $t2, exit # exit loop when i > (length-1)
	mul	$t4, $t1, 4 # multiple i by 4 to get offset within array
	add	$t4, $t3, $t4 # add base addr. of array to $t4 to get addr. of array[i]
	lw	$t4, 0($t4) # load value of array[i] from memory into $t4


	addi	$t1, $t1, 1 # increment i
	addi	$t5, $t1, 0
	beq	$t4, $t0, loop1		#if the number that we are looking for has a duplicate it will exit the loop
	beq	$t1, 10, notfnd		#if we reaced the end of the list then the number was not found then it will end the program
	j	loop1
	
loop1:
#The second loop is there to see if there is a duplicate of the number when one is found

	bgt	$t1, $t2, exit # exit loop when i > (length-1)
	mul	$t4, $t1, 4 # multiple i by 4 to get offset within array
	add	$t4, $t3, $t4 # add base addr. of array to $t4 to get addr. of array[i]
	lw	$t4, 0($t4) # load value of array[i] from memory into $t4


	addi	$t1, $t1, 1 # increment i
	addi	$t5, $t1, 0
	beq	$t4, $t0, exit		#if the number that we are looking for has a duplicate it will exit the loop
	beq	$t1, 10, notfnd		#if we reaced the end of the list then the number was not found then it will end the program
	j	loop

exit:

	# print num message
	li	$v0, 4
	la	$a0, numMessage
	syscall 
	# print value that we are looking for
	li	$v0, 1
	addi	$a0,$t0,0
	syscall
	
	# print new line
	li	$v0, 4
	la	$a0, newLine
	syscall 
	
	# print amounbt of loops message 
	li	$v0, 4
	la	$a0, loopMessage
	syscall 
	# print nuumber of loop iterations it took to find it
	li	$v0, 1
	addi	$a0,$t1,0
	syscall	

	j	done

notfnd:
	li	$v0, 4
	la	$a0, notfoundMsg
	syscall 

done:
