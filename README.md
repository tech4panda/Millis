# **Millis**

Provides an Arduino library for use of millis() and create a delay without the delay()'s function.

## Installation

To use this library download the .zip file, uncompress it to a folder named **Millis**. Move the folder to {Arduino path}/libraries.

## Usage

 Include the library on the top of your Arduino script. `#include <Millis.h>`

Create a global variable. `Millis myMillis;`

​	Default value is 500 ms.

Set the delay with constructor:

`Millis myMillis(1000);`

or

`myMillis.setDelay(1000);`

In loop function:

`myMillis.toCall(myFunction);`

## Methods

### Millis(const uint32_t t_delay = 500)

Constructor with default value of 500ms. 

### void setDelay(const uint_32_t t_delay)

Set a new delay.

### void setActive(const bool active)

Set the activity status ON or OFF (true or false).

### bool isActive() const

Return the activity status if ON or OFF.

### uint32_t getDelay() const

Return the current value of the delay setted.

### void toCall(void (*func)(void))

Call your function in the loop.

## Example

```c++
#include <Millis.h>
Millis ms(1000);

void loop(){
	ms.toCall(myFunction);
}

void myFunction(){
	//your code after 1000ms
}
```

## License

GNU GPL 3.0
