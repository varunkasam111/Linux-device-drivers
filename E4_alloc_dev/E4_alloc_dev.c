#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/kdev_t.h>
#include<linux/err.h>

dev_t vdev=0;
struct class *var_class;


static int my_init(void)
{

	int res=alloc_chrdev_region(&vdev,0,1,"varun device");
	if(res<0)
	{
		pr_info("Failed to assign Major and minor number\n");
		return -1;
	}
	pr_info("Registered device with Major = %d and Minor = %d\n",MAJOR(vdev),MINOR(vdev));
	var_class=class_create(THIS_MODULE, "var_class");
	device_create(var_class,NULL,vdev,NULL,"var_device");

	return 0;
}

static void my_exit(void)
{
	unregister_chrdev_region(vdev,1);
	device_destroy(var_class,vdev);
	class_destroy(var_class);
	pr_info("Module removed\n");

}

module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL v2");



