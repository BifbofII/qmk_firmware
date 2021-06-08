#include <string.h>

#include "hid_oled.h"

#ifdef HID_OLED

Hid_oled_content_t master_content = {};
Hid_oled_content_t slave_content  = { .type = CONTENT_HW_DEFAULT };

uint8_t change_flags = HID_OLED_MASTER_CHANGE | HID_OLED_SLAVE_CHANGE;

inline uint8_t hid_oled_change_flags(void) { return change_flags; }

inline uint8_t hid_oled_set_change_flags(uint8_t flags) { return change_flags |= flags; }

inline uint8_t hid_oled_reset_change_flags(uint8_t flags) { return change_flags &= ~flags; }

uint8_t hid_oled_get_master_content(Hid_oled_content_t *content) {
    memcpy(content, &master_content, sizeof(Hid_oled_content_t));
    return hid_oled_change_flags();
}

uint8_t hid_oled_get_slave_content(Hid_oled_content_t *content) {
    memcpy(content, &slave_content, sizeof(Hid_oled_content_t));
    return hid_oled_change_flags();
}

uint8_t hid_oled_update_master_content(Hid_oled_content_t *content) {
    memcpy(&master_content, content, sizeof(Hid_oled_content_t));
    return hid_oled_set_change_flags(HID_OLED_MASTER_CHANGE);
}

uint8_t hid_oled_update_slave_content(Hid_oled_content_t *content) {
    memcpy(&slave_content, content, sizeof(Hid_oled_content_t));
    return hid_oled_set_change_flags(HID_OLED_SLAVE_CHANGE);
}

void hid_oled_write_content(Hid_oled_content_t *content) {
    switch (content->type) {
        case CONTENT_STRING:
            for (int i = 0; i < OLED_LINE_NUM; i++) {
                oled_write_ln(content->string.line_cont[i], content->string.line_inv & (1 << i));
            }
            break;
        default:
            return;
    }
}

#endif
