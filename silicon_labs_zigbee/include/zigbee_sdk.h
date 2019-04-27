
#ifndef ZIGBEE_SDK__H
#define ZIGBEE_SDK__H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#include "type_def.h"
#include "zigbee_cmd.h"
#include "zigbee_attr.h"
#include "mf_test_callback.h"
#include "zigbee_modules.h"

#if defined (__IAR_SYSTEMS_ICC__)
    #define  VIRTUAL_FUNC __weak
#else
    #define VIRTUAL_FUNC __attribute__((weak))
#endif

typedef uint8_t bool_t;
#ifndef TRUE
#define  TRUE 1
#endif
#ifndef FALSE
#define  FALSE 0
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif


#define NEXT_REJOIN_TIME            0 
#define WAKE_UP_TIME_AFTER_JOIN    30
#define POLL_INTERVAL              250
#define WAIT_APP_ACK_TIME          1000
#define POWER_ON_AUTO_REJOIN_FLAG  1
#define POLL_FOREVER_FLAG          1
#define REJOIN_TRY_TIMES           3

//Zigbee dev define
typedef enum {
    ZG_ROUTER = 0,
    ZG_END_DEVICE,
    ZG_SLEEPY_END_DEVICE,
}ZG_DEV_T;

typedef struct {
    uint32_t next_rejoin_time;
    uint32_t wake_up_time_after_join;
    uint8_t  rejoin_try_times;
    uint8_t  power_on_auto_rejoin_flag;
}zg_rejoin_config_t;

typedef struct {
    uint16_t poll_interval;
    uint16_t wait_app_ack_time;
    uint8_t  poll_forever_flag;
    uint8_t  poll_failed_times;
}zg_poll_config_t;

typedef struct {
    zg_poll_config_t    poll_conifg;
    zg_rejoin_config_t  rejoin_config;
}zg_sleep_end_device_config;

typedef struct {
    zg_rejoin_config_t  rejoin_config;
}zg_end_device_config;

typedef struct {
    uint8_t reserved;
}zg_router_config;

typedef enum {
    ZB_SCAN_DURATION_0 = 0, //  19.2 ms
    ZB_SCAN_DURATION_1,     //  38.4 ms
    ZB_SCAN_DURATION_2,     //  76.8 ms
    ZB_SCAN_DURATION_3,     //  153.6 ms
    ZB_SCAN_DURATION_4,     //  307.2 ms
    ZB_SCAN_DURATION_5,     //  614.4 ms
    ZB_SCAN_DURATION_6,     //  1.23 sec
    ZB_SCAN_DURATION_7,     //  2.46 sec
    ZB_SCAN_DURATION_8,     //  4.92 sec
    ZB_SCAN_DURATION_9,     //  9.83 sec
    ZB_SCAN_DURATION_10,    //  19.66 sec
    ZB_SCAN_DURATION_11,    //  39.32 sec
    ZB_SCAN_DURATION_12,    //  78.64 sec
    ZB_SCAN_DURATION_13,    //  157.28 sec
    ZB_SCAN_DURATION_14,    //  314.57 sec
}ZB_SCAN_DURATION_T;

typedef struct {
    ZG_DEV_T dev_type;
    union{
        zg_sleep_end_device_config  sleep_dev_cfg;
        zg_end_device_config        end_dev_cfg;
        zg_router_config            router_cfg;
    }config;
    uint16_t            beacon_send_interval_for_join;
    uint16_t            beacon_send_interval_for_rejoin;
    ZB_SCAN_DURATION_T  zb_scan_duration;
}zg_dev_config_t;

//Zigbee profile ID
typedef enum {
    ZHA_PROFILE_ID = 0x0104, //home automation
    ZGP_PROFILE_ID = 0xA1E0, //green power
    ZHC_PROFILE_ID = 0x0108, //personal,home and hospital care
    ZSE_PROFILE_ID = 0x0109, //Smart energy
    ZCBA_PROFILE_ID = 0x0105,//Commerical building automation
    ZIPM_PROFILE_ID = 0x0101,//Industial plant monitoring
    ZTA_PROFILE_ID = 0x0107, //Telecom application
    ZAMI_PROFILE_ID = 0x0109,//Advanced metering initiative
}PROFILE_ID_T;

