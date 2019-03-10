#!/usr/bin/env python
import socket
import sys
import json
#import Adafruit_DHT as dht
from coapthon.client.helperclient import HelperClient
from coapthon.utils import parse_uri
sensor_data = {'temperature': 0, 'humidity': 0}
DHT_pin = 4

wise3 = '45.114.246.183:8080'
accesstoken = 'coap'

client = None

def main():  # pragma: no cover
    global client
    op = 'POST'
    path = 'coap://'+wise3+'/api/v1/'+accesstoken+'/telemetry'
    print path
    sensordata()
    payload = json.dumps(sensor_data)
    opts = [('-o', op), ('-p', path), ('-P', payload)]
    print opts
    host, port, path = parse_uri(path)
    try:
        tmp = socket.gethostbyname(host)
        host = tmp
    except socket.gaierror:
        pass
    client = HelperClient(server=(host, 5683))
     
    if op == "POST":
        response = client.post(path,payload)
        print response.pretty_print()
        client.stop()
  
    else:
        print "Operation not recognized"
        sys.exit(2)

def sensordata():#read sensor data
    #humidity,temperature = dht.read_retry(dht.DHT22, DHT_pin)
    humidity = 56#round(humidity, 2)
    temperature = 67#round(temperature, 2)
    sensor_data['temperature'] = temperature
    sensor_data['humidity'] = humidity
    print sensor_data

if __name__ == '__main__':  # pragma: no cover
    while True:
        main()
