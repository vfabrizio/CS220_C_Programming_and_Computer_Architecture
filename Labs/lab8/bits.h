#ifndef _BITS_H
#define _BITS_H

#define BIT(n) (1 << (n)) //generate num with nth bit set (2^n)
#define BIT_SET(v, mask) ( v |= (mask) ) //force mask into v
#define BIT_CLEAR(v, mask) ( v &= ~(mask) ) //reverse mask
//second reverse!!!!!!
#define BIT_FLIP(v, mask) ( v ^= ~(mask) ) //flip all the bits
#define IS_SET_ANY(v, mask) ( v & (mask) ) //test if bits in mask are set

#define IS_CLEAR_ANY(v, mask) ( ~(v) & (mask) ) 

#define BIT_MASK(len) ( BIT(len)-1 )

//create bitfield mask of length len starting at bit start
#define BF_MASK(start, len) ( BIT_MASK(len)<<(start) )

//prepare a bitmask for insertion
#define BF_PREP(x, start, len) ( ((x) & BIT_MASK(len)) << (start) )

//extract a bitfield if len starting at start dist from y
#define BF_GET(y, start, len) ( ((y) >> start) & BF_MASK(start, len) )

//insert a bitfield x of len starting at start postion into y
#define BF_SET(y, x, start, len) ( (y) & (~(BF_MASK(start, len))) | BF_PREP(x, start, len) )

void print_in_binary(unsigned int x);

unsigned int get_page_offset(unsigned int address);
unsigned int get_tlb_id(unsigned int address);
unsigned int get_tlb_tag(unsigned int address);
unsigned int set_page_offset(unsigned int address, unsigned int new_offset);
unsigned int set_tlb_id(unsigned int address, unsigned int new_tlb_id);
unsigned int set_tlb_tag(unsigned int address, unsigned int new_tag);

#endif
