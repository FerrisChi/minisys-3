.DATA	0x0000

.TEXT	0x0000
start:
	lui	$28, 0xFFFF
	ori	$28,$28,0XF000
	lw	$3,0XC70($28)
	sw	$3,0XC60($28)
	j	start