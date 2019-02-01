#ifndef GPIO_AW_H_INCLUDED
#define GPIO_AW_H_INCLUDED
#include <linux/list.h>
#include <linux/spinlock.h>
#include <linux/rwsem.h>
#include <linux/timer.h>
struct gpio_aw_platdata {
	u32                 pio_hdle;
	unsigned int		 flags;
	char				*name;
	
};
struct gpio_aw_classdev{
	const char	*name;
	int port;					/*GPIOʹ�õĶ˿ں� 1:PA 2:PB .... */
	int port_num;				/*GPIO�ڵ�ǰ�˿ڵ����(�ڼ�������)  */
	int mul_sel;				/*GPIO�Ĺ���ѡ�� 0������  1����� */
	int pull;					/*GPIO�����õ���״̬ 0������裬1����������2�������� */
	int drv_level;				/*GPIO���������� ��0��3�ĸ��ȼ� */
	int data;					/*GPIO�ĵ�ƽ */
	int flags;
	#define AW_GPIO_SUSPENDED		(1 << 0)
	#define AW_GPIO_CORE_SUSPENDED		(1 << 16)
	int		(*gpio_aw_cfg_set)(struct gpio_aw_classdev *gpio_aw_cdev,
					int  mul_sel);		/*����gpio���������״̬ */
	int		(*gpio_aw_pull_set)(struct gpio_aw_classdev *gpio_aw_cdev,
					int  pull);			/*����gpio�ĵ������������Ǹ���������� */
	int		(*gpio_aw_data_set)(struct gpio_aw_classdev *gpio_aw_cdev,
					int  data);			/*����gpio�������ƽ*/ 				  
	int		(*gpio_aw_drv_level_set)(struct gpio_aw_classdev *gpio_aw_cdev,
					int  drv_level);	/*����gpio�������ȼ� */
	int		(*gpio_aw_cfg_get)(struct gpio_aw_classdev *gpio_aw_cdev);	
										/*��ȡgpio��������� */
	int		(*gpio_aw_pull_get)(struct gpio_aw_classdev *gpio_aw_cdev);	
										/*��ȡgpio�ĵ������������Ǹ���������� */
	int		(*gpio_aw_data_get)(struct gpio_aw_classdev *gpio_aw_cdev);			
										/*��ȡpio�������ƽ*/
	int		(*gpio_aw_drv_level_get)(struct gpio_aw_classdev *gpio_aw_cdev);	
										/*��ȡgpio�������ȼ� */
	struct device		*dev;
	struct list_head	 node;
					
};


extern void gpio_aw_classdev_suspend(struct gpio_aw_classdev *gpio_aw_cdev);
extern void gpio_aw_classdev_resume(struct gpio_aw_classdev *gpio_aw_cdev);

extern int gpio_aw_classdev_register(struct device *parent, 
				struct gpio_aw_classdev *gpio_aw_cdev);
extern void gpio_aw_classdev_unregister(struct gpio_aw_classdev *gpio_aw_cdev);


#endif