//cluster ID
typedef enum {
    CLUSTER_BASIC_CLUSTER_ID = 0x0000,
    CLUSTER_POWER_CONFIG_CLUSTER_ID = 0x0001,
    CLUSTER_DEVICE_TEMP_CLUSTER_ID = 0x0002,
    CLUSTER_IDENTIFY_CLUSTER_ID = 0x0003,
    CLUSTER_GROUPS_CLUSTER_ID = 0x0004,
    CLUSTER_SCENES_CLUSTER_ID = 0x0005,
    CLUSTER_ON_OFF_CLUSTER_ID = 0x0006,
    CLUSTER_ON_OFF_SWITCH_CONFIG_CLUSTER_ID = 0x0007,
    CLUSTER_LEVEL_CONTROL_CLUSTER_ID = 0x0008,
    CLUSTER_ALARM_CLUSTER_ID = 0x0009,
    CLUSTER_TIME_CLUSTER_ID = 0x000A,
    CLUSTER_RSSI_LOCATION_CLUSTER_ID = 0x000B,
    CLUSTER_BINARY_INPUT_BASIC_CLUSTER_ID = 0x000F,
    CLUSTER_COMMISSIONING_CLUSTER_ID = 0x0015,
    CLUSTER_PARTITION_CLUSTER_ID = 0x0016,
    CLUSTER_OTA_BOOTLOAD_CLUSTER_ID = 0x0019,
    CLUSTER_POWER_PROFILE_CLUSTER_ID = 0x001A,
    CLUSTER_APPLIANCE_CONTROL_CLUSTER_ID = 0x001B,
    CLUSTER_POLL_CONTROL_CLUSTER_ID = 0x0020,
    CLUSTER_GREEN_POWER_CLUSTER_ID = 0x0021,
    CLUSTER_KEEPALIVE_CLUSTER_ID = 0x0025,
    CLUSTER_SHADE_CONFIG_CLUSTER_ID = 0x0100,
    CLUSTER_DOOR_LOCK_CLUSTER_ID = 0x0101,
    CLUSTER_WINDOW_COVERING_CLUSTER_ID = 0x0102,
    CLUSTER_BARRIER_CONTROL_CLUSTER_ID = 0x0103,
    CLUSTER_PUMP_CONFIG_CONTROL_CLUSTER_ID = 0x0200,
    CLUSTER_THERMOSTAT_CLUSTER_ID = 0x0201,
    CLUSTER_FAN_CONTROL_CLUSTER_ID = 0x0202,
    CLUSTER_DEHUMID_CONTROL_CLUSTER_ID = 0x0203,
    CLUSTER_THERMOSTAT_UI_CONFIG_CLUSTER_ID = 0x0204,
    CLUSTER_COLOR_CONTROL_CLUSTER_ID = 0x0300,
    CLUSTER_BALLAST_CONFIGURATION_CLUSTER_ID = 0x0301,
    CLUSTER_ILLUM_MEASUREMENT_CLUSTER_ID = 0x0400,
    CLUSTER_ILLUM_LEVEL_SENSING_CLUSTER_ID = 0x0401,
    CLUSTER_TEMP_MEASUREMENT_CLUSTER_ID = 0x0402,
    CLUSTER_PRESSURE_MEASUREMENT_CLUSTER_ID = 0x0403,
    CLUSTER_FLOW_MEASUREMENT_CLUSTER_ID = 0x0404,
    CLUSTER_RELATIVE_HUMIDITY_MEASUREMENT_CLUSTER_ID = 0x0405,
    CLUSTER_OCCUPANCY_SENSING_CLUSTER_ID = 0x0406,
    CLUSTER_CARBON_MONOXIDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x040C,
    CLUSTER_CARBON_DIOXIDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x040D,
    CLUSTER_ETHYLENE_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x040E,
    CLUSTER_ETHYLENE_OXIDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x040F,
    CLUSTER_HYDROGEN_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0410,
    CLUSTER_HYDROGEN_SULPHIDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0411,
    CLUSTER_NITRIC_OXIDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0412,
    CLUSTER_NITROGEN_DIOXIDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0413,
    CLUSTER_OXYGEN_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0414,
    CLUSTER_OZONE_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0415,
    CLUSTER_SULFUR_DIOXIDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0416,
    CLUSTER_DISSOLVED_OXYGEN_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0417,
    CLUSTER_BROMATE_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0418,
    CLUSTER_CHLORAMINES_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0419,
    CLUSTER_CHLORINE_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x041A,
    CLUSTER_FECAL_COLIFORM_AND_E_COLI_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x041B,
    CLUSTER_FLUORIDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x041C,
    CLUSTER_HALOACETIC_ACIDS_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x041D,
    CLUSTER_TOTAL_TRIHALOMETHANES_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x041E,
    CLUSTER_TOTAL_COLIFORM_BACTERIA_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x041F,
    CLUSTER_TURBIDITY_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0420,
    CLUSTER_COPPER_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0421,
    CLUSTER_LEAD_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0422,
    CLUSTER_MANGANESE_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0423,
    CLUSTER_SULFATE_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0424,
    CLUSTER_BROMODICHLOROMETHANE_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0425,
    CLUSTER_BROMOFORM_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0426,
    CLUSTER_CHLORODIBROMOMETHANE_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0427,
    CLUSTER_CHLOROFORM_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0428,
    CLUSTER_SODIUM_CONCENTRATION_MEASUREMENT_CLUSTER_ID = 0x0429,
    CLUSTER_IAS_ZONE_CLUSTER_ID = 0x0500,
    CLUSTER_IAS_ACE_CLUSTER_ID = 0x0501,
    CLUSTER_IAS_WD_CLUSTER_ID = 0x0502,
    CLUSTER_GENERIC_TUNNEL_CLUSTER_ID = 0x0600,
    CLUSTER_BACNET_PROTOCOL_TUNNEL_CLUSTER_ID = 0x0601,
    CLUSTER_11073_PROTOCOL_TUNNEL_CLUSTER_ID = 0x0614,
    CLUSTER_ISO7816_PROTOCOL_TUNNEL_CLUSTER_ID = 0x0615,
    CLUSTER_PRICE_CLUSTER_ID = 0x0700,
    CLUSTER_DEMAND_RESPONSE_LOAD_CONTROL_CLUSTER_ID = 0x0701,
    CLUSTER_SIMPLE_METERING_CLUSTER_ID = 0x0702,
    CLUSTER_MESSAGING_CLUSTER_ID = 0x0703,
    CLUSTER_TUNNELING_CLUSTER_ID = 0x0704,
    CLUSTER_PREPAYMENT_CLUSTER_ID = 0x0705,
    CLUSTER_ENERGY_MANAGEMENT_CLUSTER_ID = 0x0706,
    CLUSTER_CALENDAR_CLUSTER_ID = 0x0707,
    CLUSTER_DEVICE_MANAGEMENT_CLUSTER_ID = 0x0708,
    CLUSTER_EVENTS_CLUSTER_ID = 0x0709,
    CLUSTER_MDU_PAIRING_CLUSTER_ID = 0x070A,
    CLUSTER_SUB_GHZ_CLUSTER_ID = 0x070B,
    CLUSTER_KEY_ESTABLISHMENT_CLUSTER_ID = 0x0800,
    CLUSTER_INFORMATION_CLUSTER_ID = 0x0900,
    CLUSTER_DATA_SHARING_CLUSTER_ID = 0x0901,
    CLUSTER_GAMING_CLUSTER_ID = 0x0902,
    CLUSTER_DATA_RATE_CONTROL_CLUSTER_ID = 0x0903,
    CLUSTER_VOICE_OVER_ZIGBEE_CLUSTER_ID = 0x0904,
    CLUSTER_CHATTING_CLUSTER_ID = 0x0905,
    CLUSTER_PAYMENT_CLUSTER_ID = 0x0A01,
    CLUSTER_BILLING_CLUSTER_ID = 0x0A02,
    CLUSTER_APPLIANCE_IDENTIFICATION_CLUSTER_ID = 0x0B00,
    CLUSTER_METER_IDENTIFICATION_CLUSTER_ID = 0x0B01,
    CLUSTER_APPLIANCE_EVENTS_AND_ALERT_CLUSTER_ID = 0x0B02,
    CLUSTER_APPLIANCE_STATISTICS_CLUSTER_ID = 0x0B03,
    CLUSTER_ELECTRICAL_MEASUREMENT_CLUSTER_ID = 0x0B04,
    CLUSTER_DIAGNOSTICS_CLUSTER_ID = 0x0B05,
    CLUSTER_ZLL_COMMISSIONING_CLUSTER_ID = 0x1000,
    CLUSTER_SAMPLE_MFG_SPECIFIC_CLUSTER_ID = 0xFC00,
    CLUSTER_OTA_CONFIGURATION_CLUSTER_ID = 0xFC01,
    CLUSTER_MFGLIB_CLUSTER_ID = 0xFC02,
    CLUSTER_SL_WWAH_CLUSTER_ID = 0xFC57,

    CLUSTER_PRIVATE_TUYA_CLUSTER_ID = 0xEF00,
}CLUSTER_ID_T;

