/*
 * SPDX-FileCopyrightText: 2023-2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
/**
 * @file  esp_panel_drivers_conf.h
 * @brief Configuration file for ESP Panel Drivers
 *
 * This file contains all the configurations needed for ESP Panel Drivers.
 * Users can modify these configurations according to their requirements.
 */

#pragma once

// *INDENT-OFF*

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////// Bus Configurations //////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Bus driver availability
 *
 * Enable or disable bus drivers used in the factory class. Disable to reduce code size.
 * Set to `1` to enable, `0` to disable.
 */
#define ESP_PANEL_DRIVERS_BUS_USE_ALL                   (1)
#if !ESP_PANEL_DRIVERS_BUS_USE_ALL
    #define ESP_PANEL_DRIVERS_BUS_USE_SPI               (0)
    #define ESP_PANEL_DRIVERS_BUS_USE_QSPI              (0)
    #define ESP_PANEL_DRIVERS_BUS_USE_RGB               (0)
    #define ESP_PANEL_DRIVERS_BUS_USE_I2C               (0)
    #define ESP_PANEL_DRIVERS_BUS_USE_MIPI_DSI          (0)
#endif // ESP_PANEL_DRIVERS_BUS_USE_ALL

/**
 * @brief Controls compilation of unused bus drivers
 *
 * Enable or disable compilation of unused bus drivers.
 * When set to `0`, code for unused bus drivers will be excluded to speed up compilation. At this time,
 * users should ensure that the bus driver is not used.
 *
 * Example with SPI:
 * (CONF1 = ESP_PANEL_DRIVERS_BUS_USE_SPI, CONF2 = ESP_PANEL_DRIVERS_BUS_COMPILE_UNUSED_DRIVERS)
 *
 * | CONF1 | CONF2 | Driver Available ( = CONF1 ^ CONF2) | Factory Support ( = CONF1) |
 * |-------|-------|-------------------------------------|----------------------------|
 * |   0   |   0   |                 No                  |              No            |
 * |   1   |   0   |                 Yes                 |              Yes           |
 * |   0   |   1   |                 Yes                 |              No            |
 * |   1   |   1   |                 Yes                 |              Yes           |
 */
#define ESP_PANEL_DRIVERS_BUS_COMPILE_UNUSED_DRIVERS    (1)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// LCD Configurations ///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief LCD driver availability
 *
 * Enable or disable LCD drivers used in the factory class. Disable to reduce code size.
 * Set to `1` to enable, `0` to disable.
 */
#define ESP_PANEL_DRIVERS_LCD_USE_ALL                   (0)
#if !ESP_PANEL_DRIVERS_LCD_USE_ALL
    #define ESP_PANEL_DRIVERS_LCD_USE_ST7262            (1)
#endif // ESP_PANEL_DRIVERS_LCD_USE_ALL

/**
 * @brief Controls compilation of unused LCD drivers
 *
 * Enable or disable compilation of unused LCD drivers.
 * When set to `0`, code for unused LCD drivers will be excluded to speed up compilation. At this time,
 * users should ensure that the LCD driver is not used.
 *
 * Example with ILI9341:
 * (CONF1 = ESP_PANEL_DRIVERS_LCD_USE_ILI9341, CONF2 = ESP_PANEL_DRIVERS_LCD_COMPILE_UNUSED_DRIVERS)
 *
 * | CONF1 | CONF2 | Driver Available ( = CONF1 ^ CONF2) | Factory Support ( = CONF1) |
 * |-------|-------|-------------------------------------|----------------------------|
 * |   0   |   0   |                 No                  |              No            |
 * |   1   |   0   |                 Yes                 |              Yes           |
 * |   0   |   1   |                 Yes                 |              No            |
 * |   1   |   1   |                 Yes                 |              Yes           |
 */
#define ESP_PANEL_DRIVERS_LCD_COMPILE_UNUSED_DRIVERS    (0)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////// Touch Configurations /////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Touch panel configuration parameters
 */
#define ESP_PANEL_DRIVERS_TOUCH_MAX_POINTS              (10)    // Maximum number of touch points supported
#define ESP_PANEL_DRIVERS_TOUCH_MAX_BUTTONS             (5)     // Maximum number of touch buttons supported

/**
 * @brief Touch driver availability
 *
 * Enable or disable touch drivers used in the factory class. Disable to reduce code size.
 * Set to `1` to enable, `0` to disable.
 */
#define ESP_PANEL_DRIVERS_TOUCH_USE_ALL                 (0)
#if !ESP_PANEL_DRIVERS_TOUCH_USE_ALL
    #define ESP_PANEL_DRIVERS_TOUCH_USE_GT911           (1)
#endif // ESP_PANEL_DRIVERS_TOUCH_USE_ALL

