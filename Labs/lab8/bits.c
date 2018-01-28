#include "bits.h"
#include <stdio.h>

void print_in_binary(unsigned int x) {
	for (int i = 31; i > -1; i--) {
		if (IS_SET_ANY(x, BIT(i))) {
			printf("%d", 1);
		} else {
			printf("%d", 0);
		}
	}
	printf("\n");
	
	for (int i = 31; i > -1; i--) {
		if (IS_CLEAR_ANY(x, BIT(i))) {
			printf("%d", 1);
		} else {
			printf("%d", 0);
		}
	}
	printf("\n");
}

unsigned int get_page_offset(unsigned int address) {
	return BF_GET(address, 0, 11);
}
unsigned int get_tlb_id(unsigned int address) {
	return BF_GET(address, 12, 3);
}
unsigned int get_tlb_tag(unsigned int address) {
	return BF_GET(address, 24, 7);
}
unsigned int set_page_offset(unsigned int address, unsigned int new_offset) {
	return BF_SET(address, new_offset, 0, 11);
}
unsigned int set_tlb_id(unsigned int address, unsigned int new_tlb_id) {
	return BF_SET(address, new_tlb_id, 12, 3);
}
unsigned int set_tlb_tag(unsigned int address, unsigned int new_tag) {
	return BF_SET(address, new_tag, 24, 7);
}
	
