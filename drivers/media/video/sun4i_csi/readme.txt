===========================================

Version: V1_31

Author:  raymonxiu

Date:     2012-2-28 19:47:09

Description:

newest module list:(X = 0 or 1)
insmod sun4i_csiX.ko ccm="ov7670" i2c_addr=0x42
insmod sun4i_csiX.ko ccm="gc0308" i2c_addr=0x42
insmod sun4i_csiX.ko ccm="gt2005" i2c_addr=0x78
insmod sun4i_csiX.ko ccm="hi704"  i2c_addr=0x60
insmod sun4i_csiX.ko ccm="sp0838" i2c_addr=0x30
insmod sun4i_csiX.ko ccm="mt9m112" i2c_addr=0xba
insmod sun4i_csiX.ko ccm="mt9m113" i2c_addr=0x78
insmod sun4i_csiX.ko ccm="ov2655" i2c_addr=0x60
insmod sun4i_csiX.ko ccm="hi253" i2c_addr=0x40
insmod sun4i_csiX.ko ccm="gc0307" i2c_addr=0x42
insmod sun4i_csiX.ko ccm="mt9d112" i2c_addr=0x78
insmod sun4i_csiX.ko ccm="ov5640" i2c_addr=0x78
insmod sun4i_csiX.ko ccm="gc2015" i2c_addr=0x60
insmod sun4i_csiX.ko ccm="ov2643" i2c_addr=0x60

V1_31
CSI: Modify clock gating and axp_gpio_get_io bug
1) Insure the clk_enable() and clk_disable() are called in pair
2) Fix the axp_gpio_get_io() bug for pmu gpio2

V1_30
CSI: Modfiy device source code to keep identical between sun4i/5i
1) Modfiy the device source code to keep identical between sun4i/5i
2) Fix gc0308 red color

V1_21
CSI: Add standy and reset control before power off

V1_20
CSI: Add i2c adapter lock when camera power on/off and standby on/off
1) Add i2c adapter lock when camera power on/off and standby on/off
2) Modify standby and reset io sequence when power on and standby off
3) Add new camera module gc2015,ov2643 and modify deconfig

V1_11
CSI: Mainly fix bugs on mt9m112,ov5640 and ov7670
1) Fix bug on calling poll or read before streamon
2) Fix bug on mt9m112 and ov5640 multiplex use 
3) Fix ov7670 sensor init
4) Modify the delay on ov2655 after every i2c command
5) Modify camera debug info

V1_10
CSI: Fix bugs, add new modules support and modity power/standby interface
1) Fix bugs for CTS test
2) Fix bugs for crash when insmod after rmmod
3) Add default format for csi driver
4) Modify the power on/off,stanby on/off interface
5) Fix bugs for multipex dual sensors using one csi 
6) Add gc0307, mt9d112 and ov5640 modules support
7) Fix gc0308 AWB alternation bug

V1_02
CSI: Change clock source to video pll 1 and add code for C version IC

V1_01
CSI: Add HI253 support IC version detection and fix HI704 i2c bug

V1_00
CSI:Initial version for linux 3.0.8
1) Ported from linux2.3.36


