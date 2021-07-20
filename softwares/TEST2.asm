.DATA	0x0000
	LED:	.word 0XAAAAAAAA
	LED2:   .word 0XC33C0000

.TEXT	0x0000
start:
	lui	$28, 0xFFFF
	ori	$28,$28,0XF000
	lw	$3, LED($zero)
	lw  $4, LED2($zero)
	srl	$4,$4,16
	sw	$3,0XC60($28)
	sw	$4,0XC62($28)
	j	start