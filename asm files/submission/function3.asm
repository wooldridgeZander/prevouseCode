.data

numlook:	.asciiz "Enter two numbers a to find there greatest common divisor: "
commondiv:	.asciiz "The most largest common devisor was: "

.text
.globl main
main:

	#loads $a0 with the first number entered
	li	$v0, 4
	la	$a0, numlook
	syscall
	li	$v0,  5
	syscall		# read an int
	add	$a0, $v0, $zero		# move to $a0

	#loads #a1 with the other number that was entered
	li	$v0,  5
	syscall		# read an int
	add	$a1, $v0, $zero		# move to $a0

	jal	ANS # call funtion GCD
    
	add	$a0,$v0,$zero 
	li	$v0,1
	syscall # print result

li	$v0, 10 # exit program 
syscall

ANS:
	# n1 = $a0
	# n2 = $a1

	addi	$sp, $sp, -12
	sw	$ra, 0($sp) # save function into stack
	sw	$s0, 4($sp) # save value $s0 into stack 
	sw	$s1, 8($sp) # save value $s1 into stack 

	add	$s0, $a0, $zero # s0 = a0 ( value n1 ) 
	add	$s1, $a1, $zero # s1 = a1 ( value n2 ) 

	addi	$t1, $zero, 0 # $t1 = 0
	beq	$s1, $t1, returnn1 # if s1 == 0 returnn1

	add	$a0, $zero, $s1 # make a0 = $s1
	div	$s0, $s1 # n1/n2
	mfhi	$a1 # reminder of n1/n2 which is equal to n1%n2

	jal	ANS

exitANS:
	
	lw	$ra, 0 ($sp)  # read registers from stack
	lw	$s0, 4 ($sp)
	lw	$s1, 8 ($sp)
	addi	$sp,$sp , 12 # bring back stack pointer
	jr	$ra
returnn1:
	li	$v0, 4
	la	$a0, commondiv
	syscall
	add	$v0, $zero, $s0 # return $v0 = $s0 ( n1)
	j	exitANS
