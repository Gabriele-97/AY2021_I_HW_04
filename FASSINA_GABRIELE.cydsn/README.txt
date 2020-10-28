ASSIGNMENT 4 GABRIELE FASSINA

In this assignment I was asked to develop a system simulating the functionalities of a Lamp 
which can be controlled remotely and whose intensity is tunable by a potentiometer. 

To achieve this purpose I have implemented an UART transmission protocol that enables signal sampling
when the user transmits a 'b' or 'B' charachter and blocks it when the user transmits 's' or 'S'. In this latter case
the LED turns off and the transmission of the values sampled is stopped as well (it would be nonsense to transmit
samples when nothing is currently being sampled). 
To get such samples an ADC that acquires the values of a photoresistor and of the potentiometer. 
The led turns on only in case the room light is below a given threshold value. 
Only in case the light is on, the user can set the led light intensity by the potentiometer. 
Finally, for diagnositc purpose, the sampled values are tansmitted via UART communications

A first issue is to determine the light threshold which should be done in the environment of the intended use.
Since this variable has been defined in a macro, it is easy to change the value according to user's needs. 

The light intensity is controlled by the DC of a PWM. Since human eye resolution is about 16ms,
it was needed to keep the period below this value. A first more trivial solution could be to increase
clock frequency and keep a 16 bit PWM, setting the compare value equal to the value read by the potentiometer.
Conversely, in order to optimize the firmware, I have decided to rescale the dynamics of the potentiometer in the 0-255
dynamics of an 8-bits PWM which allows me to keep the clock at 20 kHz. 

The clock of the ADC has been set at 2 kHz because I consider adequate 1 Khz for sampling each signal and thus 2 kHz 
assure a good performance when both signals are read. 