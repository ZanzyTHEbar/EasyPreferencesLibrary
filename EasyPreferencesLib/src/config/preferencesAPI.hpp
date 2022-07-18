#ifndef PREFERENCESAPI_HPP
#define PREFERENCESAPI_HPP
#include <Arduino.h>
#include <Preferences.h>

class Config
{
public:
    Config(const char *configName, const char *partitionName);
    virtual ~Config();
    bool begin();
    template <typename T>
    void write(const char *key, T &buff);
    template <typename T>
    void write(const char *key, T *&buff);
    template <typename T>
    bool read(const char *key, T &buff);
    template <typename T>
    bool read(const char *key, T *&buff);
    void clear();
    void remove(const char *key);
    size_t getValueLength(const char *key);
    byte getType(const char *key);
    size_t freeEntries();
    void checkConfigState();

private:
    enum State
    {
        INIT,
        READY,
        Reading,
        Writing,
        ERROR
    };
    State _state;
    Preferences _preferences;
    const char *_configName;
    const char *_partitionName;
};
#endif
