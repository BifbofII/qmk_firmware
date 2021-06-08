#pragma once

// Configuration of HID OLED
#ifdef HID_OLED
#include "oled_driver.h"

#define OLED_LINE_LENGTH (OLED_DISPLAY_WIDTH / OLED_FONT_WIDTH)
#define OLED_LINE_NUM (OLED_DISPLAY_HEIGHT / OLED_FONT_HEIGHT)

#define HID_OLED_MASTER_CHANGE (1<<0)
#define HID_OLED_SLAVE_CHANGE (1<<1)

typedef enum _Hid_oled_content_type_t {
    CONTENT_HW_DEFAULT = 0,
    CONTENT_STRING,
} Hid_oled_content_type_t;

typedef struct _Hid_oled_string_content_t {
    char line_cont[OLED_LINE_NUM][OLED_LINE_LENGTH + 1];
    uint8_t line_inv;
} Hid_oled_string_content_t;

typedef struct _Hid_oled_content_t {
    Hid_oled_content_type_t type;
    union {
        Hid_oled_string_content_t string;
    };
} Hid_oled_content_t;

// Return a bitmap of change flags
uint8_t hid_oled_change_flags(void);
uint8_t hid_oled_set_change_flags(uint8_t flags);
uint8_t hid_oled_reset_change_flags(uint8_t flags);
// Returns the same as hid_oled_content_change_flags
uint8_t hid_oled_get_master_content(Hid_oled_content_t *content);
uint8_t hid_oled_get_slave_content(Hid_oled_content_t *content);
uint8_t hid_oled_update_master_content(Hid_oled_content_t *content);
uint8_t hid_oled_update_slave_content(Hid_oled_content_t *content);
// Output function
void hid_oled_write_content(Hid_oled_content_t *content);

#endif
