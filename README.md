# GPS_Decoder
NMEA decoder for GPS data on Raspberry Pi. Modified from the TinyGPS++ library for Arduino.
It works exactly as described by the author of TinyGPS: http://arduiniana.org/libraries/tinygpsplus/

You would simply create a TinyGPS++ instance like this:

(WiringPi is included here because that is the easiest way to read seral data on the Pi)
```css

  #include <wiringPi.h>
  #include <wiringSerial.h>
  #include "TinyGPS.h"
  
  TinyGPSPlus *gps = new TinyGPSPlus();
```
Repeatedly feed it characters from your GPS device:
```css
  while (serialDataAvail (fd))
  gps->encode(serialGetchar (fd));
```
Then query it for the desired information:
```css
 if(gps->location.isUpdated()){
    printf("LAT=%f, LON=%f, Age:%d, Heading:%f, Speed:%f\r\n",gps->location.lat(),gps->location.lng(),
            gps->location.age(),gps->course.deg(),gps->speed.mps());
```

I used CODE::BLOCKS to edit this project, hence the .save and .depends files.
