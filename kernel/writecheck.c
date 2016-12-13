#include <linux/kernel.h>
#include <linux/gfp.h>
#include <linux/mm.h>
#include <linux/uaccess.h>
#include <linux/writecheck.h>
#include <linux/prot_addr.h>

#define PAGESIZE 4096

extern struct prot_addr addr_prot;
int writecheck(void* address, long value)
{
	struct vm_area_struct *vma;
	unsigned long old_flags, new_flags;
        unsigned long pg_start = value & ~(PAGESIZE-1);
	unsigned long pg_end = pg_start + PAGESIZE;
	struct page *shadow_page;
	void* shadow_address;
	int* user_addr;

	/* Set page contained variable as read-only */
	vma = find_vma(current->mm, pg_start);
	if(vma->vm_flags & VM_WRITE){
		vma->vm_flags = vma->vm_flags | ~VM_WRITE;
		vma_set_page_prot(vma);
	}
		
	/* Write to take care address */
	addr_prot.addr[addr_prot.index] = (unsigned long) value;
	addr_prot.index++;
	printk("Addr=%lx, index = %d\n",addr_prot.addr[addr_prot.index-1],addr_prot.index);
/*
	
	vma = find_vma(current->mm, start);

	
	if(start != vma->start)
		split_vma(vma->mm, vma, start, 1);
	if(end != vma->end)
		split_vma(vma->mm, vma, end, 0);
	
	
	old_flags = vma->vm_flags;
	
	if(old_flags & VM_WRITE)
		new_flags = old_flags & ~(VM_WRITE);

	shadow_page = alloc_page(GFP_KERNEL);
	shadow_address = page_address(shadow_page);
	user_addr = (void*) start;
	printk("User address %lx\n",start);
	copy_from_user(shadow_address, user_addr, PAGESIZE);
	printk("Kernel modified\n");
*/
//	printk("Put user \n");
//	put_user((int)value,(int*) address);
//	shadow_page = (void __user *) start;
//	printk("Shadow page %lx",shadow_page);
//	if(!mprotect(shadow_page, PAGESIZE, PROT_READ))
//		printk("Protected");
}
