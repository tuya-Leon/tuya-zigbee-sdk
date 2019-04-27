/*
 * @Author: Leon
 * @email: zhangpeng@tuya.com
 * @LastEditors: Leon
 * @file name: zigbee_modules
 * @Description: TUYA zigbee modules micro define files
 * @Copyright: HANGZHOU TUYA INFORMATION TECHNOLOGY CO.,LTD
 * @Company: http://www.tuya.com
 * @Date: 2019-04-01 17:28:33
 * @LastEditTime: 2019-04-15 20:25:26
 */

#ifndef ZIGBEE_MODULES_H
#define ZIGBEE_MODULES_H

typedef enum
{
    TYZS1 = 0,
    TYZS1L,
    TYZS2,
    TYZS2R,
    TYZS3,
    TYZS4,
    TYZS5,
    TYZS5L,
    TYZS6,
    TYZS7,
    TYZS8,
    TYZS9V,
    TYZS10,
    TYZS11,
    TYZS12,
    TYZS13,
    TYZS15
}zigbee_modules_e;

#define TYZS3_USART_CONFIG_DEFAULT {\
    UART_ID_UART0,\
    UART_PIN_TYPE_CONFIG,\
    {PORT_A, PIN_0},\
    {PORT_A, PIN_1},\
    LOC_0, \
    LOC_0, \
    115200,\
    USART_PARITY_NONE,\
    USART_STOPBITS_ONE,\
    USART_DATABITS_8BIT,\
    NULL\
}

#define TYZS5_USART_CONFIG_DEFAULT {\
    UART_ID_UART0,\
    UART_PIN_TYPE_CONFIG,\
    {PORT_F, PIN_5},\
    {PORT_F, PIN_2},\
    LOC_29, \
    LOC_25, \
    115200,\
    USART_PARITY_NONE,\
    USART_STOPBITS_ONE,\
    USART_DATABITS_8BIT,\
    NULL\
}

#define TYZS2R_USART_CONFIG_DEFAULT {\
    UART_ID_UART0,\
    UART_PIN_TYPE_CONFIG,\
    {PORT_A, PIN_3},\
    {PORT_A, PIN_4},\
    LOC_3, \
    LOC_3, \
    115200,\
    USART_PARITY_NONE,\
    USART_STOPBITS_ONE,\
    USART_DATABITS_8BIT,\
    NULL\
}

#define TYZS2_USART_CONFIG_DEFAULT {\
    UART_ID_UART0,\
    UART_PIN_TYPE_CONFIG,\
    {PORT_F, PIN_5},\
    {PORT_F, PIN_2},\
    LOC_29, \
    LOC_25, \
    115200,\
    USART_PARITY_NONE,\
    USART_STOPBITS_ONE,\
    USART_DATABITS_8BIT,\
    NULL\
}

#endif //ZIGBEE_MODULES_H