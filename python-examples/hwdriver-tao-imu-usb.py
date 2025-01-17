#!/usr/bin/env python3

# ---------------------------------------------------------------------
# Install python3-mrpt, or test with a local build with:
# export PYTHONPATH=$HOME/code/mrpt/build-Release/:$PYTHONPATH
# ---------------------------------------------------------------------

from mrpt import pymrpt
mrpt = pymrpt.mrpt  # namespace shortcut

imu = mrpt.hwdrivers.CTaoboticsIMU()

imu.setSerialPort('/dev/ttyUSB0')

# Opens the serial port and start listening
imu.initialize()

while True:
    # Process serial port data queue:
    imu.doProcess()

    # Get observations:
    obsList = imu.getObservations()

    # Process them:
    if not obsList.empty():
        print('Read {} observations'.format(obsList.size()))
        for t, obs in obsList:
            timestamp = mrpt.Clock.toDouble(t)
            print('Time={} obs={}'.format(timestamp, obs.asString()))

            # You can access individual IMU readings with:
            # angVel_z = o.get(mrpt.obs.TIMUDataIndex.IMU_WZ)
            #
            # See: https://docs.mrpt.org/reference/latest/enum_mrpt_obs_TIMUDataIndex.html
