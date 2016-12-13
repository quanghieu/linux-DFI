#ifndef PROT_ADDR_H
#define PROT_ADDR_H
struct prot_addr {
	int index;
	unsigned long addr[20];
	int wr_perm[20];
};
#endif
