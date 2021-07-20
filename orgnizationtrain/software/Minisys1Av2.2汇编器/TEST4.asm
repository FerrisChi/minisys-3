.DATA	0x0000
	LED:	.word 0XAAAAAAAA

.TEXT	0x0000
start:
	lui	$28, 0xFFFF
	ori	$28,$28,0XF000
	lw	$3, LED($zero)
	srl	$4,$3,16
	sw	$3,0XC60($28)
	j	start