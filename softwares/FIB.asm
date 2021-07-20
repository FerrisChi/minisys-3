.data 0x0
	FIB:	.word	0x00000000:35

.text 0x0
start:
	sw	$0, FIB($0)
	ori	$t0, $0, 4
	ori	$t1, $0, 1
	sw	$t1, FIB($t0)
	ori	$t0, $0, 8
	j	test
loop:
	addi	$t3, $t0, -8
	lw	$v0, FIB($t3)
	addi	$t3, $t3, 4
	lw	$v1, FIB($t3)
	add	$t1, $v0, $v1
	sw	$t1, FIB($t0)
	addi	$t0, $t0, 4
test:
	slti	$t2, $t0, 140
	beq	$t2, $zero, 1
	j	loop
done:
	lui	$28, 0xFFFF
	ori	$28,$28,0XF000
	lw	$3, 0XC70($28)
	sll	$3, $3, 2
	lw	$2, FIB($3)
	sw	$2, 0XC60($28)
	srl	$2, $2, 16
	sw	$2, 0XC62($28)
	j	done