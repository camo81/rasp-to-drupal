#!/usr/bin/env python
import os
import time
import MySQLdb
import random


#----------------------------------------------------------------
#	Note:
#		ds18b20's data pin must be connected to pin7.
#----------------------------------------------------------------

# Reads temperature from sensor and prints to stdout
# id is the id of the sensor

def readSensor(id):
	tfile = open("/sys/bus/w1/devices/"+id+"/w1_slave")
	text = tfile.read()
	tfile.close()
	secondline = text.split("\n")[1]
	temperaturedata = secondline.split(" ")[9]
	temperature = float(temperaturedata[2:])
	temperature = temperature / 1000


	temperature = round(temperature,2)
	#print rand

	# Open database connection
	db = MySQLdb.connect("localhost","stazioneMeteo","ySLQNYC9PZ3646UR","stazione_meteo" )

	# prepare a cursor object using cursor() method
	cursor = db.cursor()
	
	#SQL query to INSERT a record into the table FACTRESTTBL.
	cursor.execute('''INSERT into stazionemeteo_temperatura (valore) values (%s)''', (temperature))
                  

	# Commit your changes in the database
	db.commit()

	# disconnect from server
	db.close()






count = 0
sensor = ""
for file in os.listdir("/sys/bus/w1/devices/"):
	if (file.startswith("28-")):
		readSensor(file)
		count+=1
if (count == 0):
	print "No sensor found! Check connection"














