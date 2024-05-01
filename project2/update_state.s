.arch msp420g2553
	.p2align 1,0

	.text
	.global update_state
	.extern current_state
	.extern HOURGLASS
	.extern SQUARE
	.extern TRIANGLE
	.extern CROSS

update_state:
	cmp &HOURGLASS, &current_state
	jz hourglass_case
	cmp &SQUARE, &current_state
	jz square_case
	cmp &TRIANGLE, &current_state
	jz triangle_case
	cmp &CROSS, &current_state
	jz cross_case
hourglass_case:	
	mov &SQUARE, &current_state
	jmp end
square_case:
	mov &TRIANGLE, &current_state
	jmp end
triangle_case:
	mov &CROSS, &current_state
	jmp end
cross_case:
	mov &HOURGLASS, &current_state
	jmp end
end:
	pop r0