// ZigBee device IDs
typedef enum {
    ZG_DEVICE_ID_ON_OFF_SWITCH = 0x0000,
    ZG_DEVICE_ID_LEVEL_CONTROL_SWITCH = 0x0001,
    ZG_DEVICE_ID_ON_OFF_OUTPUT = 0x0002,
    ZG_DEVICE_ID_LEVEL_CONTROL_OUTPUT = 0x0003,
    ZG_DEVICE_ID_SCENE_SELECTOR = 0x0004,
    ZG_DEVICE_ID_CONFIG_TOOL = 0x0005,
    ZG_DEVICE_ID_REMOTE_CONTROL = 0x0006,
    ZG_DEVICE_ID_COMBINED_INTERFACE = 0x0007,
    ZG_DEVICE_ID_RANGE_EXTENDER = 0x0008,
    ZG_DEVICE_ID_MAINS_POWER_OUTLET = 0x0009,
    ZG_DEVICE_ID_DOOR_LOCK = 0x000a,
    ZG_DEVICE_ID_DOOR_LOCK_CONTROLLER = 0x000b,
    ZG_DEVICE_ID_SIMPLE_SENSOR = 0x000c,
    ZG_DEVICE_ID_CONSUMPTION_AWARENESS_DEVICE = 0x000d,

    ZG_DEVICE_ID_HOME_GATEWAY = 0x0050,
    ZG_DEVICE_ID_SMART_PLUG = 0x0051,
    ZG_DEVICE_ID_WHITE_GOODS = 0x0052,
    ZG_DEVICE_ID_METER_INTERFACE = 0x0053,

    ZG_DEVICE_ID_ON_OFF_LIGHT = 0x0100,
    ZG_DEVICE_ID_DIMMABLE_LIGHT = 0x0101,
    ZG_DEVICE_ID_COLOR_DIMMABLE_LIGHT = 0x0102,
    ZG_DEVICE_ID_ON_OFF_LIGHT_SWITCH = 0x0103,
    ZG_DEVICE_ID_DIMMER_SWITCH = 0x0104,
    ZG_DEVICE_ID_COLOR_DIMMER_SWITCH = 0x0105,
    ZG_DEVICE_ID_LIGHT_SENSOR = 0x0106,
    ZG_DEVICE_ID_OCCUPANCY_SENSOR = 0x0107,

    ZG_DEVICE_ID_SHADE = 0x0200,
    ZG_DEVICE_ID_SHADE_CONTROLLER = 0x0201,
    ZG_DEVICE_ID_WINDOW_COVERING_DEVICE = 0x0202,
    ZG_DEVICE_ID_WINDOW_COVERING_CONTROLLER = 0x0203,

    ZG_DEVICE_ID_HEATING_COOLING_UNIT = 0x0300,
    ZG_DEVICE_ID_THERMOSTAT = 0x0301,
    ZG_DEVICE_ID_TEMPERATURE_SENSOR = 0x0302,
    ZG_DEVICE_ID_PUMP = 0x0303,
    ZG_DEVICE_ID_PUMP_CONTROLLER = 0x0304,
    ZG_DEVICE_ID_PRESSURE_SENSOR = 0x0305,
    ZG_DEVICE_ID_FLOW_SENSOR = 0x0306,
    ZG_DEVICE_ID_MINI_SPLIT_AC = 0x0307,

    ZG_DEVICE_ID_IAS_CIE = 0x0400,
    ZG_DEVICE_ID_IAS_ANCILLARY_CONTROL = 0x0401,
    ZG_DEVICE_ID_IAS_ZONE = 0x0402,
    ZG_DEVICE_ID_IAS_WARNING = 0x0403,
}DEV_ID_T;
    
