#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>

//dev_t vdev=MKDEV(123,0);//for static allocation
dev_t vvdev=0;//for dynamic allocation


static int __init my_init(void)
{
	//int res=register_chrdev_region(vdev,1,"Varun_dev");//for static allocation
	int res=alloc_chrdev_region(&vvdev,0,1,"Varun_dev");//for dynamic allocation

	if(res==0)
	{
		pr_info("module inserted\n");
		//pr_info("major = %d and minor = %d\n",MAJOR(vdev),MINOR(vdev));
		 pr_info("major = %d and minor = %d\n",MAJOR(vvdev),MINOR(vvdev));

		return 0;
	}
	return -1;

}

static void __exit my_exit(void)
{
	//unregister_chrdev_region(vdev, 1);//for static alloc
	unregister_chrdev_region(vvdev, 1);//for dynamic alloc 

	pr_info("removed and unregistered the module\n");
}
module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Varun");
MODULE_DESCRIPTION("Module demonstrates how to register a LKM and assign major and minor number statically and dynamically");

