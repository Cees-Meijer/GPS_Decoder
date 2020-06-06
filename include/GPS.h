#ifndef GPS_H
#define GPS_H

#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

class GPS
{
    public:
    float X;
        GPS();
        virtual ~GPS();
        int Init();
        struct _data{
          float lat;
          float lon;
          };
         struct _data Data;
    protected:

    private:
};

#endif // GPS_H