// ZCL attribute types
typedef enum {
    ATTR_NO_DATA_ATTRIBUTE_TYPE                        = 0x00, // No data
    ATTR_DATA8_ATTRIBUTE_TYPE                          = 0x08, // 8-bit data
    ATTR_DATA16_ATTRIBUTE_TYPE                         = 0x09, // 16-bit data
    ATTR_DATA24_ATTRIBUTE_TYPE                         = 0x0A, // 24-bit data
    ATTR_DATA32_ATTRIBUTE_TYPE                         = 0x0B, // 32-bit data
    ATTR_DATA40_ATTRIBUTE_TYPE                         = 0x0C, // 40-bit data
    ATTR_DATA48_ATTRIBUTE_TYPE                         = 0x0D, // 48-bit data
    ATTR_DATA56_ATTRIBUTE_TYPE                         = 0x0E, // 56-bit data
    ATTR_DATA64_ATTRIBUTE_TYPE                         = 0x0F, // 64-bit data
    ATTR_BOOLEAN_ATTRIBUTE_TYPE                        = 0x10, // Boolean
    ATTR_BITMAP8_ATTRIBUTE_TYPE                        = 0x18, // 8-bit bitmap
    ATTR_BITMAP16_ATTRIBUTE_TYPE                       = 0x19, // 16-bit bitmap
    ATTR_BITMAP24_ATTRIBUTE_TYPE                       = 0x1A, // 24-bit bitmap
    ATTR_BITMAP32_ATTRIBUTE_TYPE                       = 0x1B, // 32-bit bitmap
    ATTR_BITMAP40_ATTRIBUTE_TYPE                       = 0x1C, // 40-bit bitmap
    ATTR_BITMAP48_ATTRIBUTE_TYPE                       = 0x1D, // 48-bit bitmap
    ATTR_BITMAP56_ATTRIBUTE_TYPE                       = 0x1E, // 56-bit bitmap
    ATTR_BITMAP64_ATTRIBUTE_TYPE                       = 0x1F, // 64-bit bitmap
    ATTR_INT8U_ATTRIBUTE_TYPE                          = 0x20, // Unsigned 8-bit integer
    ATTR_INT16U_ATTRIBUTE_TYPE                         = 0x21, // Unsigned 16-bit integer
    ATTR_INT24U_ATTRIBUTE_TYPE                         = 0x22, // Unsigned 24-bit integer
    ATTR_INT32U_ATTRIBUTE_TYPE                         = 0x23, // Unsigned 32-bit integer
    ATTR_INT40U_ATTRIBUTE_TYPE                         = 0x24, // Unsigned 40-bit integer
    ATTR_INT48U_ATTRIBUTE_TYPE                         = 0x25, // Unsigned 48-bit integer
    ATTR_INT56U_ATTRIBUTE_TYPE                         = 0x26, // Unsigned 56-bit integer
    ATTR_INT64U_ATTRIBUTE_TYPE                         = 0x27, // Unsigned 64-bit integer
    ATTR_INT8S_ATTRIBUTE_TYPE                          = 0x28, // Signed 8-bit integer
    ATTR_INT16S_ATTRIBUTE_TYPE                         = 0x29, // Signed 16-bit integer
    ATTR_INT24S_ATTRIBUTE_TYPE                         = 0x2A, // Signed 24-bit integer
    ATTR_INT32S_ATTRIBUTE_TYPE                         = 0x2B, // Signed 32-bit integer
    ATTR_INT40S_ATTRIBUTE_TYPE                         = 0x2C, // Signed 40-bit integer
    ATTR_INT48S_ATTRIBUTE_TYPE                         = 0x2D, // Signed 48-bit integer
    ATTR_INT56S_ATTRIBUTE_TYPE                         = 0x2E, // Signed 56-bit integer
    ATTR_INT64S_ATTRIBUTE_TYPE                         = 0x2F, // Signed 64-bit integer
    ATTR_ENUM8_ATTRIBUTE_TYPE                          = 0x30, // 8-bit enumeration
    ATTR_ENUM16_ATTRIBUTE_TYPE                         = 0x31, // 16-bit enumeration
    ATTR_FLOAT_SEMI_ATTRIBUTE_TYPE                     = 0x38, // Semi-precision
    ATTR_FLOAT_SINGLE_ATTRIBUTE_TYPE                   = 0x39, // Single precision
    ATTR_FLOAT_DOUBLE_ATTRIBUTE_TYPE                   = 0x3A, // Double precision
    ATTR_OCTET_STRING_ATTRIBUTE_TYPE                   = 0x41, // Octet string
    ATTR_CHAR_STRING_ATTRIBUTE_TYPE                    = 0x42, // Character string
    ATTR_LONG_OCTET_STRING_ATTRIBUTE_TYPE              = 0x43, // Long octet string
    ATTR_LONG_CHAR_STRING_ATTRIBUTE_TYPE               = 0x44, // Long character string
    ATTR_ARRAY_ATTRIBUTE_TYPE                          = 0x48, // Array
    ATTR_STRUCT_ATTRIBUTE_TYPE                         = 0x4C, // Structure
    ATTR_SET_ATTRIBUTE_TYPE                            = 0x50, // Set
    ATTR_BAG_ATTRIBUTE_TYPE                            = 0x51, // Bag
    ATTR_TIME_OF_DAY_ATTRIBUTE_TYPE                    = 0xE0, // Time of day
    ATTR_DATE_ATTRIBUTE_TYPE                           = 0xE1, // Date
    ATTR_UTC_TIME_ATTRIBUTE_TYPE                       = 0xE2, // UTC Time
    ATTR_CLUSTER_ID_ATTRIBUTE_TYPE                     = 0xE8, // Cluster ID
    ATTR_ATTRIBUTE_ID_ATTRIBUTE_TYPE                   = 0xE9, // Attribute ID
    ATTR_BACNET_OID_ATTRIBUTE_TYPE                     = 0xEA, // BACnet OID
    ATTR_IEEE_ADDRESS_ATTRIBUTE_TYPE                   = 0xF0, // IEEE address
    ATTR_SECURITY_KEY_ATTRIBUTE_TYPE                   = 0xF1, // 128-bit security key
    ATTR_UNKNOWN_ATTRIBUTE_TYPE                        = 0xFF // Unknown
} ATTR_TYPE_T;

//attr_t->attr_mask
// Attribute masks modify how attributes are used by the framework
// Attribute that has this mask is NOT read-only
#define ATTR_MASK_WRITABLE (0x01)
// Attribute that has this mask is saved to a token
#define ATTR_MASK_TOKENIZE (0x02)
// Attribute that has this mask has a min/max values
#define ATTR_MASK_MIN_MAX (0x04)
// Manufacturer specific attribute
#define ATTR_MASK_MANUFACTURER_SPECIFIC (0x08)
// Attribute deferred to external storage
#define ATTR_MASK_EXTERNAL_STORAGE (0x10)
// Attribute is singleton
#define ATTR_MASK_SINGLETON (0x20)
// Attribute is a client attribute
#define ATTR_MASK_CLIENT (0x40)

typedef enum {
    NET_POWER_ON_LEAVE,     //power on and device is not joined network
    NET_POWER_ON_ONLINE,    //power on and device is already joined network
    NET_JOIN_START,         //start joining network
    NET_JOIN_TIMEOUT,       //network joining timeout
    NET_JOIN_OK,            //network joined success
    NET_LOST,               //network lost
    NET_REJOIN_OK,          //network rejoin ok
    NET_REMOTE_LEAVE,       //remove device by remote device
    NET_LOCAL_LEAVE,        //remove device by local
}NET_EVT_T;

typedef struct {
    bool_t auto_join_power_on_flag;
    bool_t auto_join_remote_leave_flag;
    uint32_t join_timeout;
}join_config_t;

typedef struct {
    uint16_t attr_id;
    ATTR_TYPE_T type;
    uint8_t attr_value_size;
    uint8_t attr_mask;
    void *default_value;
}attr_t;

typedef struct {
    CLUSTER_ID_T cluster_id;
    attr_t *attr_list;
    uint8_t  attr_sums;
}cluster_t;

// Simple Description Format Structure
typedef struct {
  uint8_t  ep;
  PROFILE_ID_T profile_id;
  DEV_ID_T     dev_id;
  uint8_t         server_cluster_sums;
  cluster_t *server_cluster_list; //input cluster
  uint8_t         client_cluster_sums;
  cluster_t *client_cluster_list; //output cluster
} dev_description_t;

typedef enum {
    SEND_ST_OK,
    SEND_ST_ERR,
    SEND_ST_MEMORY_ERR,
    SEND_ST_QUEUE_FULL_ERR,
}SEND_ST_T;

typedef enum {
    MSG_SRC_GW_UNICAST,
    MSG_SRC_GW_BROADCAST,
    MSG_SRC_DEV_UNICAST,
    MSG_SRC_DEV_BROADCAST
}MSG_SRC_T;

