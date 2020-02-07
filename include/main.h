#pragma once

#include <Arduino.h>
#include <SPIFFS.h>
#ifndef ARDUINOJSON_DECODE_UNICODE
    #define ARDUINOJSON_DECODE_UNICODE 1
#endif
#include <ArduinoJson.h>
#include <UniversalTelegramBot.h>
#include <Ticker.h>
#include <WebServer.h>
#include <ESPTools.h>
#include <ESPConfig.h>
#include <ESPWifi.h>
#include <WiFiClientSecure.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>
//#include <TelegramBot.h>

/* Conditional compilation */
#define MQTT_ENABLE     false
#define OTA_ENABLE      false
#define SCREEN_TYPE     oled

/* General */
#define SERIAL_BAUDRATE 115200
#define DURATION_BEFORE_RESET 5000
#define DURATION_BEFORE_RESTART 5000
#define DURATION_BTN_RESET_PRESS 10000

/* Telegram */
#define CHECK_MSG_DELAY 10000

/* Leds pin */
#define LED_1_R_PIN     10
#define LED_1_B_PIN     11
#define LED_2_R_PIN     12
#define LED_2_B_PIN     13
#define LED_3_R_PIN     14
#define LED_3_B_PIN     15
#define LED_4_R_PIN     16
#define LED_4_B_PIN     17

/* Button pin */
#define BTN_READ_PIN    14
#define BTN_RESTART_PIN 15
#define BTN_RESET_PIN   16

/* TFT SCREEN */
#define TFT_DC          4
#define TFT_CS          15
#define TFT_RST         2
#define TFT_MISO        19         
#define TFT_MOSI        23           
#define TFT_CLK         18

#define BLINK_RED       9
#define BLINK_BLUE      1

#if MQTT_ENABLE == true
    // @todo See large message method in exemple
    #define MQTT_MAX_PACKET_SIZE 2048
    #include <PubSubClient.h>
#endif

#if OTA_ENABLE == true
    #include <ArduinoOTA.h>
#endif

void blinkLed(int repeat = 0, int time = 250);
void tickerManager(bool start = true, unsigned int status = BLINK_BLUE, float timer = 1);