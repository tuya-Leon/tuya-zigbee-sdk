/*
 * @Author: Leon
 * @email: zhangpeng@tuya.com
 * @LastEditors: Leon
 * @file name: zigbee_dev_template.h
 * @Description: zigbee device cluster and attribute template files
 * @Copyright: HANGZHOU TUYA INFORMATION TECHNOLOGY CO.,LTD
 * @Company: http://www.tuya.com
 * @Date: 2019-03-25 21:41:18
 * @LastEditTime: 2019-04-15 20:24:42
 */

#ifndef ZIGBEE_DEV_TEMPLATE__H
#define ZIGBEE_DEV_TEMPLATE__H

#ifdef __cplusplus
extern "C" {
#endif

#include "zigbee_sdk.h"

extern const uint8_t basic_default_value[];

//attributes define
#define BASE_ATTR_LIST \
    { 0x0000, ATTR_INT8U_ATTRIBUTE_TYPE, 1, (ATTR_MASK_SINGLETON), { (uint8_t*)0x03 } }, /* 0 / Basic / ZCL version*/\
    { 0x0001, ATTR_INT8U_ATTRIBUTE_TYPE, 1, (ATTR_MASK_SINGLETON), { (uint8_t*)0x00 } }, /* 1 / Basic / application version*/\
    { 0x0002, ATTR_INT8U_ATTRIBUTE_TYPE, 1, (ATTR_MASK_SINGLETON), { (uint8_t*)0x00 } }, /* 2 / Basic / stack version*/\
    { 0x0003, ATTR_INT8U_ATTRIBUTE_TYPE, 1, (ATTR_MASK_SINGLETON), { (uint8_t*)0x00 } }, /* 3 / Basic / hardware version*/\
    { 0x0004, ATTR_CHAR_STRING_ATTRIBUTE_TYPE, 33, (ATTR_MASK_TOKENIZE|ATTR_MASK_SINGLETON), { NULL } }, /* 4 / Basic / manufacturer name*/\
    { 0x0005, ATTR_CHAR_STRING_ATTRIBUTE_TYPE, 33, (ATTR_MASK_SINGLETON), { NULL } }, /* 5 / Basic / model identifier*/\
    { 0x0006, ATTR_CHAR_STRING_ATTRIBUTE_TYPE, 17, (ATTR_MASK_SINGLETON), { NULL } }, /* 6 / Basic / date code*/\
    { 0x0007, ATTR_ENUM8_ATTRIBUTE_TYPE, 1, (ATTR_MASK_SINGLETON), { (uint8_t*)0x01 } }, /* 7 / Basic / power source*/\
    { 0xFFFD, ATTR_INT16U_ATTRIBUTE_TYPE, 2, (ATTR_MASK_SINGLETON), { (uint8_t*)0x0001 } }, /* 8 / Basic / cluster revision*/\
    { 0xFFFE, ATTR_ENUM8_ATTRIBUTE_TYPE, 1, (ATTR_MASK_SINGLETON), { (uint8_t*)0x00 } },/*9*/\

#define POWER_ATTR_LIST \
    { 0x0000, ATTR_INT16U_ATTRIBUTE_TYPE, 2, (ATTR_MASK_SINGLETON), { (uint8_t*)0x0000UL } }, /* 10 / Power Configuration / mains voltage*/\
    { 0x0020, ATTR_INT8U_ATTRIBUTE_TYPE, 1, (ATTR_MASK_SINGLETON|ATTR_MASK_TOKENIZE), { (uint8_t*)0x00UL } }, /* 11 / Power Configuration / battery voltage*/\
    { 0x0021, ATTR_INT8U_ATTRIBUTE_TYPE, 1, (ATTR_MASK_SINGLETON|ATTR_MASK_TOKENIZE), { (uint8_t*)0x00 } }, /* 12 / Power Configuration / battery percentage remaining*/\
    { 0xFFFD, ATTR_INT16U_ATTRIBUTE_TYPE, 2, (ATTR_MASK_SINGLETON), { (uint8_t*)0x0001 } }, /* 13 / Power Configuration / cluster revision*/\


#define OTA_ATTR_LIST \
    { 0x0000, ATTR_IEEE_ADDRESS_ATTRIBUTE_TYPE, 8, (ATTR_MASK_CLIENT), { (uint8_t*)&(basic_default_value[0]) } }, /* 24 / Over the Air Bootloading / OTA Upgrade Server ID*/\
    { 0x0001, ATTR_INT32U_ATTRIBUTE_TYPE, 4, (ATTR_MASK_CLIENT), { (uint8_t*)&(basic_default_value[8]) } }, /* 25 / Over the Air Bootloading / Offset (address) into the file*/\
    { 0x0006, ATTR_ENUM8_ATTRIBUTE_TYPE, 1, (ATTR_MASK_CLIENT), { (uint8_t*)0x00 } }, /* 26 / Over the Air Bootloading / OTA Upgrade Status*/\
    { 0xFFFD, ATTR_INT16U_ATTRIBUTE_TYPE, 2, (ATTR_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 27 / Over the Air Bootloading / cluster revision*/\

#define GROUP_ATTR_LIST \
    { 0x0000, ATTR_BITMAP8_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0x00 } }, /* 12 / Groups / name support*/\
    { 0xFFFD, ATTR_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0001 } }, /* 13 / Groups / cluster revision*/\

#define SCENE_ATTR_LIST \
    { 0x0000, ATTR_INT8U_ATTRIBUTE_TYPE, 1, (ATTR_MASK_TOKENIZE), { (uint8_t*)0x00 } }, /* 15 / Scenes / scene count*/\
    { 0x0001, ATTR_INT8U_ATTRIBUTE_TYPE, 1, (ATTR_MASK_TOKENIZE), { (uint8_t*)0x00 } }, /* 16 / Scenes / current scene*/\
    { 0x0002, ATTR_INT16U_ATTRIBUTE_TYPE, 2, (ATTR_MASK_TOKENIZE), { (uint8_t*)0x0000 } }, /* 16 / Scenes / current group*/\
    { 0x0003, ATTR_BOOLEAN_ATTRIBUTE_TYPE, 1, (ATTR_MASK_TOKENIZE), { (uint8_t*)0x00 } }, /* 17 / Scenes / scene valid*/\
    { 0x0004, ATTR_BITMAP8_ATTRIBUTE_TYPE, 1, (ATTR_MASK_TOKENIZE), { (uint8_t*)0x00 } }, /* 18 / Scenes / name support*/\
    { 0xFFFD, ATTR_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0001 } }, /* 19 / Scenes / cluster revision*/\

