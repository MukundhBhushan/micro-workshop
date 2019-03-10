import numpy as np
from kafka import KafkaProducer
from kafka import KafkaConsumer
import paho.mqtt.client as mqtt
import json
import time
Cloud_HOST = 'XXXXXXXXXXXXX'
ACCESS_TOKEN = 'XXXXXXXXXXXXXXX' #change the access token

#dat = 60

def senddata(mean,client):
	count = 1
	INTERVAL=1
	sensor_data = {'temper': 0}
	next_reading = time.time() 
	client.loop_start()
	temperature = mean
	sensor_data['temper'] = temperature
	print(sensor_data)
	client.publish('v1/devices/me/telemetry', json.dumps(sensor_data), 1)
	time.sleep(INTERVAL)
	client.loop_stop()

def decode(k):
	m = k.decode("utf-8")
	p = int(k)
	return p
	
client = mqtt.Client()
client.username_pw_set(ACCESS_TOKEN)
client.connect(Cloud_HOST, 1883, 60)

consumer = KafkaConsumer(bootstrap_servers='45.114.246.183:9092')
consumer.subscribe(['Testing']) #change the topic


i = 0
cnt = 0
flag = False
l = []
for msg in consumer:
	decodedmsg = decode(msg[6])
	l.append(decodedmsg)
	i = i + 1	
	if(i == 50):
		flag = True
	if(flag == True):
		conv = np.array(l)
		mean = np.median(conv[cnt:50+cnt])
		cnt = cnt + 1	
		senddata(mean,client)
client.disconnect()
