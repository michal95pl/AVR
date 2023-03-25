#ifndef lora_header
	#define lora_header
	
	#include "LoRa.c"
	
	#warning include library after io.h and delay.h
	
	#if !defined(LoRa_pin_m0) || !defined(LoRa_pin_m1) || !defined(LoRa_port_pins) || !defined(LoRa_aux_pin)
		#error define m0, m1 pins, aux pin
	#endif
	
	#if !defined(LoRa_usart) || !defined(LoRa_usart_tx_pin) || !defined(LoRa_usart_rx_pin) || !defined(LoRa_usart_port)
		#error define usart tx, rx pins and number of usart
	#endif
	
	void LoRa_settings(uint16_t addr, uint8_t speed, uint8_t power);
	void LoRa_init();
	void LoRa_send(char *data, uint8_t len);
	
#endif