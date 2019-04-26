/*
 * @Author: Leon
 * @email: zhangpeng@tuya.com
 * @LastEditors: Leon
 * @file name: mf_test_callback.h
 * @Description: manufactury test callback files
 * @Copyright: HANGZHOU TUYA INFORMATION TECHNOLOGY CO.,LTD
 * @Company: http://www.tuya.com
 * @Date: 2019-03-25 21:41:17
 * @LastEditTime: 2019-04-15 21:32:52
 */

#ifndef MF_TEST_CALLBACK__H
#define MF_TEST_CALLBACK__H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>
#include <stdint.h>

    //device manufactury test resut status
    typedef enum
    {
        MF_TEST_SUCCESS,
        MF_TEST_FAILED,
        MF_TEST_DOING
    } MF_TEST_RET_T;

    /**
 * @description: device manufactury test result notify function
 * @param {result} none
 * @return: MF_TEST_RET_T manufactury test resut status
 */
    extern void dev_mf_noti_result(MF_TEST_RET_T result);

    /**
 * @description: device manufactury test(button test) notify 
 * @param {key_id} manufactury test key id 
 * @return: none
 */
    extern void dev_mf_button_test_notify(uint32_t key_id);

#ifdef __cplusplus
}
#endif

#endif
