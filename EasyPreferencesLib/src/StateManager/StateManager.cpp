#include "StateManager.hpp"

StateManager::StateManager() : _current_state(ProgramStates::DeviceStates::State_e::Starting),
                               _current_wifi_state(ProgramStates::DeviceStates::WiFiState_e::None),
                               _current_light_sensor_state(ProgramStates::DeviceStates::LightSensorState_e::Starting),
                               _current_config_state(ProgramStates::DeviceStates::ConfigState_e::None) {}

StateManager::~StateManager() {}

void StateManager::setState(ProgramStates::DeviceStates::State_e state)
{
    _current_state = state;
}

void StateManager::setState(ProgramStates::DeviceStates::ConfigState_e state)
{
    _current_config_state = state;
}

/*
 * Get States
 * Returns the current state of the device
 */

ProgramStates::DeviceStates::State_e StateManager::getCurrentState()
{
    return _current_state;
}

ProgramStates::DeviceStates::ConfigState_e StateManager::getCurrentConfigState()
{
    return _current_config_state;
}

StateManager stateManager;