#define SCENE_CLINET_ATTR_LIST \
    { 0xFFFD, ATTR_INT16U_ATTRIBUTE_TYPE, 2, (ATTR_MASK_CLIENT), { (uint8_t*)0x0001 } }, /* 13 / Scenes client / cluster revision*/\

#define ON_OFF_LIGHT_ATTR_LIST \
    { 0x0000, ATTR_BOOLEAN_ATTRIBUTE_TYPE, 1, (ATTR_MASK_TOKENIZE), { (uint8_t*)0x00 } }, /* 20 / On/off / on/off*/\

#define LEVEL_CONTROL_ATTR_LIST \
    { 0x0000, ATTR_INT8U_ATTRIBUTE_TYPE, 1, (ATTR_MASK_WRITABLE), { (uint8_t*)0x00 } }, /* 20 / Level Control / Current Level*/\

#define COLOR_CONTROL_ATTR_LIST \
    { 0x0000, ATTR_INT8U_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0x10 } }, /* 41 / Color Control / current hue*/\
    { 0x0001, ATTR_INT8U_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0x10 } }, /* 42 / Color Control / current saturation*/\
    { 0x0002, ATTR_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0000 } }, /* 43 / Color Control / remaining time*/\
    { 0x0003, ATTR_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0000 } }, /* 44 / Color Control / current x*/\
    { 0x0004, ATTR_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0000 } }, /* 45 / Color Control / current y*/\
    { 0x0007, ATTR_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0000 } }, /* 46 / Color Control / color temperature*/\
    { 0x0008, ATTR_ENUM8_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0x02 } }, /* 47 / Color Control / color mode*/\


