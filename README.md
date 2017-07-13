# **Autonomous driving with PID controllers**

### 1. Objective
This project is to use PID controllers to control the steering angle and the throttle for driving a car 
in a game simulator. The simulator provides cross-track error (CTE) via websocket. The PID 
(proportional-integral-differential) controllers give steering and throttle commands 
to drive the car reliably around the simulator track.


#### Demo 1: Steady drive with constant throttle (click to see the full video)

[![demo_gif1][gif1]](https://youtu.be/bI5RTZcRMAo)


### 2. Parameters of PID controller

**Description of PID values in PID control**

* **P** (proportional) accounts for present values of the error. For example, if the error is large and positive, 
the control output will also be large and positive.

* **I** (integral) accounts for all past values of the error. For example, if the current output is not sufficiently 
strong, the integral of the error will accumulate over time, and the controller will respond by 
applying a stronger action.

* **D** (differential) accounts for possible future trends of the error, based on its current rate of change.

**Finally parameters**

* PID parameters used for **steering angles**: 

    * p value: 0.1 
    * i value: 0.001
    * d value: 2.8

* PID parameters used for **throttle**: 

    * p value: 0.45 
    * i value: 0.000
    * d value: 0.5

**How to tune the parameters**

The parameters are tuned manually with the order of: p, d, i. The d and i are first setted to be zeros, 
 and 0.2 is used for the p value. I adjust the p value up and down till it could drive around the first 
 corner and hard to imporve more. Then I keep the p value as it is, and increase the d value. Use the 
 same approach for d value and i value.

In order to automatically fine tune the parameters, an optimization algorithm **twiddle** can be used, which is exampled as follows:

* [Twiddle algorithm](https://www.youtube.com/watch?v=2uQ2BSzDvXs) 

* [Twiddle sample code in python](https://martin-thoma.com/twiddle/)


Demo 2: [speedy drive](https://youtu.be/E8uXIBIRg8M), which is targeting for dirivng the car as fast
as possible, but as a side effect, the car starts to swing. In order to make the car drive 
fast as well as steady, further joint parameter tuning for both PID controllers need to be carried out. 



---

## Code & Files
### 1. Dependencies & environment

* cmake >= 3.5
* make >= 4.1
* gcc/g++ >= 5.4
* uWebSockets: used for communication between the main code and the simulator.
    * [libs/install-mac](install-mac.sh) install uWebSockets in Mac.
    * [libs/install-ubuntu](install-ubuntu.sh) install uWebSockets in Ubuntu.
    

### 2. How to run the code

1. Clone this repo.
2. Clean the project: `$./clean.sh`
3. Build the project: `$./build.sh` 
4. Run the project: `$./run.sh`
5. Start the [simulator v1.45](https://github.com/udacity/self-driving-car-sim/releases), 
select the PID Controller. 


### 3. My project files

* [CMakeLists.txt](CMakeLists.txt) is the cmake file.
* [data](data) folder contains GIFs. 
* [src](src) folder contains the source code.
* [clean.sh](clean.sh) cleans the project.
* [build.sh](build.sh) builds the project.
* [run.sh](run.sh) runs the project.
* [libs](libs) scripts to install uWebSockets.



### 4. Code Style

* [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).


### 5. Release History

* 0.1.1
    * First proper release
    * Date 14 July 2017

* 0.1.0
    * Create the repo
    * Date 13 July 2017

---









[//]: # (Image References)
[image1]: ./data/1.png
[gif1]: ./data/steady.gif
[gif2]: ./data/speedy.gif

