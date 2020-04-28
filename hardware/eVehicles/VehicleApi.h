#pragma once
#include <string>

class CVehicleApi
{
public:
	enum eCommandType {
		Climate_Off,
		Climate_On,
		Climate_Defrost,
		Climate_Defrost_Off,
		Charge_Start,
		Charge_Stop,
		Wake_Up,
		Set_Charge_Limit
	};

	struct tCapabilities {
		bool has_charge_command;
		bool has_climate_command;
		bool has_defrost_command;
		bool has_inside_temp;
		bool has_outside_temp;
		bool has_odo;
		bool has_lock_status;
		bool has_battery_level;
		bool has_charge_limit;
		int  sleep_interval;
	};

	struct tLocationData {
		double latitude;
		double longitude;
		bool is_driving;
		int speed;
	};

	struct tChargeData {
		float battery_level;
		int charge_limit;
		bool is_connected;
		bool is_charging;
		std::string status_string;
	};

	struct tClimateData {
		float inside_temp;
		float outside_temp;
		bool is_climate_on;
		bool is_defrost_on;
	};

	struct tVehicleData {
		float odo;
		bool car_open;
		std::string car_open_message;
	};

	struct tConfigData {
		std::string distance_unit;
		bool unit_miles;
		std::string car_name;
	};

	struct tAllCarData {
		tLocationData location;
		tChargeData charge;
		tClimateData climate;
		tVehicleData vehicle;
	};

	virtual bool Login() = 0;
	virtual bool RefreshLogin() = 0;
	virtual bool SendCommand(eCommandType command, std::string parameter = "") = 0;
	virtual bool IsAwake() = 0;
	virtual bool GetAllData(tAllCarData& data) = 0;
	virtual bool GetLocationData(tLocationData& data) = 0;
	virtual bool GetChargeData(tChargeData& data) = 0;
	virtual bool GetClimateData(tClimateData& data) = 0;
	virtual bool GetVehicleData(tVehicleData& data) = 0;
	
	tCapabilities m_capabilities;
	tConfigData m_config;

};
