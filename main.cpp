#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <TinyGPS.h>

#include <wiringPi.h>
#include <wiringSerial.h>

int main ()
{
  int fd ;
  int count ;
  unsigned int nextTime ;

  TinyGPSPlus *gps = new TinyGPSPlus();

  if ((fd = serialOpen ("/dev/ttyS0", 9600)) < 0)
  {
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
    return 1 ;
  }

  if (wiringPiSetup () == -1)
  {
    fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
    return 1 ;
  }

  nextTime = millis () + 300 ;
  bool firstUpdate = false;

  while(true)
  {

    while (serialDataAvail (fd))
    {
      char cc = serialGetchar (fd);

      gps->encode(cc);
      if(!firstUpdate)
      {
       firstUpdate=gps->location.isUpdated();
       printf("%c", cc) ;
      }
      else{
        if(gps->location.isUpdated()){
          printf("LAT=%f, LON=%f, Age:%d, Heading:%f, Speed:%f\r\n",gps->location.lat(),gps->location.lng(),gps->location.age(),gps->course.deg(),gps->speed.mps());
          }
       }

      fflush (stdout) ;
    }
  }

  printf ("\n") ;
  return 0 ;
}
