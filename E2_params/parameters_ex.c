#include<linux/kernel.h>

#include<linux/init.h>

#include<linux/module.h>

#include<linux/moduleparam.h>


int var=0;

int cb_var=0;

module_param(var,int , S_IRUSR | S_IWUSR);



int my_set(const char *val, const struct kernel_param *kp)

{

        int res = param_set_int(val,kp);

        if(res == 0)

        {

                printk("Call back ftn called\n");

                printk("new value of var is %d\n",var);

                printk("value of cb var is %d \n",cb_var);


                return 0;

        }

        return -1;


}


const struct kernel_param_ops my_ops =

{

        .set = &my_set,

        .get = &param_get_int,

};


module_param_cb(cb_var, &my_ops, &cb_var, S_IRUGO | S_IWUSR);




static int __init my_module_init(void)

{

        printk("Module inserted\n");

        printk("value of var is %d \n",var);

        printk("value of cb_var is %d \n",cb_var);


        return 0;

}


static void __exit my_module_exit(void)

{

         printk("Module removed\n");


}


module_init(my_module_init);

module_exit(my_module_exit);



MODULE_LICENSE("GPL v2");

MODULE_AUTHOR("Varun");

MODULE_DESCRIPTION("This module demonstrates the passing of arguments in to Ldd"); 
