#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

/*
 * StateManager
 * All Project States are managed here
 */
class ProgramStates
{
public:
    struct DeviceStates
    {
        enum State_e
        {
            Starting,
            Started,
            Stopping,
            Stopped,
            Error
        };

        enum ConfigState_e
        {
            None,
            Configured,
            Writing,
            Reading,
            Clearing,
            Cleared,
            ErrorConfig
        };

        enum LightSensorState_e
        {
            Starting,
            Started,
            NightOvercast,
            VenusAtBrightest,
            StarlightNoMoonNoAirglow,
            StarlightNoMoon,
            QuarterMoon,
            FullMoon,
            NightTime,
            FullyOverCast,
            ExtremeOfThickestStormClouds,
            SunriseOrSunset,
            Overcast,
            ShadeWithClearSkies,
            Daylight,
            BrightSunlight,
            BrightestSunlight,
            Stopping,
            Stopped,
            Error
        };

        enum WiFiState_e
        {
            None,
            Connecting,
            Connected,
            Disconnected,
            Disconnecting,
            Error
        };
    };
};

/*
 * EventManager
 * All Project Events are managed here
 */

class StateManager
{
public:
    StateManager();
    virtual ~StateManager();

    void setState(ProgramStates::DeviceStates::State_e state);
    void setState(ProgramStates::DeviceStates::WiFiState_e state);
    void setState(ProgramStates::DeviceStates::LightSensorState_e state);
    void setState(ProgramStates::DeviceStates::ConfigState_e state);

    ProgramStates::DeviceStates::State_e getCurrentState();
    ProgramStates::DeviceStates::WiFiState_e getCurrentWiFiState();
    ProgramStates::DeviceStates::LightSensorState_e getCurrentLightSensorState();
    ProgramStates::DeviceStates::ConfigState_e getCurrentConfigState();

private:
    ProgramStates::DeviceStates::State_e _current_state;
    ProgramStates::DeviceStates::WiFiState_e _current_wifi_state;
    ProgramStates::DeviceStates::LightSensorState_e _current_light_sensor_state;
    ProgramStates::DeviceStates::ConfigState_e _current_config_state;
};
extern StateManager stateManager;
#endif // STATEMANAGER_HPP