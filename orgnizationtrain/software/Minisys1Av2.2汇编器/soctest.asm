.data  0x0000              		                    # ���ݶ�����׵�ַ
	buf:   	.word  0x00000055, 0x000000AA	# ��������
	buf2:	.word 0x00000000
	DELAY: 	.word 0x3F9409           	    # 0.5����ʱ����,ֻ��һ���������
	LED:		.word 0XAAAAAAAA        # Ҫ��ʾ��LED����
	MASK:    .word 0XFFFFFFFF
.text 0x0000						        # ����ζ��忪ʼ
start:ori $at,$zero,1       #�Ĵ�����ʼ��
		ori $v0,$zero,2
		ori $v1,$zero,3
		ori $a0,$zero,4
		ori $a1,$zero,5
		ori $a2,$zero,6
		ori $a3,$zero,7
		ori $t0,$zero,8
		ori $t1,$zero,9
		ori $t2,$zero,10
		ori $t3,$zero,11
		ori $t4,$zero,12
		ori $t5,$zero,13
		ori $t6,$zero,14
		ori $t7,$zero,15
		ori $s0,$zero,16
		ori $s1,$zero,17
		ori $s2,$zero,18
		ori $s3,$zero,19
		ori $s4,$zero,20
		ori $s5,$zero,21
		ori $s6,$zero,22
		ori $s7,$zero,23
		ori $t8,$zero,24
		ori $t9,$zero,25
		ori $i0,$zero,26
		ori $i1,$zero,27
		ori $s9,$zero,28
		ori $sp,$zero,29
		ori $s8,$zero,30
		ori $ra,$zero,31
		lw $v0,buf($zero)       
		lw $v1,buf($a0)			# buf+4
		add $at,$v0,$v1
		sw $at,8($zero)         # дbuf2
		subu $a0,$v1,$v0
		slt $a0,$v0,$at
		and $at,$v1,$a3
		or $a2,$v0,$at
		xor $a3,$v0,$v1
		nor $a2,$a1,$at
lop:		beq $v1,$v0,lop
lop1:	sub $v0,$v0,$a1
		bne $a1,$v0,lop1
		beq $at,$at,lop2
		nop
lop2:	jal subp
		j next
subp:	jr $ra 
next:	addi $v0,$zero,0x99
		ori $v1,$zero,0x77
		sll $v1,$v0,4 
		srl $v1,$v0,4 
		srlv $v1,$v0,$at
		lui $a2,0x9988
		sra $a3,$a2,4
		addi $v0,$zero,0
		addi $v1,$zero,2
		sub  $at,$v0,$v1
		# ���²��������غ���LED��ʾ�����ֻ�������CPU������Ĳ��ֿ���ɾ����ֻ�����һ��j  start
disp:lui   	$28,0XFFFF					#��$28Ϊ0FFFF0000��Ϊ�˿ڵ�ַ�ĸ�16λ
		ori   	$28,$28,0XF000			    #$28�˿���ϵͳ��I/O��ַ�ĸ�20λ
		lw  $3, LED($zero)               # �õ�Ҫ��ʾ��ֵ
		srl    $4,$3,16                         # $4�õ�$3�ĸ�16λ
		sw	$3,0XC60($28)             #�����16λLED
		sw	$4,0XC62($28)             #�����6λLED
		lw    $5, MASK($zero)          # �õ����� 
		xor   $3,$3,$5                         # $3ȡ��
		sw    $3, LED($zero)             #�洢ȡ�������
		jal	dely
		j	disp
dely:lw    $29,DELAY($zero)       # �ӳٴ�Լ0.5��
dlop:addi $29,$29,-1
        bne	$29,$0,dlop
        jr 	$31

