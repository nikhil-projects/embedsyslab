#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "uart.h"
#include "semphr.h"
#include "queue.h"

/**
 * UART baudrate configuration.
 */
const uint32_t uart_baudrate = 115200;

/***
 * Insert declarations here
 */

/*-----------------------------------------------------------*/
int main(void) {
    // Initialize UART
    uart_init(uart_baudrate);

    /***
     * Insert your code here
     */

    /* The following line should never be reached.
     * Otherwise there was insufficient FreeRTOS heap
     * memory available for the task to be created.
     */
    return 0;
}
/*-----------------------------------------------------------*/

/* -------------------------------------------------------------------------
 * Default FreeRTOS hooks
 * ------------------------------------------------------------------------- */

void vApplicationMallocFailedHook( void )
{
    /* vApplicationMallocFailedHook() will only be called if
    configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
    function that will get called if a call to pvPortMalloc() fails.
    pvPortMalloc() is called internally by the kernel whenever a task, queue,
    timer or semaphore is created.  It is also called by various parts of the
    demo application.  If heap_1.c or heap_2.c are used, then the size of the
    heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
    FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
    to query the size of free heap space that remains (although it does not
    provide information on how the remaining heap might be fragmented). */
    taskDISABLE_INTERRUPTS();
    for( ;; );
}
/* ------------------------------------------------------------------------- */

void vApplicationIdleHook( void )
{
    /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
    to 1 in FreeRTOSConfig.h.  It will be called on each iteration of the idle
    task.  It is essential that code added to this hook function never attempts
    to block in any way (for example, call xQueueReceive() with a block time
    specified, or call vTaskDelay()).  If the application makes use of the
    vTaskDelete() API function (as this demo application does) then it is also
    important that vApplicationIdleHook() is permitted to return to its calling
    function, because it is the responsibility of the idle task to clean up
    memory allocated by the kernel to any task that has since been deleted. */
}
/* ------------------------------------------------------------------------- */

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
    ( void ) pcTaskName;
    ( void ) pxTask;

    /* Run time stack overflow checking is performed if
    configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
    function is called if a stack overflow is detected. */
    taskDISABLE_INTERRUPTS();
    for( ;; );
}
/* ------------------------------------------------------------------------- */

void *malloc( size_t xSize )
{
    /* There should not be a heap defined, so trap any attempts to call
    malloc. */
    Interrupt_disableMaster();
    for( ;; );
}
/* ------------------------------------------------------------------------- */


/*-----------------------------------------------------------*/

void vPreSleepProcessing(uint32_t ulExpectedIdleTime)
{

}
/*-----------------------------------------------------------*/

void vApplicationTickHook(void)
{
    /* This function will be called by each tick interrupt if
     configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.  User code can be
     added here, but the tick hook is called from an interrupt context, so
     code must not attempt to block, and only the interrupt safe FreeRTOS API
     functions can be used (those that end in FromISR()). */

    /* The full demo includes a software timer demo/test that requires
     prodding periodically from the tick interrupt. */
    //vTimerPeriodicISRTests();
    /* Call the periodic event group from ISR demo. */
    //vPeriodicEventGroupsProcessing();
    /* Use task notifications from an interrupt. */
    //xNotifyTaskFromISR();
    /* Use mutexes from interrupts. */
    //vInterruptSemaphorePeriodicTest();
}
/*-----------------------------------------------------------*/

