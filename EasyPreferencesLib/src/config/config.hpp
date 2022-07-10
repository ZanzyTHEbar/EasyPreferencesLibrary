#ifndef CONFIG_HPP
#define CONFIG_HPP
#include <Arduino.h>
#include "StateManager/StateManager.hpp"
#include <Preferences.h>

class Config
{
public:
    Config(const char *configName, const char *partitionName);
    virtual ~Config();
    void begin();
    template <typename T>
    void write(const char *key, T &value);
    template <typename T>
    void read(const char *key, T &value);
    void clear();
    void remove(const char *key);
    size_t getValueLength(const char *key);
    byte getType(const char *key);
    size_t freeEntries();
    void checkConfigState();

private:
    Preferences _preferences;
    const char *_configName;
    const char *_partitionName;
};
#endif