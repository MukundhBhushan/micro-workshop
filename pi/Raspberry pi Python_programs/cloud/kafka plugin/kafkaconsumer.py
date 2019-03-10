from kafka import KafkaConsumer
consumer = KafkaConsumer(bootstrap_servers='45.114.246.183:9092')
consumer.subscribe(['Testing'])
for msg in consumer:
     print (msg)
