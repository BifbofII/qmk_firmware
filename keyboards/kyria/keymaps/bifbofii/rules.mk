OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
ENCODER_ENABLE = no        # ENables the use of one or more encoders
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
UNICODEMAP_ENABLE = yes

SPLIT_TRANSPORT = custom

SRC += transport.c \
	serial.c \
	hid_oled.c