/**
 * @brief Controls compilation of unused touch drivers
 *
 * Enable or disable compilation of unused touch drivers.
 * When set to `0`, code for unused touch drivers will be excluded to speed up compilation. At this time,
 * users should ensure that the touch driver is not used.
 *
 * Example with GT911:
 * (CONF1 = ESP_PANEL_DRIVERS_TOUCH_USE_GT911, CONF2 = ESP_PANEL_DRIVERS_TOUCH_COMPILE_UNUSED_DRIVERS)
 *
 * | CONF1 | CONF2 | Driver Available ( = CONF1 ^ CONF2) | Factory Support ( = CONF1) |
 * |-------|-------|-------------------------------------|----------------------------|
 * |   0   |   0   |                 No                  |              No            |
 * |   1   |   0   |                 Yes                 |              Yes           |
 * |   0   |   1   |                 Yes                 |              No            |
 * |   1   |   1   |                 Yes                 |              Yes           |
 */
#define ESP_PANEL_DRIVERS_TOUCH_COMPILE_UNUSED_DRIVERS          (0)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// IO Expander Configurations //////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief IO Expander driver availability
 *
 * Enable or disable IO Expander drivers used in the factory class. Disable to reduce code size.
 * Set to `1` to enable, `0` to disable.
 */
#define ESP_PANEL_DRIVERS_EXPANDER_USE_ALL                      (0)
#if !ESP_PANEL_DRIVERS_EXPANDER_USE_ALL
    #define ESP_PANEL_DRIVERS_EXPANDER_USE_CH422G               (1)
    #define ESP_PANEL_DRIVERS_EXPANDER_USE_HT8574               (0)
    #define ESP_PANEL_DRIVERS_EXPANDER_USE_TCA95XX_8BIT         (0)
    #define ESP_PANEL_DRIVERS_EXPANDER_USE_TCA95XX_16BIT        (0)
#endif // ESP_PANEL_DRIVERS_EXPANDER_USE_ALL

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// Backlight Configurations ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Backlight driver availability
 *
 * Enable or disable backlight drivers used in the factory class. Disable to reduce code size.
 * Set to `1` to enable, `0` to disable.
 */
#define ESP_PANEL_DRIVERS_BACKLIGHT_USE_ALL                     (1)
#if !ESP_PANEL_DRIVERS_BACKLIGHT_USE_ALL
    #define ESP_PANEL_DRIVERS_BACKLIGHT_USE_SWITCH_GPIO         (0)
    #define ESP_PANEL_DRIVERS_BACKLIGHT_USE_SWITCH_EXPANDER     (0)
    #define ESP_PANEL_DRIVERS_BACKLIGHT_USE_PWM_LEDC            (0)
    #define ESP_PANEL_DRIVERS_BACKLIGHT_USE_CUSTOM              (0)
#endif // ESP_PANEL_DRIVERS_BACKLIGHT_USE_ALL

/**
 * @brief Controls compilation of unused backlight drivers
 *
 * Enable or disable compilation of unused backlight drivers.
 * When set to `0`, code for unused backlight drivers will be excluded to speed up compilation. At this time,
 * users should ensure that the backlight driver is not used.
 *
 * Example with PWM_LEDC:
 * (CONF1 = ESP_PANEL_DRIVERS_BACKLIGHT_USE_PWM_LEDC, CONF2 = ESP_PANEL_DRIVERS_BACKLIGHT_COMPILE_UNUSED_DRIVERS)
 *
 * | CONF1 | CONF2 | Driver Available ( = CONF1 ^ CONF2) | Factory Support ( = CONF1) |
 * |-------|-------|-------------------------------------|----------------------------|
 * |   0   |   0   |                 No                  |              No            |
 * |   1   |   0   |                 Yes                 |              Yes           |
 * |   0   |   1   |                 Yes                 |              No            |
 * |   1   |   1   |                 Yes                 |              Yes           |
 */
#define ESP_PANEL_DRIVERS_BACKLIGHT_COMPILE_UNUSED_DRIVERS     (1)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// File Version ///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Do not change the following versions. These version numbers are used to check compatibility between this
 * configuration file and the library. Rules for version numbers:
 * 1. Major version mismatch: Configurations are incompatible, must use library version
 * 2. Minor version mismatch: May be missing new configurations, recommended to update
 * 3. Patch version mismatch: No impact on functionality
 */
#define ESP_PANEL_DRIVERS_CONF_FILE_VERSION_MAJOR 1
#define ESP_PANEL_DRIVERS_CONF_FILE_VERSION_MINOR 0
#define ESP_PANEL_DRIVERS_CONF_FILE_VERSION_PATCH 0

// *INDENT-ON*
