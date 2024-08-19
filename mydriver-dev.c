#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pm_runtime.h>
#include <linux/regulator/consumer.h>
#include <linux/version.h>
#include <media/v4l2-subdev.h>

static int mydriver_pm_power_on(struct device *dev)
{
    return 0;
}

static int mydriver_pm_power_off(struct device *dev)
{
    return 0;
}

static int __maybe_unused mydriver_suspend(struct device *dev)
{
	return 0;
}

static int __maybe_unused mydriver_resume(struct device *dev)
{
    return 0;
}
static int mydriver_probe(struct i2c_client *client)
{
    return 0;
}
static void mydriver_remove(struct i2c_client *client) {
    return;
}

static const struct of_device_id mydriver_dt_ids[] = {
	{ .compatible = "garbage,mydriver" },
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, mydriver_dt_ids);

// clang-format off
static const struct dev_pm_ops mydriver_pm_ops = {
	SET_SYSTEM_SLEEP_PM_OPS(mydriver_suspend, mydriver_resume)
	SET_RUNTIME_PM_OPS(mydriver_pm_power_off, mydriver_pm_power_on, NULL)
};
// clang-format on

static struct i2c_driver mydriver_i2c_driver = {
	.driver = {
		.name = "mydriver",
		.of_match_table = mydriver_dt_ids,
		.pm = &mydriver_pm_ops,
	},
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 5, 0)
	.probe = mydriver_probe,
#else	
	.probe_new = mydriver_probe,
#endif
	.remove = mydriver_remove,
};


module_i2c_driver(mydriver_i2c_driver);

MODULE_AUTHOR("Michał Fita <nobody@nowhere.com>");
MODULE_DESCRIPTION("Demo code");
MODULE_VERSION("0.1");
MODULE_LICENSE("GPL v2");