typedef struct {
    uint16_t attr;
    uint8_t  cmd;
    uint8_t value_len;
    uint8_t *value;
}attr_value_t;

typedef struct {
    uint8_t attr_value_sums;
    attr_value_t *attr_value;
}attr_data_t;

typedef struct {
    uint8_t commandId;
    uint8_t len;
    void *data;
}bare_data_t;

typedef struct {
    MSG_SRC_T msg_src;
    CLUSTER_ID_T cluster;
    uint8_t zcl_id;
    uint8_t endpoint;
    union {
        attr_data_t attr_data;
        bare_data_t bare_data;
    }data;
}dev_msg_t;

typedef enum {
    DEV_IO_OFF = 0,
    DEV_IO_ON,
} DEV_IO_ST_T;

typedef enum {
    KEY_ST_UP = 0,
    KEY_ST_PUSH,
} key_st_t;
 
typedef enum {
    RELAY_ST_OFF = 0,
    RELAY_ST_ON
}RELAY_ST_T;

typedef enum {
    MF_TEST_LED_ON_ALL,
    MF_TEST_LED_OFF_ALL,
    MF_TEST_LED_BLINK_ALL,
    MF_TEST_RELAY_ON_ALL,
    MF_TEST_RELAY_OFF_ALL,
    MF_TEST_RELAY_BLINK_ALL,
    MF_TEST_BUTTON,
    MF_TEST_GET_ELEC_INFO,
    MF_TEST_ADJUST_ELEC_INFO,
    MF_TRANSFER, //transfer rare test data
}MF_TEST_CMD_T;

typedef enum {
    DEV_EVT_1  = 25,
    DEV_EVT_2,
    DEV_EVT_3,
    DEV_EVT_4,
    DEV_EVT_5,
    DEV_EVT_6,
    DEV_EVT_7,
    DEV_EVT_8,
    DEV_EVT_9,
    DEV_EVT_10,
    DEV_EVT_11,
    DEV_EVT_12,
    DEV_EVT_13,
    DEV_EVT_14,
    DEV_EVT_15,
    DEV_EVT_16,
}DEV_EVT_T;
    
typedef enum {
    PORT_A = 0x00,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E,
    PORT_F,
    PORT_H,
    PORT_I,
    PORT_J,
    PORT_K
}GPIO_PORT_T;

typedef enum {
    PIN_0 = 0x00,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
    PIN_8,
    PIN_9,
    PIN_10,
    PIN_11,
    PIN_12,
    PIN_13,
    PIN_14,
    PIN_15,
}GPIO_PIN_T;

typedef enum {
    LOC_0 = 0,
    LOC_1,
    LOC_2,
    LOC_3,
    LOC_4,
    LOC_5,
    LOC_6,
    LOC_7,
    LOC_8,
    LOC_9,
    LOC_10,
    LOC_11,
    LOC_12,
    LOC_13,
    LOC_14,
    LOC_15,
    LOC_16,
    LOC_17,
    LOC_18,
    LOC_19,
    LOC_20,
    LOC_21,
    LOC_22,
    LOC_23,
    LOC_24,
    LOC_25,
    LOC_26,
    LOC_27,
    LOC_28,
    LOC_29,
    LOC_30,
    LOC_31,
}GPIO_LOC_T;

//GPIO_Mode_TypeDef
typedef enum {
    GPIO_MODE_INPUT_HIGH_IMPEDANCE = 0,
    GPIO_MODE_INPUT_PULL,
    GPIO_MODE_OUTPUT_PP,
    GPIO_MODE_OUTPUT_OD,
    GPIO_MODE_OUTPUT_OD_PULL_UP,
    GPIO_MODE_OUTPUT_OD_PULL_DOWN,
}GPIO_MODE_T;

typedef enum {
    GPIO_DOUT_LOW = 0,
    GPIO_DOUT_HIGH = 1,
}GPIO_DOUT_T;

typedef enum {
    GPIO_LEVEL_LOW = 0,
    GPIO_LEVEL_HIGH,
    GPIO_LEVEL_ALL
}GPIO_LEVEL_T;

typedef struct {
    GPIO_PORT_T port;
    GPIO_PIN_T pin;
    GPIO_MODE_T mode;
    GPIO_DOUT_T out;
    GPIO_LEVEL_T drive_flag; //the effectively level (0 or 1)
} gpio_config_t;

typedef enum {
    UART_ID_UART0 = 0,
    UART_ID_UART1
}UART_ID_T;

//USART_Parity_TypeDef
typedef enum {
    USART_PARITY_NONE = 0,    /**< No parity. */
    USART_PARITY_EVEN,      /**< Even parity. */
    USART_PARITY_ODD,      /**< Odd parity. */
} USART_PARITY_T;

//USART_Stopbits_TypeDef
typedef enum {
    USART_STOPBITS_HALF = 0,        /**< 0.5 stop bits. */
    USART_STOPBITS_ONE,         /**< 1 stop bits. */
    USART_STOPBITS_ONEANDAHALF, /**< 1.5 stop bits. */
    USART_STOPBITS_TWO          /**< 2 stop bits. */
} USART_STOPBITS_T;

//USART_DATABITS_T
typedef enum {
    USART_DATABITS_8BIT = 0,        /**< 8 bits databits. */
    USART_DATABITS_9BIT,         /**< 9 bits databits. */
} USART_DATABITS_T;

typedef enum {
    UART_PIN_TYPE_DEFAULT = 0,//default uart is PA0,PA1
    UART_PIN_TYPE_CONFIG //user config uart port and pin 
}UART_PIN_TYPE_T;

typedef struct {
    GPIO_PORT_T port;
    GPIO_PIN_T pin;
}GPIO_PORT_PIN_T;

typedef void(*uart_callback)(uint8_t *data, uint16_t len);

typedef struct {
    UART_ID_T uart_id; 
    UART_PIN_TYPE_T pin_type; 
    GPIO_PORT_PIN_T tx;
    GPIO_PORT_PIN_T rx;
    GPIO_LOC_T tx_loc;
    GPIO_LOC_T rx_loc;
    uint32_t baud_rate;
    USART_PARITY_T parity;
    USART_STOPBITS_T stop_bits;
    USART_DATABITS_T data_bits;
    uart_callback func;
}user_uart_config_t;

#define USART_CONFIG_DEFAULT {\
    UART_ID_UART0,\
    UART_PIN_TYPE_CONFIG,\
    {PORT_A, PIN_0},\
    {PORT_A, PIN_1},\
    LOC_0,\
    LOC_0,\
    115200,\
    USART_PARITY_NONE,\
    USART_STOPBITS_ONE,\
    USART_DATABITS_8BIT,\
    NULL\
}

