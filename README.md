# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

---
## Reflection

Explanation of the P, I, D components of the PID Controller.

The P controlled the maximum the car could steer. If this value was too low, then the car would not steer enough to get back to the center of the lane. I did not use the "I" component of the algorithm, it's purpose is to account for constant environmental bias. The D component was used to keep the P from steering too hard when the steering angle was close to zero. I did not expect

## Finding Hyperparameters

This was tricky because I started by using the numbers from the lectures on the python robot. This did not work because of the order of magnitude difference in the hyperparameters. After a few hours of ideas tried and failed, I consulted the slack channel. The idea was to tune the P value ( with I and D zero) until the amount the car was turning was satisfactory. Then add the Derivative term to make it smoother. Since there was not a constant bias, I kept the I term to be zero. When neither seemed to work, I decreased the P term until it was minimal to accomplish the task. To smooth, I modified the D term until the car stopped touching the side of the lane. Also since the car did not have a constant bias, the I term was zero.

## Link to a video
Below is a link to the video. During the straight part, the D factor helps the car not steer many times. Then a few seconds later when the car gets to the curve, it is the P factor that is high enough to output a steering angle capable of navigating the curve.


[Car In Action](https://github.com/leclair-7/CarND-PID-Control-Project/PID_in_action.mp4)
