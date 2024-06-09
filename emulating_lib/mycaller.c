#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include "mylib.h"

MODULE_AUTHOR("vk");
MODULE_DESCRIPTION("Lib simulation LKM");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

int product(int a, int b);

static int __init mycaller_init(void)
{
    int result;
    result = product(2, 3);
    printk(KERN_CRIT "Product: %d\n", result);
    return 0;
}

static void __exit mycaller_exit(void)
{
    printk(KERN_CRIT "Bye, LKM\n");
}

module_init(mycaller_init);
module_exit(mycaller_exit);
