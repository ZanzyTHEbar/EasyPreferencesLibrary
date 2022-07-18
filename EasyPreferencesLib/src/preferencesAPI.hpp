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

    /**
     * @brief Writes a value to the config
     *
     * @tparam T Type of the value to write
     * @param key Key of the value to write
     * @param value Value to write
     * @return void
     * @see Takes a buffer as parameter to avoid the need to create a temporary variable
     */
    template <typename T>
    void Config::write(const char *key, T *&buff)
    {
        if (_state == Reading)
        {
            log_e("Config %s is in reading state\n", _configName);
            _state = ERROR;
            return;
        }

        _state = Writing;
        _preferences.begin(_configName);
        _preferences.putBytes(key, (T *)buff, sizeof(T));
        _preferences.end();
        _state = READY;
    }
    template <typename T>
    void Config::write(const char *key, T &buff)
    {
        if (_state == Reading)
        {
            log_e("Config %s is in reading state\n", _configName);
            _state = ERROR;
            return;
        }

        _state = Writing;
        _preferences.begin(_configName);
        _preferences.putBytes(key, (T *)&buff, sizeof(T));
        _preferences.end();
        _state = READY;
    }

    /**
     * @brief Reads a value from the config
     *
     * @tparam T Type of the value to read
     * @param key Key of the value to read
     * @param value Value to read
     * @return void
     * @see Takes a buffer as parameter to avoid the need to create a temporary variable
     */
    template <typename T>
    bool Config::read(const char *key, T &buff)
    {
        if (_state == Writing)
        {
            log_e("Config::read() - Config is being written and can not be accessed currently");
            _state = ERROR;
            return false;
        }
        _state = Reading;
        _preferences.begin(_configName, true);
        bool success = _preferences.getBytes(key, (T *)&buff, sizeof(T) * sizeof(buff));
        _preferences.end();
        _state = READY;
        return success;
    }

    template <typename T>
    bool Config::read(const char *key, T *&buff)
    {
        if (_State == Writing)
        {
            log_e("Config::read() - Config is being written and can not be accessed currently");
            _state = ERROR;
            return false;
        }
        _state = Reading;
        _preferences.begin(_configName, true);
        bool success = _preferences.getBytes(key, (T *)&buff, sizeof(T));
        _preferences.end();
        _state = READY;
        return success;
    }
    
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
