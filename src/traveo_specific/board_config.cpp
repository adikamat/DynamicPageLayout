// Copyright (C) 2025 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial

#include "cy_project.h"
#include "cy_device_headers.h"

#include "board_config.h"
#include "keymanager.h"

#include <qul/application.h>
\
#define USER_LED1_PORT           CY_USER_LED1_PORT
#define USER_LED1_PIN            CY_USER_LED1_PIN
#define USER_LED1_PIN_MUX        CY_USER_LED1_PIN_MUX

#define USER_LED2_PORT           CY_USER_LED2_PORT
#define USER_LED2_PIN            CY_USER_LED2_PIN
#define USER_LED2_PIN_MUX        CY_USER_LED2_PIN_MUX

#define USER_BUTTON1_PORT        CY_USER_BUTTON_UP_PORT
#define USER_BUTTON1_PIN         CY_USER_BUTTON_UP_PIN
#define USER_BUTTON1_PIN_MUX     CY_USER_BUTTON_UP_PIN_MUX
#define USER_BUTTON1_IRQN        CY_USER_BUTTON_UP_IRQN

#define USER_BUTTON2_PORT        CY_USER_BUTTON_WAKE_PORT
#define USER_BUTTON2_PIN         CY_USER_BUTTON_WAKE_PIN
#define USER_BUTTON2_PIN_MUX     CY_USER_BUTTON_WAKE_PIN_MUX
#define USER_BUTTON2_IRQN        CY_USER_BUTTON_WAKE_IRQN

// cy_stc_gpio_pin_config_t user_led0_port_pin_cfg {
//         .outVal    = 0ul,
//         .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
//         .hsiom     = USER_LED1_PIN_MUX,
//         .intEdge   = 0ul,
//         .intMask   = 0ul,
//         .vtrip     = 0ul,
//         .slewRate  = 0ul,
//         .driveSel  = 0ul,
// };

cy_stc_gpio_pin_config_t user_led0_port_pin_cfg {
    0ul,
    CY_GPIO_DM_STRONG_IN_OFF,
    USER_LED1_PIN_MUX,
    0ul,
    0ul,
    0ul,
    0ul,
    0ul
};

cy_stc_gpio_pin_config_t user_led1_port_pin_cfg {
        0ul,
        CY_GPIO_DM_STRONG_IN_OFF,
        USER_LED2_PIN_MUX,
        0ul,
        0ul,
        0ul,
        0ul,
        0ul
};

cy_stc_gpio_pin_config_t user_button1_port_pin_cfg {
        0ul,
        CY_GPIO_DM_HIGHZ,
        USER_BUTTON1_PIN_MUX,
        CY_GPIO_INTR_BOTH,
        1ul,
        0ul,
        0ul,
        0ul
};

cy_stc_gpio_pin_config_t user_button2_port_pin_cfg {
        0ul,
        CY_GPIO_DM_HIGHZ,
        USER_BUTTON2_PIN_MUX,
        CY_GPIO_INTR_BOTH,
        1ul,
        0ul,
        0ul,
        0ul
};

void ButtonIntHandler(void)
{
    uint32_t intStatus;

    /* If button1 falling edge detected */
    intStatus = Cy_GPIO_GetInterruptStatusMasked(USER_BUTTON1_PORT, USER_BUTTON1_PIN);
    if (intStatus != 0ul)
    {
        KeyEvent event;
        uint32_t curLevel = Cy_GPIO_Read(USER_BUTTON1_PORT, USER_BUTTON1_PIN);
        event.type = (curLevel == 1ul) ? KeyEvent::KeyRelease : KeyEvent::KeyPress;

        Cy_GPIO_ClearInterrupt(USER_BUTTON1_PORT, USER_BUTTON1_PIN);
        /* Toggle LED1 */
        Cy_GPIO_Inv(USER_LED1_PORT, USER_LED1_PIN);
        event.key = KeyEvent::BUTTON_LEFT;
        HMIInput::instance().postEventFromInterrupt(event);
    }

    /* If button2 rising edge detected */
    intStatus = Cy_GPIO_GetInterruptStatusMasked(USER_BUTTON2_PORT, USER_BUTTON2_PIN);
    if (intStatus != 0ul)
    {
        KeyEvent event;
        uint32_t curLevel = Cy_GPIO_Read(USER_BUTTON2_PORT, USER_BUTTON2_PIN);
        event.type = (curLevel == 1ul) ? KeyEvent::KeyRelease : KeyEvent::KeyPress;

        Cy_GPIO_ClearInterrupt(USER_BUTTON2_PORT, USER_BUTTON2_PIN);
        /* Toggle LED2 */
        Cy_GPIO_Inv(USER_LED2_PORT, USER_LED2_PIN);
        event.key = KeyEvent::BUTTON_RIGHT;
        Qul::PlatformInterface::log("Key %d: Event %d\r\n", event.key, event.type);
        HMIInput::instance().postEventFromInterrupt(event);
    }
}

void ConfigureBoard()
{
    /* Enable global interrupts. */
    // Done in platform\boards\cypress\tviic2d-common\bootloader\main.c:65
    // __enable_irq();
    // Cy_SysEnableApplCore(CORE_CM7_0, CY_CORTEX_M7_0_APPL_ADDR);

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Cy_GPIO_Pin_Init(USER_LED1_PORT, USER_LED1_PIN, &user_led0_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_LED2_PORT, USER_LED2_PIN, &user_led1_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_BUTTON1_PORT, USER_BUTTON1_PIN, &user_button1_port_pin_cfg);
    Cy_GPIO_Pin_Init(USER_BUTTON2_PORT, USER_BUTTON2_PIN, &user_button2_port_pin_cfg);

    /* Setup GPIO for BUTTON1 interrupt */
    cy_stc_sysint_irq_t irq_cfg
        {
            USER_BUTTON1_IRQN,
            CPUIntIdx2_IRQn,
            true,
        };

    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, ButtonIntHandler);

    /* Setup GPIO for BUTTON2 interrupt */
    irq_cfg.sysIntSrc  = USER_BUTTON2_IRQN;
    Cy_SysInt_InitIRQ(&irq_cfg);
    Cy_SysInt_SetSystemIrqVector(irq_cfg.sysIntSrc, ButtonIntHandler);

    NVIC_SetPriority(CPUIntIdx2_IRQn, 3ul);
    NVIC_EnableIRQ(CPUIntIdx2_IRQn);
}
