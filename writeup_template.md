# **PID Controler** 

## Writeup Template

### You can use this file as a template for your writeup if you want to submit it as a markdown file, but feel free to use some other method and submit a pdf if you prefer.

---

**PID Controler Project**

The goals / steps of this project are the following:
* Create the PID-Controler whose input is cte.
* Tune the PID parameters by manual tunig to successfully drive around the track.
* Summarize the results with a written report


[//]: # (Image References)

[image1]: ./reference/overshoot.png "Overshoot Image"

## Rubric Points
### Here I will consider the [rubric points](https://review.udacity.com/#!/rubrics/1972/view) individually and describe how I addressed each point in my implementation.  

---
### Files Submitted & Code Quality

#### 1. Submission includes all required files and can be used to run the simulator in autonomous mode

My project includes the following files:
* main.cpp containing the main function execute pid-control.
* PID.h defines the PID class which describes PID-controler
* PID.cpp implements PID class's member functions.
* writeup_report.md or writeup_report.pdf summarizing the results

#### 2. Submission includes functional code
Using the Udacity provided simulator and my pid.exe file, the car can be driven around the track by executing 
```sh
./pid
```

#### 3. Submission code is usable and readable

The main.cpp file contains the code for executing the driving based on cte.

### Tuning Strategy

#### 1. Attempts to drive along the path

To drive along the path, I set the P gain to 0.2. 

#### 2. Attempts to reduce overshoot

A short time later, ego vehicle overshoots and leave the road.(image1)
To avoid this, I set the D gain to 1.35 and I gain to 0.0001.
As a result of this tuning, ego vehicle became to drive without leaving lane.
