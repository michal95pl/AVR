Library for AtMega4809


```
LoRa_settings function sets and save settings. (address, speed, power):

address it's 16bit number
speed(index of speed) <- 0 - 0.3k, 1 - 1.2, 2 - 2.4k, 4 - 4.8k, 9 - 9.6k, 19 - 19.2k in Bps
power(dBm) 33dBm, 30dBm, 27dBm, 24dBm
```




Hello world, send data example:
```C

#define F_CPU 3333333

#include <avr/io.h>
#include <util/delay.h>
#include "LoRa.h"

int main(void)
{
	LoRa_init();
	//LoRa_settings(20, 19, 30);

	while (1)
	{
		LoRa_send("Hello World \n", 13);
		_delay_ms(100);
	}
}

```
