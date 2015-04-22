/*
 * Copyright (C) 2015 I2SE GmbH
 */
#ifndef SYSFS_LED_H
#define SYSFS_LED_H

int led_off(char *led);
int led_blink_prepare(char *led, unsigned int duration);
int led_blink_kick(char *led);

#endif /* SYSFS_LED_H */
