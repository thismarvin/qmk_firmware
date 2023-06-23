<<<<<<< HEAD
# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

SERIAL_DRIVER = usart
=======
# Build Options
#   change yes to no to disable
#
EEPROM_DRIVER = wear_leveling
WEAR_LEVELING_DRIVER = embedded_flash
SERIAL_DRIVER = usart

>>>>>>> 416af0171c (Remove CORTEX_ENABLE_WFI_IDLE from keyboards. (#21353))