#define IAS_ZONE_ATTR_LIST \
    { 0x0000, ATTR_ENUM8_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0x00 } }, /* 21 / IAS Zone / zone state*/\
    { 0x0001, ATTR_ENUM16_ATTRIBUTE_TYPE, 2, (ATTR_MASK_TOKENIZE), { (uint8_t*)0x0028 } }, /* 22 / IAS Zone / zone type*/\
    { 0x0002, ATTR_BITMAP16_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0000 } }, /* 23 / IAS Zone / zone status*/\
    { 0x0010, ATTR_IEEE_ADDRESS_ATTRIBUTE_TYPE, 8, (ATTR_MASK_WRITABLE), { NULL } }, /* 24 / IAS Zone / IAS CIE address*/\
    { 0x0011, ATTR_INT8U_ATTRIBUTE_TYPE, 1, (0x00), { (uint8_t*)0xff } }, /* 25 / IAS Zone / Zone ID*/\
    { 0xFFFD, ATTR_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t*)0x0001 } }, /* 26 / IAS Zone / cluster revision*/\

#define WINDOW_COVERING_ATTR_LIST \
    { 0x0008, ATTR_INT8U_ATTRIBUTE_TYPE, 1, (ATTR_MASK_TOKENIZE|ATTR_MASK_SINGLETON), { (uint8_t*)0x00 } }, /* current positiong lift percentage*/\
    { 0x0009, ATTR_INT8U_ATTRIBUTE_TYPE, 1, (ATTR_MASK_TOKENIZE|ATTR_MASK_SINGLETON), { (uint8_t*)0x00 } }, /* current positiong tilt percentage*/\


#define PRIVATE_ATTR_LIST \
    { 0x0000, ATTR_INT8U_ATTRIBUTE_TYPE, 1, (ATTR_MASK_TOKENIZE|ATTR_MASK_SINGLETON), { (uint8_t*)0x00 } }, /* current positiong lift percentage*/\

   
 

//ZCL define
#define DEF_CLUSTER_BASIC_CLUSTER_ID(a) \
    { CLUSTER_BASIC_CLUSTER_ID, (attr_t *)&((a)[0]), get_array_len((a)) },
    
#define DEF_CLUSTER_POWER_CLUSTER_ID(a) \
    { CLUSTER_POWER_CONFIG_CLUSTER_ID, (attr_t *)&((a)[0]), get_array_len((a)) },

#define DEF_CLUSTER_OTA_BOOTLOAD_CLUSTER_ID(a) \
    { CLUSTER_OTA_BOOTLOAD_CLUSTER_ID, (attr_t *)&((a)[0]), get_array_len((a)) },

#define DEF_CLUSTER_GROUPS_CLUSTER_ID(a) \
    { CLUSTER_GROUPS_CLUSTER_ID, (attr_t *)&((a)[0]), get_array_len((a)) },

#define DEF_CLUSTER_SCENES_CLUSTER_ID(a) \
    { CLUSTER_SCENES_CLUSTER_ID, (attr_t *)&((a)[0]), get_array_len((a)) },

#define DEF_CLUSTER_ON_OFF_CLUSTER_ID(a) \
    { CLUSTER_ON_OFF_CLUSTER_ID, (attr_t *)&((a)[0]), get_array_len((a)) },

#define DEF_CLUSTER_LEVEL_CONTROL_CLUSTER_ID(a) \
    { CLUSTER_LEVEL_CONTROL_CLUSTER_ID, (attr_t *)&((a)[0]), get_array_len((a)) },
    
#define DEF_CLUSTER_COLOR_CONTROL_CLUSTER_ID(a) \
    { CLUSTER_COLOR_CONTROL_CLUSTER_ID, (attr_t *)&((a)[0]), get_array_len((a)) },
    
#define DEF_CLUSTER_IAS_ZONE_CLUSTER_ID(a) \
    { CLUSTER_IAS_ZONE_CLUSTER_ID, (attr_t *)&((a)[0]), get_array_len((a)) },

#define DEF_CLUSTER_WINDOW_COVERING_CLUSTER_ID(a) \
    { CLUSTER_WINDOW_COVERING_CLUSTER_ID, (attr_t *)&((a)[0]), get_array_len((a)) },

#define DEF_CLUSTER_PRIVATE_CLUSTER_ID(a) \
    { CLUSTER_PRIVATE_TUYA_CLUSTER_ID, (attr_t *)&((a)[0]), get_array_len((a)) },

#ifdef __cplusplus
}
#endif

#endif




