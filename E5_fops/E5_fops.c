#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>
#include<linux/device.h>
#include<linux/cdev.h>

dev_t vdev;
static struct class *myclass;
static struct cdev mycdev;


static int var_open(struct inode *inode, struct file *file)
{
	pr_info("open ftn called\n");
	return 0;
}

static int var_release(struct inode *inode, struct file *file)
{
	pr_info("release ftn called\n");
	return 0;
}


static ssize_t var_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
	pr_info("read ftn called\n");
	return 0;
}

static ssize_t var_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
	pr_info("write ftn called\n");
	return len;
}

static struct file_operations my_fops={
.owner=THIS_MODULE,
.read = var_read,
.write = var_write,
.open = var_open,
.release = var_release,
};




static int __init my_init(void)
{
	alloc_chrdev_region(&vdev,0,1,"var_device");
	cdev_init(&mycdev,&my_fops);
	cdev_add(&mycdev,vdev,1);

	myclass=class_create(THIS_MODULE,"myclass ");
        device_create(myclass,NULL,vdev,NULL,"mydevice");
	pr_info("module inserted\n");
	return 0;

}

static void __exit my_exit(void)
{
        device_destroy(myclass,vdev);
	class_destroy(myclass);
	cdev_del(&mycdev);
	unregister_chrdev_region(vdev,1);
	pr_info("module removed\n");

}

module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");