typedef enum
{
    APP_VERSION = 0,
    BATTERY_VOLTAGE,
}HEARTBEAT_TYPE_E;

typedef enum {
    ZCL_CMD_RET_SUCCESS,
    ZCL_CMD_RET_FAILED
}ZCL_CMD_RET_T;

typedef enum {
    ATTR_CMD_RET_SUCCESS,
    ATTR_CMD_RET_FAILED
}ATTR_CMD_RET_T;
    
typedef enum {
    QOS_0, //permit loss packages
    QOS_1, //not permit loss packages
}SEND_QOS_T;

typedef enum {
    SEND_MODE_GW,
    SEND_MODE_GROUP,
    SEND_MODE_BINDING,
}SEND_MODE_T;

typedef struct {
    uint16_t group_id;
    uint8_t src_ep;
    uint8_t dest_ep;
    CLUSTER_ID_T cluster_id;
}group_addr_t;

typedef struct {
    uint8_t src_ep;
    CLUSTER_ID_T cluster_id;
}bind_addr_t;

typedef struct {
    uint8_t src_ep;
    CLUSTER_ID_T cluster_id;
}gw_addr_t;

typedef struct {
    SEND_MODE_T mode;
    union {
        group_addr_t group;
        bind_addr_t  bind;
        gw_addr_t    gw;
    }type;
} af_addr_t;

typedef struct {
    uint16_t attr_id;
    ATTR_TYPE_T type;
    uint8_t value_size;
    uint8_t value[8];
}attr_key_value_t;

typedef struct {
    uint8_t attr_sum;
    attr_key_value_t attr[8];
}send_zg_t;

typedef struct {
    uint8_t len;
    uint8_t data[64];
}send_private_t;


typedef enum {
    /*ZCL profile wide command such as read, write, 
    report or global cluster such as basic, identify*/
    ZCL_COMMAND_GLOBAL_CMD = 0,

    /*zcl cluster specific command*/ 
    ZCL_COMMAND_CLUSTER_SPEC_CMD
}ZCL_COMMAND_TYPE_T;

typedef enum {
    ZCL_DATA_DIRECTION_CLIENT_TO_SERVER = 0,
    ZCL_DATA_DIRECTION_SERVER_TO_CLIENT
}ZCL_DATA_DIRECTION_T;

typedef struct {
    /*real send time delay£ºdelay_time+rand()%random_time*/
    uint16_t delay_time; //send delay time with ms
    uint16_t random_time;//send random times with ms
    
    uint8_t zcl_id; //applicaiton sequence number
    uint8_t command_id; //zcl command id, the detail in commmand-id.h
    ZCL_COMMAND_TYPE_T commmand_type;
    ZCL_DATA_DIRECTION_T direction;
    SEND_QOS_T qos;
    af_addr_t addr;
    union {
        send_zg_t zg;
        send_private_t private;
    }data;
}dev_send_data_t;

typedef struct {
    SEND_ST_T st;
    dev_send_data_t send_data;
}zck_ack_t;

typedef void (*send_result_func_t)(SEND_ST_T, dev_send_data_t *);

#define SCENES_MAX_DATA_LEN   128

typedef enum {
    SCENE_DATA_TYPE_SERVER_DEFINE = 0,
    SCENE_DATA_TYPE_USER_DEFINE = 1,
    SCENE_DATA_TYPE_ZIGBEE_DEFINE
}SCENE_DATA_TYPE_T;

typedef struct {
    SCENE_DATA_TYPE_T type;
    uint8_t data_len;
    uint8_t data[SCENES_MAX_DATA_LEN];
}scene_save_data_t;

typedef enum {
    LETTER_TYPE_UPPER = 0,
    LETTER_TYPE_LOWER
}LETTER_TYPE_T;

typedef enum {
    HARDWARE_TIMER_AUTO_RELOAD_ENABLE = 0,
    HARDWARE_TIMER_AUTO_RELOAD_DISABLE
}TIMER_RELOAD_FLAG_T;

typedef enum {
    V_TIMER0 = 0,
    V_TIMER1,
    V_TIMER2,
    V_TIMER3,
    V_TIMER_ERR = 0xFF
}TIMER_ID_T;

typedef void (*hardware_timer_func_t)(TIMER_ID_T);

typedef struct {
    uint32_t temp_time;
    uint32_t delay_time;
    hardware_timer_func_t func;
    TIMER_RELOAD_FLAG_T auto_reload_flag;
    uint8_t valid_flag;
}hardware_timer_t;

typedef enum {
    QUEUE_RET_OK = 0,
    QUEUE_RET_ERR,
}QUEUE_RET_T;

typedef void * dev_queue_t;

typedef void (*serialMfgRxCallback)(uint8_t *packet, uint8_t lqi, int8_t rssi);
typedef struct
{
    uint8_t channel;
    uint8_t data_len;
    uint8_t* data;
    serialMfgRxCallback received_callback;
}serial_protocol_rf_test_t;

#ifdef APP_DEBUG
#define app_print(...) uart_printf(UART_ID_UART0, __VA_ARGS__)
#else
#define app_print(...)
#endif

#define get_array_len(x) (sizeof(x)/sizeof(x[0]))

//uart api
/**
 * @description: user uart init function
 * @param {config} user uart configuration information
 * @return: none
 */
extern void user_uart_init(user_uart_config_t *config);

/**
 * @description: user uart data send funciton
 * @param {uart_id} UART_ID_UART0 or UART_ID_UART1
 * @param {data} send data
 * @param {data_len} send data length
 * @return: none
 */
extern void user_uart_send(UART_ID_T uart_id, uint8_t* data, uint16_t data_len);

/**
 * @description: user uart function disable function
 * @param {uart_id} UART_ID_UART0 or UART_ID_UART1
 * @return: none
 */
extern void user_uart_disable(UART_ID_T uart_id);

/**
 * @description: uart log print function
 * @param {uart_id} UART_ID_UART0 or UART_ID_UART1
 * @param {formatString} print data list
  * @return: none
 */
extern void uart_printf(UART_ID_T uart_id, const char *formatString, ...);

//soft timer api
typedef void (*timer_func_t)(uint8_t);

/**
 * @description: system event stop function
 * @param {evt} event id
 * @return: none
 */
extern void dev_timer_stop(uint8_t evt);

/**
 * @description: system event start with callback function
 * @param {evt} event id
 * @param {t} event run delay time(ms)
 * @param {func} event handler function
 * @return: none
 */
