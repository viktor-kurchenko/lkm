#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_AUTHOR("vk");
MODULE_DESCRIPTION("hello, world LKM");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");

static char* mp_msg;
module_param(mp_msg, charp, 0660);
MODULE_PARM_DESC(mp_msg, "Greeting message module param.");

static int __init param_init(void)
{
    printk(KERN_CRIT "Param value: %s\n", mp_msg);
    return 0;
}

static void __exit param_exit(void)
{
    printk(KERN_CRIT "Bye, LKM\n");
}

module_init(param_init);
module_exit(param_exit);
