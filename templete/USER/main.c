#include "sys.h"
#include "delay.h"
#include "usart.h"
/************************************************
 ALIENTEK Mini STM32F103������ʵ��0-1
 Template����ģ��-�½������½�ʹ��-HAL��汾
 ����֧�֣�www.openedv.com
 �Ա����̣� http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/


/***ע�⣺�����̺ͽ̳��е��½�����3.3С�ڶ�Ӧ***/


void Delay(__IO uint32_t nCount);

void Delay(__IO uint32_t nCount)
{
  while(nCount--){}
}

int main(void)
{
		GPIO_InitTypeDef GPIO_Initure;
     
    HAL_Init();                    	 				//��ʼ��HAL��    
    Stm32_Clock_Init(RCC_PLL_MUL9);   			//����ʱ��,72M

    __HAL_RCC_GPIOB_CLK_ENABLE();           	//����GPIOBʱ��
	
    GPIO_Initure.Pin=GPIO_PIN_12; 						//PB12
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  	//�������
    GPIO_Initure.Pull=GPIO_PULLUP;          	//����
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;    	 	//����
    HAL_GPIO_Init(GPIOB,&GPIO_Initure);

	
		while(1)
		{
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12);  			
			Delay(0x7FFFFF);
		}
}