extern void dev_timer_start_with_callback(uint8_t evt, uint32_t t, timer_func_t func);

/**
 * @description: system event start with no callback function
 * @param {evt} event id
 * @param {t} event run delay time(ms)
 * @return: none
 */
extern void dev_timer_start(uint8_t evt, uint32_t t);

/**
 * @description: system event active flag get function
 * @param {evt} event id
 * @return: bool_t: true is active, false is inctive
 */
extern bool_t dev_timer_get_valid_flag(uint8_t evt);

//base tools api
/**
 * @description: hex to hexstr convert function
 * @param {type} upper or lower letter
 * @param {hex} input hex data
 * @param {hex_len} input hex data length
 * @param {hex_str} output covert hexstr result
 * @return: none
 */
extern void hex_to_hexstr(LETTER_TYPE_T type, uint8_t *hex, uint16_t hex_len, char *hex_str);

/**
 * @description: hexstr to hex convert function
 * @param {hex_str} input hexstr data
 * @param {hex} output covert hex result
 * @return: hex data length
 */
extern uint16_t hexstr_to_hex(char *hex_str, uint8_t *hex);

/**
 * @description: device firmware version get
 * @param {ver} the int version 
 * @return: convert result of string version
 */
extern char *get_dev_firmware_ver(uint8_t ver);

/**
 * @description: data reversal function
 * @param {in_data} reversal source data
 * @param {out_data} reversal dest data
 * @param {len} reversal data length
 * @return: none
 */
extern void data_reversal(uint8_t *in_data, uint8_t *out_data, uint16_t len);

//base info register
/**
 * @description: device basic information register function
 * @param {model_id} modle id attribute of basic cluster
 * @param {pid_prefix} manufacture name attribute(0-8bytes) of basic cluster
 * @param {pid} manufacture name attribute(9-16bytes) of basic cluster
 * @return: none
 */
extern void dev_register_base_info(char *model_id, char *pid_prefix, char *pid);

/**
 * @description: zigbee endpoint information register function
 * @param {ep_desc} endpoint information description, include profileid, 
 * deviceid, in and out clusters
 * @param {ep_sums} totals endpoints
  * @return: none
 */
extern void dev_register_zg_ep_infor(dev_description_t *ep_desc, uint8_t ep_sums);

/**
 * @description: zigbee device information register funciton
 * @param {config} device configuratin, inculde device type, join  mechanism ETC
 * @return: none
 */
extern void dev_register_zg_dev_config(zg_dev_config_t *config);

/**
 * @description: network join information configuration
 * @param {*cfg} network join struct
 * @return: none
 */
extern void dev_zg_join_config(join_config_t *cfg);

/**
 * @description: zigbee device start to join network
 * @param {join_timeout} join timeout ticks, uint is ms
 * @return: true or false
 */
extern bool_t dev_zigbee_join_start(uint32_t join_timeout);

//hardware timer api
/**
 * @description: hardware timer enable
 * @param {type} none
 * @return: none
 */
extern void hardware_timer_enable(void);

/**
 * @description: hardware timer disable
 * @param {type} none
 * @return: none
 */
extern void hardware_timer_disable(void);

/**
 * @description: hardware timer start with a us timedelay
 * @param {t} times with us
 * @param {flag} reload timer or not
 * @param {func} callback function
 * @return: TIMER_ID_T: time id
 */
extern TIMER_ID_T timer_hardware_start_100us(uint32_t t, TIMER_RELOAD_FLAG_T flag, hardware_timer_func_t func);

/**
 * @description: hardware timer stop
 * @param {id} time id
 * @return: none
 */
extern void timer_hardware_stop_100us(TIMER_ID_T id);

/**
 * @description: get the current systerm millisecond ticks
 * @param {type} none
 * @return: current millisecond ticks
 */
extern uint32_t dev_current_millisecond_ticks_get(void);

/**
 * @description: systerm reset function
 * @param in: none
 * @param out: none
 * @return: none
 */
extern void dev_sys_reset(void) ;

/**
 * @description: send data from mac layer immediately
 * @param in: data: data to be send
 * @param in: data_len: data_len to be send
 * @return: none
 */
extern void dev_sys_data_send_mac(serial_protocol_rf_test_t* rf_test);

//led api
#define DEV_LED_BLINK_FOREVER 0xFFFF

/**
 * @description: device output io event handler function
 * @param {evt} event id
 * @param {tick} event period ticks
 * @return: none
 */
extern void dev_led_output_handle(uint8_t evt, uint16_t tick);

/**
 * @description: device output(led) blink start funciton
 * @param {led_index} led id
 * @param {on_time} led on time
 * @param {off_time} led off time
 * @param {st} end state, end with on or off
 * @return: none 
 */
extern void dev_led_start_blink(uint8_t led_index, uint16_t on_time, uint16_t off_time, uint16_t blink_times, DEV_IO_ST_T st);

/**
 * @description: device output(led) blink stop function
 * @param {led_index} led id
 * @param {st} end state, end with on or off
 * @return: none
 */
extern void dev_led_stop_blink(uint8_t led_index, DEV_IO_ST_T st);

/**
 * @description: device led is blink or not
 * @param {led_index} led id
 * @return: 0 is not blink, 1 is blink
 */
extern uint8_t dev_led_is_blink(uint8_t led_index);
#define dev_io_op dev_led_stop_blink

//gpio op
/**
 * @description: read input gpio status 
 * @param {port} port
 * @param {pin} pin
 * @return: current status value
 */
extern uint8_t gpio_raw_input_read_status( GPIO_PORT_T port, GPIO_PIN_T pin);

/**
 * @description: read output gpio status
  * @param {port} port
 * @param {pin} pin
 * @return: current status value
 */
extern uint8_t gpio_raw_output_read_status(  GPIO_PORT_T port, GPIO_PIN_T pin);

/**
 * @description: write output gpio status
  * @param {port} port
 * @param {pin} pin
 * @return: none
 */
extern void gpio_raw_output_write_status(  GPIO_PORT_T port, GPIO_PIN_T pin, uint8_t value);

/**
 * @description: read input gpio status with index 
 * @param {i} index
 * @return: current status value
 */
extern uint8_t gpio_index_input_read_status(  uint8_t i);

/**
 * @description: write output gpio status with index 
 * @param {index} index
 * @param {value} value
 * @return: none
 */
