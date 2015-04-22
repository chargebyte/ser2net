/*
 * Copyright (C) 2015 I2SE GmbH
 */
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "sysfs-led.h"

#define SYSFS_LED_BASE "/sys/class/leds"

static int led_write(char *led, char *property, char *buf)
{
    char fn[255];

    snprintf(fn, sizeof(fn), "%s/%s/%s", SYSFS_LED_BASE, led, property);
    
    return file_store(fn, buf, strlen(buf));
}

int led_off(char *led)
{
    led_write(led, "trigger", "none");
    led_write(led, "brightness", "0");
    return 0;
}

int led_blink_prepare(char *led, unsigned int duration)
{
    char buffer[10];

    snprintf(buffer, sizeof(buffer), "%u", duration);
    led_write(led, "trigger", "transient");
    msleep(10);
    led_write(led, "state", "1");
    led_write(led, "duration", buffer);
    return 0;
}

int led_blink_kick(char *led)
{
    return led_write(led, "activate", "1");
}
