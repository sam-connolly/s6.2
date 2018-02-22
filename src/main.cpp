#include <mbed.h>
#include <rtos.h>
#include <mbed_events.h>

DigitalOut red(LED1,1);
void flash(void){
    red = !red;
}
DigitalOut green(LED2,1);
void blink(void){
    green = !green;
}
DigitalOut blue(LED3,1);
void pulse(void){
  blue = !blue;
}

Serial pc(USBTX, USBRX);
Thread worker;
EventQueue queue ;

Thread thread;

int main() {
    pc.printf("ready");
    queue.call_every(500, flash);
    queue.call_every(300, blink);
    queue.call_every(100, pulse);
    printf("dispatching...");
    queue.dispatch_forever();
    //worker.start(callback(&queue, &EventQueue::dispatch_forever ));
    printf("dispatched");
    while(1){}
}
