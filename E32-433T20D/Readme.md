Library for AtMega4809

Hello world send example:

```C

#define F_CPU 3333333

#define LoRa_pin_m0 PIN0_bm
#define LoRa_pin_m1 PIN1_bm
#define LoRa_aux_pin PIN2_bm
#define LoRa_port_pins PORTC

#define LoRa_usart USART0
#define LoRa_usart_tx_pin PIN0_bm
#define LoRa_usart_rx_pin PIN1_bm
#define LoRa_usart_port PORTA

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