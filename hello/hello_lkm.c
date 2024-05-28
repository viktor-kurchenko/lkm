#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_AUTHOR("vk");
MODULE_DESCRIPTION("hello, world LKM");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

static int __init hello_init(void)
{
    printk(KERN_CRIT "Hello, LKM\n");
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_CRIT "Bye, LKM\n");
}

module_init(hello_init);
module_exit(hello_exit);
