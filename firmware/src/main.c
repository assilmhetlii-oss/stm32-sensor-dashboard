#if defined(STM32F103xB)
#include "stm32f1xx.h"
#define LED_GPIO_PORT GPIOC
#define LED_PIN (1U << 13)
#define LED_GPIO_CLOCK_ENABLE() do { RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; } while (0)
#elif defined(STM32F401xE)
#include "stm32f4xx.h"
#define LED_GPIO_PORT GPIOA
#define LED_PIN (1U << 5)
#define LED_GPIO_CLOCK_ENABLE() do { RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; } while (0)
#else
#error "Unsupported target board"
#endif

static void GPIO_Init(void)
{
    LED_GPIO_CLOCK_ENABLE();

#if defined(STM32F103xB)
    LED_GPIO_PORT->CRH &= ~(0xFU << 20);
    LED_GPIO_PORT->CRH |= (0x2U << 20);
#elif defined(STM32F401xE)
    LED_GPIO_PORT->MODER &= ~(0x3U << 10);
    LED_GPIO_PORT->MODER |= (0x1U << 10);
    LED_GPIO_PORT->OTYPER &= ~(0x1U << 5);
    LED_GPIO_PORT->OSPEEDR &= ~(0x3U << 10);
    LED_GPIO_PORT->OSPEEDR |= (0x2U << 10);
    LED_GPIO_PORT->PUPDR &= ~(0x3U << 10);
#endif

    LED_GPIO_PORT->ODR &= ~LED_PIN;
}

int main(void)
{
    GPIO_Init();

    while (1)
    {
        LED_GPIO_PORT->ODR ^= LED_PIN;
        for (volatile uint32_t i = 0; i < 500000; ++i)
        {
        }
    }
}