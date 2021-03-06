#ifndef __TAS256X_REGMAP__
#define __TAS256X_REGMAP__

struct linux_platform {
	struct device *dev;
	struct i2c_client *client;
	struct regmap *regmap;
	struct hrtimer mtimer;
	/* device is working, but system is suspended */
	int (*runtime_suspend)(struct tas256x_priv *p_tas256x);
	int (*runtime_resume)(struct tas256x_priv *p_tas256x);
	bool mb_runtime_suspend;
	bool i2c_suspend;
};

#ifdef CONFIG_DEBUG_FS
extern const struct file_operations smartpa_dbgfs_register_fops;
extern const struct file_operations smartpa_dbgfs_i2c_fops;
#endif

#endif /*__TAS256X_REGMAP__*/