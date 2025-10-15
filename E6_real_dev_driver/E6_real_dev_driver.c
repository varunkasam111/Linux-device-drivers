#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>
#include<linux/device.h>
#include<linux/cdev.h>
#include<linux/slab.h>
#include<linux/uaccess.h>


dev_t mydev;
static struct class *my_class;
static struct cdev my_cdev;
uint8_t *kernel_buffer;


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
	if(copy_to_user(buf, kernel_buffer,1024))
	{
		pr_err("read errror\n");
	}

        pr_info("read ftn called\n");
        return 0;
}

/*static ssize_t var_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
    size_t datalen = strlen(kernel_buffer);

    // Return 0 if data is already read
    if (*off >= datalen)
        return 0;

    // Limit len to available data
    if (len > datalen - *off)
        len = datalen - *off;

    if (copy_to_user(buf, kernel_buffer + *off, len))
        return -EFAULT;

    *off += len; // update file offset
    pr_info("read ftn called, %zu bytes read\n", len);

    return len;
}*/


static ssize_t var_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
	if(copy_from_user(kernel_buffer,buf,len))
	{
		pr_err("write error\n");
	}

        pr_info("write ftn called\n");
        return len;
}



static struct file_operations my_fops=
{
.owner = THIS_MODULE,
.read = var_read,
.write = var_write,
.open = var_open,
.release = var_release,

};



static int __init my_init(void)
{
	alloc_chrdev_region(&mydev,0,1,"varun_device");
	
	
	my_class=class_create(THIS_MODULE,"var_class");
	device_create(my_class,NULL,mydev,NULL,"var_device");
	
	
	cdev_init(&my_cdev,&my_fops);
	cdev_add(&my_cdev,mydev,1);
	
//	kernel_buffer=kmalloc(1024,GFP_KERNEL)        /*Creating Physical memory*/
        if((kernel_buffer = kmalloc(1024 , GFP_KERNEL)) == 0){
            pr_info("Cannot allocate memory in kernel\n");
         //   goto r_device;
        };
	strcpy(kernel_buffer,"Hello World");

	pr_info("Module created and inserted succesfully\n");

	return 0;
}


static void __exit my_exit(void)
{
	
	cdev_del(&my_cdev);

	device_destroy(my_class,mydev);
	class_destroy(my_class);

	unregister_chrdev_region(mydev,1);
	pr_info("mod removed\n");
}


module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("VARUN KAASAM");
MODULE_DESCRIPTION("THIS MODULE IS A BASIC LINUX DVICE DRIVER WHICH PERFORMS FILE WRITE AND READ OPERATIONS");
