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

  for (count = 0 ; count < 256 ; )
  {

    while (serialDataAvail (fd))
    {
      char cc = serialGetchar (fd);
      printf ("%c", cc) ;
      gps->encode(cc);
      fflush (stdout) ;
    }
  }

  printf ("\n") ;
  return 0 ;
}