extern void gpio_index_output_write_status(uint8_t index, uint8_t value);
//gpio input api
typedef void(*key_func_t)(uint32_t,key_st_t,uint32_t);
typedef void (*gpio_int_func_t)(GPIO_PORT_T, GPIO_PIN_T);

/**
 * @description: input gpio ISR handle function register
 * @param {key_func} ISR handle fuction
 * @return: none
 */
extern void dev_gpio_input_set_handle_func(key_func_t key_func);

/**
 * @description: input gpio ISR handle function get
 * @param {type} none
 * @return: ISR handle fuction
 */
extern key_func_t dev_gpio_input_get_handle_func(void);

/**
 * @description: gpio button initialize
 * @param {config} config information
 * @param {sum} numbers of button
 * @param {jitter_time} key jitter time
 * @param {key_func} key ISR handle callback
 * @return: none
 */
extern void gpio_button_init(gpio_config_t *config, uint8_t sum, uint32_t jitter_time, key_func_t key_func);

/**
 * @description: gpio output initialize
 * @param {config} config information
 * @param {sum} no=umbers of output gpio information
 * @return: none
 */
extern void gpio_output_init(gpio_config_t *config, uint8_t sum);

/**
 * @description: gpio interrupt functoin set
 * @param {config} config information
 * @param {func} interrupt callback
 * @return: none
 */
extern void gpio_int_register(gpio_config_t *config, gpio_int_func_t func);

//flash api
/**
 * @description: write data to flash
 * @param {data} data
 * @param {len} data length
 * @return: none
 */
extern void user_flash_data_write(uint8_t *data, uint8_t len);

/**
 * @description: read data from flash 
 * @param {data} data
 * @param {len} data length
 * @return: none
 */
extern uint8_t user_flash_data_read(uint8_t *data, uint8_t len);

/**
 * @description: network state get 
 * @param {type} none
 * @return: current network state
 */
extern NET_EVT_T nwk_state_get(void);

/**
 * @description: zigbee data send function
 * @param {send_data} data information need to be send
 * @param {fun} data send callback
 *  @param {send_timeout} data send timeout
 * @return: none
 */
extern void dev_zigbee_send_data(dev_send_data_t *send_data, send_result_func_t fun, uint32_t send_timeout);

/**
 * @description: device heartbeat type and duration set
 * @param {type} heart type, app version attribute or power percentage attribute 
 * @param {duration} heartbeat send duration
 * @return: none
 */
extern bool_t dev_heartbeat_set(HEARTBEAT_TYPE_E type, uint32_t duration);

/**
 * @description: device leave by user
 * @param {type} none
 * @return: none
 */
extern void dev_zigbee_leave_for_user(void);

/**
 * @description: device wakeup with a time; when timeout, it will be sleep
 * @param {t} wakeup time
 * @return: none
 */
extern void zg_wake_up(uint32_t t); //sleep after t ms

/**
 * @description: device sleep now
 * @param {type} none
 * @return: none
 */
extern void zg_sleep(void); //sleep

/**
 * @description: device rejoin now
 * @param {type} none
 * @return: none
 */
extern void zg_rejoin_manual(void);

/**
 * @description: zigbee attribute write function
 * @param {endpoint} endpoint of the attribute
 * @param {cluster} cluster of the attribute
 * @param {attr_id} attribute id
 * @param {data} attribute data to be write
 * @param {data_type} attribute datatype to be write
 * @return: write status
 */
extern ATTR_CMD_RET_T dev_zigbee_write_attribute(
    uint8_t endpoint,
    CLUSTER_ID_T cluster,
    uint16_t attr_id, //attribute-id.h
    void* data,
    ATTR_TYPE_T dataType
);

/**
 * @description: zigbee attribute read function
 * @param {endpoint} endpoint of the attribute
 * @param {cluster} cluster of the attribute
 * @param {attr_id} attribute id
 * @param {data} attribute data read result
 * @param {read_length} attribute datalength to be read
 * @return: write status
 */
extern ATTR_CMD_RET_T dev_zigbee_read_attribute(
    uint8_t endpoint,
    CLUSTER_ID_T cluster,
    uint16_t attr_id, //attribute-id.h
    void *data,
    uint8_t read_length
);

//base tools
/**
 * @description: battery information get funtion
 * @param {percent} percentage attribute of power configure cluster
 * @param {voltage} voltage attribute of power configure cluster
 * @return: none
 */
extern void get_battery_info(uint8_t *percent, float *voltage);

/**
 * @description: random a time with 0-t ms
 * @param {t} random maxinum ms
 * @return: none
 */
extern uint32_t random_ms(uint32_t t);

/**
 * @description: caculate the crc of the date
 * @param {data} data
 * @param {data_len} data length
 * @return: crc result
 */
extern uint16_t make_crc16(uint8_t *msg, uint16_t len);


//firmware security config
/**
 * @description: device firmware security mode enable
 * @param {data} data
 * @param {data_len} data length
 * @return: crc result
 */
extern void dev_security_mode_enable(void);

/**
 * @description:  scene cluster view valid callback, this function is used to check if the secne and group of the endpoint is exist 
 * @param {endpoint} endpoint
 * @param {groupId} group id
 * @param {sceneId} scene id
 * @return: true: exist, false: not exist;
 */
extern bool_t devViewSceneValidCallback(uint16_t endpoint, uint16_t groupId, uint8_t sceneId);

/**
 * @description: this function is used to remove the scene info from scene table of the endpoint
 * @param {endpoint} endpoint
 * @param {groupId} group id
 * @param {sceneId} scene id
 * @return: true or false
 */
extern bool_t devScenesClusterRemoveSceneCallback(uint16_t endpoint, uint16_t groupId, uint8_t sceneId);

/**
 * @description: this function is used to get the scene info from scene table of the endpoint
 * @param {endpoint} in   endpoint
 * @param {*groupId} out  group id
 * @param {*sceneId} out  scene id
 * @return: true or false
 */
extern bool_t devGetSceneCallback(uint16_t endpoint, uint16_t* groupId, uint8_t* sceneId);

/**
 * @description: remove all scenes in scene table of current endpoint; just used by scene control device; default is not remove
 * @param {type} none
 * @return: true: remove all, false: not remove;
 */
extern bool_t zigbee_sdk_scene_remove_before_add(void);

/**
 * @description: scene recall command send
 * @param {endpoint} src endpoint of recall scene
 * @param {groupId} group id
 * @param {sceneId} scene id
 * @return: none
 */
extern bool_t dev_scene_recall_send_command(uint16_t endpoint, uint16_t groupId, uint8_t sceneId);

#ifdef __cplusplus
}
#endif

#endif




