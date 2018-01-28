#include "bits.h"
#include <stdio.h>

int main() {
	/*int x = 4;
	printf("4\n");
	print_in_binary(4);
	
	printf("call BIT\n");
	print_in_binary(BIT(4));
	
	printf("Set bit 32 to 1\n");
	print_in_binary(BIT_SET(x, 32));
	
	printf("clear bit 2\n");
	print_in_binary(BIT_CLEAR(x, 32));
	
	printf("flip bits\n");
	print_in_binary(BIT_FLIP(x, 2));
	
	printf("is set any \n");
	print_in_binary(IS_SET_ANY(x, 2));
	*/

	printf("page offset: %x\n", get_page_offset(0xf712c0d0));
	printf("tlb id: %x\n", get_tlb_id(0xf712c0d0));
	printf("tlb tag: %x\n", get_tlb_tag(0xf712c0d0));
	printf("\n");
	printf("page offset: %x\n", set_page_offset(0xf712c0d0, 0x1a3));
	printf("tlb id: %x\n", set_tlb_id(0xf712c0d0, 0));
	printf("tlb tag: %x\n", set_tlb_tag(0xf712c0d0, 0x8400));
	return 0;

}
