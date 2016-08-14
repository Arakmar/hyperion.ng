
// STL includes
#include <cstring>
#include <cstdio>
#include <iostream>

// Linux includes
#include <fcntl.h>
#include <sys/ioctl.h>

// hyperion local includes
#include "LedDeviceWs2801.h"

LedDeviceWs2801::LedDeviceWs2801(const std::string& outputDevice, const unsigned baudrate, const unsigned latchTime,
                                const int spiMode, const bool spiDataInvert)
	: LedSpiDevice(outputDevice, baudrate, latchTime, spiMode, spiDataInvert)
{
	// empty
}

int LedDeviceWs2801::write(const std::vector<ColorRgb> &ledValues)
{
	_ledCount = ledValues.size();

	const unsigned dataLen = ledValues.size() * sizeof(ColorRgb);
	const uint8_t * dataPtr = reinterpret_cast<const uint8_t *>(ledValues.data());

	return writeBytes(dataLen, dataPtr);
}

int LedDeviceWs2801::switchOff()
{
	return write(std::vector<ColorRgb>(_ledCount, ColorRgb{0,0,0}));
}
