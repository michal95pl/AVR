#ifndef lora_header
	#define lora_header
	
	#define LoRa_pin_m0 PIN0_bm
	#define LoRa_pin_m1 PIN1_bm
	#define LoRa_aux_pin PIN2_bm
	#define LoRa_port_pins PORTC

	#define LoRa_usart USART0
	#define LoRa_usart_tx_pin PIN0_bm
	#define LoRa_usart_rx_pin PIN1_bm
	#define LoRa_usart_port PORTA

	#include "LoRa.c"
	
	#warning include library after io.h and delay.h
	
	void LoRa_settings(uint16_t addr, uint8_t speed, uint8_t power);
	void LoRa_init();
	void LoRa_send(char *data, uint8_t len);
	
#endif
