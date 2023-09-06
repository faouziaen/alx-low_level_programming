#!/bin/bash

# This script prints the maximum process ID value allowed by the system.

pid_max=$(cat /proc/sys/kernel/pid_max)
echo "Maximum PID Value: $pid_max"
