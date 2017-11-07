#!/usr/bin/python

# Copyright (c) 2014 Adafruit Industries
# Author: Tony DiCola

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
import sys
#uncomment per avere dati reali
#import Adafruit_DHT
import MySQLdb
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


#uncomment per leggerei dati reali. Commentare poi le due linee sottostanti
#humidity, temperature = Adafruit_DHT.read_retry(Adafruit_DHT.DHT11, 27)

# Un-comment the line below to convert the temperature to Fahrenheit.
# temperature = temperature * 9/5.0 + 32

#commenta per avere dati reali
humidity = 30
temperature = 30

if humidity is not None and temperature is not None:

	humidity = round(humidity,2)
	temperature = round(temperature,2)


	#insert in db 
	db_config()

	# Connetto al DB
	db = MySQLdb.connect(db_host,user,password,db_name )
	cursor = db.cursor()
	
	#SQL query to INSERT a record into the table FACTRESTTBL.
	cursor.execute('''INSERT into stazionemeteo_umidita (valore,tempDht) values (%s,%s)''', (humidity,temperature))
                  

	# Commit your changes in the database
	db.commit()

	# disconnect from server
	db.close()	
else:
	print 'Failed to get reading. Try again!'
	sys.exit(1)
