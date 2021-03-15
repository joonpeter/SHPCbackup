#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x85359828, "module_layout" },
	{ 0xd5c7c17c, "debugfs_remove_recursive" },
	{ 0xf9a482f9, "msleep" },
	{ 0xf527cd21, "debugfs_create_file" },
	{ 0x276824d6, "debugfs_create_dir" },
	{ 0xd2b09ce5, "__kmalloc" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x733f1e9b, "pv_ops" },
	{ 0xb3ec1971, "follow_pte_pmd" },
	{ 0x25417377, "up_read" },
	{ 0xabfcafc3, "down_read" },
	{ 0x5bff2c08, "pid_task" },
	{ 0x4b098dd8, "find_vpid" },
	{ 0x9166fada, "strncpy" },
	{ 0xa916b694, "strnlen" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x69acdf38, "memcpy" },
	{ 0xbb238fc5, "filp_close" },
	{ 0x7a4bf251, "kernel_write" },
	{ 0x273ca39, "filp_open" },
	{ 0x37a0cba, "kfree" },
	{ 0x1a9a433c, "prandom_u32_state" },
	{ 0x55200ae5, "kmem_cache_alloc_trace" },
	{ 0x11bd46af, "kmalloc_caches" },
	{ 0xc5850110, "printk" },
	{ 0x3a78fadc, "current_task" },
	{ 0x72a029a5, "wake_up_process" },
	{ 0xcd0e930b, "kthread_create_on_node" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xbb4f4766, "simple_write_to_buffer" },
	{ 0xdecd0b29, "__stack_chk_fail" },
	{ 0xf5e7ea40, "ktime_get_coarse_ts64" },
	{ 0xbdfb6dbb, "__fentry__" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "482E77C83025C3600B5295D");
