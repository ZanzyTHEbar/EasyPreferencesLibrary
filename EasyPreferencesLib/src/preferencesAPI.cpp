#include "preferencesAPI.hpp"

Config::Config(const char *configName, const char *partitionName) : _configName(configName),
                                                                    _partitionName(partitionName),
                                                                    _state(INIT) {}

Config::~Config() {}

bool Config::begin()
{
    bool success = _preferences.begin(_configName);
    delay(100);
    return success;
}

void Config::clear()
{
    _state = Writing;
    _preferences.begin(_configName);
    _preferences.clear();
    _preferences.end();
    _state = READY;
}

void Config::remove(const char *key)
{
    _state = Writing;
    _preferences.begin(_configName);
    _preferences.remove(key);
    _preferences.end();
    _state = READY;
}

size_t Config::getValueLength(const char *key)
{
    _state = Reading;
    _preferences.begin(_configName);
    size_t length = _preferences.getBytesLength(key);
    _preferences.end();
    _state = READY;
    return length;
}

//**********************************************************
//* Return value | Prefs Type | Data Type | Enumerated Value
//* 0            | Char       | int8_t    | PT_I8
//* 1            | UChar      | uint8_t   | PT_U8
//* 1            | Bool       | bool      | PT_U8
//* 2            | Short      | int16_t   | PT_I16
//* 3            | UShort     | uint16_t  | PT_U16
//* 4            | Int        | int32_t   | PT_I32
//* 4            | Long       | int32_t   | PT_I32
//* 5            | UInt       | int32_t   | PT_U32
//* 5            | ULong      | uint32_t  | PT_U32
//* 6            | Long64     | int64_t   | PT_I64
//* 7            | ULong64    | uint64_t  | PT_U64
//* 8            | String     | String    | PT_STR
//* 8            | String     | *char     | PT_STR
//* 9            | Float      | float_t   | PT_BLOB
//* 9            | Double     | double_t  | PT_BLOB
//* 10           | -          | -         | PT_INVALID
//************************************************************
byte Config::getType(const char *key)
{
    _state = Reading;
    _preferences.begin(_configName);
    byte type = _preferences.getType(key);
    _preferences.end();
    _state = READY;
    return type;
}

size_t Config::freeEntries()
{
    _state = Reading;
    _preferences.begin(_configName);
    size_t freeEntries = _preferences.freeEntries();
    _preferences.end();
    _state = READY;
    return freeEntries;
}

template void Config::write<uint8_t>(const char *key, uint8_t &buff);
template void Config::write<uint16_t>(const char *, uint16_t &buff);
template void Config::write<uint32_t>(const char *key, uint32_t &buff);
template void Config::write<uint64_t>(const char *key, uint64_t &buff);
template void Config::write<int8_t>(const char *key, int8_t &buff);
template void Config::write<int16_t>(const char *key, int16_t &buff);
template void Config::write<int32_t>(const char *key, int32_t &buff);
template void Config::write<int64_t>(const char *key, int64_t &buff);
template void Config::write<bool>(const char *key, bool &buff);
template void Config::write<float_t>(const char *key, float_t &buff);
template void Config::write<double_t>(const char *key, double_t &buff);
template void Config::write<const char *>(const char *key, const char *&buff);
template void Config::write<String>(const char *key, String &buff);

template void Config::write<uint8_t>(const char *key, uint8_t *&buff);
template void Config::write<uint16_t>(const char *key, uint16_t *&buff);
template void Config::write<uint32_t>(const char *key, uint32_t *&buff);
template void Config::write<uint64_t>(const char *key, uint64_t *&buff);
template void Config::write<int8_t>(const char *key, int8_t *&buff);
template void Config::write<int16_t>(const char *key, int16_t *&buff);
template void Config::write<int32_t>(const char *key, int32_t *&buff);
template void Config::write<int64_t>(const char *key, int64_t *&buff);
template void Config::write<bool>(const char *key, bool *&buff);
template void Config::write<float_t>(const char *key, float_t *&buff);
template void Config::write<double_t>(const char *key, double_t *&buff);
template void Config::write<const char *>(const char *key, const char **&buff);
template void Config::write<String>(const char *key, String *&buff);

template bool Config::read<uint8_t>(const char *key, uint8_t *&buff);
template bool Config::read<uint16_t>(const char *key, uint16_t *&buff);
template bool Config::read<uint32_t>(const char *key, uint32_t *&buff);
template bool Config::read<uint64_t>(const char *key, uint64_t *&buff);
template bool Config::read<int8_t>(const char *key, int8_t *&buff);
template bool Config::read<int16_t>(const char *key, int16_t *&buff);
template bool Config::read<int32_t>(const char *key, int32_t *&buff);
template bool Config::read<int64_t>(const char *key, int64_t *&buff);
template bool Config::read<bool>(const char *key, bool *&buff);
template bool Config::read<float_t>(const char *key, float_t *&buff);
template bool Config::read<double_t>(const char *key, double_t *&buff);
template bool Config::read<const char *>(const char *key, const char **&buff);
template bool Config::read<String>(const char *key, String *&buff);

template bool Config::read<uint8_t>(const char *key, uint8_t &buff);
template bool Config::read<uint16_t>(const char *key, uint16_t &buff);
template bool Config::read<uint32_t>(const char *key, uint32_t &buff);
template bool Config::read<uint64_t>(const char *key, uint64_t &buff);
template bool Config::read<int8_t>(const char *key, int8_t &buff);
template bool Config::read<int16_t>(const char *key, int16_t &buff);
template bool Config::read<int32_t>(const char *key, int32_t &buff);
template bool Config::read<int64_t>(const char *key, int64_t &buff);
template bool Config::read<bool>(const char *key, bool &buff);
template bool Config::read<float_t>(const char *key, float_t &buff);
template bool Config::read<double_t>(const char *key, double_t &buff);
template bool Config::read<const char *>(const char *key, const char *&buff);
template bool Config::read<String>(const char *key, String &buff);
