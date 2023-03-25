#define LoRa_SLEEP_MODE LoRa_port_pins.OUT |= LoRa_pin_m0 | LoRa_pin_m1
#define LoRa_NORMAL_MODE LoRa_port_pins.OUT &= ~(LoRa_pin_m0 | LoRa_pin_m1)

void usart_init(void)
{
	LoRa_usart_port.DIR |= LoRa_usart_tx_pin;
	LoRa_usart.BAUD = 1388;
	LoRa_usart.CTRLB |= USART_TXEN_bm;
}

void usart_sendChar(char c)
{
	while ( !(LoRa_usart.STATUS & USART_DREIF_bm) ) {;}
	LoRa_usart.TXDATAL = c;
}

void LoRa_settings(uint16_t addr, uint8_t speed, uint8_t power) 
{
	uint8_t sped_register = 0;
	uint8_t option_register = 0;
	
	// switch to sleep mode
	while (!(LoRa_port_pins.IN & LoRa_aux_pin)); // check busy
	_delay_ms(2);
	LoRa_SLEEP_MODE;
	_delay_ms(1);
		
		
	sped_register |= (0b011 << 3); // uart 9600bps
	
	// speed data
	switch (speed) { 
		case 1:
			sped_register |= 0b001;
			 break;
			 
		case 2:
			sped_register |= 0b010; 
			break;
			
		case 4:
			sped_register |= 0b011; 
			break;
			
		case 9:
			sped_register |= 0b100;
			break;
			
		case 19:
			sped_register |= 0b101;
			break;
	}
	
	option_register |= (0b1 << 6); // IO drive
	option_register |= (0b1 << 2); // FEC
	
	// power in dBm
	switch (power) {
		case 30:
			option_register |= 0b01;
			break;
		case 27:
			option_register |= 0b10;
			break;
		case 24:
			option_register |= 0b11;
	}
	
	// send data
	while (!(LoRa_port_pins.IN & LoRa_aux_pin)); // check busy
	usart_sendChar(0xC0);
	usart_sendChar(addr >> 8);
	usart_sendChar(addr);
	usart_sendChar(sped_register);
	usart_sendChar(0);
	usart_sendChar(option_register);
	
	
	// sleep to normal mode
	while (!(LoRa_port_pins.IN & LoRa_aux_pin)) {} // check busy
	_delay_ms(2);
	LoRa_NORMAL_MODE;
	_delay_ms(1);
	
}

void LoRa_init() {
	// set pins to out mode
	LoRa_port_pins.DIR |= LoRa_pin_m0 | LoRa_pin_m1;
	usart_init();
}

void LoRa_send(char *data, uint8_t len) {
	
	// check busy
	//while (!(LoRa_port_pins.IN & LoRa_aux_pin)); // check busy
		
	for (uint8_t i=0; i < len && i < 58; i++) 
	{
		usart_sendChar(data[i]);
	}
}