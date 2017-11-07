#!/usr/bin/env python
import os
import time
import MySQLdb
import random
import yaml

def db_config():

    with open("config.yaml", 'r') as ymlfile:
        cfg = yaml.load(ymlfile)
    global user
    user = cfg['dbconfig']['user']
    global password
    password = cfg['dbconfig']['password']
    global db_name
    db_name = cfg['dbconfig']['dbname']
    global db_host
    db_host = cfg['dbconfig']['dbhost']


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

	#insert in db 
	db_config()

	# Connetto al DB
	db = MySQLdb.connect(db_host,user,password,db_name )
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














