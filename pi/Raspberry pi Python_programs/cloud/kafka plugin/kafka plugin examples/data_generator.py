import os
import time
import sys
import paho.mqtt.client as mqtt
import json
import random

Cloud_HOST = 'XXXXXXXXXXXXX'
ACCESS_TOKEN = 'XXXXXXXXXXXXX' #change access token

INTERVAL=1
sensor_data = {'temp': 0}
next_reading = time.time() 
client = mqtt.Client()

cnt = 0

client.username_pw_set(ACCESS_TOKEN)
client.connect(Cloud_HOST, 1883, 60)
client.loop_start()
try:
	while True:
		if (cnt%50 == 0):
			temperature = 55
		else:
			temperature = random.randint(35	,36)
		sensor_data['temp'] = temperature
		print temperature
		client.publish('v1/devices/me/telemetry', json.dumps(sensor_data), 1)
		time.sleep(INTERVAL)
		cnt = cnt + 1
except KeyboardInterrupt:
	pass
client.loop_stop()
client.disconnect()
