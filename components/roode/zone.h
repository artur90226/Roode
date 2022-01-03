
#pragma once
#include "VL53L1X_ULD.h"
#include <math.h>
#include "esphome/core/log.h"
#include "configuration.h"
static const char *const TAG = "Zone";
namespace esphome
{
    namespace roode
    {
        class Zone
        {
        public:
            Zone(int roi_width, int roi_height, int roi_center);
            uint16_t getNewDistance(VL53L1X_ULD &distanceSensor);
            uint16_t calibrateThreshold();
            uint16_t calibrateRoi();
            uint16_t getMinThreshold();
            uint16_t getMaxThreshold();
            uint16_t getRoiWidth();
            uint16_t getRoiHeight();
            uint16_t getRoiCenter();
            uint16_t setRoiWidth(uint16_t new_roi_width);
            uint16_t setRoiHeight(uint16_t new_roi_height);
            uint16_t setRoiCenter(uint16_t new_roi_center);
            uint8_t getZoneId();
            uint16_t getDistance();
            bool handleSensorStatus();

        protected:
            int getSum(int *values, int size);
            int getOptimizedValues(int *values, int sum, int size);
            void setCorrectDistanceSettings(float average_zone_0, float average_zone_1);
            uint16_t roi_width;
            uint16_t roi_height;
            uint16_t roi_center;
            uint8_t id;
            uint16_t distance;
        };
    }
}
