from kafka import KafkaProducer
import time
producer = KafkaProducer(bootstrap_servers='45.114.246.183:9092')
for _ in range(100):
    producer.send('Testing', b'some_message_bytes')
    time.sleep(1)
