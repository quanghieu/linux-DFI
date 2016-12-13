#include <linux/kernel.h>
#include <linux/syscalls.h>

asmlinkage long sys_hello(void*,long)
{
	printk("Hello World\n");
	return 0;
}
