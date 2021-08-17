#include<avr/io.h>
#include<util/delay.h>
void init_adc()
{
ADCSRA=ADCSRA |(0b00000001<<ADEN);
ADCSRA=ADCSRA |(0b00000001<<ADPS2);
ADCSRA=ADCSRA |(0b00000001<<REFSO);
}
unsigned int read_adc()
{
int p=0b00000000;
ADMUX=ADMUX|p;
ADCSRA=ADCSRA|(0b00000001<<ADSC);
while((ADSCRA&(0b00000001<<ADIF))==0)
{}
ADCSRA=ADCSRA|(0b00000001<<ADIF);
return(ADC);
}
void main()
{
DDRB=0b11111111;
init_adc();
_delay_ms(500);
unsigned int a;
unsigned int p;
unsigned int T;
unsigned int TON;
unsigned int TOFF;
while(1)
{
p=read_adc();
a=(p/40);
T=25.6;
TOFF=a;
TON=T-TOFF;
if(p<819.2)
{
PORTB=0b00001010;
delay_ms(TON);
PORTB=0b00000000;
delay_ms(TOFF);
}
Else
PORTB=0b00000000;
}
}


