.data 0x0

.text 0x0
start:
	lui	$28, 0xFFFF
	ori	$28, $28, 0xFC00
	lw	$t0, 0x70($28)
	andi	$v0, $t0, 0xFFF
	srl	$t0, $t0, 12
	andi	$t0, $t0, 0xF
	lw	$t1, 0x72($28)
	sll	$t1, $t1, 4
	or	$v1, $t0, $t1
	addu	$at, $v0, $v1
	sw	$at, 0x60($28)
	srl	$at, $at, 16
	sw	$at, 0x62($28)
	j	start